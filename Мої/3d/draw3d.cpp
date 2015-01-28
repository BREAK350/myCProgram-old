//---------------------------------------------------------------------------
#pragma hdrstop
#include "space.h"
#pragma package(smart_init)
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
for(i=0;i<256;i++)
  for(j=0;j<256;j++)
    {
     Form1->Canvas->Pen->Color=(TColor) RGB(i,j,i);
     Form1->Canvas->MoveTo(i,j);
     Form1->Canvas->LineTo(i+1,j);
    }
}
