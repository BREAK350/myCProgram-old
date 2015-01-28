//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
// обережно! можна поламати клавіатуру))
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner),Rect(100,100,600,200)
{
    NewGame();
    P1=50;
    Game=true;
    GameType=1;
}
//---------------------------------------------------------------------------
void TForm1::NewGame()
{
    Player1.Level=0;
    Player1.Color=clBlue;
    Player1.Key=68;
    Player1.KeyDown=false;

    Player2.Level=0;
    Player2.Color=clRed;
    Player2.Key=75;
    Player2.KeyDown=false;
}
//---------------------------------------------------------------------------
void TForm1::DrawRect(const int &P1)
{
    Canvas->Brush->Color=Player1.Color;
    Canvas->Rectangle(Rect.Left,Rect.Top,Rect.Width()*P1/100+Rect.Left,Rect.Bottom);
    Canvas->Brush->Color=Player2.Color;
    Canvas->Rectangle(Rect.Left+Rect.Width()*P1/100,Rect.Top,Rect.Right,Rect.Bottom);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Game)
    {
        switch(GameType)
        {
            case 1:
                GameType_1_KeyUp(Key);
                break;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Game)
    {
        switch(GameType)
        {
            case 1:
                GameType_1_KeyDown(Key);
                break;
        }
    }
}
//---------------------------------------------------------------------------
void TForm1::GameType_1_KeyDown(WORD &Key)
{
    if(Key==Player1.Key)
    {
        if(Player1.KeyDown==false)
        {
            Player1.KeyDown=true;
            P1++;
        }
    }
    if(Key==Player2.Key)
    {
        if(Player2.KeyDown==false)
        {
            Player2.KeyDown=true;
            P1--;
        }
    }
    DrawRect(P1);
    if(P1<=0 || P1>=100)
    {
        Game=false;
    }
}
//---------------------------------------------------------------------------
void TForm1::GameType_1_KeyUp(WORD &Key)
{
    if(Key==Player1.Key)
    {
        Player1.KeyDown=false;
    }
    if(Key==Player2.Key)
    {
        Player2.KeyDown=false;
    }
}
//---------------------------------------------------------------------------

