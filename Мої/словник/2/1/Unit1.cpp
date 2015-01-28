//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "Lib.h"
#include <conio.h>
#pragma argsused
void Add(T_Lib_Words &Lib)
{
    char w[20];
    do
    {
        gets(w);
        Lib.AddWord(w);
    }
    while(w[0]);
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    T_Lib_Words Lib;
    Lib.LoadFromFile("Words.txt");
    Add(Lib);
    Lib.SaveToFile("Words.txt");
    cout<<Lib[7];
    getch();
    return 0;
}
//---------------------------------------------------------------------------
