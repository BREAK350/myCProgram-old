//---------------------------------------------------------------------------

#pragma hdrstop
#include "Unit2.h"
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
polinom f,g,q,r;
ScanPolynomial(f);
ScanPolynomial(g);
Division(f,g,q,r);
printf("\nafter division\n");
PrintPolynomial(q);
PrintPolynomial(r);
getch();
return 0;
}
//---------------------------------------------------------------------------





