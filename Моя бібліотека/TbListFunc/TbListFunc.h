//---------------------------------------------------------------------------
#ifndef TbListFuncH
#define TbListFuncH
#include <stdio.h>
//---------------------------------------------------------------------------
template <class TbListItem,class TData>
void AddNext1(TbListItem *Item,const TData &Data) // Item!=NULL && Item!=Last
{
    TbListItem *Next=Item->Next;
    Item->Next=new TbListItem(Data);
    Item->Next->Next=Next;
}
//---------------------------------------------------------------------------
template <class TbListItem,class TData>
void AddNext2(TbListItem *Item,const TData &Data) // Item!=NULL && Item!=Last
{
    AddNext1(Item,Data);
    Item->Next->Prev=Item;
    Item->Next->Next->Prev=Item->Next;
}
//---------------------------------------------------------------------------
template <class TbListItem,class TData>
void AddLast1(TbListItem *&Last,const TData  &Data) // Last!=NULL
{
    AddNext1(Last,Data);
    Last=Last->Next;
}
//---------------------------------------------------------------------------
template <class TbListItem,class TData>
void AddLast2(TbListItem *&Last,const TData  &Data) // Last!=NULL
{
    AddNext1(Last,Data);
    Last->Next->Prev=Last;
    Last=Last->Next;
}
//---------------------------------------------------------------------------
template <class TbListItem,class TData>
void AddFirst1(TbListItem *&First,const TData &Data) // First!=NULL
{
    TbListItem *Prev=new TbListItem(Data);
    Prev->Next=First;
    First=Prev;
}
//---------------------------------------------------------------------------
template <class TbListItem,class TData>
void AddFirst2(TbListItem *&First,const TData &Data) // First!=NULL
{
    TbListItem *Prev=new TbListItem(Data);
    Prev->Next=First;
    First->Prev=Prev;
    First=Prev;
}
//---------------------------------------------------------------------------
template <class TbListItem>
void DeleteItem(TbListItem *&Item) // Item!=NULL && Item!=First && Item!=Last
{
    Item->Prev->Next=Item->Next;
    Item->Next->Prev=Item->Prev;
    delete Item;
}
//---------------------------------------------------------------------------
template <class TbListItem>
void DeleteFirst(TbListItem *&First) // First!=NULL 
{
    TbListItem *del=First;
    First=First->Next;
    First->Prev=NULL;
    delete del;
}
//---------------------------------------------------------------------------
template <class TbListItem>
void DeleteLast(TbListItem *&Last) // Last!=NULL && Last!=First
{
    TbListItem *del=Last;
    Last=Last->Prev;
    Last->Next=NULL;
    delete del;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
