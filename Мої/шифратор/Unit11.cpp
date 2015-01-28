//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "Unit2.h"
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
 int i;
 FILE*f;
 f=fopen("encoder_information.txt","rt");
 if(f)
 {
  char a[256];
  fgets(a,256,f);
  En_DecoderStr233(a);
  fclose(f);
  puts(a);
 }
 else
  printf("Error!");
 getch();
 return 0;
}
//---------------------------------------------------------------------------
