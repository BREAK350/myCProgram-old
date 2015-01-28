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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	TPoint p[] = {TPoint(100,100),TPoint(100,300),TPoint(200,200)};
	Canvas->Brush->Style = bsSolid;
	Canvas->Brush->Color = clBlack;
	Canvas->Polygon(p,2);
}
//---------------------------------------------------------------------------

