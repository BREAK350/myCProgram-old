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
    Or.Scale.Init(4,4);
    Or.Shift.x=50;
    Or.Shift.y=50;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int n=1300;
    for(int x=0;x<100;x++)
    {
        for(int y=0;y<100;y++)
        {
            if(x & y & n)
            {
                Canvas->Brush->Color=clBlack;
            }
            else
            {
                Canvas->Brush->Color=clWhite;
            }
            Or.Pixel(Canvas,x,y);
        }
    }
}
//---------------------------------------------------------------------------
 