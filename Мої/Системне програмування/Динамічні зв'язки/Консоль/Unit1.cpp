//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "TbUFAd.h"
#include <iostream.h>
#include <conio.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    TbUFAd UFA;
    int Name=0;
    char s[100];
    while(1)
    {
        cout<<"s=";
        cin>>s;
        TbUFAd::CreateSimpleAutomaton(s,Name).print();
    }
    getch();
    return 0;
}
//---------------------------------------------------------------------------
 