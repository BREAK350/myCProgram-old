//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include <iostream.h>
#include <conio.h>
#include <math.h>
//---------------------------------------------------------------------------
/*����� �2*/
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    float f[10];
    for(int i=0;i<10;i++)
    {
        cin>>f[i];
    }

    int k=0;
    for(int i=0;i<10;i++)
    {
        if(f[i]<0)
        {
            k++;
        }
    }
    cout<<k<<endl;
    getch();
    return 0;
}
//---------------------------------------------------------------------------
