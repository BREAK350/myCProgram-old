//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Commander.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Resource operator + (T_Resource l,T_Resource r)
{
    T_Resource d;
    d.Gold=l.Gold+r.Gold;
    d.Stone=l.Stone+r.Stone;
    d.Tree=l.Tree+r.Tree;
    d.Coal=l.Coal+r.Coal;
    d.Iron=l.Iron+r.Iron;
    return d;
}
//---------------------------------------------------------------------------
void T_Commander::AddCity(char *CityName)
{
    int i;
    T_City **Cities;
    Cities=new T_City*[LinkCity->LinkMap->KCity];
    for(i=0;i<LinkCity->LinkMap->KCity;i++)
    {
        Cities[i]=LinkCity->LinkMap->Cities[i];
    }
    delete LinkCity->LinkMap->Cities;
    LinkCity->LinkMap->KCity++;
    LinkCity->LinkMap->Cities=new T_City*[LinkCity->LinkMap->KCity];
    for(i=0;i<LinkCity->LinkMap->KCity-1;i++)
    {
        LinkCity->LinkMap->Cities[i]=Cities[i];
    }
    LinkCity->LinkMap->Cities[i]=new T_City(LinkCity->LinkMap,CityName,XY,Nation,T_Resource(),T_Resource(),T_Character(),0,NULL);
    delete Cities;
}
//---------------------------------------------------------------------------
T_Resource::T_Resource(float g,float s,float t,float c,float i)
{
    Gold=g;
    Stone=s;
    Tree=t;
    Coal=c;
    Iron=i;
}
//---------------------------------------------------------------------------
T_Resource::T_Resource()
{
    Gold=0;
    Stone=0;
    Tree=0;
    Coal=0;
    Iron=0;
}
//---------------------------------------------------------------------------
T_Commander::T_Commander():T_Warrior(),Resource()
{
    Nation=-1;
    KWarrior=0;
    Warriors=NULL;
}
//---------------------------------------------------------------------------
T_Commander::T_Commander(const T_Commander &c):T_Warrior(c)
{
    int i;
    Nation=c.Nation;
    Resource=c.Resource;
    KWarrior=c.KWarrior;
    Warriors=new T_Warrior*[KWarrior];
    for(i=0;i<KWarrior;i++)
    {
        Warriors[i]=new T_Warrior(*c.Warriors[i]);
    }
}
//---------------------------------------------------------------------------
T_Commander::T_Commander(char *name,TPoint p,T_Character c,int nation,T_Resource res,int k,T_Warrior **w)
                        :T_Warrior(name,p,c)
{
    int i;
    Nation=nation;
    Resource=res;
    KWarrior=k;
    Warriors=new T_Warrior*[KWarrior];
    for(i=0;i<KWarrior;i++)
    {
        Warriors[i]=new T_Warrior(*w[i]);
    }
}
//---------------------------------------------------------------------------
T_Commander::~T_Commander()
{
    int i;
    for(i=0;i<KWarrior;i++)
    {
        delete Warriors[i];
    }
    delete Warriors;
    Warriors=NULL;
    KWarrior=0;
}
//---------------------------------------------------------------------------
T_Commander& T_Commander::operator = (const T_Commander &c)
{
    int i;
    if(this==&c)
    {
        return *this;
    }
    T_Warrior::operator = (c);
    Nation=c.Nation;
    Resource=c.Resource;
    KWarrior=c.KWarrior;
    for(i=0;i<KWarrior;i++)
    {
        delete Warriors[i];
    }
    delete Warriors;
    Warriors=new T_Warrior*[KWarrior];
    for(i=0;i<KWarrior;i++)
    {
        Warriors[i]=new T_Warrior(*c.Warriors[i]);
    }
    return *this;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
