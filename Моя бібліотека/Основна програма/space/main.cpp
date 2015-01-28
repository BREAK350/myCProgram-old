//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
TbSphericalSpace *ss=new TbSphericalSpace(500,0,500);
TbSpaceVector2d v1(ss),v2(ss),v3(ss);
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	v1.Init(400*M_PI/2,0,ss);
	v2.Init(0,0,ss);
	Label1->Caption=500*M_PI/2;
}
//---------------------------------------------------------------------------
void TForm2::Draw()
{
	int r=4,x=400,y=300;
	TPoint p=v1.GetTPoint(ss);
	Label1->Caption=stZ;
	if(cl==clBlack)
	{
		Canvas->Ellipse(p.x-r+x,ClientHeight-(p.y-r+y),p.x+r+x,ClientHeight-(p.y+r+y));
    }
	v1=v1.Add(v2,ss);

	Label2->Caption=v1.GetModule(ss);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	v2.Init(Edit1->Text.ToDouble(),0,ss);
	Draw();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	v2.Init(0,Edit2->Text.ToDouble(),ss);
	Draw();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	v2.Init(Edit1->Text.ToDouble(),Edit2->Text.ToDouble(),ss);
	Draw();
}
//---------------------------------------------------------------------------

