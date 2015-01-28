//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "paint2.h"
#include "paintH.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
FILE *fp;
int n1=0;
int n2=0;
Graphics::TBitmap*   gBitmap = new Graphics::TBitmap;
Graphics::TBitmap*   bmp = new Graphics::TBitmap;
TCanvas* tCanvas = new TCanvas;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 PaintPicture(Form1,"Picture1.ppf",0,0);
 gBitmap->LoadFromFile("1.bmp");
 bmp->Width=ClientWidth;
 bmp->Height=ClientHeight;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 Canvas->Draw(n1,n2,gBitmap);
 n1++;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
 Canvas->Draw(n1,n2,gBitmap);
 n1--;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 Canvas->Draw(n1,n2,gBitmap);
 n2++;       
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
 Canvas->Draw(n1,n2,gBitmap);
 n2--;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
 int i;
 for(i=0;i<100;i++)
  Canvas->Draw(i,i,gBitmap);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
 TRect tRectFrom;
 TRect tRectTo;
 tRectFrom.Left=0;
 tRectFrom.Top=0;
 tRectTo.Left=0;
 tRectTo.Top=0;
 tCanvas->Handle = CreateDC("DISPLAY",NULL,NULL,NULL);
 gBitmap->Width = Screen->Width;
 gBitmap->Height = Screen->Height;
 tRectFrom.Right=Screen->Width;
 tRectFrom.Bottom=Screen->Height;
 tRectTo.Right=Screen->Width;
 tRectTo.Bottom=Screen->Height;
 gBitmap->Canvas->CopyRect(tRectTo,tCanvas,tRectFrom);
 Canvas->Draw(0,0,gBitmap);
 gBitmap->SaveToFile("2.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    bmp->Canvas->Pen->Color=clWhite;
    bmp->Canvas->Rectangle(0,0,bmp->Width,bmp->Height);
    bmp->Canvas->Draw(n1,n2,gBitmap);
    Canvas->Draw(0,0,bmp);
    n1++;
}
//---------------------------------------------------------------------------

