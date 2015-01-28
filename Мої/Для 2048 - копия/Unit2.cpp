//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
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
	HWND hWnd;
	//hWnd = FindWindow("Chrome_WidgetWin_1",0);
	hWnd=(HWND)0x00050244;
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
long int HexToLInt(const char *hex)
{
	long int res=0;
	sscanf(hex,"%x",&res);
	return res;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::OKClick(TObject *Sender)
{
	HWND hWnd;
	hWnd = (HWND)HexToLInt(Edit1->Text.t_str());
	String caption=String("Ваш результат: ")+
				   Edit2->Text+
				   " з 20\nПовідомте викладача про результат";
	SetWindowTextA(hWnd,caption.t_str());
}
//---------------------------------------------------------------------------

