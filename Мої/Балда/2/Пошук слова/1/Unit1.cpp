//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
T_Dictionary D("1.txt");
T_List List("філософія"),Border;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    List.Draw(Canvas,TPoint(100,200),40);
    //Border.Draw(Canvas,TPoint(100,100),20);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    int i=0;
    T_Data Data(' ',TPoint(0,0));
    Data=List.SearchMaxWord(D,i);
    Canvas->Rectangle(0,0,200,50);
    Canvas->TextOutA(10,10,D[i]);
    if(Data.S!='+')
    {
        List.Add(Data);
    }
    List.Draw(Canvas,TPoint(100,200),40);
}
//---------------------------------------------------------------------------
