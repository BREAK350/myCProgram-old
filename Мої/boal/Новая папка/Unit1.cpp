//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int X=300,Y=300;
TVector vec1,vec2,p;
TVector g,track[5];
TBoal b;
Graphics::TBitmap*   gBitmap = new Graphics::TBitmap;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 int i;
 Form1->Show();
 g.alpha=-90;
 g.v=0.01;
 vec1.alpha=90;
 vec1.v=0;
 vec1.y=-9;
 track[0].CreateVector_xyxy(-200,0,500,-50);
 track[1].CreateVector_xyxy(-10,-10,100,0);
 track[2].CreateVector_xyxy(100,0,150,100);
 track[3].CreateVector_xyxy(150,100,0,200);
 track[4].CreateVector_xyxy(0,200,-100,100);
// for(i=0;i<5;i++)
   track[0].Draw(X,Y,Form1);
 gBitmap->LoadFromFile("Boal.bmp");
 b.vector.alpha=30;
 b.vector.v=2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
 int i;
 for(i=0;i<5;i++)
 if(vec1.Collision(track[0],5)==0)
   //vec1.v=vec1.v*0.6;
   vec1.Interaction(g);
 vec1.Move();
 vec1.Draw(X,Y,Form1);
 b.vector.Interaction(g);
 for(i=0;i<5;i++)
   if(b.vector.Collision(track[i],7)==1)
     b.vector.v*=1.0;
 b.vector.Move();
 Canvas->Draw(X+b.vector.x-25,Y-b.vector.y-25,gBitmap);
 for(i=0;i<5;i++)
   track[i].Draw(X,Y,Form1);
}
//---------------------------------------------------------------------------
