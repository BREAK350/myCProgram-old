//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
char *fname[]={"1","2","3","4"};
Graphics::TBitmap *BMP=new Graphics::TBitmap;
MainInsect mi;
point2D cur;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    BMP->Width=ClientWidth;
    BMP->Height=ClientHeight;
    randomize();
    mi.myinsect.oform.LoadFromFile("2.detail");
    mi.myinsect.loc.InitXY(0,0);
    mi.myinsect.go.InitXY(0,0);
    mi.myinsect.v=2;
    mi.myinsect.oform.S=20;
    mi.CreateListInsect(10,4,fname);
    CreateBMP(100,100);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    mi.MoveAll();
    mi.DrawAll(BMP);
    Canvas->Draw(0,0,BMP);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
    mi.myinsect.go=cur;    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    cur.InitXY(X-BMP->Width/2,-Y+BMP->Height/2);    
}
//---------------------------------------------------------------------------
