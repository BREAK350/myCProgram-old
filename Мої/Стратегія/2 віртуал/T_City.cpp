//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_City.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void T_City::UpResource()
{
    Resource=Resource+Income;
}
//---------------------------------------------------------------------------
void T_City::UpIncome(_Resource_ r,float price,float add)
{
    switch(r)
    {
        _Gold_:
            if(Income.Gold*price<=Resource.Gold)
            {
                Resource.Gold-=Income.Gold*price;
                Income.Gold+=add;
            }
            break;
        _Stone_:
            if(Income.Stone*price<=Resource.Stone)
            {
                Resource.Stone-=Income.Stone*price;
                Income.Stone+=add;
            }
            break;
        _Tree_:
            if(Income.Tree*price<=Resource.Tree)
            {
                Resource.Tree-=Income.Tree*price;
                Income.Tree+=add;
            }
            break;
        _Coal_:
            if(Income.Coal*price<=Resource.Coal)
            {
                Resource.Coal-=Income.Coal*price;
                Income.Coal+=add;
            }
            break;
        _Iron_:
            if(Income.Iron*price<=Resource.Iron)
            {
                Resource.Iron-=Income.Iron*price;
                Income.Iron+=add;
            }
            break;
    }
}
//---------------------------------------------------------------------------
void T_City::UpIncome(_Resource_ r,int add)
{
    UpIncome(r,2*add+1,add);
}
//---------------------------------------------------------------------------
T_City::T_City():XY(0,0),Resource(),Income(),Character()
{
    LinkMap=NULL;
    Name=NULL;
    Nation=-1;
    KCommander=0;
    Commanders=NULL;
    CurrentCommander=0;
}
//---------------------------------------------------------------------------
T_City::T_City(T_Map *map,char *name,TPoint xy,int nation,T_Resource resource,
               T_Resource income,T_Character character,int kcommander,
               T_Commander **commanders)
{
    int i;
    LinkMap=map;
    Name=strdup(name);
    XY=xy;
    Nation=nation;
    Resource=resource;
    Income=income;
    Character=character;
    KCommander=kcommander;
    if(KCommander>0)
    {
        Commanders=new T_Commander*[KCommander];
        for(i=0;i<KCommander;i++)
        {
            Commanders[i]=new T_Commander(*commanders[i]);
        }
    }
    else
    {
        KCommander=0;
        Commanders=NULL;
    }
    CurrentCommander=0;
}
//---------------------------------------------------------------------------
T_Commander* T_City::GetNextCommander()
{
    return NULL;
}
//---------------------------------------------------------------------------
T_Commander* T_City::GetCommander(int k)
{
    if(k<0 || k>=KCommander || Commanders[k]->GetActive()==false)
    {
        return NULL;
    }
    return Commanders[k];
}
//---------------------------------------------------------------------------
T_City::T_City(const T_City &c)
{
    int i;
    LinkMap=c.LinkMap;
    Name=strdup(c.Name);
    XY=c.XY;
    Nation=c.Nation;
    Resource=c.Resource;
    Income=c.Income;
    Character=c.Character;
    KCommander=c.KCommander;
    Commanders=new T_Commander*[KCommander];
    for(i=0;i<KCommander;i++)
    {
        Commanders[i]=new T_Commander(*c.Commanders[i]);
    }
    CurrentCommander=c.CurrentCommander;
}
//---------------------------------------------------------------------------
T_City::~T_City()
{
    int i;
    delete Name;
    Name=NULL;
    for(i=0;i<KCommander;i++)
    {
        delete Commanders[i];
    }
    delete Commanders;
    Commanders=NULL;
    KCommander=0;
}
//---------------------------------------------------------------------------
void T_City::CreateNewCommander(char *name)
{
    int i;
    T_Commander **c=new T_Commander*[KCommander];
    for(i=0;i<KCommander;i++)
    {
        c[i]=Commanders[i];
    }
    delete Commanders;
    KCommander++;
    Commanders=new T_Commander*[KCommander];
    for(i=0;i<KCommander-1;i++)
    {
        Commanders[i]=c[i];
    }
    Commanders[i]=new T_Commander(name,XY,T_Character(),Nation,T_Resource(),0,NULL);
    delete c;
}
//---------------------------------------------------------------------------
T_Commander* T_City::SearchCommander(TPoint p)
{
    int i=0;
    while(i<KCommander && !(Commanders[i]->XY==p))
    {
        i++;
    }
    if(i>=KCommander)
    {
        return NULL;
    }
    return Commanders[i];
}
//---------------------------------------------------------------------------
void T_City::Draw(TCanvas *Canvas,float s,TPoint p)
{
    int i;
    for(i=0;i<KCommander;i++)
    {
        Commanders[i]->Draw(Canvas,s,p);
    }
    TPoint d(XY.x*s+p.x,XY.y*s+p.y);
    Canvas->Rectangle(d.x-s/2,d.y-s/2,d.x+s/2,d.y+s/2);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
