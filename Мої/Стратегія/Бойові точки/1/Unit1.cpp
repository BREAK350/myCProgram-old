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
    : TForm(Owner)
{
    bMouseDown=false;
    Or.Up=true;
    Or.Shift.X=0;
    Or.Shift.Y=ClientHeight;
    Or.Scale.Init(40,40);
    Or.Canvas=Canvas;
    randomize();
    CityAttack=-1;
    Game.Init1();
}
//---------------------------------------------------------------------------
void TForm1::GameDraw()
{
    Canvas->Brush->Color=clWhite;
    Canvas->Rectangle(-1,-1,ClientWidth+1,ClientHeight+1);
    Game.Draw(Or);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
    Or.Scale.X--;
    Or.Scale.Y--;
    if(Or.Scale.X<=0)
    {
        Or.Scale.X=1;
    }
    if(Or.Scale.Y<=0)
    {
        Or.Scale.Y=1;
    }
    GameDraw();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseWheelUp(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
    Or.Scale.X++;
    Or.Scale.Y++;
    GameDraw();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    bMouseDown=true;
    pMouseDown.x=X;
    pMouseDown.y=Y;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    Curr.x=Or.UnOrientX(X);
    Curr.y=Or.UnOrientY(Y);
    if(bMouseDown)
    {
        Or.Shift.X=Or.Shift.X+X-pMouseDown.x;
        Or.Shift.Y=Or.Shift.Y+Y-pMouseDown.y;
        pMouseDown.x=X;
        pMouseDown.y=Y;
        GameDraw();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
    T_CityInf3 ci;
    GameDraw();
    Game.ChooseCity(Curr);
    ci=Game.GetCityInf3();
    Label10->Caption=IntToStr(ci.CityNumber);
    Label11->Caption=IntToStr(ci.Location.x)+';'+IntToStr(ci.Location.y);
    Label12->Caption=IntToStr(ci.PlayerNumber);
    Edit1->Text=IntToStr(ci.CountArmy[0]);
    Edit2->Text=IntToStr(ci.CountArmy[1]);
    Edit3->Text=IntToStr(ci.CountArmy[2]);    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    bMouseDown=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if(CityAttack==-1)
    {
        CityAttack=Game.isAttack();
    }
    else
    {
        T_CityInf3 ca;
        ca.CountArmy[0]=StrToInt(Edit1->Text);
        ca.CountArmy[1]=StrToInt(Edit2->Text);
        ca.CountArmy[2]=StrToInt(Edit3->Text);
        Game.Attack(ca.CountArmy,CityAttack);
        CityAttack=-1;
    }
}
//---------------------------------------------------------------------------

