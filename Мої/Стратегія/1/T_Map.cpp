//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Map.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void T_Map::NextDay()
{
    int i;
    for(i=0;i<KCity;i++)
    {
        Cities[i]->UpResource();
    }
}
//---------------------------------------------------------------------------
T_City* T_Map::GetNextCity()
{
    while(CurrentCity<KCity && CurrentNation!=Cities[CurrentCity]->GetNation())
    {
        CurrentCity++;
    }
    if(CurrentCity>=KCity)
    {
        CurrentCity=0;
        NextNation();
        return NULL;
    }
    return Cities[CurrentCity];
}
//---------------------------------------------------------------------------
void T_Map::NextNation()
{
    CurrentNation++;
    if(CurrentNation>=AllNation)
    {
        CurrentNation=0;
        NextDay();
    }
}
//---------------------------------------------------------------------------
T_City* T_Map::GetCity(int k)
{
    if(k<0 || k>=KCity)
    {
        return NULL;
    }
    return Cities[k];
}
//---------------------------------------------------------------------------
T_Map::T_Map()
{
    Name=NULL;
    AllNation=0;
    KCity=0;
    Cities=NULL;
    CurrentNation=0;
    CurrentCity=0;
}
//---------------------------------------------------------------------------
T_Map::T_Map(const T_Map &m)
{
    int i;
    Name=strdup(m.Name);
    AllNation=m.AllNation;
    KCity=m.KCity;
    Cities=new T_City*[KCity];
    for(i=0;i<KCity;i++)
    {
        Cities[i]=new T_City(*m.Cities[i]);
    }
    CurrentNation=m.CurrentNation;
    CurrentCity=m.CurrentCity;
}
//---------------------------------------------------------------------------
T_Map::~T_Map()
{
    int i;
    delete Name;
    Name=NULL;
    for(i=0;i<KCity;i++)
    {
        delete Cities[i];
    }
    delete Cities;
    Cities=NULL;
    KCity=0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
