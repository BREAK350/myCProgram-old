//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDictionary *Dictionary;
//---------------------------------------------------------------------------
__fastcall TDictionary::TDictionary(TComponent* Owner)
    : TForm(Owner)
{
    Again=true;
    Modified=false;
    TypeShow=HALF;
}
//---------------------------------------------------------------------------
TbWord TDictionary::GetWord()
{
    TbWord Word;
    Word.Eng=English->Text.c_str();
    Word.Ukr=Ukranian->Text.c_str();
    return Word;
}
//---------------------------------------------------------------------------
void TDictionary::SetWord(TbWord &Word)
{
    ClearWord();
    EditWord(Word,TypeShow,!RadioButtonEng->Checked);
    English->Text=Word.Eng.ToChar();
    Ukranian->Text=Word.Ukr.ToChar();
}
//---------------------------------------------------------------------------
void TDictionary::ClearWord()
{
    English->Clear();
    Ukranian->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TDictionary::SpeedButtonAddClick(TObject *Sender)
{
    Modified=true;
    TbWord Word=GetWord();
    Dict.Add(Word);
    ClearWord();
    ShowMess("Слово додано.");
}
//---------------------------------------------------------------------------
void __fastcall TDictionary::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    if(Modified)
    {
        Dict.SaveToFile(FNAME);
    }
}
//---------------------------------------------------------------------------
void __fastcall TDictionary::SpeedButtonSearchClick(TObject *Sender)
{
    if(Again)
    {
        SearchingWord=GetWord();
    }
    if(CorrectSearchWord())
    {
        if(RadioButtonEng->Checked)
        {
            Dict.SearchEng(SearchingWord.Eng,Again);
        }
        else
        {
            Dict.SearchUkr(SearchingWord.Ukr,Again);
        }
        if(Again)
        {
            Again=false;
        }
        if(Dict.GetCurr(FindWord))
        {
            SetWord(FindWord);
        }
        else
        {
            ShowMess("Слово не знайдено.");
        }
    }
    else
    {
        ShowMess("Введіть слово для пошуку...");
    }
}
//---------------------------------------------------------------------------
bool TDictionary::CorrectSearchWord()
{
    return (RadioButtonEng->Checked && SearchingWord.Eng.Length()) ||
           (RadioButtonUkr->Checked && SearchingWord.Ukr.Length());
}
//---------------------------------------------------------------------------
void __fastcall TDictionary::SpeedButtonEditClick(TObject *Sender)
{
    Modified=true;
    Dict.EditCurr(GetWord());
    ShowMess("Слово редаговано.");
}
//---------------------------------------------------------------------------
void __fastcall TDictionary::SpeedButtonDeleteClick(TObject *Sender)
{
    Modified=true;
    if(Dict.DeleteCurr())
    {
        ShowMess("Слово видалене.");
        ClearWord();
    }
    else
    {
        ShowMess("Помилка при видалені.");
    }
}
//---------------------------------------------------------------------------
void __fastcall TDictionary::EnglishClick(TObject *Sender)
{
    ActivateKeyboardLayout(LoadKeyboardLayout("00000409",0),0);
    RadioButtonEng->Checked=true;
    ShowMess("Введіть англійське слово...");
}
//---------------------------------------------------------------------------
void __fastcall TDictionary::EnglishKeyPress(TObject *Sender, char &Key)
{
    Again=true;
}
//---------------------------------------------------------------------------
void __fastcall TDictionary::UkranianClick(TObject *Sender)
{
    ActivateKeyboardLayout(LoadKeyboardLayout("00000422",0),0);
    RadioButtonUkr->Checked=true;
    ShowMess("Введіть українське слово...");
}
//---------------------------------------------------------------------------
void __fastcall TDictionary::UkranianKeyPress(TObject *Sender, char &Key)
{
    Again=true;
}
//---------------------------------------------------------------------------
void TDictionary::ShowMess(const char *mess)
{
    Mess->Text=mess;    
}
//---------------------------------------------------------------------------
void __fastcall TDictionary::FormClick(TObject *Sender)
{
    AnsiString mess("Всього слів: ");
    mess+=IntToStr(Dict.GetCount());
    ShowMess(mess.c_str());
}
//---------------------------------------------------------------------------
void TDictionary::EditWord(TbWord &Word,const int &Type,const bool &EditEng)
{
    if(EditEng)
    {
        EditWord(Word.Eng,Type);
    }
    else
    {
        EditWord(Word.Ukr,Type);
    }
}
//---------------------------------------------------------------------------
void TDictionary::EditWord(TbBaseString &Word,const int &Type)
{
    if(Word.ToChar())
    {
        if(Type==EMPTY)
        {
            Word="";
        }
        else
        {
            if(Type==HALF)
            {
                char *buf=strdup(Word.ToChar());
                int i=0;
                while(buf[i])
                {
                    if(i%2==1)
                    {
                        buf[i]='_';
                    }
                    i++;
                }
                Word=buf;
                delete[] buf;
            }
        }
    }
}
//---------------------------------------------------------------------------

