//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TText text[1];
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    Memo3->Text="��� ������������ ���������� ����� � ��������� �������";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo2MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    Memo3->Text="��� ���������� ���� ���������� �����, ��� ����������� ����� �������� �� ������";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    Memo3->Text="�������� ���, ��� ���������, ��������� �� �������� �������� �������� �� �";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    Memo3->Text="�������� ���, ��� ������ ������� ����";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo3MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    Memo3->Text="����� ��������";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    Memo3->Text="��� �������� ������ ������ �� ����������";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    Memo3->Text="���������, ������������ �� �������� �������, �������";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    TWord w;
    TSentence sent;
    char s[]="������� ������� ����.";
    char *beg=s;
    beg=sent.CreateFirstSentence(beg);
    Memo1->Text=s;
    Memo2->Text=sent.GetSentence();            
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
    OpenDialog1->Execute();
    text[0].CreateTextWithFile(OpenDialog1->FileName.c_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    static int i=0;
    Memo1->Text=text[0].GetSentences(i);
    i++;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N13Click(TObject *Sender)
{
    Memo1->Font->Height++;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Memo2->Clear();    
}
//---------------------------------------------------------------------------

