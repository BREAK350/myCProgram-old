//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TRect Region;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    randomize();
    
    Player1.Rect=TRect(100,100,170,200);
    Player1.Color=clBlue;
    Player1.Angle=180;
    Player1.vAngle=5;
    Player1.HP=100;
    Player1.Shot=false;
    Player1.Move=random(5)+2;
    Player1.sv=50;

    Player2.Rect=TRect(-170+Form1->ClientWidth,100,-100+Form1->ClientWidth,200);
    Player2.Color=clRed;
    Player2.Angle=0;
    Player2.vAngle=-5;
    Player2.HP=100;
    Player2.Shot=false;
    Player2.Move=(random(5)+2);
    Player2.sv=50;

    Region=TRect(0,0,Form1->ClientWidth,Form1->ClientHeight);
    Game=false;
    MaxHP=100;

    //MediaPlayer1->FileName="awp1.wav";
    //MediaPlayer1->Open();
}
//---------------------------------------------------------------------------
void T_Player::Draw(TCanvas *Canvas)
{
    Canvas->Brush->Color=clWhite;
    Canvas->Rectangle(Rect.Left,Rect.Top,Rect.Right,
            Rect.Top+Rect.Height()*(Form1->MaxHP-HP)/Form1->MaxHP);
    Canvas->Brush->Color=Color;
    Canvas->Rectangle(Rect.Left,
            Rect.Top+Rect.Height()*(Form1->MaxHP-HP)/Form1->MaxHP,Rect.Right,Rect.Bottom);
    TPoint c((Rect.Left+Rect.Right)/2,(Rect.Top+Rect.Bottom)/2);
    int r=(Rect.Width()+Rect.Height())/6, d=100, sr=3;
    Canvas->Pen->Width=sr;
    TPoint e(d*cos(Angle*M_PI/180),d*sin(Angle*M_PI/180));
    Canvas->MoveTo(c.x,c.y);
    Canvas->LineTo(e.x+c.x,e.y+c.y);
    Canvas->Pen->Width=1;
    Canvas->Ellipse(c.x-r,c.y-r,c.x+r,c.y+r);
    if(Shot)
    {
        Canvas->Ellipse(Snaryad.x-sr,Snaryad.y-sr,Snaryad.x+sr,Snaryad.y+sr);
    }
}
//---------------------------------------------------------------------------
void T_Player::DoShot()
{
    if(Shot==false)
    {
        int d=100;
        Shot=true;
        TPoint c((Rect.Left+Rect.Right)/2,(Rect.Top+Rect.Bottom)/2);
        SnaryadAngle=Angle;
        Snaryad=TPoint(d*cos(Angle*M_PI/180)+c.x,d*sin(Angle*M_PI/180)+c.y);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    if(Game)
    {
        Canvas->Brush->Color=clWhite;
        Canvas->Rectangle(-1,-1,2000,1000);
        Player1.Draw(Canvas);
        Player2.Draw(Canvas);
        Player1.NextStep(Region,Player2);
        Player2.NextStep(Region,Player1);
    }
    else
    {
        Timer1->Enabled=false;
        if(Player1.HP>0)
        {
            ShowMessage("Виграв перший гравець (синій)");
        }
        else
        {
            ShowMessage("Виграв другий гравець (червоний)");
        }
    }
}
//---------------------------------------------------------------------------
void T_Player::NextStep(const TRect &Region,T_Player &Enemy)
{
    if(Rect.Top+Move<Region.Top || Rect.Bottom+Move>Region.Bottom)
    {
        Move=-Move;
    }
    Rect.Top+=Move;
    Rect.Bottom+=Move;
    Angle+=vAngle;
    if(Shot)
    {
        if(Snaryad.x>=Enemy.Rect.Left && Snaryad.x<=Enemy.Rect.Right &&
           Snaryad.y>=Enemy.Rect.Top && Snaryad.y<=Enemy.Rect.Bottom)
        {
            Enemy.HP-=random(10)+10;
            Shot=false;
            if(Enemy.HP<=0)
            {
                Form1->Game=false;
            }
        }
        Snaryad.x+=sv*cos(SnaryadAngle*M_PI/180);
        Snaryad.y+=sv*sin(SnaryadAngle*M_PI/180);
        if(Snaryad.x<Region.Left || Snaryad.y<Region.Top ||
           Snaryad.x>Region.Right || Snaryad.y>Region.Bottom)
        {
            Shot=false;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key==68)
    {
        Player1.DoShot();
        //MediaPlayer1->Stop();
        //MediaPlayer1->Play();
    }
    if(Key==75)
    {
        Player2.DoShot();
    }
    if(Key==13)
    {
        FormClick(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
    if(Game==false)
    {
        Player1.Rect=TRect(100,100,170,200);
        Player1.Color=clBlue;
        Player1.Angle=180;
        Player1.vAngle=5;
        Player1.HP=100;
        Player1.Shot=false;
        Player1.Move=random(5)+2;
        Player1.sv=50;

        Player2.Rect=TRect(-170+Form1->ClientWidth,100,-100+Form1->ClientWidth,200);
        Player2.Color=clRed;
        Player2.Angle=0;
        Player2.vAngle=-5;
        Player2.HP=100;
        Player2.Shot=false;
        Player2.Move=(random(5)+2);
        Player2.sv=50;

        Region=TRect(0,0,Form1->ClientWidth,Form1->ClientHeight);
        Game=true;
        MaxHP=100;
        Timer1->Enabled=true;
    }
}
//---------------------------------------------------------------------------

