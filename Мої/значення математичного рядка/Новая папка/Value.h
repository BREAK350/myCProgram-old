//---------------------------------------------------------------------------

#ifndef ValueH
#define ValueH
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <math.h>
#include <string.h>
//---------------------------------------------------------------------------
#define iftg     if((a[d_l-1]=='g')&&(a[d_l-2]=='t'))
#define ifsin    if((a[d_l-1]=='n')&&(a[d_l-2]=='i')&&(a[d_l-3]=='s'))
#define ifcos    if((a[d_l-1]=='s')&&(a[d_l-2]=='o')&&(a[d_l-3]=='c'))
#define ifabs    if((a[d_l-1]=='s')&&(a[d_l-2]=='b')&&(a[d_l-3]=='a'))
#define ifln     if((a[d_l-1]=='g')&&(a[d_l-2]=='o')&&(a[d_l-3]=='l'))
#define ifexp    if((a[d_l-1]=='p')&&(a[d_l-2]=='x')&&(a[d_l-3]=='e'))
#define ifsqrt   if((a[d_l-1]=='t')&&(a[d_l-2]=='r')&&(a[d_l-3]=='q')&&(a[d_l-4]=='s'))
#define ifasin   if((a[d_l-1]=='n')&&(a[d_l-2]=='i')&&(a[d_l-3]=='s')&&(a[d_l-4]=='a'))
#define ifacos   if((a[d_l-1]=='s')&&(a[d_l-2]=='o')&&(a[d_l-3]=='c')&&(a[d_l-4]=='a'))
//---------------------------------------------------------------------------
float      Value(char*,float);
float      _Value(int,int);
int        Skip(int,int);
float      _Number(int,int);
//---------------------------------------------------------------------------
#endif
