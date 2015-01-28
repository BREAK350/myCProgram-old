//---------------------------------------------------------------------------
#ifndef MathFunction1H
#define MathFunction1H
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
//---------------------------------------------------------------------------
struct TAction {
 int id;
 int kd;
               };
//---------------------------------------------------------------------------
float _Value(int,int);
float _Number(int,int);
float Value();
int CheckFunction(int);
//---------------------------------------------------------------------------
float _ValueX(int,int,float);
float _NumberX(int,int,float);
float Value(float);
//---------------------------------------------------------------------------
void StartProgram();
void Mathematical_expression();
void Function();
void TheProgramBeginsFILE();
//---------------------------------------------------------------------------
#endif

