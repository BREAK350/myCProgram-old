//---------------------------------------------------------------------------

#include <vcl.h>
#include "myclasses.cpp"
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Graphics::TBitmap*back;//Задний буффер
Graphics::TBitmap*bug;//Задний буффер
float X,Y;
float angle;
float speed=3;
float RotSpeed=3;
const float M_RAD_CONV=M_PI/180.0;       //Для преобразований градусов и радианов
bool IsRightDown;
bool IsLeftDown;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
     : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
back=new Graphics::TBitmap();
back->Width=Form1->Width;
back->Height=Form1->Height;
bug=new Graphics::TBitmap();
bug->LoadFromFile("bug.bmp");
X=100;
Y=100;
angle=10;
IsRightDown=false;
IsLeftDown=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
back->Canvas->FillRect(Rect(0,0,back->Width,back->Height));//Очищаем задний буффер
RotateDC(back->Canvas->Handle,angle);
SetViewportOrgEx(back->Canvas->Handle,X,Y,NULL);//Смещаем нашу точку
back->Canvas->Draw(-33,-31,bug);

SetViewportOrgEx(back->Canvas->Handle,0,0,NULL);//Смещаем нашу точку назад
RotateDC(back->Canvas->Handle,0);
Form1->Canvas->Draw(0,0,back);   //И рисуем все на экран

X+=cos(M_RAD_CONV*angle)*speed;
Y+=sin(M_RAD_CONV*angle)*speed;
if(X<-50)X=Form1->Width+50;
if(Y<-50)Y=Form1->Height+50;
if(X>Form1->Width+50)X=-50;
if(Y>Form1->Height+50)Y=-50;
if(IsRightDown==true)
     {
     angle+=RotSpeed;
     }
if(IsLeftDown==true)
     {
     angle-=RotSpeed;
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RIGHT)
     {
     IsRightDown=true;
     }
if(Key==VK_LEFT)
     {
     IsLeftDown=true;
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RIGHT)
     {
     IsRightDown=false;
     }
if(Key==VK_LEFT)
     {
     IsLeftDown=false;
     }
}
//---------------------------------------------------------------------------
