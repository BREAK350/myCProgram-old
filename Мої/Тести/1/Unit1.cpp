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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    /*char *V[]={"зоря","планета","галактика"},
         Q[]="сонце це?",
         CA[]="100";
    float ca;
    T_Question Question(Q,V,CA);
    ca=Question.CheckAnswer("100");
    FILE *f=fopen("1.txt","wt");
    Question.SaveToFile(f);
    fclose(f);*/
    FILE *f;
    T_Question Question;
    f=fopen("1.txt","rt");
    Question.LoadFromFile(f);
}
//---------------------------------------------------------------------------
