//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "footl.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap*   gBitmap = new Graphics::TBitmap;
FILE *list;
tchar lisT[32];
int kTeam=-1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 Form1->Show();
 gBitmap->LoadFromFile("2.bmp");
 Canvas->Draw(0,0,gBitmap);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button13Click(TObject *Sender)
{
 Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
 Panel6->Visible=false;
 Panel2->Visible=true;
 Canvas->Draw(0,0,gBitmap);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button14Click(TObject *Sender)
{
 Panel2->Visible=false;
 Panel6->Visible=true;
 Panel1->Visible=false;
 Panel3->Visible=false;
 Canvas->Draw(0,0,gBitmap);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 Panel3->Visible=true;       
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label25Click(TObject *Sender)
{
 Panel1->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button17Click(TObject *Sender)
{
 Panel1->Visible=false;
 Canvas->Draw(0,0,gBitmap);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label28Click(TObject *Sender)
{
 Panel1->Visible=true;    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label31Click(TObject *Sender)
{
 Panel1->Visible=true;           
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label34Click(TObject *Sender)
{
 Panel1->Visible=true;           
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label37Click(TObject *Sender)
{
 Panel1->Visible=true;           
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label40Click(TObject *Sender)
{
 Panel1->Visible=true;           
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label43Click(TObject *Sender)
{
 Panel1->Visible=true;           
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
 int i;
 char name[10];
 Panel6->Visible=false;
 Panel4->Visible=true;
 Canvas->Draw(0,0,gBitmap);
 Label46->Caption="...";
 Label47->Caption="...";
 Label48->Caption="...";
 Label49->Caption="...";
 if(kTeam==-1)
 {
   list=fopen(TL,"r");
   i=0;
   while((i<32)&&(fgets(name,10,list)))
   {
     strcpy(lisT[i],name);
     i++;
   }
   kTeam=i;
   fclose(list);
 }
 if(kTeam>=1) Label46->Caption=lisT[0];
 if(kTeam>=2) Label47->Caption=lisT[1];
 if(kTeam>=3) Label48->Caption=lisT[2];
 if(kTeam>=4) Label49->Caption=lisT[3];
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
 Panel6->Visible=true;
 Panel4->Visible=false;
}
//---------------------------------------------------------------------------
