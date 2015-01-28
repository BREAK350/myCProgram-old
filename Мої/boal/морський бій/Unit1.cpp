//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int X,Y;
TArmy s,v;
mTCursor cur;
int cl=0;
int kk=20;
int index,N=2,nz=10;
int ia=0;
TCommander *player;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 int i;
 randomize();
 Form1->Show();
 Canvas->Pen->Color=clLime;
 Form1->Height=Screen->Height;
 Form1->Width=Screen->Width;
 Form1->Top=0;
 Form1->Left=0;
 Panel1->Height=Form1->Height;
 Panel1->Left=0;
 X=100;
 Y=Form1->Height-100;
 s.name="Army";
 s.x=100;
 s.y=100;
 s.r=50;
 s.activ=1;
 v.name="War";
 v.x=400;
 v.y=400;
 v.r=30;
 v.activ=0;
 Canvas->Pen->Color=clRed;
 player=new TCommander[N];
 for(index=0;index<N;index++)
  {
   player[index].name=IntToStr(index+1);
   player[index].n=nz;
   player[index].army=new TArmy[nz];
   for(i=0;i<nz;i++)
    {
     player[index].army[i].name=IntToStr(i+1);
     player[index].army[i].activ=1;
     player[index].army[i].x=random(1000)+1;
     player[index].army[i].y=random(600)+1;
     player[index].army[i].r=30;
     player[index].army[i].rocket.r=20;
     player[index].army[i].rocket.n=100;
     player[index].army[i].life=100;
     player[index].army[i].A=30;
     player[index].army[i].Z=20;
    }
  }
 index=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
 int i;
 Snood(Form1);
 if(player[index].army[ia].activ!=0)
   player[index].army[ia].activ=2;
 player[index].ShowArmy(Form1);
 for(i=0;i<N;i++)
   if(i!=index)
     player[index].ShowEnemy(player[i],Form1);
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
   cur.y=Y-_Y;
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
   if((player[index].army[ia].activ!=0)&&(player[index].army[ia].distance(cur.x,cur.y)<=kk))
    {
     player[index].army[ia].x=cur.x;
     player[index].army[ia].y=cur.y;
     player[index].army[ia].activ=0;
    }
 ia++;
 if(ia>=player[index].n)
   ia=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
 int i,j,a;
 cl=0;
 Canvas->Brush->Color=clRed;
 Canvas->Ellipse(X+cur.x-player[index].army[ia].rocket.r,Y-cur.y-player[index].army[ia].rocket.r,X+cur.x+player[index].army[ia].rocket.r,Y-cur.y+player[index].army[ia].rocket.r);
 if(ia>=0)
   if(player[index].army[ia].activ!=0)
     for(i=0;i<N;i++)
       for(j=0;j<player[i].n;j++)
        {
         a=player[index].army[ia].Bang(player[i].army[j],cur.x,cur.y);
         player[i].army[j]._life(a);
        }
 player[index].army[ia].activ=0;
 player[index].army[ia].rocket.n--;
 ia++;
 if(ia>=player[index].n)
   ia=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
 int i;
 for(i=0;i<player[index].n;i++)
   player[index].army[i].activ=1;
 index++;
 if(index>=N)
   index=0;
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
   ia=player[index].n-1;
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
 if(ia>=player[index].n)
   ia=0;
 if(player[index].army[ia].activ!=0)
   player[index].army[ia].activ=2;
 player[index].army[ia].ShowInfo();  
}
//---------------------------------------------------------------------------

