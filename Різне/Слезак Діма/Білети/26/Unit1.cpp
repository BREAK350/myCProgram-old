//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include <iostream.h>
#include <conio.h>
#include <math.h>
//---------------------------------------------------------------------------
/*Білет №26*/
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    int num;
    cout<<"month=";
    cin>>num;
    if(num==1 || num==2 || num==12)
    {
        cout<<"Winter";
    }
    else
    if(num==3 || num==4 || num==5)
    {
        cout<<"Spring";
    }
    else
    if(num==6 || num==7 || num==8)
    {
        cout<<"Summer";
    }
    else
    if(num==9 || num==10 || num==11)
    {
        cout<<"Autumn";
    }
    else
    {
        cout<<"Error";
    }
    cout<<endl;
    getch();
    return 0;
}
//---------------------------------------------------------------------------
