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
    Scale=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    Cursor.x=X;
    Cursor.y=Y;
    LabelCursor->Caption=IntToStr(Cursor.x)+","+IntToStr(Cursor.y);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
    Stack.Write(T_Vector2d(Cursor.x*Scale,Cursor.y*Scale));
}
//---------------------------------------------------------------------------
 