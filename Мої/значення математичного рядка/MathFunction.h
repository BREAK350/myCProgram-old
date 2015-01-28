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
struct TAction {
 int id;
 int kd;
               };
//---------------------------------------------------------------------------
float _Value(char*,int,int);
float _Number(char*,int,int);
float Value(char*);
int CheckFunction(char*,int);
//---------------------------------------------------------------------------
float _ValueX(char*,int,int,float);
float _NumberX(char*,int,int,float);
float Value(char*,float);
//---------------------------------------------------------------------------
void StartProgram();
void Mathematical_expression();
void Function();
void TheProgramBeginsFILE();
//---------------------------------------------------------------------------
#endif

