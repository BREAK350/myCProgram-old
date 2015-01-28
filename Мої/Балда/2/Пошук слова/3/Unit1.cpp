//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
T_Dictionary D;
bT_List List(D);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner),Centre(400,200)
{
    S=40;
    Show();
    List.Draw(Canvas,Centre,S);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
    int i=0;
    bT_ListItem::T_Data Data;
    bT_Stack bs;
    Data=List.SearchMaxWord(D,i,bs);
    Panel2->Caption=D[i];
    if(Data.S)
    {
        List.Add(Data,i,D);
    }
    Canvas->Rectangle(-1,-1,2000,1000);
    bs.Draw(Canvas,Centre,S);
    List.Draw(Canvas,Centre,S);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Centre.y-=S;
    Canvas->Rectangle(-1,-1,2000,1000);
    List.Draw(Canvas,Centre,S);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    Centre.y+=S;
    Canvas->Rectangle(-1,-1,2000,1000);
    List.Draw(Canvas,Centre,S);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
    Centre.x+=S;
    Canvas->Rectangle(-1,-1,2000,1000);
    List.Draw(Canvas,Centre,S);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
    Centre.x-=S;
    Canvas->Rectangle(-1,-1,2000,1000);
    List.Draw(Canvas,Centre,S);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    List.Again(D);
    Canvas->Rectangle(-1,-1,2000,1000);
    List.Draw(Canvas,Centre,S);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
    OpenDialog1->Execute();
    D.LoadFromFile(OpenDialog1->FileName.c_str());
    List.CreateFirstWord(D.GetRandomWord());
    List.Draw(Canvas,Centre,S);
}
//---------------------------------------------------------------------------

