//---------------------------------------------------------------------------
#pragma hdrstop
#include "list.h"
//---------------------------------------------------------------------------
#pragma argsused
int main(int argc, char* argv[])
{
 TList l;
 CreateList(l,5);
 PrintList(l,3);
 DeleteList(l);
 return 0;
}
//---------------------------------------------------------------------------
