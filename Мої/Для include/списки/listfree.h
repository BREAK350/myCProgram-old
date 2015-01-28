//---------------------------------------------------------------------------
#ifndef listfreeH
#define listfreeH
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include "listchange.h"
//---------------------------------------------------------------------------
struct TListItem {
 TInfo info;
 TListItem *next,*prev;
                 };
struct TList {
 TListItem *first,*last;
             };
//---------------------------------------------------------------------------
/*__int__*/
void push_back(TList&,TListItem*);
void push_forward(TList&,int);
void push_forward(TList&,TListItem*);
void CreateList(TList&,int);
void PrintList(TList,int);
void PrintListConversely(TList,int);
void InverseList(TList&);
void InverseList(TList&,TListItem*,TListItem*);
void _DeleteList(TListItem*&);
void DeleteList(TList&);
void ConnectLists(TList&,TList&);
int DeleteItem(TList&,TListItem*&);
int ExcludeItem(TList&,TListItem*&);
int isList(TList);
//---------------------------------------------------------------------------
#endif
