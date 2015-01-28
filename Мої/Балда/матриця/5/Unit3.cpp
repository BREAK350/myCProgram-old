//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit4.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
    Form1->Balda.Again(StrToInt(Edit2->Text),StrToInt(Edit3->Text),Edit1->Text.c_str());
    Form1->Words.Write(Edit1->Text.c_str());
    Form1->Memo1->Lines->Add(Edit1->Text);
    Form1->Canvas->Rectangle(Form1->Balda.GetRect(Form1->Centre,Form1->S));
    Form1->Balda.Draw(Form1->Canvas,Form1->Centre,Form1->S);
    Form1->Players.SetN(StrToInt(Edit4->Text));
    Form4->Show();
    Form4->i=0;
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key==13)
    {
        Button1Click(Sender);
    }
}
//---------------------------------------------------------------------------
