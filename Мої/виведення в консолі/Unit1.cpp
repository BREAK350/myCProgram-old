//---------------------------------------------------------------------------
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <string.h>
#pragma hdrstop
#define stand 10
//---------------------------------------------------------------------------
#pragma argsused
struct TChar {
 char a;
 TChar *next;
             };
struct TStr {
 int x:7,y:5;
 TChar *first;
            };
TStr CharToStr(char*a)
{
 int i;
 TStr str;
 TChar *t;
 i=0;
 while(a[i])
 {
  t=(TChar*)malloc(sizeof(TChar));
  t->a=a[i];
  t=t->next;
  i++;
 }
 for(i=0;i<4;i++)
  {
   t=(TChar*)malloc(sizeof(TChar));
   t->a=' ';
  }
  t->next=str.first;
 return str;
}
void PrintStr(TStr str)
{
 TChar *t;
 t=str.first;
 gotoxy(str.x,str.y);
 while(2>1)
 {
  putc(t->a,stdout);
  t=t->next;
  getch();
 }
}
int main(int argc, char* argv[])
{
 int i,n,g;
 char a[256];
 TStr str;
 str=CharToStr("0123456789abcdefghijklmnopqrstuvwxyz");
 PrintStr(str);
 getch();
 return 0;
}
//---------------------------------------------------------------------------
