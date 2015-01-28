//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit3.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbPlural_char::TbPlural_char(const char *Item)
{
    if(Item)
    {
        Init(Item);
    }
    else
    {
        Nullify();
    }
}
//---------------------------------------------------------------------------
void TbPlural_char::Init(const char *Item)
{
    int i;
    New(strlen(Item));
    for(i=0;i<Count;i++)
    {
        this->Item[i]=Item[i];
    }
}
//---------------------------------------------------------------------------
void TbPlural_char::Nullify()
{
    Count=0;
    Item=NULL;
}
//---------------------------------------------------------------------------
void TbPlural_char::Delete()
{
    delete Item;
}
//---------------------------------------------------------------------------
TbPlural_char::~TbPlural_char()
{
    if(Item)
    {
        Delete();
        Nullify();
    }
}
//---------------------------------------------------------------------------
void TbPlural_char::New(const int &Count)
{
    this->Count=Count;
    this->Item=new char [this->Count];
}
//---------------------------------------------------------------------------
TbPlural_char TbPlural_char::Union(const TbPlural_char &Pl)const
{
    int n=Count,i=0;
    while(i<Pl.Count)
    {
        n+=!SearchItem(Pl.Item[i]);
        i++;
    }
    TbPlural_char res(n);
    for(i=0;i<Count;i++)
    {
        res.Item[i]=Item[i];
    }
    n=Count;
    i=0;
    while(i<Pl.Count)
    {
        if(!SearchItem(Pl.Item[i]))
        {
            res.Item[n]=Pl.Item[i];
            n++;
        }
        i++;
    }
    return res;
}
//---------------------------------------------------------------------------
int TbPlural_char::GetCommonItem(const TbPlural_char &Pl)const
{
    int n=0,i=0;
    while(i<Count)
    {
        n+=Pl.SearchItem(Item[i]);
        i++;
    }
    return n;
}
//---------------------------------------------------------------------------
TbPlural_char TbPlural_char::Cross(const TbPlural_char &Pl)const
{
    TbPlural_char res;
    int n=GetCommonItem(Pl),i=0;
    if(n>0)
    {
        res.New(n);
        i=0;
        n=0;
        while(i<Count)
        {
            if(Pl.SearchItem(Item[i]))
            {
                res.Item[n]=Item[i];
                n++;
            }
            i++;
        }
    }
    return res;
}
//---------------------------------------------------------------------------
bool TbPlural_char::SearchItem(const char &Item)const
{
    return GetItemPos(Item)!=-1;
}
//---------------------------------------------------------------------------
TbPlural_char::TbPlural_char(const char &Count)
{
    if(Count>0)
    {
        New(Count);
    }
    else
    {
        Nullify();
    }
}
//---------------------------------------------------------------------------
int TbPlural_char::GetItemPos(const char &Item)const
{
    int i=0;
    while(i<Count && this->Item[i]!=Item)
    {
        i++;
    }
    return (i>=Count)?(-1):(i);
}
//---------------------------------------------------------------------------
TbPlural_char TbPlural_char::Sub(const TbPlural_char &Pl)const
{
    TbPlural_char res;
    int n=0,i=0;
    while(i<Count)
    {
        n+=!Pl.SearchItem(Item[i]);
        i++;
    }
    if(n>0)
    {
        res.New(n);
        i=0;
        n=0;
        while(i<Count)
        {
            if(!Pl.SearchItem(Item[i]))
            {
                res.Item[n]=Item[i];
                n++;
            }
            i++;
        }
    }
    return res;
}
//---------------------------------------------------------------------------
TbPlural_char& TbPlural_char::operator = (const TbPlural_char &Pl)
{
    if(this!=&Pl)
    {
        if(Item)
        {
            Delete();
        }
        if(Pl.Count>0)
        {
            New(Pl.Count);
            int i=0;
            while(i<Pl.Count)
            {
                Item[i]=Pl.Item[i];
                i++;
            }
        }
        else
        {
            Nullify();
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
TbPlural_char::TbPlural_char(const TbPlural_char &Pl)
{
    if(Pl.Count>0)
    {
        New(Pl.Count);
        int i=0;
        while(i<Pl.Count)
        {
            Item[i]=Pl.Item[i];
            i++;
        }
    }
    else
    {
        Nullify();
    }
}
//---------------------------------------------------------------------------
char* TbPlural_char::GetStr()const
{
    int i=0;
    char *res=new char [Count+1];
    while(i<Count)
    {
        res[i]=Item[i];
        i++;
    }
    res[i]=0;
    return res;
}
//---------------------------------------------------------------------------
bool TbPlural_char::operator == (const TbPlural_char &Pl)const
{
    return GetCount()==Pl.GetCount() && GetCommonItem(Pl)==GetCount();
}
//---------------------------------------------------------------------------
bool TbPlural_char::operator != (const TbPlural_char &Pl)const
{
    return !(*this==Pl);
}
//---------------------------------------------------------------------------
TbPlural_char TbPlural_char::GetFirst(const int &Count)const
{
    TbPlural_char res;
    if(Count>0 && Count<this->Count)
    {
        res.New(Count);
        int i=0;
        while(i<Count)
        {
            res[i]=Item[i];
            i++;
        }
    }
    return res;
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

