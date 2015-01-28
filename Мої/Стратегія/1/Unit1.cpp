//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "T_Map.h"
//---------------------------------------------------------------------------
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    T_Map Map;
    T_City *City;
    T_Commander *C;
    Price.Commander;
    //C=new T_Commander;
}
//---------------------------------------------------------------------------
 