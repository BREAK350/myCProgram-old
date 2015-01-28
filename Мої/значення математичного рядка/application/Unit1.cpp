//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Value.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
/* TData save; */
 float X,A;
 char a[300];
 char x[100];
 int preciseness=5;
 int scale=20;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 Edit3->ReadOnly=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
 Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
 strcpy(a,(Edit1->Text).c_str());
 strcpy(x,(Edit2->Text).c_str());
 X=Value(x,0);
 A=Value(a,X);
 Edit3->Text="f("+FloatToStrF(X,ffGeneral,3,2)+")="+FloatToStrF(A,ffGeneral,preciseness,2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 int i;
 strcpy(a,(Edit1->Text).c_str());
 Form3->Show();
 Form3->Canvas->MoveTo(Form3->ClientWidth/2,0);
 Form3->Canvas->LineTo(Form3->ClientWidth/2,Form3->ClientHeight);
 Form3->Canvas->MoveTo(0,Form3->ClientHeight/2);
 Form3->Canvas->LineTo(Form3->ClientWidth,Form3->ClientHeight/2);
 Form3->Canvas->MoveTo(0,Form3->ClientHeight/2-Value(a,-Form3->ClientWidth/2));
 BuildGraph(a,scale);
}
//---------------------------------------------------------------------------
/*void StandartData()
{
 save.preciseness=5;
 save.scale=20;
 save.clForm1=clHighlight;
 save.clForm3=clWhite;
}

void Assign()
{
 Form1->Color=save.clForm1;
 Form3->Color=save.clForm3;
}*/
