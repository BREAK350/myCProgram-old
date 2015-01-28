//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
TForm1 *Form1;
Graphics::TBitmap *BMP=new Graphics::TBitmap;
const int TankMaxCount = 5;
TColor TankColor[]={clBlue,clGreen,clRed,clAqua,clPurple};
int TankButton[]={81,89,80,90,77};
//                 Q  Y  P  Z  M
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner),GC(Timer1)
{
    randomize();
    BMP->Width=1300;
    BMP->Height=700;
    BMP->Canvas->Pen->Width=3;
    GC.Or.Canvas=BMP->Canvas;
    Trajectory.LoadFromFile("rect.txt");

    /*
    Trajectory.SetAmount(2);
    Trajectory[0]=new T_HermiteCurve(T_Vector2d(650,350),T_Vector2d(650,350),T_Vector2d(-2000,-2000),T_Vector2d(2000,-2000));
    Trajectory[1]=new T_HermiteCurve(T_Vector2d(650,350),T_Vector2d(650,350),T_Vector2d(2000,-2000),T_Vector2d(-2000,-2000));
    Trajectory.SetEpsilon(0.01);
    Trajectory.SaveToFile("octa.txt");
    */

    TankCount=0;
    ReadData();
    NewGame(3);
}
//---------------------------------------------------------------------------
void TForm1::NewGame(const int &_TankCount)
{
    for(int i=0;i<TankCount;i++)
    {
        delete Tank[i];
    }
    delete Tank;
    GC.List.DeleteAll();
    TankCount=(_TankCount<=TankMaxCount && _TankCount>1)?(_TankCount):(2);
    double h=Trajectory.GetAmount()/((double)TankCount),b=0;
    Tank=new TbTank*[TankCount];
    for(int i=0;i<TankCount;i++)
    {
        Tank[i]=new TbTank(Form1,TankSpeed,40.0,TankSpeedShoot);
        Tank[i]->Last_t=b;
        Tank[i]->Color=TankColor[i];
        Tank[i]->Button=TankButton[i];
        GC.List.AddLast(Tank[i]);
        b+=h;
    }
}
//---------------------------------------------------------------------------
void TForm1::ReadData()
{
    TankHealth=StrToFloat(Edit1->Text);
    TankSpeed=StrToFloat(Edit2->Text);
    TankSpeedShoot=StrToFloat(Edit3->Text);
    ShellMinPower=StrToFloat(Edit4->Text);
    ShellMaxPower=StrToFloat(Edit5->Text);
    ShellSpeed=StrToFloat(Edit6->Text);
}
//---------------------------------------------------------------------------
void TbTank::Move(T_Trajectory *Trajectory)
{
    Direction=Location;
    Trajectory->NextPoint_Right(Last_t,Location);
    Last_t=Trajectory->Get_t();
    Direction=Location-Direction;
}
//---------------------------------------------------------------------------
void TbTank::NextPos()
{
    if(Health>0)
    {
        if(CurrTimeShoot<MaxTimeShoot)
        {
            CurrTimeShoot++;
        }
        Move(&Form->Trajectory);
        Gun.Rotate(5*M_PI/180);
    }
}
//---------------------------------------------------------------------------
TbTank::TbTank(TForm1 *Form,const double &Speed,const double &R,
    const int &MaxTimeShoot):TbMoveObj(Form,R,Form1->TankHealth),Gun(1,0)
{
    Last_t=0;
    Form->Trajectory.SetEpsilon(0.01);
    Form->Trajectory.SetLength(Speed);
    Gun.Rotate(random(360)*M_PI/180);
    Gun.SetLength(2.0*R);
    CurrTimeShoot=this->MaxTimeShoot=MaxTimeShoot;
    Button=0;
}
//---------------------------------------------------------------------------
TbMoveObj::TbMoveObj(TForm1 *Form,const double &R,const double &Health):Location()
{
    this->R=R;
    this->Form=Form;
    MaxHealth=this->Health=Health;
}
//---------------------------------------------------------------------------
void TbShell::Move()
{
    Location=Location+Speed;
}
//---------------------------------------------------------------------------
TbShell::TbShell(TForm1 *Form,const T_Vector2d &Speed)
    :TbMoveObj(Form,4,random(Form1->ShellMaxPower-Form1->ShellMinPower)+Form1->ShellMinPower)
{
    this->Speed=Speed;
}
//---------------------------------------------------------------------------
void TbShell::Check()
{
    int i=0;
    while(i<Form->TankCount && ((Form->Tank[i])?((Location-Form->Tank[i]->Location).Length()>R+Form->Tank[i]->R):(true)))
    {
        i++;
    }
    if(i<Form->TankCount)
    {
        Form->Tank[i]->Health-=Health;
        Health=0;
        Enabled=false;
    }
}
//---------------------------------------------------------------------------
void TbMoveObj::Draw(TbOrientation &Or)
{
    Or.Canvas->Brush->Color=clGray;
    Or.Canvas->Ellipse(Location.X-R,Location.Y-R,Location.X+R,Location.Y+R);
    SetColor(Or.Canvas);
    T_Vector2d l(0,100),r(0,100);
    l.Rotate(-M_PI*Health/MaxHealth);
    r.Rotate(M_PI*Health/MaxHealth);
    l=l+Location;
    r=r+Location;
    Or.Canvas->Chord(Location.X-R,Location.Y-R,Location.X+R,Location.Y+R,
                r.X,r.Y,l.X,l.Y);
}
//---------------------------------------------------------------------------
void TbShell::Draw(TbOrientation &Or)
{
    TbMoveObj::Draw(Or);
}
//---------------------------------------------------------------------------
void TbTank::Draw(TbOrientation &Or)
{
    TbMoveObj::Draw(Or);
    Or.MoveTo(Location);
    Or.LineTo(Location+Gun);
}
//---------------------------------------------------------------------------
void TbShell::NextPos()
{
    Check();
    if(Health>0)
    {
        if(Location.Length()>2000)
        {
            Enabled=false;
        }
        else
        {
            Move();
        }
    }
}
//---------------------------------------------------------------------------
TbShell* TbTank::DoShoot()
{
    TbShell *Shell=NULL;
    if(CurrTimeShoot>=MaxTimeShoot && Health>0)
    {
        T_Vector2d Speed=Gun;
        Speed.SetLength(Form1->ShellSpeed);
        Shell=new TbShell(Form,Speed);
        Shell->Location=Location+Gun;
        CurrTimeShoot=0;
    }
    return Shell;
}
//---------------------------------------------------------------------------
TbShell* TbAvtoTank::AvtoShoot()
{
    TbShell *Shell=NULL;
    if(CurrTimeShoot>=MaxTimeShoot && Health>0)
    {
        int i=0,min;
        double d=-1;
        while(i<Form->TankCount && (Form->Tank[i]->Health<=0 || this==Form->Tank[i]))
        {
            i++;
        }
        if(i<Form->TankCount)
        {
            d=fabs((Form->Tank[i]->Location-Location).AngleR()-Gun.AngleR());
            //d=(Location-Form->Tank[i]->Location).Length();
            min=i;
        }
        while(i<Form->TankCount)
        {
            if(this!=Form->Tank[i] && Form->Tank[i]->Health>0)
            {
                if(d>fabs((Form->Tank[i]->Location-Location).AngleR()-Gun.AngleR()))
                //if(d>(Location-Form->Tank[i]->Location).Length())
                {
                    d=fabs((Form->Tank[i]->Location-Location).AngleR()-Gun.AngleR());
                    //d=(Location-Form->Tank[i]->Location).Length();
                    min=i;
                }
            }
            i++;
        }
        if(d!=-1)
        {
            T_Vector2d Speed=VectorShoot(Form->Tank[min]->Direction,Location-Form->Tank[min]->Location,Form1->ShellSpeed);
            if(Speed)
            {
                if(fabs(Speed.AngleR()-Gun.AngleR())<0.05)
                {
                    Speed=Gun;
                    Speed.SetLength(Form1->ShellSpeed);
                    Shell=new TbShell(Form,Speed);
                    Shell->Location=Location+Gun;
                    CurrTimeShoot=0;
                }
            }
        }
    }
    return Shell;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    BMP->Canvas->Brush->Color=clWhite;
    BMP->Canvas->Rectangle(-1,-1,1301,701);
    GC.Execute();
    Canvas->Draw(0,0,BMP);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    TbShell *Shell=NULL;
    int i=0;
    while(i<TankCount && Key!=Tank[i]->Button)
    {
        i++;
    }
    if(i<TankCount)
    {
        Shell=Tank[i]->DoShoot();
    }
    if(Shell)
    {
        GC.List.AddLast(Shell);
    }
    if(Key==50)
    {
        NewGame(2);
    }
    else
    if(Key==51)
    {
        NewGame(3);
    }
    else
    if(Key==52)
    {
        NewGame(4);
    }
    else
    if(Key==53)
    {
        NewGame(5);
    }
    else
    if(Key==13)
    {
        Timer1->Enabled=!Timer1->Enabled;
    }
    else
    if(Key==116)
    {
        NewGame(TankCount);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N21Click(TObject *Sender)
{
    NewGame(2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N31Click(TObject *Sender)
{
    NewGame(3);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N41Click(TObject *Sender)
{
    NewGame(4);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N51Click(TObject *Sender)
{
    NewGame(5);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
    Panel1->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    ReadData();
    Panel1->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N111Click(TObject *Sender)
{
    Timer1->Interval=40;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N121Click(TObject *Sender)
{
    Timer1->Interval=80;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N141Click(TObject *Sender)
{
    Timer1->Interval=160;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N181Click(TObject *Sender)
{
    Timer1->Interval=320;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N22Click(TObject *Sender)
{
    Timer1->Interval=20;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N32Click(TObject *Sender)
{
    Timer1->Interval=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N5Click(TObject *Sender)
{
    Trajectory.LoadFromFile("rect.txt");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N6Click(TObject *Sender)
{
    Trajectory.LoadFromFile("octa.txt");
}
//---------------------------------------------------------------------------
T_Vector2d VectorShoot(const T_Vector2d &Enemy,const T_Vector2d &LookAtMe,
    const double &Distance)
{
    T_Vector2d Way;
    double A=LookAtMe.X*LookAtMe.X+LookAtMe.Y*LookAtMe.Y,
           B=2*LookAtMe.X*Enemy.X*LookAtMe.Y*Enemy.Y,
           C=Enemy.X*Enemy.X+Enemy.Y*Enemy.Y-Distance*Distance,
           D=B*B-4*A*C;
    if(D>=0)
    {
        double t=0;
        if(A)
        {
            D=sqrt(D);
            double t1=(B-D)/(2*A),
                   t2=(B+D)/(2*A);
            t=(t1>=0)?(t1):(t2);
        }
        else
        {
            if(B)
            {
                t=-C/B;
            }
        }
        Way=LookAtMe*t;
        Way=Enemy-Way;
    }
    return Way;
}
//---------------------------------------------------------------------------
void TbAvtoTank::NextPos()
{
    TbTank::NextPos();
    if(Health>0)
    {
        TbShell *Shell=AvtoShoot();
        if(Shell)
        {
            Form->GC.List.AddLast(Shell);
        }
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

