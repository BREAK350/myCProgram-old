//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include <iostream.h>
#include <conio.h>
#include <math.h>
//---------------------------------------------------------------------------
/*Білет №9*/
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    float t,a,b,Y;
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    cout<<"t=";
    cin>>t;
    if(t<1)
    {
        Y=1;
    }
    else
    if(t<=2)
    {
        Y=a*t*t*log(t);
    }
    else
    {
        Y=exp(a*t)*cos(b*t);
    }
    cout<<Y<<endl;
    getch();
    return 0;
}
//---------------------------------------------------------------------------
