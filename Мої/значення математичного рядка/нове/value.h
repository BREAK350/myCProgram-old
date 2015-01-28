//---------------------------------------------------------------------------
#ifndef valueH
#define valueH
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define UC unsigned char
#define USI unsigned short int
#define TO TypeOperatciyi
#define Op Operatciya
#define PRYSV p.i=i;p.LS.level=d.level
//---------------------------------------------------------------------------
#define ifsin(i) ((a[i]=='s')&&(a[i+1]=='i')&&(a[i+2]=='n'))
#define ifcos(i) ((a[i]=='c')&&(a[i+1]=='o')&&(a[i+2]=='s'))
#define ifctg(i) ((a[i]=='c')&&(a[i+1]=='t')&&(a[i+2]=='g'))
#define iftg(i)  ((a[i]=='t')&&(a[i+1]=='g'))
#define ifpow(i) ((a[i]=='p')&&(a[i+1]=='o')&&(a[i+2]=='w'))
#define ifln(i)  ((a[i]=='l')&&(a[i]=='n'))
#define ifabs(i) ((a[i]=='a')&&(a[i+1]=='b')&&(a[i+2]=='s'))

#define if3f(i)  if(ifsin(i)||ifcos(i)||ifctg(i)||ifpow(i)||ifabs(i))
#define if2f(i)  if(iftg(i)||ifln(i))
//---------------------------------------------------------------------------
union LevelStarshynstvo {
 UC data;
 UC starshynstvo:2;
 UC level:6;
                        };
struct Operatciya {
 LevelStarshynstvo LS;
 UC i;
                  };
union Data {
 UC data;
 UC TypeOperatciyi:2;
 UC level:6;
            };
//---------------------------------------------------------------------------
float _Value(int,int);
float Value(char*,float);
#endif
