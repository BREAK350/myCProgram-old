//---------------------------------------------------------------------------
#pragma hdrstop
#include "listfree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
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
void push_forward(TList &list,TListItem *t)
{
 if(list.first)
 {
  list.first->prev=t;
  t->prev=NULL;
  t->next=list.first;
  list.first=t;
 }
 else
 {
  list.first=t;
  t->next=t->prev=NULL;
  list.last=list.first;
 }
}
void PrintListConversely(TList list,int k)
{
 int i=0;
 TListItem *t;
 t=list.last;
 printf("\nList:\n");
 while(t)
  {
   printf("%d ",t->value);
   t=t->prev;
   i++;
   if(i>=k)
    {
     i=0;
     printf("\n");
    }
  }
 printf("\n");
}
void InverseList(TList &list)
{
 TListItem *t;
 t=list.first;
 if(t)
 {
  if(t->next)
  {
   t=t->next;
   while(t)
   {
    t->prev->next=t->prev->prev;
    t=t->next;
   }
   t=list.last;
   t->next=t->prev;
   t->prev=NULL;
   while(t->next)
   {
    t->next->prev=t;
    t=t->next;
   }
  }
  t=list.first;
  list.first=list.last;
  list.last=t;
 }
}
void InverseList(TList &list,TListItem *t1,TListItem *t2)
{
 TList l;
 TListItem *t;
 if((!t1)||(!t2))
  return;
 if((t1==t2)||(t1->next==t2)||(t1->next->next==t2))
  return;
 t=t1->next;
 t->prev=NULL;
 t=t2->prev;
 t->next=NULL;
 l.first=t1->next;
 l.last=t2->prev;
 PrintList(l,5);
 InverseList(l);
 PrintList(l,5);
 l.first->prev=t1;
 l.last->next=t2;
 t1->next=l.first;
 t2->prev=l.last;
}
void _DeleteList(TListItem*&t)
{
 if(t)
 {
  _DeleteList(t->next);
  free(t);
  t=NULL;
 }
}
void DeleteList(TList &list)
{
 _DeleteList(list.first);
 list.first=list.last=NULL;
}
void ConnectLists(TList &list1,TList &list2)
{
 if((list1.first)&&(list1.last)&&(list2.first)&&(list2.last))
 {
  list1.last->next=list2.first;
  list2.first->prev=list1.last;
 }
 else
 {
  if((!list1.first)&&(!list1.last))
  {
   list1.first=list2.first;
   list1.last=list2.last;
  }
 }
 list2.first=list2.last=NULL;
}
int DeleteItem(TList &list,TListItem *&t)
{
 TListItem *p;
 p=t;
 if(!t)
  return 0;
 if(!t->prev)
 {
  if(!t->next)
   list.first=list.last=NULL;
  else
  {
   list.first=p->next;
   p->next->prev=NULL;
   p->next=NULL;
  }
 }
 else
 {
  if(!t->next)
  {
   list.last=p->prev;
   p->prev->next=NULL;
   p->prev=NULL;
  }
  else
  {
   p->prev->next=p->next;
   p->next->prev=p->prev;
   p->next=NULL;
   p->prev=NULL;
  }
 }
 free(t);
 t=NULL;
 return 1;
}
int ExcludeItem(TList &list,TListItem *&t)
{
 TListItem *p;
 p=t;
 if(!t)
  return 0;
 if(!t->prev)
 {
  if(!t->next)
   list.first=list.last=NULL;
  else
  {
   list.first=p->next;
   p->next->prev=NULL;
   p->next=NULL;
  }
 }
 else
 {
  if(!t->next)
  {
   list.last=p->prev;
   p->prev->next=NULL;
   p->prev=NULL;
  }
  else
  {
   p->prev->next=p->next;
   p->next->prev=p->prev;
   p->next=NULL;
   p->prev=NULL;
  }
 }
 return 1;
}
int isList(TList list)
{
 TListItem *t;
 t=list.first;
 if(!t)
 {
  if((!list.last)&&(!list.first))
   return 1;
  return 0; 
 }
 if((!t->next)&&(!t->prev))
 {
  if(list.last==t)
   return 1;
  return -1;
 }
 t=t->next;
 while(t)
 {                               
  if(t!=t->prev->next)
   return 0;
  if(!t->next)
  {
   if(t==list.last)
    return 1;
   return -1;
  }
  t=t->next;
 }
 return -2;
}
//---------------------------------------------------------------------------
