//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma argsused
#include <iostream.h>
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    int *in,n,i;
    char s[]="(2+4)-5*(4-6)-2+(3-5)+0",*p;
    n=SearchTerms(s,in);
    for(i=0;i<n;i++)
    {
        cout<<&s[in[i]]<<endl;
    }
    system("pause");
    return 0;
}
//---------------------------------------------------------------------------
