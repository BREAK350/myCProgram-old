//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "TbList2.h"
#include <iostream.h>
#include <conio.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    TbList2 <int> List;
    int i;
    TbList2Iterator <int> il(List);
    for(i=0;i<10;i++)
    {
        List.Add(i);
    }
    il.SetFirst();
    while(il.Correct())
    {
        cout<<il.Get()<<endl;
        il.SetNext();
    }
    getch();
    return 0;
}
//---------------------------------------------------------------------------
 