//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x=10,y=10,i=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Image1->Transparent=true;
    Image1->Canvas->Lock();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Image1->Refresh();
    Image1->Canvas->Rectangle(x,y,x+200,y+200);
    x+=10;
    y+=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Image1->Left+=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    ImageList1->Draw(Canvas,10,10,i,true);
    i++;
    if(i>=5)
    {
        i=0;
    }
}
//---------------------------------------------------------------------------
