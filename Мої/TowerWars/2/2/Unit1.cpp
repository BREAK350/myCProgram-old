//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap *BMP=new Graphics::TBitmap;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    /*T_Trajectory tr(4);
    tr.SetEpsilon(0.01);
    tr.SetLength(1);
    tr[0]=new T_Segment(100,100,1000,100);
    tr[1]=new T_Segment(1000,100,1000,600);
    tr[2]=new T_Segment(1000,600,100,600);
    tr[3]=new T_Segment(100,600,100,100);
    tr.SaveToFile("test.txt");
    */
    randomize();
    Game.EnemyTrajectory.LoadFromFile("test.txt");
    Game.EnemyTrajectory.SetLength(5);
    AddGun(2);
    AddEnemy(10);
    BMP->Width=1100;
    BMP->Height=700;
    BMP->Canvas->Pen->Width=3;
}
//---------------------------------------------------------------------------
void TForm1::AddEnemy(const int &n)
{
    TbTWEnemy e;
    double h=(double)Game.EnemyTrajectory.GetAmount()/n;
    e.Health=1000;
    e.MaxHealth=1000;
    e.Time=0;
    e.vGun.Init(100,0);
    e.R=20;
    e.TimeRecharge=20;
    e.Last_t=0;
    for(int i=0;i<n;i++)
    {
        e.Time=random(e.TimeRecharge);
        Game.Enemy.AddLast(e);
        e.Last_t+=h;
    }
}
//---------------------------------------------------------------------------
void TForm1::AddGun(const int &n)
{
    TbTWGun g;
    g.Health=20000;
    g.MaxHealth=20000;
    g.R=20;
    g.vGun.Init(-100,0);
    g.TimeRecharge=1;
    for(int i=0;i<n;i++)
    {
        g.Time=random(g.TimeRecharge);
        g.Location.Init(random(700)+200,random(300)+200);
        Game.Gun.AddLast(g);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    BMP->Canvas->Brush->Color=clWhite;
    BMP->Canvas->Rectangle(-1,-1,1101,701);
    Timer1->Enabled=Game.Click();
    if(Timer1->Enabled==false)
    {
        if(Game.Enemy.GetCount()==0)
        {
            ShowMessage("Пушки виграли");
        }
        else
        {
            ShowMessage("Танки виграли");
        }
    }
    Game.Draw(BMP->Canvas);
    Canvas->Draw(0,0,BMP);
}
//---------------------------------------------------------------------------
/*
    T_Trajectory tr(3);
    tr.SetEpsilon(0.01);
    tr.SetLength(1);
    tr[0]=new T_Arc(300,200,100,M_PI,0,1);
    tr[1]=new T_Segment(400,200,200,400);
    tr[2]=new T_HermiteCurve(T_Vector2d(200,400),T_Vector2d(200,200),
                             T_Vector2d(-750,750),T_Vector2d(0,500));
    tr.SaveToFile("test.txt");
*/

