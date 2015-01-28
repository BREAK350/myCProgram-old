//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "T_Question.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    AnswerVisible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AnswerTimerTimer(TObject *Sender)
{
    if(AnswerVisible)
    {
        if(Answer->Left>0)
        {
            Answer->Left=Answer->Left-8;
        }
        else
        {
            AnswerTimer->Enabled=false;
            AnswerVisible=false;
        }
    }
    else
    {
        if(Answer->Left<440)
        {
            Answer->Left=Answer->Left+8;
        }
        else
        {
            AnswerTimer->Enabled=false;
            AnswerVisible=true;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    AnswerTimer->Enabled=true;    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    AnswerTimer->Enabled=true;    
}
//---------------------------------------------------------------------------
