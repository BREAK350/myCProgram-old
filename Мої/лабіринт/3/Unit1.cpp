//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "PlayerH.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TPlayer P;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    int x,y;
    P.GetSize(x,y);
    Form1->ClientHeight=y;
    Form1->ClientWidth=x;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	int w, h;
	P.GetSize(w, h);
	Form1->Width = w;
	Form1->Height = h;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
    OpenDialog1->Execute();
    P.LoadFromFile(OpenDialog1->FileName.t_str());
    P.Draw(0,0,Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
    P.LoadFromFileAgain();
    P.Draw(0,0,Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    int u;
    switch(Key)
    {
        case 38:
            u=P.Move(UP);
            break;
        case 39:
            u=P.Move(RIGHT);
            break;
        case 40:
            u=P.Move(DOWN);
            break;
        case 37:
            u=P.Move(LEFT);
            break;
    }
    P.Draw(0,0,Canvas);
    if(u==END)
    {
        Canvas->Pen->Color=clRed;
        Canvas->Brush->Color=clGreen;
        Canvas->TextOutA(150,150,"Ви Виграли!");
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N6Click(TObject *Sender)
{
    OpenDialog1->Execute();
    P.LoadStyle(OpenDialog1->FileName.t_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N7Click(TObject *Sender)
{
    P.DeleteStyle();    
}
//---------------------------------------------------------------------------

