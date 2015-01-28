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
int searchChar(const wchar_t &wc,const UnicodeString &where)
{
	int i=0,n=where.Length();
	while(i<n && where[i+1]!=wc)
	{
		i++;
	}
	if(i>=n)
	{
		i=-1;
	}
	return i;
}
//---------------------------------------------------------------------------
void Decoder(const UnicodeString &TextFrom,const UnicodeString &KeyFrom,
			 UnicodeString &TextTo,const UnicodeString &KeyTo)
{
	int n=TextFrom.Length();
	TextTo.SetLength(n);
	for(int i=0;i<n;i++)
	{
		int index=searchChar(TextFrom[i+1],KeyFrom);
		if(index==-1)
		{
			TextTo[i+1]=TextFrom[i+1];
		}
		else
		{
            TextTo[i+1]=KeyTo[index+1];
        }
    }
}
//---------------------------------------------------------------------------
UnicodeString* TForm1::switchKey(TComboBox *ComboBox)
{
	UnicodeString *Key=NULL;
	switch(ComboBox->ItemIndex)
	{
		case 0: Key=&Eng;break;
		case 1: Key=&Ukr;break;
		case 2: Key=&Rus;break;
	}
	return Key;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo1Change(TObject *Sender)
{
	UnicodeString *KeyFrom=switchKey(ComboBox1),
				  *KeyTo=switchKey(ComboBox2);
	UnicodeString res;
	Decoder(Memo1->Text,*KeyFrom,res,*KeyTo);
	Memo2->Text=res;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo2Change(TObject *Sender)
{
	UnicodeString *KeyFrom=switchKey(ComboBox2),
				  *KeyTo=switchKey(ComboBox1);
	UnicodeString res;
	Decoder(Memo2->Text,*KeyFrom,res,*KeyTo);
	Memo1->Text=res;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
	Memo1Change(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
	Memo2Change(Sender);
}
//---------------------------------------------------------------------------

