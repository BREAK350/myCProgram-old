//---------------------------------------------------------------------------

#pragma hdrstop
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
 unsigned long int n,i;
 FILE*fp;
 char a[50],sb;
 printf("input file name: ");
 gets(a);
 printf("input n=");
 scanf("%d",&n);
 fp=fopen(a,"wt");
 for(i=0;i<n;i++)
 {
  sb='a'+random(26);
  fputc(sb,fp);
 }
 fclose(fp);
 return 0;
}
//---------------------------------------------------------------------------
