//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "T_Map.h"
//---------------------------------------------------------------------------
TForm1 *Form1;
T_Map Map;
TPoint p(0,0),cur;
float s=1;
EVENT e=DONOTHING;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Map.Init();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
    Canvas->Rectangle(-1,-1,1000,1000);
    s=TrackBar1->Position;
    Map.Draw(Canvas,s,p);
    Canvas->Ellipse(p.x-3,p.y-3,p.x+3,p.y+3);
    Edit1->Text=FloatToStr(s);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar2Change(TObject *Sender)
{
    Canvas->Rectangle(-1,-1,1000,1000);
    p.x=TrackBar2->Position;
    Map.Draw(Canvas,s,p);
    Canvas->Ellipse(p.x-3,p.y-3,p.x+3,p.y+3);
    AnsiString a=IntToStr(p.x);
    a=a+';';
    a=a+IntToStr(p.y);
    Edit2->Text=a;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar3Change(TObject *Sender)
{
    Canvas->Rectangle(-1,-1,1000,1000);
    p.y=TrackBar3->Position;
    Map.Draw(Canvas,s,p);
    Canvas->Ellipse(p.x-3,p.y-3,p.x+3,p.y+3);
    AnsiString a=IntToStr(p.x);
    a=a+';';
    a=a+IntToStr(p.y);
    Edit2->Text=a;
}
//---------------------------------------------------------------------------
void Cursor(TPoint c)
{
    AnsiString a=IntToStr(c.x);
    a=a+';';
    a=a+IntToStr(c.y);
    Form1->Canvas->TextOutA(500,50,a);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    cur.x=X/s+0.5;
    cur.y=Y/s+0.5;
    AnsiString a=IntToStr((int)(cur.x));
    a=a+';';
    a=a+IntToStr((int)(cur.y));
    Edit3->Text=a;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
    Map.Control(cur,e,0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GOCITY1Click(TObject *Sender)
{
    e=GO_CITY;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GOCOMMANDER1Click(TObject *Sender)
{
    e=GO_COMMANDER;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MOVETO1Click(TObject *Sender)
{
    e=MOVETO;
}
//---------------------------------------------------------------------------

