//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include <windows.h>
#include "English.h"
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char *ukr[]={"назовні","ззовні"};
    word w("out",2,ukr);
    cout<<w<<endl;
    system("pause");
    return 0;
}
//---------------------------------------------------------------------------
 