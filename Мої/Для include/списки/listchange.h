//---------------------------------------------------------------------------
#ifndef listchangeH
#define listchangeH
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
//---------------------------------------------------------------------------
struct TInfo {
 int value;
             };
//---------------------------------------------------------------------------
void push_back(TList&,TInfo);
TInfo ScanInfo();
void CreateList(TList&,int);
//---------------------------------------------------------------------------
#endif
