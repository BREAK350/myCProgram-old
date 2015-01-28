//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "TWallH.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TElement *a[2];
TRect r;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    r.Left=100;
    r.Top=100;
    r.Right=200;
    r.Bottom=200;
    a[0]=new TWall;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    a[0]->DrawNo(Form1->Canvas,r);
}
//---------------------------------------------------------------------------
