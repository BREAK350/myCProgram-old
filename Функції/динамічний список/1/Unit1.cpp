//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "TlistH.h"
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    int a;
    mTList list;
    cout<<"do {...} while(a!=-1);\n";
    do
    {
        cout<<"a=";
        cin>>a;
        list.CreateNewItem(a);
        list.ShowConsol();
        cout<<endl;
    }while(a!=-1);
    return 0;
}
//---------------------------------------------------------------------------
