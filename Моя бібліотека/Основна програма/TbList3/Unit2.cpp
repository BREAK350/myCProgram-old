//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Canvas->Brush->Style=bsClear;
    Or.Canvas=Canvas;
    Or.Scale.Init(2,2);
    Or.Up=true;
    Or.Shift=TPoint(ClientWidth/2,ClientHeight/2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    /*for(int i=-7;i<7;i++)
    {
        L.Add(TPoint(i,0),NULL);
        L.Add(TPoint(0,i),NULL);
    }*/
    //while(1)
    {
        int b=10;
        for(int x=-b;x<b;x++)
        {
            for(int y=-b;y<b;y++)
            {
                L.Add(TPoint(x,y),NULL);
            }
        }
        L.Draw(Or);
    }
    L.Delete(TPoint(5,5));
}
//---------------------------------------------------------------------------

