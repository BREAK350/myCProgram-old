//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
double h=10*M_PI/180;
TbPeriodicd p(2*M_PI,12),q(2*M_PI);
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	ShowData();
}
//---------------------------------------------------------------------------
void TForm2::ShowData()
{
	q.SetValue(ScrollBar1->Position*h);
	Label3->Caption=q.GetValue();
	Label2->Caption=ScrollBar1->Position;
	Label1->Caption=p.GetSignedDistance(ScrollBar1->Position*h);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	static int i=-10;
	p.GetSignedDistance(3);
	p=i+q;
	Label1->Caption=p.GetValue();
	i--;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ScrollBar1Change(TObject *Sender)
{
	ShowData();
}
//---------------------------------------------------------------------------

