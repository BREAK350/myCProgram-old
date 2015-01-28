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
    W.SetSize(64);
    Save=1;
    Check=1;
    fname->Caption="Без назви.txt";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key==13)
    {
        if(Check)
        {
            W.Add(Edit2->Text.c_str());
            Edit2->Text=Edit1->Text;
        }
        else
        {
            W.Add(Edit1->Text.c_str());
        }
        Edit1->Text="";
        Save=0;
        Label3->Caption=StrToInt(W.GetN());
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
    OpenDialog1->Execute();
    fname->Caption=OpenDialog1->FileName;
    W.LoadFromFile(fname->Caption.c_str());
    Label3->Caption=StrToInt(W.GetN());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
    SaveDialog1->Execute();
    fname->Caption=SaveDialog1->FileName;
    W.SaveToFile(fname->Caption.c_str());
    Save=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N5Click(TObject *Sender)
{
    if(Save==0)
    {
        ShowMessage("Зміни не були збережені! натисніть знову 'вихід', щоб вийти без збереження");
        Save=1;
    }
    else
    {
        Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
    W.SaveToFile(fname->Caption.c_str());
    Save=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N7Click(TObject *Sender)
{
    Check=1-Check;
    //Перевірка слів: вкл викл
    if(Check)
    {
        N7->Caption="Перевірка слів: вкл";
    }
    else
    {
        N7->Caption="Перевірка слів: викл";
    }
}
//---------------------------------------------------------------------------

