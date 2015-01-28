//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Draw3D.h"
#include "Create3D.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
vector3 SEE,LOC;
Graphics::TBitmap*BMP=new Graphics::TBitmap;
TModel mod;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    BMP->Height=ClientHeight;
    BMP->Width=ClientWidth;
    mod.LoadFromFile("2.model");
    SEE.Init(45,45,0);
    LOC.Init(0,0,-300);
    mod.S=100;
    mod.Draw3DModel(SEE,LOC,BMP);
    Canvas->Draw(0,0,BMP);
}
//---------------------------------------------------------------------------
void sdrg()
{
    /*******************
    mod.N_line=1;
    mod.N_point=1;
    mod.line=new Line[1];
    mod.col=new TColor[1];
    mod.col[0]=clBlack;
    mod.line[0].l=0;  ***/
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    CreateModel b;
    b.Point[0].Init(1,1,1);
    b.Point[1].Init(1,1,-1);
    b.Point[2].Init(1,-1,1);
    b.Point[3].Init(-1,1,1);
    b.Point[4].Init(-1,-1,1);
    b.Point[5].Init(-1,1,-1);
    b.Point[6].Init(1,-1,-1);
    b.Point[7].Init(-1,-1,-1);
    b.N_point=8;
    b.AddNewLine(0,1,clBlue);
    b.AddNewLine(0,2,clRed);
    b.AddNewLine(0,3,clBlack);
    b.AddNewLine(1,5,clGreen);
    b.AddNewLine(1,6,clYellow);
    b.AddNewLine(2,4,clLime);
    b.AddNewLine(2,6,clOlive);
    b.AddNewLine(3,4,clBlue);
    b.AddNewLine(3,5,clRed);
    b.AddNewLine(4,7,clBlack);
    b.AddNewLine(5,7,clGreen);
    b.AddNewLine(6,7,clYellow);
    b.SaveToFile("2.model");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    mod.LoadFromFile("2.model");
    SEE.Init(45,45,0);
    LOC.Init(0,0,-300);
    mod.S=100;
    mod.Draw3DModel(SEE,LOC,BMP);
    Canvas->Draw(0,0,BMP);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    BMP->Canvas->Rectangle(0,0,BMP->Width,BMP->Height);
    SEE.x++;
    SEE.y++;
    SEE.z++;
    //LOC.x++;
    mod.Draw3DModel(SEE,LOC,BMP);
    Canvas->Draw(0,0,BMP);
}
//---------------------------------------------------------------------------
