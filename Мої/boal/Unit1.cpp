//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
struct TBoal {
 float v,alpha,x,y;
 int r;
             };
int k=0;
int X,Y;
TForm1 *Form1;
CBoal *b=new CBoal;
Graphics::TBitmap*   gBitmap = new Graphics::TBitmap;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 String s;
 Form1->Show();
 b->Radius(10);
 b->v=10;
 X=300;
 Y=300;
 Canvas->MoveTo(0,Y);
 Canvas->LineTo(Form1->Width,Y);
 Canvas->MoveTo(X,0);
 Canvas->LineTo(X,Form1->Height);
 gBitmap->Width=Form1->Width;
 gBitmap->Height=Form1->Height;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
 b->ClearBoal(X,Y,Form1);
 b->alpha+=10;
 b->alpha.CheckAlpha();
 b->v=k;
 b->Move();
 b->DrawBoal(X,Y,Form1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
 k=(random(40)-20);
}
//---------------------------------------------------------------------------
