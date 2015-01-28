//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <limits.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int n=0,s=10;
T_Game Game;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Game.AmountCity=0;
    Game.AddCity(0,100,100);
    Game.AddCity(0,100,200);
    Game.AddCity(0,200,100);
    Game.AddCity(1,300,100);
    Game.AddCity(1,400,300);
    Game.UnionCity(0,1);
    Game.UnionCity(1,2);
    Game.UnionCity(2,3);
    Game.UnionCity(3,4);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Game.DrawCityLink(Canvas);
    Game.DrawCity(Canvas);
}
//---------------------------------------------------------------------------
