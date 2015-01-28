//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
mTCursor cur;
DataGame dg;
int cl=0;
int index;
int ia=0;
TCommander *player;
int OK=1;
int HEALTHY;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 randomize();
 Form1->Show();
 Canvas->Pen->Color=clLime;
 Form1->Height=Screen->Height;
 Form1->Width=Screen->Width;
 Form1->Top=0;
 Form1->Left=0;
 Panel1->Height=Form1->Height;
 Panel1->Left=0;
 dg.X=100;
 dg.Y=Form1->Height-100;
 index=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 Panel3->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
 int i;
 HEALTHY=0;
 for(i=0;i<dg.N;i++)
   if(player[i].Healthy()>0)
     HEALTHY++;
 Label5->Caption=IntToStr(HEALTHY);    
 Snood(Form1);
 if(HEALTHY>0)
  {
   if(player[index].army[ia].activ!=0)
     player[index].army[ia].activ=2;
   player[index].army[ia].ShowInfo();  
   if(OK==1)
    {
     player[index].ShowArmy(Form1);
     Label11->Caption="Здорових: "+IntToStr(player[index].Healthy());
     for(i=0;i<dg.N;i++)
       if(i!=index)
         player[index].ShowEnemy(player[i],Form1);
    }
  }  
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
 cur.Show(Form1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int _X, int _Y)
{
 if(cl==0)
  {
   cur.x=_X-100;
   cur.y=dg.Y-_Y;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
 cl=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
 cl=0;
 if(ia>=0)
   if((player[index].army[ia].activ!=0)&&(player[index].army[ia].distance(cur.x,cur.y)<=dg.kk))
    {
     player[index].army[ia].x=cur.x;
     player[index].army[ia].y=cur.y;
     player[index].army[ia].activ=0;
    }
 ia++;
 if(ia>=player[index].nHealthy)
   ia=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
 int i,j,a;
 cl=0;
 Canvas->Brush->Color=clRed;
 Canvas->Ellipse(dg.X+cur.x-player[index].army[ia].rocket.r,dg.Y-cur.y-player[index].army[ia].rocket.r,dg.X+cur.x+player[index].army[ia].rocket.r,dg.Y-cur.y+player[index].army[ia].rocket.r);
 if(ia>=0)
   if(player[index].army[ia].activ!=0)
     for(i=0;i<dg.N;i++)
       for(j=0;j<player[i].n;j++)
        {
         a=player[index].army[ia].Bang(player[i].army[j],cur.x,cur.y);
         player[i].army[j]._life(a);
        }
 player[index].army[ia].activ=0;
 player[index].army[ia].rocket.n--;
 ia++;
 if(ia>=player[index].nHealthy)
   ia=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
 int i;
 OK=1-OK;
 Label12->Caption=" ";
 if(OK==1)
  {
   for(i=0;i<player[index].nHealthy;i++)
     player[index].army[i].activ=1;
   index++;
   if(index>=dg.N)
     index=0;
  }
 ia=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 if(ia>=0)
  {
   if(player[index].army[ia].activ!=0)
     player[index].army[ia].activ=1;
  }
 ia--;
 if(ia<0)
   ia=player[index].nHealthy-1;
 if(player[index].army[ia].activ!=0)
   player[index].army[ia].activ=2;
 player[index].army[ia].ShowInfo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 if(player[index].army[ia].activ!=0)
   player[index].army[ia].activ=1;
 ia++;
 if(ia>=player[index].nHealthy)
   ia=0;
 if(player[index].army[ia].activ!=0)
   player[index].army[ia].activ=2;
 player[index].army[ia].ShowInfo();  
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
 cl=0;       
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
 dg.ReadData();
 CreateNewGame();
 Panel3->Visible=false;
 index=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
 Form1->Close();
}
//---------------------------------------------------------------------------
void CreateNewGame()
{
 int i;
 dg.ReadData();
 player=new TCommander[dg.N];
 for(index=0;index<dg.N;index++)
  {
   player[index].name=IntToStr(index+1);
   player[index].n=dg.nz;
   player[index].army=new TArmy[dg.nz];
   for(i=0;i<dg.nz;i++)
    {
     player[index].army[i].name=IntToStr(i+1);
     player[index].army[i].activ=1;
     player[index].army[i].x=random(1000)+1;
     player[index].army[i].y=random(600)+1;
     player[index].army[i].r=dg.rv;
     player[index].army[i].rocket.r=dg.rdr;
     player[index].army[i].rocket.n=dg.kr;
     player[index].army[i].life=dg.life;
     player[index].army[i].A=dg.A;
     player[index].army[i].Z=dg.Z;
    }
   player[index].Healthy();
  }
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
