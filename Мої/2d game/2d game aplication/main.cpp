//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "main.h"
#include "DrawFunction.h"
#include "SaveLoad.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TTrack Track;
TElementObject ElementObject;

TPicture2d Picture;
FILE *f;
char *name="Picture1";
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 Form1->Color=(TColor)RGB(255,255,255);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
 Draw2DElementObject(ElementObject);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
// SavePicture(Picture,f,name);
 LoadPicture(Picture,f,name);
 Draw2DPicture(100,100,Picture);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 Form1->Canvas->Brush->Color=(TColor)RGB(255,255,255);
 Form1->Canvas->Pen->Color=(TColor)RGB(255,255,255);
 Form1->Canvas->Rectangle(0,0,1000,1000);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
 exit(1);
}
//---------------------------------------------------------------------------

