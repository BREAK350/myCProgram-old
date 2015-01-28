//---------------------------------------------------------------------------
#ifndef MathFunctionH
#define MathFunctionH
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
//---------------------------------------------------------------------------
#define ifsin(i) if((a[i]=='s')&&(a[i+1]=='i')&&(a[i+2]=='n'))
#define ifcos(i) if((a[i]=='c')&&(a[i+1]=='o')&&(a[i+2]=='s'))
#define ifctg(i) if((a[i]=='c')&&(a[i+1]=='t')&&(a[i+2]=='g'))
#define iftg(i) if((a[i]=='t')&&(a[i+1]=='g'))
#define ifpow(i) if((a[i]=='p')&&(a[i+1]=='o')&&(a[i+2]=='w'))
#define ifln(i) if((a[i]=='l')&&(a[i]=='n'))
#define ifabs(i) if((a[i]=='a')&&(a[i+1]=='b')&&(a[i+2]=='s'))
#define gotoif(k,n) i+=k; tf=n; goto t;
//---------------------------------------------------------------------------
struct TActionF {
 int id;
 int kd;
               };
//---------------------------------------------------------------------------
int CheckFunction(int);
void BuildGraph(char*,int);
//---------------------------------------------------------------------------
float _ValueX(int,int);
float _NumberX(int,int);
float Value(char*,float);
//---------------------------------------------------------------------------
void StartProgram();
void Mathematical_expression();
void Function();
void TheProgramBeginsFILE();
//---------------------------------------------------------------------------
#endif
 
