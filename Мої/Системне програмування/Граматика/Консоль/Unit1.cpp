//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "Unit2.h"
#include "Unit3.h"
#include <conio.h>
//---------------------------------------------------------------------------
void Test1()
{
    TbElement a('A');
    a.Print1();
    cout<<endl;
    a.Print2();
    cout<<endl;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    while(getchar()=='\n')
    {
        cout<<CreateRule(CreateStructOperandRight(1,1),CreateStructOperand(1,0))<<endl;
    }
    getch();
    return 0;
}
//---------------------------------------------------------------------------
 