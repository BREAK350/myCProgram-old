//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include <iostream.h>
#include <conio.h>
#include <math.h>
//---------------------------------------------------------------------------
/*Білет №25*/
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    char s1,s2;
    char r[100];
    cout<<"ryadok: ";
    gets(r);
    cout<<"pershuy sumvol: ";
    cin>>s1;
    cout<<"dryguy sumvol: ";
    cin>>s2;
    int i=0;
    while(r[i])
    {
        if(r[i]==s1)
        {
            r[i]=s2;
        }
        i++;
    }
    cout<<"result: "<<r<<endl;
    getch();
    return 0;
}
//---------------------------------------------------------------------------
