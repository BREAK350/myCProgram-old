//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <string.h>
#define CreateNewItem()            _CreateNewItem()
#define AwardingItem(a,b,c,d)      _AwardingItem(a,b,c,d)
#define PrintItem(a)               _PrintItem(a)
#define PrintTree(a);              _PrintTree(a);
//---------------------------------------------------------------------------
struct TTreeItem
{
    char *word;
    TTreeItem *right,*left;
};
//---------------------------------------------------------------------------
void         _DestroyTree(TTreeItem*&);
int          Rozd(char);
void         _FPrintTree(TTreeItem*);
int         Search();
void        _InsertItemWithoutRepetitions(TTreeItem*&);
void        TrueWord();
//---------------------------------------------------------------------------
#endif
