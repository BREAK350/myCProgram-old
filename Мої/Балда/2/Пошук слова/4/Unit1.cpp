//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner),Centre(500,200)
{
    S=40;
    Show();
    List.Draw(Canvas,Centre,S);
    p[0].List=&List;
    p[0].D=&D[0];
    p[1].List=&List;
    p[1].D=&D[1];
    p[0].Name="ִ³לא";
    p[1].Name="־כוד";
    kword=0;
    player=0;
    NPlayer=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
    bT_Stack bs;
    char *w;
    int i;
    w=D[player][i=p[player].GetWord(bs)];
    if(w)
    {
        p[0].AddWord(w);
        p[1].AddWord(w);
        kword++;
        Memo1->Lines->Add(IntToStr(kword)+")"+AnsiString("[")+p[player].Name.c_str()+"] "+w);
        delete w;
    }
    Canvas->Rectangle(-1,-1,2000,1000);
    bs.Draw(Canvas,Centre,S);
    List.Draw(Canvas,Centre,S);
    //List.ShowLink(Canvas,Centre,S);
    BS.Again();
    player++;
    if(player>=NPlayer)
    {
        player=0;
    }
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
    List.Again(D[player]);
    Canvas->Rectangle(-1,-1,2000,1000);
    List.Draw(Canvas,Centre,S);
    kword=0;
    Memo1->Clear();
    BS.Again();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
    OpenDialog1->Execute();
    D[player].LoadFromFile(OpenDialog1->FileName.c_str());
    List.CreateFirstWord(D[player].GetRandomWord());
    List.Draw(Canvas,Centre,S);
    player++;
    if(player>=NPlayer)
    {
        player=0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    C.x=floor((float)(X-Centre.x+S/3.0)/S);
    C.y=floor((float)(Y-Centre.y+S/3.0)/S);
    //Canvas->TextOutA(200,10,IntToStr(C.x)+":"+IntToStr(C.y)+"  ");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
    BS.Write(C);
    BS.Draw(Canvas,Centre,S);
    List.Draw(Canvas,Centre,S);
}
//---------------------------------------------------------------------------

