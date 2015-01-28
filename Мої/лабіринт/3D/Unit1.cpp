//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Draw3D.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TForm1 *Form1;
Graphics::TBitmap *Map=new Graphics::TBitmap;
TDraw3D d;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Map->Height=350;
    Map->Width=350;
    //
    d.Data[0][0]=0;
    d.Data[0][1]=1;
    d.Data[0][2]=0;
    d.Data[1][0]=0;
    d.Data[1][1]=0;
    d.Data[1][2]=1;
    d.D=3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    d.Draw3DAll(Map);
    Canvas->Draw(10,10,Map);
}
//---------------------------------------------------------------------------
