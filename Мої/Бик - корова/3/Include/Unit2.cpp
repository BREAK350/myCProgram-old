//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbGame::TbGame()
{
    nStep=0;
    nSet=1;
    nDigit=10;
    int i;
    for(i=0;i<10;i++)
    {
        Digit[i]='0'+i;
        Set[0][i]=1;
    }
    Set[0][10]=4;
}
//---------------------------------------------------------------------------
void TbGame::SetSub(const int &i,const int &j,const int &r)
{
    int k=0;
    while(k<10)
    {
        if(Set[i][k]==1)
        {
            
        }
        k++;
    }
}
//---------------------------------------------------------------------------
bool TbGame::SetEquals(const int &i,const int &j)const
{
    bool res=true;
    int k=0;
    while(k<10 && res)
    {
        res=(Set[i][k]==Set[j][k]);
        k++;
    }
    return res;
}
//---------------------------------------------------------------------------
int TbGame::SetGetCommon(const int &i,const int &j)const
{
    int n=0,k=0;
    while(k<10)
    {
        n+=(Set[i][k]==Set[j][k] && Set[i][k]==1);
        k++;
    }
    return n;
}
//---------------------------------------------------------------------------
int TbGame::SetGetCount(const int &i)const
{
    int k=0,n=0;
    while(k<10)
    {
        n+=Set[i][k];
        k++;
    }
    return n;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void Add(TbCPlural_char *Set,int &n,const TbCPlural_char &pl) // Set!=NULL
{
    if(pl.GetCount()>0 && pl.GetFound()>0)
    {
        int i=0;
        TbCPlural_char buf;
        bool used=false;
        while(i<n && pl!=Set[i])
        {
            if((Set[i]*pl).GetCount()==pl.GetCount())
            {
                buf=Set[i]-pl;
                buf.Found=Set[i].Found-pl.Found;
                Set[i]=pl;
                Add(Set,n,buf);
                used=true;
            }
            else
            if((Set[i]*pl).GetCount()==Set[i].GetCount())
            {
                buf=pl-Set[i];
                buf.Found=pl.Found-Set[i].Found;
                Add(Set,n,buf);
                used=true;
            }
            i++;
        }
        if(i>=n && !used)
        {
            Set[n]=pl;
            n++;
        }
    }
}
//---------------------------------------------------------------------------
void Delete(TbCPlural_char *Set,int &n,const TbCPlural_char &pl) // Set!=NULL
{
    if(pl.GetCount()>0)
    {
        int i=0;
        while(i<n)
        {
            Set[i]=Set[i]-pl;
            if(Set[i].GetCount()==0)
            {
                int j=i;
                while(j<n-1)
                {
                    Set[j]=Set[j+1];
                    j++;
                }
            }
            i++;
        }
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 