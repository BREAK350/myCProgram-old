//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int d=0,x,y;
TRect R(100,100,200,200);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Show();
    Canvas->Rectangle(R);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    d=1;
    if(X>R.Left && X<R.Right && Y>R.Top && Y<R.Bottom)
    {
        x=X;
        y=Y;
    }
    else
    {
        x=-1;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    d=0;
    x=-1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    if(d==1)
    {
        if(x>=0)
        {
            TColor cl=Canvas->Pen->Color;
            Canvas->Pen->Color=Canvas->Brush->Color;
            Canvas->Rectangle(R);
            R.Left=R.Left-x+X;
            R.Right=R.Right-x+X;
            R.Top=R.Top-y+Y;
            R.Bottom=R.Bottom-y+Y;
            Canvas->Pen->Color=cl;
            Canvas->Rectangle(R);
            x=X;
            y=Y;
        }
    }
}
//---------------------------------------------------------------------------
