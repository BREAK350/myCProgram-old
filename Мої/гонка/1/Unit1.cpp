//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
dv2d dv,g;
l2d l[2];
WORD Key;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    dv.init(100,100,1,0);
    dv.center.initxy(300,300);
    g.center=dv.center;
    g.init(0,0,1,-90);
    l[0].center=dv.center;
    l[1].center=dv.center;
    l[0].init(-200,200,200,200);
    l[1].init(200,200,200,0);
    Show();
    l[0].drawcanvas(Canvas);
    l[1].drawcanvas(Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    dv.drawcanvas(Canvas);
    dv.rightmove(l,2);
    //dv+g;
    if(Key==38)
    {
        dv.d++;
    }
    if(Key==37)
    {
        dv.alpha+=10;
    }
    if(Key==39)
    {
        dv.alpha-=10;
    }
    if(Key==40)
    {
        dv.d--;
    }
    Key=-1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    ::Key=Key;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyPress(TObject *Sender, char &Key)
{
    ::Key=Key;
}
//---------------------------------------------------------------------------

