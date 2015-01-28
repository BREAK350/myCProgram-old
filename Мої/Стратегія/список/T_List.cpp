//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_List.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_List::T_List()
{
    First=NULL;
    Simile=NULL;
}
//---------------------------------------------------------------------------
void T_List::Add(T_Any_Object *ao)
{
    if(First)
    {
        T_ListItem *p=First,*d=NULL,*s;
        while(p && Simile(ao,p->Object)>0)
        {
            d=p;
            p=p->Next;
        }
        s=new T_ListItem;
        if(d)
        {
            s->Object=ao;
            s->Next=p;
            d->Next=s;
        }
        else
        {
            First=new T_ListItem;
            First->Object=ao;
            First->Next=p;
        }
    }
    else
    {
        First=new T_ListItem;
        First->Object=ao;
        First->Next=NULL;
    }
}
//---------------------------------------------------------------------------
void T_List::Delete()
{
    Delete(First);
}
//---------------------------------------------------------------------------
void T_List::Delete(T_ListItem *&Item)
{
    if(Item)
    {
        Delete(Item->Next);
    }
    delete Item;
    Item=NULL;
}
//---------------------------------------------------------------------------
void T_List::DeleteItem(T_ListItem *&Item)
{
    T_ListItem *p=First,*d=NULL;
    while(p!=Item)
    {
        d=p;
        p=p->Next;
    }
    d->Next=p->Next;
    delete Item;
    Item=NULL;
}
//---------------------------------------------------------------------------
void T_List::Draw(TCanvas *Canvas,float s,float a)
{
    T_ListItem *p=First;
    while(p)
    {
        p->Object->Draw(Canvas,s,a);
        p=p->Next;
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
T_LIST::T_LIST()
{
    First=NULL;
    SimileX=SimileY=NULL;
}
//---------------------------------------------------------------------------
void T_LIST::Add(T_Any_Object *ao)
{
    if(First)
    {
        T_List_Item *p=First,*d=NULL,*s;
        while(p && SimileX(ao,p->List->First->Object)>0)
        {
            d=p;
            p=p->Next;
        }
        if(p!=NULL && SimileX(ao,p->List->First->Object)==0)
        {
            p->List->Add(ao);
            return;
        }
        if(d)
        {
            s=new T_List_Item;
            s->List->SetSimile(SimileY);
            s->List->Add(ao);
            s->Next=p;
            d->Next=s;
        }
        else
        {
            First=new T_List_Item;
            First->List->SetSimile(SimileY);
            First->List->Add(ao);
            First->Next=p;
        }
    }
    else
    {
        First=new T_List_Item;
        First->List->SetSimile(SimileY);
        First->List->Add(ao);
        First->Next=NULL;
    }
}
//---------------------------------------------------------------------------
void T_LIST::Draw(TCanvas *Canvas,float s,float a)
{
    T_List_Item *p=First;
    while(p)
    {
        p->List->Draw(Canvas,s,a);
        p=p->Next;
    }
}
//---------------------------------------------------------------------------
T_List_Item::T_List_Item()
{
    List=new T_List;
    Next=NULL;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
