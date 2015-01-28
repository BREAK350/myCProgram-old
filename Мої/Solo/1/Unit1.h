//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <fstream.h>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include "CGAUGES.h"
#include "Unit2.h"
#include "Languages.h"
#include <Buttons.hpp>
#include "Unit3.h"
//---------------------------------------------------------------------------
enum TLanguage
{                      
    Ukrainian,English
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class TMain : public TForm
{
__published:	// IDE-managed Components
    TMemo *Field;
    TMainMenu *MainMenu1;
    TMenuItem *N1;
    TMenuItem *N2;
    TOpenDialog *OpenDialog1;
    TMenuItem *NLanguage;
    TMenuItem *NLanguageEnglish;
    TMenuItem *NLanguageUkrainian;
    TLabel *Message;
    TTimer *Timer1;
    TCGauge *Progress;
    TMenuItem *N6;
    TMenuItem *N7;
    TMenuItem *N8;
    TMenuItem *N9;
    TMenuItem *N10;
    TPanel *Options;
    TGroupBox *LeftHand;
    TGroupBox *RightHand;
    TBitBtn *OptionsOK;
    TCheckBox *Finger0;
    TCheckBox *Finger1;
    TCheckBox *Finger2;
    TCheckBox *Finger3;
    TCheckBox *Finger4;
    TCheckBox *Finger5;
    TCheckBox *Finger6;
    TCheckBox *Finger7;
    TCheckBox *Finger8;
    TCheckBox *Finger9;
    TCheckBox *CheckBoxBigSymbol;
    TGroupBox *GroupBoxAdditionally;
    TCheckBox *CheckBoxDigit;
    TMenuItem *N3;
    TMenuItem *N4;
    void __fastcall FieldKeyPress(TObject *Sender, char &Key);
    void __fastcall N2Click(TObject *Sender);
    void __fastcall NLanguageEnglishClick(TObject *Sender);
    void __fastcall NLanguageUkrainianClick(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall N7Click(TObject *Sender);
    void __fastcall N6Click(TObject *Sender);
    void __fastcall N8Click(TObject *Sender);
    void __fastcall N9Click(TObject *Sender);
    void __fastcall N10Click(TObject *Sender);
    void __fastcall OptionsOKClick(TObject *Sender);
    void __fastcall FieldClick(TObject *Sender);
    void __fastcall FormKeyPress(TObject *Sender, char &Key);
    void __fastcall N3Click(TObject *Sender);
    void __fastcall N4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    char ***Symbols;

    int FingerChecked[11]; // перший елемент - довжина
    int KeyStatistic[33];
    bool Start,isEndllesText;
    int ErrorKey;
    String lessons;
    TLessons *Lessons;
    TLanguage Language;
    void loadFromFile(const wchar_t *fileName);
    void Again();
    String GenerateWord()const;
    String GenerateWordForEndllesText()const;
    String GenerateWord(const char Key[2][33])const;
    String GenerateWordForEndllesText(const char Key[2][33])const;
    void GetCheckedFinger();
    int GetActiveKey()const;
    int GetActiveKey(const char Key[2][33])const;
    int GetIndexKey(const char Key[2][33],const char &s);
    char GetActiveSymbol()const;
    void ReductionStatistic();
    __fastcall TMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMain *Main;
//---------------------------------------------------------------------------
#endif

