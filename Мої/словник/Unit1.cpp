//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TListW list;
TListItem *t,**l;
int n,N_E=0,N_U=0;
int type=0,
    eoru;
int tcol=1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 int i;
 TListItem *p;
 Form1->Show();
 Memo1->Enabled=false;
 Memo2->Enabled=false;
 n=CreateList(list,"1.txt");
 i=0;
 l=(TListItem**)malloc(n*sizeof(TListItem));
 p=list.first;
 while(p)
 {
  l[i]=p;
  N_E+=p->word.n_e;
  N_U+=p->word.n_u;
  i++;
  p=p->next;
 }
 Label2->Caption="Англійська("+FloatToStr(N_E)+")";
 Label3->Caption="Українська("+FloatToStr(N_U)+")";
 switch(type)
  {
   case 0:t=list.first;
          ShowWord(t);
          Button1->Enabled=false;
          if(!t->next)
            Button1->Enabled=false; break;
   case 1:t=l[random(n)];
          ShowWord(t);break;
   case 2:t=l[random(n)];
          eoru=random(2);
          ShowWordOne(t,eoru); break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 switch(type)
  {
   case 0:if(t->prev)
           {
            t=t->prev;
            ShowWord(t);
            Button2->Enabled=true;
           }
          if(!t->prev)
            Button1->Enabled=false; break;
   case 1:t=l[random(n)];
          ShowWord(t);break;
   case 2:t=l[random(n)];
          eoru=random(2);
          ShowWordOne(t,eoru); break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 switch(type)
  {
   case 0:if(t->next)
           {
            t=t->next;
            ShowWord(t);
            Button1->Enabled=true;
           }
          if(!t->next)
            Button2->Enabled=false; break;
   case 1:t=l[random(n)];
          ShowWord(t);break;
   case 2:t=l[random(n)];
          eoru=random(2);
          ShowWordOne(t,eoru); break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label2Click(TObject *Sender)
{
 switch(type)
  {
   case 2:if(eoru==1)
            ShowWordEng(t);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label3Click(TObject *Sender)
{
 switch(type)
  {
   case 2:if(eoru==0)
            ShowWordUkr(t);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label1Click(TObject *Sender)
{
 type++;
 if(type>2)
   type=0;
 switch(type)
  {
   case 0:t=list.first;
          ShowWord(t);
          Button1->Enabled=false;
          if(!t->next)
            Button1->Enabled=false; break;
   case 1:t=l[random(n)];
          ShowWord(t);
          Button1->Enabled=true;
          Button2->Enabled=true;break;
   case 2:t=l[random(n)];
          eoru=random(2);
          ShowWordOne(t,eoru);
          Button1->Enabled=true;
          Button2->Enabled=true;break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel1Click(TObject *Sender)
{
 tcol++;
 if(tcol>maxtcol)
   tcol=1;
 switch(tcol)
  {
   case 1:Form1->Color=clBtnFace;
          Panel1->Color=clBtnFace;
          Label1->Color=clBtnFace; break;
   case 2:Form1->Color=clBlue;
          Panel1->Color=clAqua;
          Label1->Color=clAqua; break;
   case 3:Form1->Color=clBlue;
          Panel1->Color=clGreen;
          Label1->Color=clGreen; break;
   case 4:Form1->Color=clRed;
          Panel1->Color=clFuchsia;
          Label1->Color=clFuchsia; break;
   case 5:Form1->Color=clGreen;
          Panel1->Color=clLime;
          Label1->Color=clLime; break;
   case 6:Form1->Color=clPurple;
          Panel1->Color=clYellow;
          Label1->Color=clYellow; break;
  }
}
//---------------------------------------------------------------------------

