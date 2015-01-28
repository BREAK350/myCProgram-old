//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    T_Track Track;
    T_Object o;
    Track.AddObject(o);
    Track.AddObject(o);
    Track.AddObject(o);
    Track.AddObject(o);
}
//---------------------------------------------------------------------------
 