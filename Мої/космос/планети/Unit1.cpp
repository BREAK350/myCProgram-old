//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TForm1 *Form1;
TRect r(0,0,1,1);
TRect space(0,0,1300,700);
T_Space Space(300,2,5,space);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
	//Canvas->Brush->Style=bsClear;
	bmp = new Graphics::TBitmap();
	bmp->Width = space.Width();
	bmp->Height = space.Height();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	bmp->Canvas->Rectangle(0, 0, space.Width(), space.Height());
	Space.Interection();
	Space.Move();
	Space.Draw(bmp->Canvas, true);

	Canvas->Draw(0, 0, bmp);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Space.nextPlanet();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Space.prevPlanet();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
	Space.setScale(TrackBar1->Position);
	Edit1->Text = TrackBar1->Position;
}
//---------------------------------------------------------------------------

