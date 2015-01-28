//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#include <conio.h>
#define Sq 1000
//---------------------------------------------------------------------------
Graphics::TBitmap *bmpI=new Graphics::TBitmap;
//---------------------------------------------------------------------------
void CreateBMP(int w,int h)
{
    bmpI->Width=w;
    bmpI->Height=h;
    bmpI->Transparent=true;
    bmpI->TransparentColor=clWhite;
}
//---------------------------------------------------------------------------
void insect::DrawInsect(Graphics::TBitmap*bmp)
{
    bmpI->Canvas->Pen->Color=clWhite;
    bmpI->Canvas->Brush->Color=clWhite;
    bmpI->Canvas->Rectangle(0,0,bmpI->Width,bmpI->Height);
    oform.DrawDetail(bmpI);
    bmp->Canvas->Draw(loc.x-bmpI->Width/2+bmp->Width/2,bmp->Height/2-loc.y-bmpI->Height/2,bmpI);
}
//---------------------------------------------------------------------------
void insect::Move()
{
    point2D vec;
    vec=go-loc;
    oform.alpha=vec.Alpha();
    if(vec.D()>5)
    {
        loc=loc+vec*(v/vec.D());
    }
    else
    {
        go.x=random(Sq)-Sq/2;
        go.y=random(Sq)-Sq/2;
    }
    //oform.alpha=vec.Alpha();
    oform.alpha=ALPHA(vec.x,vec.y);
}
//---------------------------------------------------------------------------
void push_back(list &l,listitem *t)
{
    if(l.last)
    {
        l.last->next=t;
        t->next=NULL;
        t->prev=l.last;
        l.last=t;
    }
    else
    {
        l.first=t;
        t->next=t->prev=NULL;
        l.last=l.first;
    }
}
//---------------------------------------------------------------------------
void _DeleteList(listitem*&t)
{
    if(t)
    {
        _DeleteList(t->next);
        free(t);
        t=NULL;
    }
}
//---------------------------------------------------------------------------
void DeleteList(list &l)
{
    _DeleteList(l.first);
    l.first=l.last=NULL;
}
//---------------------------------------------------------------------------
void MainInsect::Move()
{
    listitem *t=ins.first;
    myinsect.Move();
    while(t)
    {
       // t->ins.loc=t->ins.loc-myinsect.loc;
      //  t->ins.go=t->ins.go-myinsect.loc;
        t=t->next;
    }
   // myinsect.go=myinsect.go-myinsect.loc;
   // myinsect.loc.InitXY(0,0);
}
//---------------------------------------------------------------------------
void MainInsect::CreateListInsect(int n,int fn,char **fname)
{
    int i,j;
    AnsiString name;
    listitem *newins;
    for(i=0;i<n;i++)
    {
        j=random(fn);
        newins=new listitem;
        name=fname[j];
        newins->ins.oform.LoadFromFile((name+".detail").c_str());
        if(newins->ins.oform.Npoint>0)
        {
            newins->ins.loc.x=random(Sq)-Sq/2;
            newins->ins.loc.y=random(Sq)-Sq/2;
            newins->ins.oform.S=random(20)+10;
            newins->ins.go=newins->ins.loc;
            newins->ins.v=random(5)+1;
            //life,atack...
            push_back(ins,newins);
        }
    }
}
//---------------------------------------------------------------------------
void MainInsect::MoveAll()
{
    listitem *t=ins.first;
    while(t)
    {
        t->ins.Move();
        t=t->next;
    }
    Move();
}
//---------------------------------------------------------------------------
void MainInsect::DrawAll(Graphics::TBitmap*bmp)
{
    listitem *t=ins.first;
    bmp->Canvas->Pen->Color=clWhite;
    bmp->Canvas->Brush->Color=clWhite;
    bmp->Canvas->Rectangle(0,0,bmp->Width,bmp->Height);
    while(t)
    {
        t->ins.DrawInsect(bmp);
        t=t->next;
    }
    myinsect.DrawInsect(bmp);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
