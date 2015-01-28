//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TQ *q=NULL;
int n=0,*index;
int i_m=0,itrue=0;
int ianswer;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 Panel2->Visible=true;
 Panel1->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
 Panel2->Visible=false;
 Panel1->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 Cl(q,index,n);
 Panel5->Enabled=true;
 Panel5->Enabled=true;
 Panel1->Visible=true;
 Panel2->Visible=true;
 Panel3->Visible=true;
 Panel4->Visible=true;
 Panel5->Visible=true;
 Panel6->Visible=true;
 Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 Panel1->Visible=false;
 Panel3->Visible=true;
 Panel5->Visible=true;
 Panel6->Visible=true;
 Panel5->Enabled=true;
 Panel3->Enabled=true;
 if(n==0)
  {
   n=LoadQuestion(q);
   index=(int*)malloc(n*sizeof(int));
  } 
 RandomIndex(index,n);
 ShowQuestion(q,index[i_m]);
 i_m++;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
 Panel3->Visible=false;
 Panel5->Visible=false;
 Panel6->Visible=false;
 Panel1->Visible=true;
 i_m=0;
 itrue=0;
}                        
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
 if(i_m<n)
  {
   ShowQuestion(q,index[i_m]);
   i_m++;
   Panel3->Enabled=true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
 if(ianswer==0)
  {
    Button6->Caption="Правильно";
    if(itrue<n)
     {
      itrue++;
      Label7->Caption=FloatToStr(itrue);
     }
  }
 else
  {
    Button6->Caption="Неправильно";
    Panel5->Enabled=false;
  }
 Panel3->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
 if(ianswer==1)
  {
    Button7->Caption="Правильно";
    if(itrue<n)
     {
      itrue++;
      Label7->Caption=FloatToStr(itrue);
     }
  }
 else
  {
    Button7->Caption="Неправильно";
    Panel5->Enabled=false;
  }
 Panel3->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
 if(ianswer==2)
  {
    Button8->Caption="Правильно";
    if(itrue<n)
     {
      itrue++;
      Label7->Caption=FloatToStr(itrue);
     }
  }
 else
  {
    Button8->Caption="Неправильно";
    Panel5->Enabled=false;
  }
 Panel3->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
 if(ianswer==3)
  {
    Button9->Caption="Правильно";
    if(itrue<n)
     {
      itrue++;
      Label7->Caption=FloatToStr(itrue);
     }
  }
 else
  {
    Button9->Caption="Неправильно";
    Panel5->Enabled=false;
  }
 Panel3->Enabled=false;
}
//---------------------------------------------------------------------------
