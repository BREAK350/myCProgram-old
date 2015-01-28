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
    : TForm(Owner),GC(Timer1)
{
    GC.Or.Canvas=Canvas;
    GC.List.AddLast(new TbText("Test 1",TPoint(100,100),200));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    Form1->Repaint();
    GC.Execute();    
}
//---------------------------------------------------------------------------
