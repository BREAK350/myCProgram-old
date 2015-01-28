//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner),Centre(240,100),Curr(0)
{
    S=35;
    Show();
    Balda.Draw(Canvas,Centre,S);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
    TColor cl=Canvas->Pen->Color;
    Canvas->Pen->Color=clWhite;
    Canvas->Rectangle(Balda.GetRect(Centre,S));
    Canvas->Pen->Color=cl;
    Form3->Show();
    Memo1->Clear();
    Words.Clear();
}
//---------------------------------------------------------------------------
void TForm1::Draw(T_SWBA &SWBA)
{
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
void __fastcall TForm1::Edit2KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key==13)
    {
        if(Curr->isPeople)
        {
            if(Words.Search(Edit2->Text.c_str())==0)
            {
                T_SWBA SWBA(Edit2->Text.c_str());
                Balda.AddWord(SWBA,FOUR);
                if(SWBA.Q==1)
                {
                    Words.Write(Edit2->Text.c_str());
                    Memo1->Lines->Add(AnsiString("[")+Curr->Name.c_str()+"]: "+Edit2->Text);
                    Balda.Draw(Canvas,Centre,S);
                    Draw(SWBA);
                    Curr->Symbols+=strlen(Edit2->Text.c_str());
                    Curr=Players.GetCurrPlayer();
                }
                else
                {
                    Curr->Symbols--;
                }
            }
            else
            {
                Curr->Symbols--;
            }
        }
        else
        {
            T_SWBA SWBA("");
            Curr->GetWord(SWBA,Words,Balda);
            if(SWBA.Q==1)
            {
                Memo1->Lines->Add(AnsiString("[")+Curr->Name.c_str()+"]: "+SWBA.Word.c_str());
                Balda.Draw(Canvas,Centre,S);
                Draw(SWBA);
                Curr->Symbols+=strlen(SWBA.Word.c_str());
                Curr=Players.GetCurrPlayer();
            }
            else
            {
                ShowMessage("Здаюся");
            }
        }
        Edit2->Text="";
        Label3->Caption=AnsiString("")+Curr->Name.c_str()+" ("+IntToStr(Curr->Symbols)+")";
        ShowPlayers();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
    Balda.Draw(Canvas,Centre,S);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N5Click(TObject *Sender)
{
    SaveDialog1->Execute();
    ofstream ofs(SaveDialog1->FileName.c_str());
    Words.SaveToFile(ofs);
    Players.SaveToFile(ofs);
    Balda.SaveToFile(ofs);
    ofs.close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N6Click(TObject *Sender)
{
    OpenDialog1->Execute();
    ifstream ifs(OpenDialog1->FileName.c_str());
    Words.LoadFromFile(ifs);
    Players.LoadFromFile(ifs);
    Balda.LoadFromFile(ifs);
    ifs.close();
    Curr=Players.GetCurrPlayer();
    Label3->Caption=AnsiString("")+Curr->Name.c_str()+" ("+IntToStr(Curr->Symbols)+")";
    Balda.Draw(Canvas,Centre,S);
    Memo1->Clear();
    Words.GetStarted();
    string buf;
    int i=0,n=Players.GetN();
    T_Player *r=NULL;
    Words.GetCurrWord(buf);
    Memo1->Lines->Add(buf.c_str());
    while(Words.GetCurrWord(buf))
    {
        r=Players.GetPlayer(i);
        Memo1->Lines->Add(AnsiString("[")+r->Name.c_str()+"]: "+buf.c_str());
        i++;
        if(i>=n)
        {
            i=0;
        }
    }
}    //AnsiString("[")+Curr->Name.c_str()+"]: "+Edit2->Text
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if(Curr)
    {
        Curr->Symbols--;
        Curr=Players.GetCurrPlayer();
        Edit2->Text="";
        Label3->Caption=AnsiString("")+Curr->Name.c_str()+" ("+IntToStr(Curr->Symbols)+")";
        ShowPlayers();
    }
}
//---------------------------------------------------------------------------
void TForm1::ShowPlayers()
{
    int i,n=Players.GetN();
    Memo2->Clear();
    T_Player *p;
    for(i=0;i<n;i++)
    {
        p=Players.GetPlayer(i);
        Memo2->Lines->Add(AnsiString("")+p->Name.c_str()+": "+IntToStr(p->Symbols));
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

