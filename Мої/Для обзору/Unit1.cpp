//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TbView <int> View(T_Vector2d(1,0),30,1000);
int Link=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    double Angle1=StrToFloat(Edit1->Text),
           Angle2=StrToFloat(Edit2->Text),
           Value=StrToFloat(Edit3->Text),
           Distance=StrToFloat(Edit4->Text);
    View.Add(Angle1,Angle2,Value,Distance,&Link);
    View.Print(Memo1);
}
//---------------------------------------------------------------------------
