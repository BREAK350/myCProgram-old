//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
TbMatrix_3d m(2, 5, 7,
			  6, 3, 4,
			  5,-2,-3);
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	Show(m);
	T=TbMatrix_3d::GetTranslation(100,100);
	D=TbMatrix_3d::GetDilation(10,10);
	C=D*T;
	TbMatrix_3d bt=TbMatrix_3d::GetBasicTriangle();
	TbArrayPoint2d abt;
	abt=bt*C;
	BT=abt.GetArrayPoint();

	mdown=false;
	ic=0;
	DrawBT();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	ic=0;
}
//---------------------------------------------------------------------------
void TForm2::Show(const TbMatrix_d &m)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
            StringGrid1->Cells[j][i]=FloatToStr(m.GetElement(i,j));
        }
	}
}
//---------------------------------------------------------------------------
void TForm2::DrawBT()
{
	Image1->Canvas->Pen->Style=psSolid;
	Image1->Canvas->Rectangle(Image1->ClientRect);
	Image1->Canvas->Pen->Style=psDot;
	Image1->Canvas->Polygon(BT,2);

	TbArrayPoint2d abt(3,BT);
	TbMatrix_3d toBT;
	toBT=abt;
	Show(TbMatrix_3d::GetMatrixConverting(TbMatrix_3d::GetBasicTriangle(),toBT));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image1Click(TObject *Sender)
{
	BT[ic]=mpos;
	DrawBT();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	mpos.x=X;
	mpos.y=Y;
	if(mdown)
	{
		BT[ic]=mpos;
		DrawBT();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	mdown=true;
	BT[ic]=mpos;
	DrawBT();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	mdown=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	ic=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	ic=2;
}
//---------------------------------------------------------------------------

