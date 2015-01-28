//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void Drow();
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Form1->Button1->Caption="PDSK";
Form1->Button1->Caption="PDSK";
Drow();
}
//---------------------------------------------------------------------------
void Drow()
{
int i,j,k;
Form1->Canvas->Brush ->Color=(TColor) RGB(255,255,255);
Form1->Canvas->Pen->Color=(TColor) RGB(255,255,255);
Form1-> Canvas->Rectangle(0,0,1000,1000);
Form1-> Canvas->FloodFill(400,200,Form1->Color, fsBorder);
Form1->Canvas->Pen->Color=(TColor) RGB(0,0,0);
Form1->Canvas->Pen->Width=1;
Form1->Canvas->MoveTo(200,200);
Form1->Canvas->LineTo(600,200);
Form1->Canvas->MoveTo(400,0);
Form1->Canvas->LineTo(400,400);
for(i=0;i<1300;i++)
  for(j=0;j<700;j++)
    {
     Form1->Canvas->Pen->Color=(TColor) RGB(i,j,i);
     Form1->Canvas->MoveTo(i,j);
     Form1->Canvas->LineTo(i+1,j);

    }
}
//---------------------------------------------------------------------------
