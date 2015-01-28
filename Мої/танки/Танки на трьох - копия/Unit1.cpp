//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
TForm1 *Form1;
const int MaxMPCount = 5;
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
    MPCur=0;
    BMP->Width=1300;
    BMP->Height=700;
    BMP->Canvas->Pen->Width=3;
    GC.Or.Canvas=BMP->Canvas;

    /*Trajectory.SetAmount(12);
    Trajectory[0]=new T_Segment(100,100,1200,100);
    Trajectory[1]=new T_Segment(1200,100,1200,200);
    Trajectory[2]=new T_Segment(1200,200,700,200);
    Trajectory[3]=new T_Segment(700,200,700,500);
    Trajectory[4]=new T_Segment(700,500,1200,500);
    Trajectory[5]=new T_Segment(1200,500,1200,600);
    Trajectory[6]=new T_Segment(1200,600,100,600);
    Trajectory[7]=new T_Segment(100,600,100,500);
    Trajectory[8]=new T_Segment(100,500,600,500);
    Trajectory[9]=new T_Segment(600,500,600,200);
    Trajectory[10]=new T_Segment(600,200,100,200);
    Trajectory[11]=new T_Segment(100,200,100,100);
    Trajectory.SaveToFile("en.txt");*/

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
}
//---------------------------------------------------------------------------
int Search(const int &n,const int *a,const int &s)
{
    int q=0,i=0;
    while(q==0 && i<n)
    {
        q=(s==a[i]);
        i++;
    }
    return q;
}
//---------------------------------------------------------------------------
void Random(const int &n,int *a)
{
    int i,s;
    for(i=0;i<n;i++)
    {
        while(Search(i,a,s=random(n))==1);
        a[i]=s;
    }
}
//---------------------------------------------------------------------------
void TForm1::NewGame()
{
    Tank.CurrSetFirst();
    while(Tank.CurrCorrect())
    {
        delete Tank.GetCurr();
        Tank.CurrSetNext();
    }
    Tank.DeleteAll();
    GC.List.DeleteAll();
    double h=Trajectory.GetAmount()/((double)TankCount+TankEnemyCount);
    TbTank *t;
    int *rnd=new int [TankCount+TankEnemyCount];
    Random(TankCount+TankEnemyCount,rnd);
    for(int i=0;i<TankCount;i++)
    {
        t=new TbTank(Form1,TankSpeed,40.0,TankSpeedShoot);
        t->Last_t=h*rnd[i];
        t->Color=TankColor[i];
        t->Button=TankButton[i];
        Tank.AddLast(t);
        GC.List.AddLast(t);

    }
    for(int i=0;i<TankEnemyCount;i++)
    {
        t=new TbAvtoTank(Form1,TankSpeed,40.0,TankSpeedShoot);
        t->Last_t=h*rnd[i+TankCount];
        t->Color=clMaroon;
        Tank.AddLast(t);
        GC.List.AddLast(t);
    }
    delete rnd;
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
    GunRotate=StrToFloat(Edit7->Text);
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
        Gun.Rotate(GunRotate*M_PI/180);
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
    GunRotate=Form->GunRotate*((random(2)==1)?(1):(-1));
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
    Form->Tank.CurrSetFirst();
    while(Form->Tank.CurrCorrect() && ((Form->Tank.GetCurr())?((Location-Form->Tank.GetCurr()->Location).Length()>R+Form->Tank.GetCurr()->R):(true)))
    {
        Form->Tank.CurrSetNext();
    }
    if(Form->Tank.CurrCorrect())
    {
        Form->Tank.GetCurr()->Health-=Health;
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

        //PlaySound("awp1.wav",0,SND_ASYNC);
        Form->MPlay();
    }
    return Shell;
}
//---------------------------------------------------------------------------
void TForm1::MPlay()
{
    switch(MPCur)
    {
        case 0:
            MediaPlayer1->Previous();
            MediaPlayer1->Play();
            break;
        case 1:
            MediaPlayer2->Previous();
            MediaPlayer2->Play();
            break;
        case 2:
            MediaPlayer3->Previous();
            MediaPlayer3->Play();
            break;
        case 3:
            MediaPlayer4->Previous();
            MediaPlayer4->Play();
            break;
        case 4:
            MediaPlayer5->Previous();
            MediaPlayer5->Play();
            break;
    }
    MPCur++;
    if(MPCur>=MaxMPCount)
    {
        MPCur=0;
    }
}
//---------------------------------------------------------------------------
TbShell* TbAvtoTank::AvtoShoot()
{
    TbShell *Shell=NULL;
    if(CurrTimeShoot>=MaxTimeShoot && Health>0)
    {
        TbTank *min=NULL;
        double d=-1;
        Form->Tank.CurrSetFirst();
        while(Form->Tank.CurrCorrect() && (Form->Tank.GetCurr()->Health<=0 || this==Form->Tank.GetCurr()))
        {
            Form->Tank.CurrSetNext();
        }
        if(Form->Tank.CurrCorrect())
        {
            d=fabs((Form->Tank.GetCurr()->Location-Location).AngleR()-Gun.AngleR());
            //d=(Location-Form->Tank[i]->Location).Length();
            min=Form->Tank.GetCurr();
        }
        while(Form->Tank.CurrCorrect())
        {
            if(this!=Form->Tank.GetCurr() && Form->Tank.GetCurr()->Health>0)
            {
                if(d>fabs((Form->Tank.GetCurr()->Location-Location).AngleR()-Gun.AngleR()))
                //if(d>(Location-Form->Tank[i]->Location).Length())
                {
                    d=fabs((Form->Tank.GetCurr()->Location-Location).AngleR()-Gun.AngleR());
                    //d=(Location-Form->Tank[i]->Location).Length();
                    min=Form->Tank.GetCurr();
                }
            }
            Form->Tank.CurrSetNext();
        }
        if(d!=-1)
        {
            T_Vector2d Speed=VectorShoot(min->Direction,Location-min->Location,Form1->ShellSpeed);
            if(Speed)
            {
                if(Gun.GetAngleBetweenR(Speed)<0.05)
                {
                    Shell=TbTank::DoShoot();
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
    Tank.CurrSetFirst();
    while(Tank.CurrCorrect() && Key!=Tank.GetCurr()->Button)
    {
        Tank.CurrSetNext();
    }
    if(Tank.CurrCorrect())
    {
        Shell=Tank.GetCurr()->DoShoot();
    }
    if(Shell)
    {
        GC.List.AddLast(Shell);
    }
    if(Key==49)
    {
        TankCount=1;
        if(TankEnemyCount+TankCount<2)
        {
            TankEnemyCount=1;
        }
        NewGame();
        Play();
    }
    else
    if(Key==50)
    {
        TankCount=2;
        NewGame();
        Play();
    }
    else
    if(Key==51)
    {
        TankCount=3;
        NewGame();
        Play();
    }
    else
    if(Key==52)
    {
        TankCount=4;
        NewGame();
        Play();
    }
    else
    if(Key==53)
    {
        TankCount=5;
        NewGame();
        Play();
    }
    else
    if(Key==13)
    {
        Timer1->Enabled=!Timer1->Enabled;
    }
    else
    if(Key==116)
    {
        NewGame();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
    Pause();
    Panel1->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    ReadData();
    Panel1->Visible=false;
    Play();
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
    T_Vector2d Way=Enemy;
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
    else
    {
        Way.AngleR();
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
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    TankCount=(ComboBox1->ItemIndex>-1)?(ComboBox1->ItemIndex):(0);
    TankEnemyCount=(ComboBox2->ItemIndex>-1)?(ComboBox2->ItemIndex):(0);
    if(TankCount+TankEnemyCount>1)
    {
        NewGame();
    }
    Panel2->Visible=false;
    Play();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)
{
    Pause();
    Panel2->Visible=true;
}
//---------------------------------------------------------------------------
/*DWORD __stdcall ThreadFunc ( void *p )
{
    HDC hDC = GetDC ( Form1->Handle );
    SetTextColor ( hDC, RGB ( 0, 127, 127 ) );

    for ( size_t i = 0; i < 1000000; ++i )
    {
        String s = i;
        TextOutA ( hDC, 10, i/10000, s.c_str(), s.Length() );
    }
    ReleaseDC ( Form1->Handle, hDC );
    MessageBeep( MB_OK );
    return 0;
}*/
void __fastcall TForm1::N7Click(TObject *Sender)
{
    Form2->Show();
    //Sleep(5000);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N8Click(TObject *Sender)
{
    Trajectory.LoadFromFile("en.txt");
}
//---------------------------------------------------------------------------

