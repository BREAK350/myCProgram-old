//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_List.h"
#pragma package(smart_init)
#include "T_Warrior.h"
#include "T_Minery.h"
//---------------------------------------------------------------------------
T_List::T_List()
{
    First=NULL;
    N=0;
    Picture=NULL;
}
//---------------------------------------------------------------------------
bool T_List::Add(T_Any_Object *ao)
{
    T_ListItem *p,*d,*s;
    if(First)
    {
        p=First;
        while(p && !(p->Object->isHere(ao->GetXY())))
        {
            p=p->Next;
        }
        if(p)
        {
            return false;
        }
        s=new T_ListItem;
        s->Object=ao;
        s->Next=First;
        First=s;
    }
    else
    {
        First=new T_ListItem;
        First->Object=ao;
    }
    return true;
}
//---------------------------------------------------------------------------
void T_List::Draw(TCanvas *Canvas,T_Point Centre,float s,float a)
{
    T_ListItem *p=First;
    while(p)
    {
        p->Object->Draw(Canvas,Centre,s,a);
        p=p->Next;
    }
}
//---------------------------------------------------------------------------
void T_List::Delete()
{
    int i;
    Delete(First);
    for(i=0;i<N;i++)
    {
        delete Picture[i];
        Picture[i]=NULL;
    }
    delete[] Picture;
    Picture=NULL;
    N=0;
}
//---------------------------------------------------------------------------
void T_List::Delete(T_ListItem *&Item)
{
    if(Item)
    {
        Delete(Item->Next);
        delete Item->Object;
        delete Item;
        Item=NULL;
    }
}
//---------------------------------------------------------------------------
void T_List::DeleteItem(T_ListItem *&Item)
{
    T_ListItem *p=First,*d=NULL;
    if(Item==NULL)
    {
        return;
    }
    while(p!=Item)
    {
        d=p;
        p=p->Next;
    }
    if(d)
    {
        d->Next=p->Next;
    }
    else
    {
        First=p->Next;
    }
    delete Item->Object;
    delete Item;
    Item=NULL;
}
//---------------------------------------------------------------------------
T_List::~T_List()
{
    Delete(First);
}
//---------------------------------------------------------------------------
void T_List::AfterBang(T_Bang Bang)
{
    T_ListItem *p=First;
    while(p)
    {
        p->Object->AfterBang(Bang);
        p=p->Next;
    }
}
//---------------------------------------------------------------------------
bool T_List::isHere(T_Point Point)
{
    return GetObject(Point);
}
//---------------------------------------------------------------------------
T_Any_Object* T_List::GetObject(T_Point Point)
{
    T_ListItem *p=First;
    while(p)
    {
        if(p->Object->isHere(Point))
        {
            return p->Object;
        }
        p=p->Next;
    }
    return NULL;
}
//---------------------------------------------------------------------------
void T_List::Check()
{
    T_ListItem *p=First,*d;
    while(p)
    {
        if(!p->Object->isLive())
        {
            d=p;
            p=p->Next;
            DeleteItem(d);
        }
        else
        {
            p=p->Next;
        }
    }
}
//---------------------------------------------------------------------------
void T_List::NextStep()
{
    T_ListItem *p=First;
    while(p)
    {
        p->Object->DoActive();
        p=p->Next;
    }
}
//---------------------------------------------------------------------------
void T_List::SaveToFile(char *fname)
{
    FILE *f;
    int n;
    f=fopen(fname,"wb");
    T_ListItem *p=First;
    while(p)
    {
        n=p->Object->nSaveToFile(f);
        p->Object->SaveToFile(f);
        p->Object->SavePicture(IntToStr(n).c_str());
        p=p->Next;
    }
    fclose(f);
}
//---------------------------------------------------------------------------
void T_List::LoadFromFile(char *fname)
{
    int n;
    FILE *f;
    T_Poligon *P;
    f=fopen(fname,"rb");
    T_Any_Object *ao;
    if(!f)
    {
        return;
    }
    Delete();
    while(fread(&n,sizeof(int),1,f)==1)
    {
        switch(n)
        {
            case nT_Warrior:
                ao=new T_Warrior;
                break;
            case nT_Minery:
                ao=new T_Minery;
                break;
        }
        ao->LoadFromFile(f);
        if(n>=N || Picture[n]==NULL)
        {
            P=new T_Poligon;
            P->LoadFromFile(IntToStr(n).c_str());
            AddPicture(P,n);
        }
        ao->SetPicture(Picture[n]);
        Add(ao);
    }
    fclose(f);
}
//---------------------------------------------------------------------------
int T_List::AddPicture(T_Poligon *p,int n)
{
    if(n<0)
    {
        return -1;
    }
    if(n<N)
    {
        Picture[n]=p;
    }
    else
    {
        int i;
        T_Poligon **buf=new T_Poligon*[N];
        for(i=0;i<N;i++)
        {
            buf[i]=Picture[i];
        }
        delete[] Picture;
        Picture=new T_Poligon*[n+1];
        for(i=0;i<N;i++)
        {
            Picture[i]=buf[i];
        }
        delete[] buf;
        for(;i<n;i++)
        {
            Picture[i]=NULL;
        }
        Picture[n]=p;
        N=n+1;
    }
    return n;
}
//---------------------------------------------------------------------------
