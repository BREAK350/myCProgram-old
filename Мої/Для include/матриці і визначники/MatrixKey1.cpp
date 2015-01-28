//---------------------------------------------------------------------------
#pragma hdrstop
#include "MatrixKey2.h"
//---------------------------------------------------------------------------
#pragma argsused
int main(int argc, char* argv[])
{
    TMatrix a,b,c;
    TKey v;
    ScanMatrix(a);
    PrintMatrix(a);
    v=MinorMatrix(a,1,1);
    PrintKey(v);
    getch();
    return 0;
}
//---------------------------------------------------------------------------
 