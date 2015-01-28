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
bool T_Map::Control(TPoint p,EVENT e,int n)
{
    if(cCity)
    {
        if(cCommander)
        {
            if(cWarrior)
            {
                switch(e)
                {
                    case GO_BACK:
                        cWarrior=NULL;
                        break;
                    case MOVETO:
                        cWarrior->Move(p);
                        break;
                    case ATTACK:
                        cWarrior->Attack(EnemyCommander->SearchWarrior(p));
                        cWarrior->Attack(cCommander->SearchWarrior(p));
                        break;
                }
                return true;
            }
            switch(e)
            {
                case GO_BACK:
                    cCommander=NULL;
                    break;
                case GO_WARRIOR:
                    cWarrior=cCommander->SearchWarrior(p);
                    break;
                case MOVETO:
                    cCommander->Move(p);
                    break;
                case ATTACK:
                    EnemyCity=SearchCity(p);
                    if(!EnemyCity)
                    {
                        EnemyCommander=SearchCommander(p);
                    }
                    break;
            }
            return true;
        }
        switch(e)
        {
            case GO_BACK:
                cCity=NULL;
                break;
            case GO_COMMANDER:
                cCommander=cCity->SearchCommander(p);
                break;
        }
        return true;
    }
    switch(e)
    {
        case GO_CITY:
            cCity=SearchCity(p);
            break;
    }
    return true;
}
//---------------------------------------------------------------------------
T_City* T_Map::SearchCity(TPoint p)
{
    int i=0;
    while(i<KCity && !(Cities[i]->XY==p))
    {
        i++;
    }
    if(i>=KCity)
    {
        return NULL;
    }
    return Cities[i];
}
//---------------------------------------------------------------------------
T_Commander* T_Map::SearchCommander(TPoint p)
{
    int i=0;
    T_Commander *c;
    c=Cities[i]->SearchCommander(p);
    i++;
    while(i<KCity && c==NULL)
    {
        c=Cities[i]->SearchCommander(p);
        i++;
    }
    if(i>=KCity)
    {
        return NULL;
    }
    return c;
}
//---------------------------------------------------------------------------
void T_Map::Draw(TCanvas *Canvas,float s,TPoint p)
{
    int i;
    for(i=0;i<KCity;i++)
    {
        Cities[i]->Draw(Canvas,s,p);
    }
}
//---------------------------------------------------------------------------
void T_Map::Init()
{
    T_Commander **Com=new T_Commander*[1];
    Com[0]=new T_Commander("Com",TPoint(3,6),T_Character(0,0,0,0,10),1,T_Resource(100,100,100,100,100),0,NULL);
    Name=strdup("New");
    AllNation=1;
    KCity=1;
    Cities=new T_City*[1];
    Cities[0]=new T_City(this,"City",TPoint(5,10),1,T_Resource(1000,1000,1000,1000,1000),T_Resource(1000,1000,1000,1000,1000),T_Character(0,0,0,0,0),1,Com);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
