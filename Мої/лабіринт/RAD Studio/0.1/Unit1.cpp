//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
bool forEach(const int &row, const int &col, int &item)
{
	item++;
	return true;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	TbMatrix<int> m(2, 2);
	m.forEachDo(forEach);
}
//---------------------------------------------------------------------------
