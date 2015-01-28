//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_City::T_City()
{
    x=0;
    y=0;
    Nationality=-1;
    Population=0;
    Gold=0;
    GoldMining=0;
    AmountArmy=0;
    LevelOfMedicine=0;
    AmountEntrance=2;
    for(int i=0;i<MAX_DIFFERENT_ENTRANCE;i++)
    {
        CityLink[i]=0;
    }
}
//---------------------------------------------------------------------------
T_Warrior::T_Warrior()
{
    idWN=0;
    Amount=0;
    Efficiency=0;
}
//---------------------------------------------------------------------------
int T_Game::isCityFriendly(const T_City *City1,const T_City *City2)
{
    return Union[City1->Nationality][City2->Nationality];
}
//---------------------------------------------------------------------------
int T_Game::MovingArmy(T_City *CityFrom,const int &idArmy,T_City *CityTo)
{
    int q=isCityFriendly(CityFrom,CityTo);
    if(q)
    {
        if(CityTo->AmountArmy<MAX_DIFFERENT_ARMY)
        {
            int i=0;
            while(i<MAX_DIFFERENT_ARMY && CityTo->Army[i].AmountWarrior!=0)
            {
                i++;
            }
            CityTo->Army[i]=CityFrom->Army[idArmy];
            CityFrom->Army[idArmy]=T_Army();
            CityFrom->AmountArmy--;
        }
    }
    return q;
}
//---------------------------------------------------------------------------
int T_Game::isUnionWarrior(const T_Warrior &Warrior1,const T_Warrior &Warrior2)
{
    return Warrior1.idWN==Warrior2.idWN && Warrior1.Efficiency==Warrior2.Efficiency;
}
//---------------------------------------------------------------------------
int T_Game::AddCity(const int &nationality,const int &_x,const int &_y)
{
    int i=-1;
    if(AmountCity<MAX_DIFFERENT_CITY)
    {
        i=0;
        while(i<MAX_DIFFERENT_CITY && City[i].Nationality!=-1)
        {
            i++;
        }
        City[i].Nationality=nationality;
        City[i].x=_x;
        City[i].y=_y;
        AmountCity++;
    }
    return i;
}
//---------------------------------------------------------------------------
int T_Game::UnionWarrior(T_Warrior &Warrior1,T_Warrior &Warrior2)
{
    int q=isUnionWarrior(Warrior1,Warrior2);
    if(q)
    {
        Warrior1.Amount+=Warrior2.Amount;
        Warrior2.idWN=0;
        Warrior2.Amount=0;
        Warrior2.Efficiency=0;
    }
    return q;
}
//---------------------------------------------------------------------------
void T_Game::DrawCity(TCanvas *Canvas)
{
    int i;
    for(i=0;i<MAX_DIFFERENT_CITY;i++)
    {
        if(City[i].Nationality!=-1)
        {
            Canvas->Ellipse(City[i].x-5,City[i].y-5,City[i].x+5,City[i].y+5);
        }
    }
}
//---------------------------------------------------------------------------
void T_Game::DrawCityLink(TCanvas *Canvas)
{
    int i,j;
    for(i=0;i<MAX_DIFFERENT_CITY;i++)
    {
        if(City[i].Nationality!=-1)
        {
            for(j=0;j<MAX_DIFFERENT_ENTRANCE;j++)
            {
                if(City[i].CityLink[j])
                {
                    Canvas->MoveTo(City[i].x,City[i].y);
                    Canvas->LineTo(City[i].CityLink[j]->x,City[i].CityLink[j]->y);
                }
            }
        }
    }
}
//---------------------------------------------------------------------------
int T_Game::isFreeEntrance(const T_City *City)
{
    return City->AmountEntrance<MAX_DIFFERENT_ENTRANCE;
}
//---------------------------------------------------------------------------
int T_Game::UnionCity(T_City *City1,T_City *City2)
{
    int q=isFreeEntrance(City1) && isFreeEntrance(City2);
    if(q)
    {
        int i=0;
        while(i<MAX_DIFFERENT_ENTRANCE && City1->CityLink[i])
        {
            i++;
        }
        City1->CityLink[i]=City2;
        i=0;
        while(i<MAX_DIFFERENT_ENTRANCE && City2->CityLink[i])
        {
            i++;
        }
        City2->CityLink[i]=City1;
    }
    return q;
}
//---------------------------------------------------------------------------
int T_Game::UnionCity(const int &City1,const int &City2)
{
    return UnionCity(&City[City1],&City[City2]);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
