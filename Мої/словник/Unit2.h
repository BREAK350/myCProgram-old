//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H

#include <stdio.h>
#include <alloc.h>
#define MaxLines 20
#define maxtcol 6
//---------------------------------------------------------------------------
union UBit {
 char data;
 char _e:4,
      _u:4;
           };
struct TWord {
 char n_e,
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
TWord   CreateWord(char*);
void    PrintWord(TWord);
void    push_back(TListW&,TWord);
int     CreateList(TListW&,char*);
void    ShowWord(TListItem*);
void    ShowWordEng(TListItem*);
void    ShowWordUkr(TListItem*);
void    ShowWordOne(TListItem*,int);
//---------------------------------------------------------------------------
#endif
