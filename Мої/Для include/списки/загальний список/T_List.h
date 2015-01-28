//---------------------------------------------------------------------------
#ifndef T_ListH
#define T_ListH
#include <stdio.h>
typedef bool (*gT_ListCompare)(const void *,const void *);
template <class Type>
class gT_List;
/***************************************************************************/
/***************************class gT_ListItem*******************************/
/***************************************************************************/
template <class Type>
class gT_ListItem
{
    protected:
        friend gT_List <Type>;
        Type Data;
        gT_ListItem *Next;
    public:
        gT_ListItem(const Type &);
        gT_ListItem(const gT_ListItem &);
        ~gT_ListItem() { Next=NULL; }
};
//---------------------------------------------------------------------------
template <class Type>
gT_ListItem <Type>::gT_ListItem(const Type &d)
{
    Data=d;
    Next=NULL;
}
//---------------------------------------------------------------------------
template <class Type>
gT_ListItem <Type>::gT_ListItem(const gT_ListItem &gtli)
{
    Data=gtli.Data;
    Next=NULL;
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
/***************************************************************************/
/*****************************class gT_List*********************************/
/***************************************************************************/
template <class Type>
class gT_List //general T_List
{
    protected:
        int Amount,
            LastNumber;
        gT_ListItem <Type> *First,
            *LastItem;
        gT_ListCompare Compare;
        void Delete(gT_ListItem <Type> *&);
    public:
        gT_List(const gT_ListCompare);
        gT_List(const Type &,const gT_ListCompare);
        gT_List(const gT_List &);
        ~gT_List();
        bool Search(const Type &)const;
        bool Add(const Type &);
        bool Search(const gT_ListCompare,Type &)const;
        bool Delete(const gT_ListCompare,const Type &);
        Type* GetItem(const int &);
        Type* GetItem() { return GetItem(LastNumber); }
        Type* GetNextItem() { return GetItem(LastNumber+1); }
        int GetAmount() { return Amount; }
        int GetLastNumber() { return LastNumber; }
};
//---------------------------------------------------------------------------
template <class Type>
gT_List <Type>::gT_List(const gT_ListCompare compare)
{
    First=NULL;
    Amount=0;
    LastNumber=0;
    LastItem=First;
    Compare=compare;
}
//---------------------------------------------------------------------------
template <class Type>
gT_List <Type>::gT_List(const Type & d,const gT_ListCompare compare)
{
    First=new gT_ListItem <Type> (d);
    Amount=1;
    LastNumber=0;
    LastItem=First;
    Compare=compare;
}
//---------------------------------------------------------------------------
template <class Type>
gT_List <Type>::gT_List(const gT_List &List)
{
    gT_ListItem <Type> *t=List.First;
    while(t)
    {
        Add(t->Data);
        t=t->Next;
    }
    Compare=List.Compare;
    LastNumber=0;
    LastItem=First;
}
//---------------------------------------------------------------------------
template <class Type>
bool gT_List <Type>::Search(const Type &d)const
{
    gT_ListItem <Type> *t=First;
    while(t && Compare(&d,&t->Data)==false)
    {
        t=t->Next;
    }
    return t;
}
//---------------------------------------------------------------------------
template <class Type>
bool gT_List <Type>::Add(const Type &d)
{
    if(Search(d))
    {
        return false;
    }
    gT_ListItem <Type> *t=First;
    First=new gT_ListItem <Type> (d);
    First->Next=t;
    Amount++;
    LastNumber=0;
    LastItem=First;
    return true;
}
//---------------------------------------------------------------------------
template <class Type>
bool gT_List <Type>::Search(const gT_ListCompare lc,Type &d)const
{
    gT_ListItem <Type> *t=First;
    while(t && lc(&d,&t->Data)==false)
    {
        t=t->Next;
    }
    if(t)
    {
        d=t->Data;
    }
    return t;
}
//---------------------------------------------------------------------------
template <class Type>
bool gT_List <Type>::Delete(const gT_ListCompare lc,const Type &d)
{
    gT_ListItem <Type> *f=NULL,*t=First;
    while(t && lc(&d,&t->Data)==false)
    {
        f=t;
        t=t->Next;
    }
    if(t)
    {
        if(f)
        {
            f->Next=t->Next;
        }
        else
        {
            First=t->Next;
        }
        delete t;
        Amount--;
        LastNumber=0;
        LastItem=First;
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------
template <class Type>
gT_List <Type>::~gT_List()
{
    Delete(First);
}
//---------------------------------------------------------------------------
template <class Type>
void gT_List <Type>::Delete(gT_ListItem <Type> *&li)
{
    if(li)
    {
        Delete(li->Next);
        delete li;
        li=NULL;
    }
}
//---------------------------------------------------------------------------
template <class Type>
Type* gT_List <Type>::GetItem(const int &k)
{
    if(k>=Amount || k<0)
    {
        return NULL;
    }
    if(LastNumber>k)
    {
        LastItem=First;
        LastNumber=0;
    }
    while(LastNumber<k)
    {
        LastItem=LastItem->Next;
        LastNumber++;
    }
    return &LastItem->Data;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 