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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	char *text = Memo1->Text.t_str();
	StringVector sv = readWordsFrom(text);
	TWords w(sv);
	sv = w.toStringVector();
	Memo2->Clear();
	for(int i = 0; i < sv.size(); i++)
	{
    	Memo2->Lines->Add(sv[i]);
    }
}
//---------------------------------------------------------------------------
