//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	lastFocus = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	int n = EditN->Text.ToInt();
	int m = EditM->Text.ToInt();
	String variableName = EditVariable->Text;

	StringGridF->ColCount = n;
	StringGridRestrictionLeft->ColCount = n;
	StringGridAdditionalRestriction->ColCount = n;
	StringGridRestrictionLeft->RowCount = m;
	StringGridRestrictionSignedRight->RowCount = m;

	for(int i = 0;i < n; i++)
	{
		String variable = variableName + IntToStr(i + 1);
		StringGridF->Cells[i][0] = variable;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm3::StringGridsClick(TObject *Sender)
{
	lastFocus = (TStringGrid *)Sender;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ButtonsClick(TObject *Sender)
{
	if(lastFocus)
	{
		TButton *button = (TButton *)Sender;
		int row, col;
		if(lastFocus == StringGridRestrictionSignedRight)
		{
			row = lastFocus->Selection.TopLeft.Y;
			col = 0;
		}
		else
		if(lastFocus == StringGridAdditionalRestriction)
		{
			row = 0;
			col = lastFocus->Selection.TopLeft.X;
		}
        lastFocus->Cells[col][row] = button->Caption;
    }
}
//---------------------------------------------------------------------------

