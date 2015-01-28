//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_BattleGround.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_BattleGround::T_BattleGround()
{
    NMembers=NNation=0;
    CurrentNation=0;
    CurrentMember=-1;
    Members=NULL;
}
//---------------------------------------------------------------------------
T_Members::T_Members(int n,T_Any_Warrior **aw)
{
    NMembers=n;
    Members=aw;
}
//---------------------------------------------------------------------------
T_Members::~T_Members()
{
    NMembers=0;
    Members=NULL;
}
//---------------------------------------------------------------------------
T_BattleGround::T_BattleGround(int n,T_Members *M,...)
{
    int i,j,k;
    T_Members *p;
    if(n<1)
    {
        Members=NULL;
        return;
    }
    NNation=n;
    NMembers=0;
    p=M;
    for(i=0;i<n;i++)
    {
        NMembers+=p->NMembers;
        p++;
    }
    Members=new T_MemberOfFight[NMembers];
    p=M;
    i=0;
    j=0;
    while(i<n)
    {
        k=0;
        while(k<p->NMembers)
        {
            Members[j].Nation=i;
            Members[j].p=p->Members[k];
            k++;
            j++;
        }
        i++;
        p++;
    }
    CurrentNation=0;
    CurrentMember=-1;
}
//---------------------------------------------------------------------------
T_BattleGround::~T_BattleGround()
{
    NMembers=NNation=0;
    delete Members;
    Members=NULL;
}
//---------------------------------------------------------------------------
T_BattleGround::T_BattleGround(const T_BattleGround &bg)
{
    int i;
    NMembers=bg.NMembers;
    NNation=bg.NNation;
    CurrentNation=bg.CurrentNation;
    CurrentMember=bg.CurrentMember;
    Members=new T_MemberOfFight[NMembers];
    for(i=0;i<NMembers;i++)
    {
        Members[i]=bg.Members[i];
    }
}
//---------------------------------------------------------------------------
T_BattleGround& T_BattleGround::operator = (const T_BattleGround &bg)
{
    int i;
    if(this==&bg)
    {
        return *this;
    }
    delete Members;
    NMembers=bg.NMembers;
    NNation=bg.NNation;
    Members=new T_MemberOfFight[NMembers];
    for(i=0;i<NMembers;i++)
    {
        Members[i]=bg.Members[i];
    }
    CurrentNation=bg.CurrentNation;
    CurrentMember=bg.CurrentMember;
    return *this;
}
//---------------------------------------------------------------------------
void T_BattleGround::Draw(TCanvas *Canvas,TPoint p,float s)
{
    int i;
    for(i=0;i<NMembers;i++)
    {
        Members[i].p->Draw(Canvas,p,s);
    }
}
//---------------------------------------------------------------------------
int T_BattleGround::SearchMember(TPoint p)
{
    int i=0;
    while(i<NMembers)
    {
        if(Members[i].p->XY==p)
        {
            if(Members[i].p->isLive())
            {
                return i;
            }
            return -1;
        }
        i++;
    }
    if(i>=NMembers)
    {
        return -1;
    }
    return i;
}
//---------------------------------------------------------------------------
bool operator == (TPoint p1,TPoint p2)
{
    return (p1.x==p2.x && p1.y==p2.y);
}
//---------------------------------------------------------------------------
bool T_BattleGround::Battle(int n1,int n2)
{
    if(n1<0 || n2<0 || n1==n2)
    {
        return false;
    }
    Members[n1].p->Attack(Members[n2].p,T_Character(0,0,0,0,0));
    return true;
}
//---------------------------------------------------------------------------
void T_BattleGround::NextNation()
{
    int i;
    CurrentNation++;
    if(CurrentNation>=NNation)
    {
        CurrentNation=0;
    }
    for(i=0;i<NMembers;i++)
    {
        Members[i].p->DoActive();
    }
}
//---------------------------------------------------------------------------
void T_BattleGround::Init(int n,T_Members *M,...)
{
    int i,j,k;
    T_Members *p;
    if(n<1)
    {
        return;
    }
    NNation=n;
    NMembers=0;
    p=M;
    for(i=0;i<n;i++)
    {
        NMembers+=p->NMembers;
        p++;
    }
    Members=new T_MemberOfFight[NMembers];
    p=M;
    i=0;
    j=0;
    while(i<n)
    {
        k=0;
        while(k<p->NMembers)
        {
            Members[j].Nation=i;
            Members[j].p=p->Members[k];
            k++;
            j++;
        }
        i++;
        p++;
    }
    CurrentNation=CurrentMember=0;
}
//---------------------------------------------------------------------------
bool T_BattleGround::ChooseMember(TPoint p)
{
    int k;
    k=SearchMember(p);
    if(k<0 || Members[k].Nation!=CurrentNation)
    {
        return false;
    }
    CurrentMember=k;
    return true;
}
//---------------------------------------------------------------------------
bool T_BattleGround::MoveTo(TPoint p)
{
    if(CurrentMember<0 || SearchMember(p)>=0)
    {
        return false;
    }
    Members[CurrentMember].p->Move(p);
    return true;
}
//---------------------------------------------------------------------------
bool T_BattleGround::Attack(TPoint p)
{
    return Battle(CurrentMember,SearchMember(p));
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
