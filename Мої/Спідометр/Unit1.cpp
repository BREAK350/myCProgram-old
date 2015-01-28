//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "myclasses.cpp"
#include "Unit1.h"
#include "Unit2.h"
#include <time.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap *back;//Задний буффер
Graphics::TBitmap *arrow;//Задний буффер
Graphics::TBitmap *speed;
float angle;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    back=new Graphics::TBitmap();
    speed=new Graphics::TBitmap();
    arrow=new Graphics::TBitmap();
    back->LoadFromFile("спідометр1.bmp");
    speed->LoadFromFile("спідометр1.bmp");
    arrow->LoadFromFile("Стрілка 1.bmp");
    angle=10;
    back->Canvas->Brush->Color=clBlack;
    Width=speed->Width;
    Height=speed->Height;
    Left=Screen->Width-speed->Width;
    Top=Screen->Height-speed->Height;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    time_t t;
    time(&t);
    tm *ts;
    ts=localtime(&t);
    angle=(360.0-211.0)*ts->tm_sec/60.0+211.0;
    back->Canvas->Draw(0,0,speed);
    RotateDC(back->Canvas->Handle,angle);
    SetViewportOrgEx(back->Canvas->Handle,218,211,NULL);
    back->Canvas->Draw(-21,-145,arrow);
    SetViewportOrgEx(back->Canvas->Handle,0,0,NULL);
    RotateDC(back->Canvas->Handle,0);
    Form1->Canvas->Draw(0,0,back);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
    Form2->Show();
}
//---------------------------------------------------------------------------

