//---------------------------------------------------------------------------
#ifndef listH
#define listH
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
//---------------------------------------------------------------------------
struct TInfo {
 int        value;
             };
struct TListItem {
 TInfo      info;
 TListItem  *next,
            *prev;
                 };
struct TList {
 TListItem  *first,
            *last;
             };
//:::::::::::::::::::::
class CList {
 private:
         TList List;
 public:
        CList();
        void CreateList(int);

            };
//:::::::::::::::::::::
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
