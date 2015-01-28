//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Data.h"
//---------------------------------------------------------------------------
const String Months[12] = {"січень","лютий","березень","квітень","травень","червень",
                     "липень","серпень","вересень","жовтень","листопад","грудень",};
//---------------------------------------------------------------------------
class TFormNaturalGas : public TForm
{
__published:	// IDE-managed Components
    TLabel *LabelPersonalAccount;
    TEdit *EditPersonalAccount;
    TLabel *LabelBy;
    TLabel *LabelMonth;
    TLabel *LabelYear;
    TEdit *EditNameAndAddress;
    TLabel *LabelNameAndAddress;
    TLabel *LabelGasDate;
    TLabel *LabelTerminal;
    TEdit *EditTerminal;
    TLabel *LabelInitial;
    TLabel *LabelDifference;
    TLabel *LabelPrice;
    TLabel *LabelSum;
    TEdit *EditInitial;
    TEdit *EditDifference;
    TEdit *EditPrice;
    TEdit *EditSum;
    TButton *ButtonOK;
    TEdit *EditMonth;
    TEdit *EditYear;
    void __fastcall ButtonOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    TbData *bData;
    int size;
    __fastcall TFormNaturalGas(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormNaturalGas *FormNaturalGas;
//---------------------------------------------------------------------------
#endif
