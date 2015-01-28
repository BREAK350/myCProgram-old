//---------------------------------------------------------------------------
#ifndef game1H
#define game1H
#include "Draw2D.h"
typedef detail Insect;
struct TInfo;
struct _TListItem;
struct _TList;
//---------------------------------------------------------------------------
struct TInfo
{
    Insect insect;
};
//---------------------------------------------------------------------------
struct _TListItem
{
    TInfo info;
    _TList *NextLevel;
    _TListItem *next,*prev;
};
//---------------------------------------------------------------------------
struct _TList
{
    _TListItem *first,*last;
};
//---------------------------------------------------------------------------
void push_back(_TList&,_TListItem*);
void _DeleteList(_TListItem*&);
void DeleteList(_TList&);
int DeleteItem(_TList&,_TListItem*&);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
