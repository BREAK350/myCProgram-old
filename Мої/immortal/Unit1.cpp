//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma argsused
#include "Unit2.h"
#include <conio.h>
#include <windows.h>
int main(int argc, char* argv[])
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    message mess("Words.txt");
    mess.ShowMess(-1);
    mess.ShowMess(0);
    mess.ShowMess(1);
    mess.ShowMess(2);
    getch();
    return 0;
}
//---------------------------------------------------------------------------
 