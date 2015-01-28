//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbList2.h"
#pragma argsused
#include <iostream.h>
#include <conio.h>
//---------------------------------------------------------------------------
int Compare(const void *arg1,const void *arg2)
{
    int a=*(int*)arg1,
        b=*(int*)arg2;
    return (a>b)?(1):((a<b)?(-1):(0));
}
//---------------------------------------------------------------------------
void Test1()
{
    TbList2 <float> L;
    L.AddFirst(2.0);
    L.AddLast(4.0);
    L.CurrSetFirst();
    float c=L.GetCurr();
}
//---------------------------------------------------------------------------
void Test2()
{
    TbSortList2 <int> L(Compare);
    L.Add(2);
    L.Add(3);
    L.Add(1);
    L.Add(6);
    L.Add(-13);
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    while(1) Test2();
    TbSortList2 <int> L(Compare);
    L.Add(2);
    L.Add(3);
    L.Add(1);
    L.Add(6);
    L.Add(-13);
    L.CurrSetFirst();
    while(L.CurrCorrect())
    {
        cout<<L.GetCurr()<<' ';
        L.CurrSetNext();
    }
    getch();
    return 0;
}
//---------------------------------------------------------------------------
 