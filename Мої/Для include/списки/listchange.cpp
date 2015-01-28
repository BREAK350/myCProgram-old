//---------------------------------------------------------------------------
#pragma hdrstop
#include "listchange.h"
//---------------------------------------------------------------------------
void push_back(TList &list,TInfo v)
{
 if(list.last)
 {
  list.last->next=(TListItem*)malloc(sizeof(TListItem));
  list.last->next->info=v;
  list.last->next->next=NULL;
  list.last->next->prev=list.last;
  list.last=list.last->next;
 }
 else
 {
  list.first=(TListItem*)malloc(sizeof(TListItem));
  list.first->next=list.first->prev=NULL;
  list.first->info=v;
  list.last=list.first;
 }
}
void push_back(TList &list,TListItem *t)
{
 if(list.last)
 {
  list.last->next=t;
  t->next=NULL;
  t->prev=list.last;
  list.last=t;
 }
 else
 {
  list.first=t;
  t->next=t->prev=NULL;
  list.last=list.first;
 }
}
TInfo ScanInfo()
{
 TInfo v;
 scanf("%d",&v.value);
 return v;
}
void CreateList(TList &list,int n)
{
 int i;
 list.last=list.first=NULL;
 printf("Input list(%d elements)\n",n);
 for(i=0;i<n;i++)
  push_back(list,ScanInfo());
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
