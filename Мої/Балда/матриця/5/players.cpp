//---------------------------------------------------------------------------
#pragma hdrstop
#include "players.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Players::T_Players(const int &n)
{
    N=(n>1)?(n):(1);
    Player=new T_Player[N];
    Curr=0;
}
//---------------------------------------------------------------------------
T_Players::T_Players()
{
    N=2;
    Player=new T_Player[N];
    Curr=0;
}
//---------------------------------------------------------------------------
T_Players::~T_Players()
{
    delete Player;
    Player=NULL;
    N=Curr=0;
}
//---------------------------------------------------------------------------
T_Player* T_Players::GetCurrPlayer()
{
    T_Player *r;
    if(Curr>=N)
    {
        Curr=0;
    }
    r=&Player[Curr];
    Curr+=1;
    return r;
}
//---------------------------------------------------------------------------
void T_Players::SetN(const int &n)
{
    delete Player;
    N=(n>1)?(n):(1);
    Player=new T_Player[N];
    Curr=0;
}
//---------------------------------------------------------------------------
T_Player* T_Players::GetPlayer(const int &i)
{
    T_Player *r=NULL;
    if(i>=0 && i<N)
    {
        r=&Player[i];
    }
    return r;
}
//---------------------------------------------------------------------------
void T_Players::SaveToFile(ofstream &ofs)
{
    int i;
    ofs<<N<<' '<<Curr<<endl;
    for(i=0;i<N;++i)
    {
        ofs<<Player[i].Name<<endl<<Player[i].Symbols<<endl;
    }
}
//---------------------------------------------------------------------------
void T_Players::LoadFromFile(ifstream &ifs)
{
    int i,n;
    ifs>>n>>Curr;
    SetN(n);
    for(i=0;i<N;++i)
    {
        ifs>>Player[i].Name>>Player[i].Symbols;
    }
}
//---------------------------------------------------------------------------
void T_Player::GetWord(T_SWBA &SWBA,T_Words &Words,T_Balda &Balda)
{
    char *w;
    int i=0,n=Dictionary.GetN();
    SWBA.Q=0;
    while(i<n && SWBA.Q==0)
    {
        if(Words.Search(Dictionary[i])==0)
        {
            T_SWBA _SWBA(Dictionary[i]);
            Balda.AddWord(_SWBA,FOUR);
            if(_SWBA.Q==1)
            {
                SWBA=_SWBA;
                Words.Write(Dictionary[i]);
            }
        }
        i++;
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
