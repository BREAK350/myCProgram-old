//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TForm1 *Form1;
data   dat;
int    n=0;
TWord  *w,add;
int    typeshow1=1;
int    typeshow2=1;
int    index=0;
int    oneword;
char   search[500];
int    change=0;
int    cs=0;
int    pfn=1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 StandartData();
 randomize();
 if(LoadWords()==0)
   CreateStandartWords();
 ShowWord1();
 add.eng=add.ukr=NULL;
 Label5->Caption=FloatToStr(n);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::nextClick(TObject *Sender)
{
 switch(typeshow1)
  {
   case 1:index++;
          if(index>=n)
            index=0;break;
  }
 ShowWord1();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::prevClick(TObject *Sender)
{
 switch(typeshow1)
  {
   case 1:index--;
          if(index<0)
            index=n-1;break;
  }
 ShowWord1();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buttonClick(TObject *Sender)
{
 switch(oneword)
           {
            case 1:Form1->eng->Lines->Strings[0]=w[index].eng;
                   break;
            case 0:Form1->ukr->Lines->Strings[0]=w[index].ukr;
                   break;
           }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N11Click(TObject *Sender)
{
 typeshow1=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N21Click(TObject *Sender)
{
 typeshow1=2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N8Click(TObject *Sender)
{
 typeshow2=1;
 Form1->button->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N9Click(TObject *Sender)
{
 typeshow2=2;
 Form1->button->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N10Click(TObject *Sender)
{
 typeshow2=3;
 Form1->button->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N12Click(TObject *Sender)
{
 typeshow2=4;
 Form1->button->Enabled=true;          
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N5Click(TObject *Sender)
{
 SortWordEng();
 change=1;       
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N6Click(TObject *Sender)
{
 SortWordUkr();
 change=1;       
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N14Click(TObject *Sender)
{
 Form1->Color=clBtnFace;
 Panel1->Color=clBtnFace;
 Panel2->Color=clBtnFace;
 Panel3->Color=clBtnFace;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N22Click(TObject *Sender)
{
 Form1->Color=clBlue;
 Panel1->Color=clAqua;
 Panel2->Color=clSkyBlue;
 Panel3->Color=clSkyBlue;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N23Click(TObject *Sender)
{
 Form1->Color=clGreen;
 Panel1->Color=clLime;
 Panel2->Color=clAqua;
 Panel3->Color=clAqua;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N31Click(TObject *Sender)
{
 Form1->Color=clRed;
 Panel1->Color=clFuchsia;
 Panel2->Color=clMaroon;
 Panel3->Color=clMaroon;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N41Click(TObject *Sender)
{
 Form1->Color=clPurple;
 Panel1->Color=clYellow;
 Panel2->Color=clTeal;
 Panel3->Color=clTeal;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N15Click(TObject *Sender)
{
 int i;
 if(change==0)
   {
    for(i=0;i<n;i++)
     {
      free(w[i].eng);
      free(w[i].ukr);
     }
    free(w);
    Form1->Close();
   }
 else
  {
   msg->Visible=true;
   Memo1->Text="Увага! Були проведені деякі зміни в словах. Без збереження ці зміни не збережуться!";
   change=0;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N16Click(TObject *Sender)
{
 Form1->eng->Clear();
 Form1->ukr->Clear();
 Panel2->Visible=true;
 Panel3->Visible=false;
 index=0;
 Button1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 strcpy(search,(Edit1->Text).c_str());
 if(strlen(search)>0)
   {
    SearchNextWord();
    index++;
    if(index>=n)
      {
       Form1->eng->Clear();
       Form1->ukr->Clear();
       Button1->Enabled=false;
       index=0;
      }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 Panel2->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
 SaveAll();
 change=0;
 msg->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N17Click(TObject *Sender)
{
 Panel3->Visible=true;
 Panel2->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 FILE *f;
 strcpy(search,(Edit2->Text).c_str());
 add.eng=strdup(search);
 strcpy(search,(Edit3->Text).c_str());
 add.ukr=strdup(search);
 if((strlen(add.eng)>0)&&(strlen(add.ukr)>0))
   SaveOne();
 free(add.eng);
 free(add.ukr);
 add.eng=add.ukr=NULL;
 Edit2->Clear();
 Edit3->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
 cs=0;
 Panel3->Visible=false;
 Button3->Enabled=true;
 Button5->Enabled=true;
 Edit2->Clear();
 Edit3->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit2Change(TObject *Sender)
{
 if(cs==0)
  {
   Form1->eng->Clear();
   Form1->ukr->Clear();
   strcpy(search,(Edit2->Text).c_str());
   if(strlen(search)>0)
     SearchEngWord();
   Button6->Enabled=true;
  } 
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit3Change(TObject *Sender)
{
 if(cs==0)
  {
   Form1->eng->Clear();
   Form1->ukr->Clear();
   strcpy(search,(Edit3->Text).c_str());
   if(strlen(search)>0)
     SearchUkrWord();
   Button6->Enabled=true;
  } 
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
 if((cs==0)&&(strlen(search)>0))
   {
    SearchNextWord();
    index++;
    if(index>=n)
      {
       Form1->eng->Clear();
       Form1->ukr->Clear();
       Button6->Enabled=false;
       index=0;
      }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::msgClick(TObject *Sender)
{
 msg->Visible=false;       
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
 ActivateKeyboardLayout(LoadKeyboardLayout("00000422",0),0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
 ActivateKeyboardLayout(LoadKeyboardLayout("00000422",0),0);
 if(cs==0)
   Edit1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Change(TObject *Sender)
{
 strcpy(search,(Edit1->Text).c_str());
 if(strlen(search)>0)
   {
    index=0;
    SearchNextWord();
    index++;
    if(index>=n)
      {
       Button1->Enabled=false;
       index=0;
      }
   }
 Button1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
 if(index<n)
  {
   Button3->Enabled=false;
   Button5->Enabled=false;
   Button6->Enabled=false;
   Button11->Enabled=true;
   Edit2->Text=w[index].eng;
   Edit3->Text=w[index].ukr;
   cs=1;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
 free(w[index].eng);
 free(w[index].ukr);
 w[index].eng=w[index].ukr=NULL;
 strcpy(search,(Edit2->Text).c_str());
 w[index].eng=strdup(search);
 strcpy(search,(Edit3->Text).c_str());
 w[index].ukr=strdup(search);
 cs=0;
 change=2;
 Button3->Enabled=true;
 Button5->Enabled=true;
 Button6->Enabled=true;
 Button11->Enabled=false;
 Edit2->Clear();
 Edit3->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
 ActivateKeyboardLayout(LoadKeyboardLayout("00000409",0),0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
 ActivateKeyboardLayout(LoadKeyboardLayout("00000409",0),0);
 if(cs==0)
   Edit1->Clear();       
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button12Click(TObject *Sender)
{
 if(index<n)
  {
   free(w[index].eng);
   free(w[index].ukr);
   w[index].eng=NULL;
   w[index].ukr=NULL;
   Edit2->Clear();
   Edit3->Clear();
   Form1->eng->Clear();
   Form1->ukr->Clear();
   change=2;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N18Click(TObject *Sender)
{
 reLoad();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N20Click(TObject *Sender)
{
 pfn=1;
 reLoad();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N24Click(TObject *Sender)
{
 pfn=2;
 reLoad();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
 Panel1->Height=Form1->ClientHeight*0.9-200;
 Panel1->Width=Form1->ClientWidth*0.9;
 Panel1->Left=(Form1->ClientWidth-Panel1->Width)/2;
 Panel1->Top=(Form1->ClientHeight-Panel1->Height)/2-100;
 eng->Height=Panel1->Height-100;
 eng->Top=50;
 eng->Left=Panel1->Width*0.06;
 eng->Width=Panel1->Width*0.41;
 ukr->Height=Panel1->Height-100;
 ukr->Top=50;
 ukr->Left=Panel1->Width*0.53;
 ukr->Width=Panel1->Width*0.41;
 prev->Top=50+eng->Height+12;
 prev->Width=Panel1->Width*0.2;
 prev->Left=Panel1->Width*0.1;
 button->Top=50+eng->Height+12;
 button->Width=Panel1->Width*0.2;
 button->Left=Panel1->Width*0.4;
 next->Top=50+eng->Height+12;
 next->Width=Panel1->Width*0.2;
 next->Left=Panel1->Width*0.7;
 Label5->Left=eng->Left+eng->Width;
 Label1->Left=eng->Left;
 Label2->Left=ukr->Left;
 Panel3->Top=Panel1->Top+Panel1->Height;
 Panel3->Left=(Form1->ClientWidth-Panel3->Width)/2;
 Panel2->Top=Panel1->Top+Panel1->Height;
 Panel2->Left=(Form1->ClientWidth-Panel2->Width)/2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N25Click(TObject *Sender)
{
 Form1->Color=clGray;
 Panel1->Color=clGray;
 Panel2->Color=clGray;
 Panel3->Color=clGray;
}
//---------------------------------------------------------------------------

