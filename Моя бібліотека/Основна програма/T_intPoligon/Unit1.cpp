//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "T_intPoligon.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    T_intPoligon ip;
    ip.SetN(3);
    ip[0]=TPoint(100,100);
    ip[1]=TPoint(200,200);
    ip[2]=TPoint(200,100);
    Show();
    ip.Draw(Canvas);
    ip.Shift(TPoint(100,100));
    ip.Draw(Canvas);
}
//---------------------------------------------------------------------------
 