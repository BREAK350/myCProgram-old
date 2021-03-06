//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbSet.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbSet::TbSet()
{
    Count=0;
    Elements=NULL;
}
//---------------------------------------------------------------------------
TbSet::TbSet(const TbSet &Set)
{
    Count=Set.Count;
    if(Count>0)
    {
        Elements=new int [Count];
        int i=0;
        while(i<Count)
        {
            Elements[i]=Set.Elements[i];
            i++;
        }
    }
    else
    {
        Elements=NULL;
    }
}
//---------------------------------------------------------------------------
TbSet::~TbSet()
{
    Clear();
}
//---------------------------------------------------------------------------
void TbSet::Clear()
{
    if(Count>0)
    {
        delete Elements;
        Elements=NULL;
        Count=0;
    }
}
//---------------------------------------------------------------------------
TbSet& TbSet::operator = (const TbSet &Set)
{
    if(this!=&Set)
    {
        if(Count>0)
        {
            delete Elements;
        }
        Count=Set.Count;
        if(Count>0)
        {
            Elements=new int [Count];
            int i=0;
            while(i<Count)
            {
                Elements[i]=Set.Elements[i];
                i++;
            }
        }
        else
        {
            Elements=NULL;
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
void TbSet::Add(const int &Element) // Element>=0
{
    if(!Search(Element))
    {
        if(Count>0)
        {
            TbSet buf=*this;
            delete Elements;
            Count++;
            Elements=new int [Count];
            int i=0;
            while(i<buf.Count && Element>buf.Elements[i])
            {
                Elements[i]=buf.Elements[i];
                i++;
            }
            Elements[i]=Element;
            i++;
            while(i<Count)
            {
                Elements[i]=buf.Elements[i-1];
                i++;
            }
        }
        else
        {
            Count=1;
            Elements=new int [Count];
            Elements[0]=Element;
        }
    }
}
//---------------------------------------------------------------------------
bool TbSet::Search(const int &Element)const
{
    int i=0;
    while(i<Count && Elements[i]!=Element)
    {
        i++;
    }
    return i<Count;
}
//---------------------------------------------------------------------------
int TbSet::GetCommon(const TbSet &Set)const
{
    int i=0,k=0;
    while(i<Count)
    {
        k+=Set.Search(Elements[i]);
        i++;
    }
    return k;
}
//---------------------------------------------------------------------------
void TbSet::Add(const TbSet &Set)
{
    int i=0;
    while(i<Set.Count)
    {
        this->Add(Set.Elements[i]);
        i++;
    }
}
//---------------------------------------------------------------------------
void TbSet::Print()const
{
    int i=0;
    while(i<Count-1)
    {
        cout<<Elements[i]<<';';
        i++;
    }
    if(i==Count-1)
    {
        cout<<Elements[i];
    }
}
//---------------------------------------------------------------------------
TbSet TbSet::operator + (const int &Element)const
{
    TbSet res;
    if(!Search(Element))
    {
        if(Count>0)
        {
            res.Count=Count+1;
            res.Elements=new int [res.Count];
            int i=0;
            while(i<res.Count && Element>Elements[i])
            {
                res.Elements[i]=Elements[i];
                i++;
            }
            res.Elements[i]=Element;
            i++;
            while(i<res.Count)
            {
                res.Elements[i]=Elements[i-1];
                i++;
            }
        }
        else
        {
            res.Count=1;
            res.Elements=new int [Count];
            res.Elements[0]=Element;
        }
    }
    else
    {
        res=*this;
    }
    return res;
}
//---------------------------------------------------------------------------
TbSet TbSet::operator + (const TbSet &Set)const
{
    TbSet res=*this;
    res.Add(Set);
    return res;
}
//---------------------------------------------------------------------------
const int* TbSet::GetElements()const
{
    return Elements;
}
//---------------------------------------------------------------------------
int TbSet::GetCount()const
{
    return Count;
}
//---------------------------------------------------------------------------
int TbSet::GetIndex(const int &Element)const
{
    int i=0;
    while(i<Count && Elements[i]!=Element)
    {
        i++;
    }
    return (i<Count)?(i):(-1);
}
//---------------------------------------------------------------------------
void TbSet::Shift(const int &ShiftTo)
{
    for(int i=0;i<Count;i++)
    {
        Elements[i]+=ShiftTo;
    }
}
//---------------------------------------------------------------------------
bool TbSet::operator == (const TbSet &Set)const
{
    bool res=Count==Set.Count;
    if(res)
    {
        int i=0;
        while(i<Count && res)
        {
            res=Elements[i]==Set.Elements[i];
            i++;
        }
    }
    return res;
}
//---------------------------------------------------------------------------
bool TbSet::isEmpty()const
{
    return Count==0;
}
//---------------------------------------------------------------------------
bool TbSet::operator != (const TbSet &Set)const
{
    return !(*this==Set);
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
