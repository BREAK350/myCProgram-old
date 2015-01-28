//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
char w[]="срака";
T_Balda Balda(w);
TPoint Centre(30,30);
int S=50; 
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Show();
    Balda.Draw(Canvas,Centre,S);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    TPoint p;
    int q=0,i=0;
    T_C c;
    T_Stack stack(32);
    q=Balda.SearchWord(w,stack,c,i);
    if(q==1)
    {
        Balda.SetSymbol(c,w[i]);
    }
    Balda.Draw(Canvas,Centre,S);
    Canvas->Brush->Style=bsClear;
    Canvas->Pen->Color=clBlue;
    Canvas->Pen->Width=3;
    while(stack.Read(p))
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

