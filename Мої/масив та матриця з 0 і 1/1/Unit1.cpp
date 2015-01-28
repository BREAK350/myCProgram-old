//---------------------------------------------------------------------------
#include <conio.h>
#pragma hdrstop
#include "masmatr01.h"
//---------------------------------------------------------------------------
mass01 m;
#pragma argsused
int main(int argc, char* argv[])
{
    int i,n=10;
    m.Create(n);
    m.PrintfAll();
    m.SetBit(5,1);
    printf("\n");
    m.PrintfAll();
    getch();
    return 0;
}
//---------------------------------------------------------------------------
 