//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#endif
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <math.h>
#include <string.h>
//---------------------------------------------------------------------------

struct TAction {
 float value;
 TAction *next;
               };
struct TZn {
 TAction a;
 TZn *next;
           };
struct TValue {
 float a;
 int action;
 TValue *next;

              };
struct Tv {
 float a;
 int action;
 int level;
 Tv *next;
          };
struct action {
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
