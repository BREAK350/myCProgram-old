//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "balda.h"
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
    T_Field F("12314346");
    F.Draw(Canvas,TPoint(100,100),20);    
}
//---------------------------------------------------------------------------
