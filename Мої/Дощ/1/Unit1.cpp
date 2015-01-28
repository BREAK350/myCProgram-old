//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TbVector2d Speed;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner),g(0,9)
{
    Speed.Init(8,0);

    Or.Canvas=Canvas;
    Frequency=5;
    CountDrops=40;
    World.Location.Init(400,300);
    World.Width=400;
    World.Height=300;
    Obj.Width=20;
    Obj.Height=100;
    Obj.Speed.Init(0,0);
    NewTest();
}
//---------------------------------------------------------------------------
void TForm1::NextDrops()
{
    TDrop Drop;
    Drop.Radius=3;
    Drop.Location.Y=World.Location.Y-World.Height+10;
    int i=0;
    while(i<CountDrops)
    {
        Drop.Location.X=World.Width*2.0/CountDrops*i;
        Drops.Add(Drop);
        i++;
    }
}
//---------------------------------------------------------------------------
void TForm1::NextPos()
{
    if(CurrFrequency<Frequency)
    {
        CurrFrequency++;
    }
    else
    {
        CurrFrequency=0;
        NextDrops();
    }
    if(Obj.Speed==false)
    {
        if(CountDropsHitting>0)
        {
            Obj.Speed=Speed;
        }
    }
    Drops.CurrSetFirst();
    while(Drops.CurrCorrect())
    {
        if(World.isHitting(Drops.GetCurr())==false)
        {
            Drops.DeleteCurr();
        }
        else
        {
            if(Obj.isHitting(Drops.GetCurr()))
            {
                Drops.DeleteCurr();
                CountDropsHitting++;
            }
            else
            {
                Drops.GetCurr().Location+=g;
                Drops.CurrSetNext();
            }
        }
    }
}
//---------------------------------------------------------------------------
void TForm1::NewTest()
{
    Drops.DeleteAll();
    Obj.Location.Init(World.Location.X-World.Width,World.Location.Y+World.Height);
    CurrFrequency=0;
    CountDropsHitting=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    //Repaint();
    NextPos();
    Obj.Location+=Obj.Speed;
    DrawDrops();
    Obj.Draw(Or);
    TDrop d;
    d.Location=Obj.Location;
    if(World.isHitting(d)==false)
    {
        Timer1->Enabled=false;
        Label1->Caption=IntToStr(CountDropsHitting);
    }
}
//---------------------------------------------------------------------------
void TForm1::DrawDrops()
{
    Drops.CurrSetFirst();
    while(Drops.CurrCorrect())
    {
        Drops.GetCurr().Draw(Or);
        Drops.CurrSetNext();
    }
}
//---------------------------------------------------------------------------

