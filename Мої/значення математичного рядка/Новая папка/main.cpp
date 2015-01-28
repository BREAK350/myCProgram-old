//---------------------------------------------------------------------------
#pragma hdrstop
#include "Value.h"
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
 float x;
 char X[100],f[100];
 printf("input f(x)=");
 gets(f);
 printf("input x=");
 gets(X);
 x=Value(X,0);
 printf("f(%f)=%f",x,Value(f,x));
 getch();
 return 0;
}
//---------------------------------------------------------------------------
