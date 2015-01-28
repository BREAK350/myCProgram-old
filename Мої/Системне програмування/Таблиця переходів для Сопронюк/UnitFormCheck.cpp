//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormCheck.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormCheck *FormCheck;
//TComboBox *cmbLanguage=FormRegularExpression->cmbLanguage;
//---------------------------------------------------------------------------
__fastcall TFormCheck::TFormCheck(TComponent* Owner)
    : TForm(Owner)
{
    Action=0;
    CurrQ=CurrS=0;
}
//---------------------------------------------------------------------------
void __fastcall TFormCheck::ExpressionChange(TObject *Sender)
{
	Result->Caption=Label[FormRegularExpression->cmbLanguage->ItemIndex][8];
	BitBtnCheck->Caption=Label[FormRegularExpression->cmbLanguage->ItemIndex][5];
    Action=0;
    CurrQ=CurrS=0;
}
//---------------------------------------------------------------------------
void __fastcall TFormCheck::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    this->Action=0;
    CurrQ=CurrS=0;    
}
//---------------------------------------------------------------------------
void __fastcall TFormCheck::BitBtnCheckClick(TObject *Sender)
{
	Action=0;
	CurrQ=CurrS=0;
	BitBtnCheck->Caption=Label[FormRegularExpression->cmbLanguage->ItemIndex][5];
	Result->Caption=Label[FormRegularExpression->cmbLanguage->ItemIndex][8];
	if(FormRegularExpression->MDFA.isOwn(Expression->Text.t_str()))
	{
		Result->Caption=Label[FormRegularExpression->cmbLanguage->ItemIndex][9];
	}
	else
	{
		Result->Caption=Label[FormRegularExpression->cmbLanguage->ItemIndex][10];
	}
}
//---------------------------------------------------------------------------

