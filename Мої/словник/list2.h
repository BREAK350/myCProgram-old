//---------------------------------------------------------------------------
#ifndef list2H
#define list2H
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include "Unit2.h"
//---------------------------------------------------------------------------
struct TInfo {
 TWord value;
             };
struct TListItem {
 TInfo info;
 TListItem *next,*prev;
                 };
struct TList {
 TListItem *first,*last;
             };
//---------------------------------------------------------------------------
void push_back(TList&,TInfo);
void push_back(TList&,TListItem*);
TInfo ScanInfo();
void CreateList(TList&,int);
//---------------------------------------------------------------------------
#endif
