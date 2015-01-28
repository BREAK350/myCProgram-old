//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
struct bits1{
 unsigned int b0:1,b1:1,b2:1,b3:1,b4:1,b5:1,b6:1,b7:1;
            };
struct bits233 {
 unsigned int b01:2,b24:3,b57:3;
               };
union sumbol {
 char s;
 bits1 bit;
 bits233 bit233;
             };
//---------------------------------------------------------------------------
void Encoder1(char&a)
{
 int p;
 sumbol d;
 d.s=a;
 p=d.bit.b0;
 d.bit.b0=d.bit.b1;
 d.bit.b1=d.bit.b2;
 d.bit.b2=d.bit.b3;
 d.bit.b3=d.bit.b4;
 d.bit.b4=d.bit.b5;
 d.bit.b5=d.bit.b6;
 d.bit.b6=d.bit.b7;
 d.bit.b7=p;
 a=d.s;
}
void Decoder1(char&a)
{
 int p;
 sumbol d;
 d.s=a;
 p=d.bit.b7;
 d.bit.b7=d.bit.b6;
 d.bit.b6=d.bit.b5;
 d.bit.b5=d.bit.b4;
 d.bit.b4=d.bit.b3;
 d.bit.b3=d.bit.b2;
 d.bit.b2=d.bit.b1;
 d.bit.b1=d.bit.b0;
 d.bit.b0=p;
 a=d.s;
}
void Print2(char a)
{
 sumbol s;
 s.s=a;
 printf("%c=(%d%d%d%d%d%d%d%d)\n",s.s,s.bit.b7,s.bit.b6,s.bit.b5,s.bit.b4,s.bit.b3,s.bit.b2,s.bit.b1,s.bit.b0);
}

void EncoderStr(char*&a)
{
 int i;
 i=0;
 while(a[i])
 {
  Encoder1(a[i]);
  i++;
 }
}

void DecoderStr(char*&a)
{
 int i;
 i=0;
 while(a[i])
 {
  Decoder1(a[i]);
  i++;
 }
}
//---------------------------------------------------------------------------

void En_Decoder233(char&a)
{
 int p;
 sumbol d;
 d.s=a;
 p=d.bit233.b24;
 d.bit233.b24=d.bit233.b57;
 d.bit233.b57=p;
 a=d.s;
}

void En_DecoderStr233(char*&a)
{
 int i;
 i=0;
 while(a[i])
 {
  En_Decoder233(a[i]);
  i++;
 }
}
