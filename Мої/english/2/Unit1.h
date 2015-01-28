//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include "Unit2.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Menu;
    TBitBtn *AddButton;
    TBitBtn *TestButton;
    TPanel *Add;
    TLabel *English;
    TLabel *Ukraine;
    TEdit *EngEdit;
    TEdit *UkrEdit;
    TBitBtn *AddBtn;
    TPanel *Test;
    TLabel *Question;
    TBitBtn *Variant1;
    TBitBtn *Variant2;
    TBitBtn *Variant3;
    TBitBtn *Variant4;
    TBitBtn *Cancel;
    TBitBtn *Back;
    TBitBtn *Next;
    void __fastcall TestButtonClick(TObject *Sender);
    void __fastcall AddButtonClick(TObject *Sender);
    void __fastcall Variant1Click(TObject *Sender);
    void __fastcall Variant2Click(TObject *Sender);
    void __fastcall Variant3Click(TObject *Sender);
    void __fastcall Variant4Click(TObject *Sender);
    void __fastcall BackClick(TObject *Sender);
    void __fastcall NextClick(TObject *Sender);
    void __fastcall AddBtnClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall CancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    Dictionary dictionary;
    void TestShow();
    int correctAnswer;
    bool changes;
    void Result(const int &res);
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
