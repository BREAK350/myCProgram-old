//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner),Center(100,100),e(200,150)
{
	Scale=1;
	Label1->Caption=Scale/10.0;
	//Form2->BorderWidth=30;
	//Form2->Scale=5;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled)
{
	int a=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
		  bool &Handled)
{
	if(Scale>1)
	{
		Scale--;
	}
	Label1->Caption=Scale/10.0;
	Draw(MousePos);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
		  bool &Handled)
{
	Scale++;
	Label1->Caption=Scale/10.0;
	Draw(MousePos);
}
//---------------------------------------------------------------------------
void TForm2::Draw(const TPoint &MousePos)
{
	int r=5;
	double sc=Scale/10.0;
	Canvas->Rectangle(ClientRect);
	Canvas->MoveTo(Center.x,Center.y);
	Canvas->LineTo(e.x*sc-Center.x,e.y*sc-Center.y);
	Canvas->Ellipse((e.x)*sc-r-Center.x,
					(e.y)*sc-r-Center.y,
					(e.x)*sc+r-Center.x,
					(e.y)*sc+r-Center.y);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)

{
	Center.x=X;
	Center.y=Y;
}
//---------------------------------------------------------------------------

