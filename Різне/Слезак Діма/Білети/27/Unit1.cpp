//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include <iostream.h>
#include <conio.h>
#include <math.h>
//---------------------------------------------------------------------------
/*����� �27*/
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    int n;
    cout<<"n=";
    cin>>n;
    float Y=0;
    for(int i=0;i<n;i++)
    {
        Y+=sin(i+1);
    }
    cout<<Y<<endl;
    getch();
    return 0;
}
//---------------------------------------------------------------------------
