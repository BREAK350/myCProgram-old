//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Unit1.h"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TCheck : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TEdit *Expression;
    TBitBtn *BitBtn1;
    TCheckBox *StepByStep;
    TLabel *Result;
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall ExpressionChange(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall StepByStepClick(TObject *Sender);
private:	// User declarations
    int CurrQ,CurrS,Action;
public:		// User declarations
    __fastcall TCheck(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCheck *Check;
//---------------------------------------------------------------------------
#endif
