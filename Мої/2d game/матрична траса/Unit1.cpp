//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap *BMP=new Graphics::TBitmap;
trasa tr;
int i=10,j=10,cx,cy;
float x,y,s=70;
float vx=0,vy=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    BMP->Width=500;
    BMP->Height=500;
    x=250;
    y=250;
    tr.Create(10,10);
    tr.RandomColor();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
    s++;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
    s--;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    x+=vx;
    y+=vy;
    if(fabs(cx-x)<5 && fabs(cy-y)<5)
    {
        vx=0;
        vy=0;
        return;
    }
    if(vx==0 && vy==0)
    {
        return;
    }
    tr.Draw(x,y,s,BMP);
    Canvas->Draw(0,0,BMP);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    cx=X;
    cy=Y;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
    float d,x,y;
    x=cx-BMP->Width/2;
    y=cy-BMP->Height/2;
    d=sqrt(x*x+y*y);
    if(d==0)
    {
        vx=0;
        vy=0;
        return;
    }
    vx=x/(d*s);
    vy=y/(d*s);
}
//---------------------------------------------------------------------------

