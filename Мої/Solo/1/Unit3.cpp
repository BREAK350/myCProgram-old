//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit3.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
TKeyBoard *KeyBoard;
//---------------------------------------------------------------------------
__fastcall TKeyBoard::TKeyBoard(TComponent* Owner)
    : TForm(Owner)
{
    bmp=new Graphics::TBitmap;
    bmp->Width=ClientWidth;
    bmp->Height=ClientHeight;
    bmp->Canvas->Font=Canvas->Font;

}
//---------------------------------------------------------------------------
void __fastcall TKeyBoard::FormClose(TObject *Sender, TCloseAction &Action)
{
    Main->N4->Caption="Без клавіатури";
    delete bmpKey;
    delete bmpSpace;
}
//---------------------------------------------------------------------------
void __fastcall TKeyBoard::FormPaint(TObject *Sender)
{
    switch(Main->Language)
    {
        case English:
            WriteSymbols(EnglishSymbol);
            break;
        case Ukrainian:
            WriteSymbols(UkrainianSymbol);
            break;
    }
    Canvas->Draw(0,0,bmp);
}
//---------------------------------------------------------------------------
void TKeyBoard::WriteSymbols(const char Symbols[2][33])
{
    int ak=Main->GetActiveKey(),x,y;
    bmp->Canvas->Brush->Color=clGreen;
    bmp->Canvas->Rectangle(ClientRect);
    for(int i=0;i<33;i++)
    {
        if(i==ak)
        {
            bmp->Canvas->Brush->Color=clYellow;
        }
        else
        {
            bmp->Canvas->Brush->Color=clWhite;
            if(i==Main->ErrorKey)
            {
                bmp->Canvas->Brush->Color=clRed;
            }
        }
        bmp->Canvas->Draw(KeyCoordinate[i].x,KeyCoordinate[i].y,bmpKey);
        x=KeyCoordinate[i].x+(bmpKey->Width-Canvas->TextWidth(Symbols[0][i]))/2.0;
        y=KeyCoordinate[i].y+(bmpKey->Height-Canvas->TextHeight(Symbols[0][i]))/2.0;
        bmp->Canvas->TextOutA(x,y,Symbols[0][i]);
    }
    x=204+(bmpSpace->Width-Canvas->TextWidth("пробіл"))/2.0;
    y=205+(bmpSpace->Height-Canvas->TextHeight("пробіл"))/2.0;
    bmp->Canvas->Draw(204,205,bmpSpace);
    bmp->Canvas->TextOutA(x,y,"пробіл");
    if(ak==-1 && Main->GetActiveSymbol()==' ')
    {
        bmp->Canvas->Brush->Color=clYellow;
        bmp->Canvas->TextOutA(x,y,"пробіл");
    }
}
//---------------------------------------------------------------------------
void __fastcall TKeyBoard::FormActivate(TObject *Sender)
{
    bmpKey=new Graphics::TBitmap();
    bmpKey->LoadFromFile("Кнопки\\Кнопка.bmp");
    bmpSpace=new Graphics::TBitmap();
    bmpSpace->LoadFromFile("Кнопки\\Пробіл.bmp");
}
//---------------------------------------------------------------------------

