//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
#include "TbDFA.h"
#include "Unit2.h"
#include "Unit3.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormRegularExpression : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TEdit *RegularExp;
    TStringGrid *Table;
    TBitBtn *BitBtn1;
    TRadioButton *Undetermined;
    TRadioButton *Determined;
    TRadioButton *Minimized;
    TBitBtn *BitBtnCheck;
    TBitBtn *BitBtn3;
    TBitBtn *BitBtn4;
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall RegularExpChange(TObject *Sender);
    void __fastcall UndeterminedClick(TObject *Sender);
    void __fastcall DeterminedClick(TObject *Sender);
    void __fastcall MinimizedClick(TObject *Sender);
    void __fastcall BitBtnCheckClick(TObject *Sender);
    void __fastcall BitBtn3Click(TObject *Sender);
    void __fastcall BitBtn4Click(TObject *Sender);
private:	// User declarations
    bool RegChanges;
public:		// User declarations
    TbUFA UFA;
    TbDFA DFA,MDFA;
    void ShowUFA();
    void ShowDFA(const TbDFA &DFA);
    void ShowMDFA();
    __fastcall TFormRegularExpression(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRegularExpression *FormRegularExpression;
//---------------------------------------------------------------------------
#endif
