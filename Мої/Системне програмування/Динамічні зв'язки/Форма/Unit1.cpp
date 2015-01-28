//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap *bmp=new Graphics::TBitmap;
//TbMyThread *mt=new TbMyThread(true);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    bmp->Width=1300;
    bmp->Height=700;
    bmp->Canvas->Font=Canvas->Font;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Canvas->Brush->Color=clWhite;

    int Number=0;
    TbUFAd sa(bmp->Canvas);
    sa.Create(Edit1->Text.c_str(),bmp->Canvas,Number);

    //Form3->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    Button2->Caption=String(X)+";"+String(Y);    
}
//---------------------------------------------------------------------------

