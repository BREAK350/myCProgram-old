//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "T_BattleGround.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TForm1 *Form1;
pT_Any_Warrior w1[3],w2[3];
T_BattleGround BG;                                                       
TPoint p,c;
float s=1,angle=0;
Event event;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    T_Character ch(100,40,4,7,9);
    T_Poligon poligon;
    T_Point tp[]={T_Point(-0.5,0.5),T_Point(0.5,0.5),T_Point(0,-0.5)};
    poligon.Init(3,clBlack,clRed,tp);
    w1[0]=new T_Warrior("w1[1]",TPoint(1,1),ch,poligon);
    w1[1]=new T_Warrior("w1[2]",TPoint(1,2),ch,poligon);
    w1[2]=new T_Warrior("w1[3]",TPoint(1,3),ch,poligon);
    poligon.clBrush=clBlue;
    poligon.SaveToFile("Triangle");
    w2[0]=new T_Warrior("w2[1]",TPoint(3,1),ch,poligon);
    w2[1]=new T_Warrior("w2[2]",TPoint(3,2),ch,poligon);
    w2[2]=new T_Warrior("w2[3]",TPoint(3,3),ch,poligon);
    BG.Init(2,&T_Members(3,w1),&T_Members(3,w2),poligon);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
    s=TrackBar1->Position;
    Canvas->Rectangle(-1,-1,1000,1000);
    BG.Draw(Canvas,p,s);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar2Change(TObject *Sender)
{
    p.x=TrackBar2->Position*s;
    Canvas->Rectangle(-1,-1,1000,1000);
    BG.Draw(Canvas,p,s);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar3Change(TObject *Sender)
{
    p.y=TrackBar3->Position*s;
    Canvas->Rectangle(-1,-1,1000,1000);
    BG.Draw(Canvas,p,s);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    event=CHOOSEMEMBER;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    event=MOVETO;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    event=ATTACK;    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
    switch(event)
    {
        case CHOOSEMEMBER:
            BG.ChooseMember(c);
            break;
        case MOVETO:
            BG.MoveTo(c);
            break;
        case ATTACK:
            BG.Attack(c);
            break;
    }
    Canvas->Rectangle(-1,-1,1000,1000);
    BG.Draw(Canvas,p,s);
    event=CHOOSEMEMBER;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    c.x=floor((X-p.x)/s+0.5);
    c.y=floor((Y-p.y)/s+0.5);
    AnsiString a=IntToStr(c.x);
    a=a+';';
    a=a+IntToStr(c.y);
    Edit1->Text=a;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    BG.NextNation();
    Canvas->Rectangle(-1,-1,1000,1000);
    BG.Draw(Canvas,p,s);  
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
    T_Poligon poligon;
    T_Point tp[]={T_Point(10,10),T_Point(20,20),T_Point(30,0)};
    poligon.Init(3,clBlack,clRed,tp);
    poligon.Draw(Canvas,TPoint(30,30),s,angle*M_PI/180);
    angle+=10;
}
//---------------------------------------------------------------------------

