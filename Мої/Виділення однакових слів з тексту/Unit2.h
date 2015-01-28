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
#define rozd ((a[i]==' ')||(a[i]==',')||(a[i]=='.')||(a[i]=='!')||(a[i]=='?')||(a[i]=='\t'))
#define rozd2 ((a[i]==';')||(a[i]==':')||(a[i]=='\n'))
//---------------------------------------------------------------------------
struct TTreeItem {
 char *word;
 TTreeItem *right,*left;
                 };
//---------------------------------------------------------------------------
class CTreeItem {
 private:
     char      *word;
     CTreeItem *right,
               *left;
 public:
     CTreeItem();
     ~CTreeItem();
     //void InsertItem(CTreeItem*);
                };
//---------------------------------------------------------------------------
void         _InsertItem(TTreeItem*&,TTreeItem*);
TTreeItem*   _CreateNewItem();
void         _AwardingItem(TTreeItem*&,char*,int,int);
void         _PrintItem(TTreeItem*);
void         _PrintTree(TTreeItem*);
void         _InsertItem(TTreeItem*&,char*&);
char*        _SeparateWord(char*,int,int);
void         _DestroyTree(TTreeItem*&);
void         _CreateTree(TTreeItem*&,char*);
void         _InsertItemWithoutRepetitions(TTreeItem*&,char*&);
int          Rozd(char);
void         _FPrintItem(TTreeItem*);
void         _FPrintTree(TTreeItem*);
//---------------------------------------------------------------------------
#endif
