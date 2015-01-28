//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "Unit2.h"
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
 int i;
 FILE*f;
 f=fopen("encoder_information.txt","wt");
 if(f)
 {
  char a[256];
  gets(a);
  En_DecoderStr233(a);
  fputs(a,f);
  fclose(f);
 }
 else
  printf("Error!");
 getch();
 return 0;
}
//---------------------------------------------------------------------------
