//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
    if(i>=0 && i<Form1->Players.GetN())
    {
        T_Player *r;
        r=Form1->Players.GetPlayer(i);
        r->SetName(Edit1->Text.c_str());
        i++;
        Edit1->Text="";
    }
    if(i>=Form1->Players.GetN())
    {
        Close();
        Form1->Curr=Form1->Players.GetCurrPlayer();
        Form1->Label3->Caption=AnsiString("")+Form1->Curr->Name.c_str()+" ("+IntToStr(Form1->Curr->Symbols)+")";
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key==13)
    {
        Button1Click(Sender);
    }
}
//---------------------------------------------------------------------------
