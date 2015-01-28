//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H

#include <stdio.h>
#include <alloc.h>
//---------------------------------------------------------------------------
struct TWord {
 int n_e,
     n_u;
 char **eng,
      **ukr;
             };
struct TListItem {
 TWord word;
 TListItem *next,*prev;
                 };
struct TListW {
 TListItem *first,*last;
             };
//---------------------------------------------------------------------------
TWord CreateWord(char*);
void PrintWord(TWord);
void push_back(TListW&,TWord);
void CreateList(TListW&,char*);
//---------------------------------------------------------------------------
#endif
