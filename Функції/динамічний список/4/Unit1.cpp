//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "Unit2.h"
#include <windows.h>
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    TList L,R,S;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Input(L);
    PrintList(L);cout<<endl;
    S=ValueAtXPlusA(L,2);           
    PrintList(S);cout<<endl;
    system("Pause");
    return 0;
}
//---------------------------------------------------------------------------
