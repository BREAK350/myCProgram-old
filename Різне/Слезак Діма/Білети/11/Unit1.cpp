//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include <iostream.h>
#include <conio.h>
#include <math.h>
//---------------------------------------------------------------------------
/*����� �11*/
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    char r[100];
    gets(r);
    int k=0,i=0;
    while(r[i])
    {
        if(r[i]>='0' && r[i]<='9')
        {
            k++;
        }
        i++;
    }
    cout<<k<<endl;
    getch();
    return 0;
}
//---------------------------------------------------------------------------
