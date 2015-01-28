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
    : TForm(Owner),Game(Canvas)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    Cursor.x=X;
    Cursor.y=Y;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
    Game.onClick(Cursor);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Load1Click(TObject *Sender)
{
    if(OpenDialog1->Execute())
    {
        Game.LoadFromFile(OpenDialog1->FileName.c_str());
    }
}
//---------------------------------------------------------------------------
