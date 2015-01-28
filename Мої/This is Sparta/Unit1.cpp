//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
double x=0,xh=30*M_PI/180,t=0,th=5*M_PI/180;
double IH=558,IW=462;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    ClientHeight=IH*((cos(x)+1)/2.0*0.3+0.7);
    ClientWidth=IW*((cos(x)+1)/2.0*0.3+0.7);
    TPoint ScreenCenter(Screen->Width/2.0,Screen->Height/2.0);
    int a=(Screen->Width-Width)/2.0;
    int b=(Screen->Height-Height)/2.0;
    Left=a*cos(t)-Width/2+ScreenCenter.x;
    Top=b*sin(t)-Height/2+ScreenCenter.y;
    x+=xh;
    t-=th;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    PROCESS_INFORMATION pi;
    STARTUPINFO si;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb=sizeof(STARTUPINFO);
    CreateProcess(NULL,"This is Sparta.exe",NULL,NULL,0,0,NULL,NULL,&si,&pi);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1Click(TObject *Sender)
{
    PROCESS_INFORMATION pi;
    STARTUPINFO si;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb=sizeof(STARTUPINFO);
    CreateProcess(NULL,"This is Sparta.exe",NULL,NULL,0,0,NULL,NULL,&si,&pi);
}
//---------------------------------------------------------------------------

