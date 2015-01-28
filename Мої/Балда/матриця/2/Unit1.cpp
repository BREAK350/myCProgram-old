//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
char w[]="באכהא";
T_Balda Balda(w);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner),Centre(30,30)
{
    S=30;
    Show();
    Balda.Draw(Canvas,Centre,S);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    T_SWBA SWBA(Edit2->Text.c_str());
    Balda.AddWord(SWBA,FOUR);
    Balda.Draw(Canvas,Centre,S);
    
    Canvas->Brush->Style=bsClear;
    Canvas->Pen->Color=clBlue;
    Canvas->Pen->Width=3;
    TPoint p;
    while(SWBA.Stack.Read(p))
    {
        Canvas->Rectangle(p.y*S+Centre.x,p.x*S+Centre.y,(p.y+1)*S+Centre.x,(p.x+1)*S+Centre.y);
    }
    Canvas->Brush->Style=bsSolid;
    Canvas->Pen->Color=clBlack;
    Canvas->Pen->Width=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
    Panel1->Visible=true;
    Edit1->Text=IntToStr(Canvas->Font->Size);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Canvas->Font->Size=StrToInt(Edit1->Text);
    Panel1->Visible=false;
}
//---------------------------------------------------------------------------

