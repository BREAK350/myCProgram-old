//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
//---------------------------------------------------------------------------
#endif
struct polinom {
int st;
float *k;
               };

int Division(float*,int,float*,int,float*&,float*&);
int ScanPolynomial(float*&);
void PrintPolynomial(float*,int);
void ScanPolynomial(polinom&);
void PrintPolynomial(polinom);
void Division(polinom,polinom,polinom&,polinom&);
