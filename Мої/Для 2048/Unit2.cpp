//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
HWND hWnd;
//---------------------------------------------------------------------------
long int HexToLInt(const char *hex)
{
	long int res=0;
	sscanf(hex,"%x",&res);
	return res;
}
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	CountLeft=CountRight=CountDown=1;
	CountUp=0;
}
//---------------------------------------------------------------------------
void MyPostMessage(HWND hWnd,UINT vk)
{
	PostMessage(hWnd,WM_KEYDOWN,vk,0);
	PostMessage(hWnd,WM_KEYUP,vk,0);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
	//hWnd = FindWindow("Chrome_WidgetWin_1",0);
	for(int i=0;i<CountRight;i++)
	{
		MyPostMessage(hWnd,VK_RIGHT);
	}
	for(int i=0;i<CountLeft;i++)
	{
		MyPostMessage(hWnd,VK_LEFT);
	}
	for(int i=0;i<CountUp;i++)
	{
		MyPostMessage(hWnd,VK_UP);
	}
	for(int i=0;i<CountDown;i++)
	{
		MyPostMessage(hWnd,VK_DOWN);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::OKClick(TObject *Sender)
{
	hWnd = (HWND)HexToLInt(Edit6->Text.t_str());
	CountLeft=Edit2->Text.ToInt();
	CountRight=Edit3->Text.ToInt();
	CountUp=Edit4->Text.ToInt();
	CountDown=Edit5->Text.ToInt();
	if(Edit1->Text.ToInt()==0)
	{
		Timer1->Enabled=false;
	}
	else
	{
		Timer1->Interval=Edit1->Text.ToInt();
		Timer1->Enabled=true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	Timer1->Enabled=false;
}
//---------------------------------------------------------------------------

