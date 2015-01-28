//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormSE.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
	double a = EditA->Text.ToDouble();
	double b = EditB->Text.ToDouble();
	double c = EditC->Text.ToDouble();
	TbSquareEquation *problem = new TbSquareEquation(a, b, c);
	Form2->setProblem(problem);
	Form2->Show();
}
//---------------------------------------------------------------------------
