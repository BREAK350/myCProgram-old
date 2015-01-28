//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TDictionary : public TForm
{
__published:	// IDE-managed Components
    TRadioButton *RadioButtonEng;
    TRadioButton *RadioButtonUkr;
    TSpeedButton *SpeedButtonAdd;
    TSpeedButton *SpeedButtonEdit;
    TSpeedButton *SpeedButtonDelete;
    TSpeedButton *SpeedButtonSearch;
    TSpeedButton *SpeedButtonNext;
    TSpeedButton *SpeedButtonSettings;
    TEdit *English;
    TEdit *Ukranian;
    TEdit *Mess;
    void __fastcall SpeedButtonAddClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall SpeedButtonSearchClick(TObject *Sender);
    void __fastcall SpeedButtonEditClick(TObject *Sender);
    void __fastcall SpeedButtonDeleteClick(TObject *Sender);
    void __fastcall EnglishClick(TObject *Sender);
    void __fastcall EnglishKeyPress(TObject *Sender, char &Key);
    void __fastcall UkranianClick(TObject *Sender);
    void __fastcall UkranianKeyPress(TObject *Sender, char &Key);
    void __fastcall FormClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    TbDictionary Dict;
    TbWord GetWord();
    void SetWord(TbWord &Word);
    void ClearWord();
    bool Again,Modified;
    TbWord SearchingWord,FindWord;
    void ShowMess(const char *mess);
    bool CorrectSearchWord();
    void EditWord(TbWord &Word,const int &Type,const bool &EditEng);
    void EditWord(TbBaseString &Word,const int &Type);
    int TypeShow;
    __fastcall TDictionary(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDictionary *Dictionary;
//---------------------------------------------------------------------------
#endif
