//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "TbOrientation.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TbOrientation Or;
T_Vector2d v(100,0),v2(-47,0);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Or.Canvas=Canvas;
    Or.Shift.Init(ClientWidth/2,ClientHeight/2);
    Or.Up=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
    Or.Shift.Init(ClientWidth/2,ClientHeight/2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Repaint();
    v.Rotate(5*M_PI/180);
    Canvas->TextOutA(10,10,FloatToStr(v.GetSignedAngleR()*180/M_PI));
    Or.MoveTo(0,0);
    Or.LineTo(v);
    Or.MoveTo(0,0);
    Or.LineTo(v2);
}
//---------------------------------------------------------------------------

