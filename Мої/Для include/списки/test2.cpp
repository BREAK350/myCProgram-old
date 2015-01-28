//---------------------------------------------------------------------------
#pragma hdrstop
#include "list.h"
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
   int          er;
   TList        l;
   TListItem    *t,
                *p;
 CreateList(l,4);
 t=l.first;
 p=l.last;
 printf("***********************\n");
 InverseList(l,t,p);
 PrintList(l,5);
 PrintListConversely(l,5);
 printf("isList=%d\n",isList(l));
 getch();
 return 0;
}
//---------------------------------------------------------------------------

