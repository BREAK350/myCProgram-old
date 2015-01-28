//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "T_Trajectory.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
double t=0,s=1,v=0.1;
TPoint Shift(0,0);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    tr.SetAmount(3);
    tr.SetEpsilon(0.01);
    tr.SetLength(0.05);
    //tr[0]=new T_Segment(0,0,4,0);
    tr[0]=new T_Arc(2,0,2,M_PI,0,1);
    //tr[1]=new T_Arc(2,0,2,0,M_PI,1);
    tr[1]=new T_Segment(4,0,0,4);
    //tr[2]=new T_Segment(0,4,0,0);
    tr[2]=new T_HermiteCurve(T_Vector2d(0,4),T_Vector2d(0,0),
                             T_Vector2d(-15,15),T_Vector2d(0,10));
    tr.SaveToFile("test.txt");

    tr.LoadFromFile("test.txt");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    T_Vector2d p;
    //Canvas->Rectangle(-1,-1,ClientWidth+1,ClientHeight+1);
    tr.NextPoint_Right(t,p);
    t=tr.Get_t();
    Canvas->Ellipse(p.X*s-5+Shift.x,p.Y*s-5+Shift.y,p.X*s+5+Shift.x,p.Y*s+5+Shift.y);
    Label1->Caption=FloatToStr(t);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Load1Click(TObject *Sender)
{
    if(OpenDialog1->Execute())
    {
        tr.LoadFromFile(OpenDialog1->FileName.c_str());
        tr.SetLength(1);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    T_Curve *c=new T_Arc;
    T_Arc *s=dynamic_cast <T_Arc*> (c);
    //s=(T_Segment*)c;
    s->c.Length();
}
//---------------------------------------------------------------------------

