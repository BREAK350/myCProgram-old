//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void T_Room::AddDoor(pT_Door door)
{
    int i;
    pT_Door *buf=new pT_Door[N];
    for(i=0;i<N;i++)
    {
        buf[i]=Door[i];
    }
    delete[] Door;
    Door=new pT_Door[N+1];
    for(i=0;i<N;i++)
    {
        Door[i]=buf[i];
    }
    Door[i]=door;
    delete[] buf;
    buf=NULL;
    N+=1;
}
//---------------------------------------------------------------------------
T_Door::T_Door()
{
    Max=a=0;
    Number=0;
    First=Second=NULL;
}
//---------------------------------------------------------------------------
void T_Door::Init(const int &n,const int &_a,pT_Room f,pT_Room s)
{
    Max=a=(_a>0)?(_a):(0);
    Number=n;
    First=f;
    Second=s;
}
//---------------------------------------------------------------------------
pT_Room T_Door::Go(pT_Room room)
{
    if(CanGo())
    {
        if(room==First)
        {
            a--;
            return Second;
        }
        if(room==Second)
        {
            a--;
            return First;
        }
    }
    return NULL;
}
//---------------------------------------------------------------------------
void T_Room::Go(int *list,const int j,const int &N,int &k)
{
    int i;
    pT_Room r;
    for(i=0;i<N;i++)
    {
        if(k<N)
        {
            r=Door[i]->Go(this);
            if(r)
            {
                list[j]=Number;
                r->Go(list,j+1,N,k=j+1);
            }
            Door[i]->Restore();
        }
    }
}
//---------------------------------------------------------------------------
int T_Room::Cango()
{
    int s=0,i;
    for(i=0;i<N;i++)
    {
        s+=Door[i]->CanGo();
    }
    return s;
}
//---------------------------------------------------------------------------
T_Puzzle::T_Puzzle()
{
    nDoor=nRoom=0;
    Door=NULL;
    Room=NULL;
}
//---------------------------------------------------------------------------
T_Puzzle::T_Puzzle(const int &d,const int &r)
{
    nDoor=d;
    nRoom=r;
    Door=new T_Door[nDoor];
    Room=new T_Room[nRoom];
}
//---------------------------------------------------------------------------
T_Puzzle::~T_Puzzle()
{
    delete[] Door;
    delete[] Room;
    nDoor=nRoom=0;
    Door=NULL;
    Room=NULL;
}
//---------------------------------------------------------------------------
void T_Door::Restore()
{
    a=Max;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 