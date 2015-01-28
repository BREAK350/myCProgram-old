//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "func1.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TModel m;
Point2D XY;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    XY.x=0;
    XY.y=Form1->Height;
    m.LoadToFile("Model1.model");
    Form1->Show();
    m.Show(XY);
}
//---------------------------------------------------------------------------
