//---------------------------------------------------------------------------
#pragma hdrstop
#include <windows.h>
#include <iostream.h>
#include <conio.h>
#pragma argsused
#include <math.h>
#include "T_Vector2d.h"
//---------------------------------------------------------------------------
int GetTime1000000()
{
    int start=GetTickCount();
    int i=0;
    TbVector2d P(2,3),LP1(1,6),LP2(5,3);
    while(i<1000000)
    {
        GetDistanceFromPointToLine(P,LP1,LP2);
        i++;
    }
    int end=GetTickCount();
    return end-start;
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    cout<<"press key\n";
    getch();
    cout<<"start...\n";
    int min=GetTime1000000(),max=min,i=0,curr;
    while(i<100)
    {
        curr=GetTime1000000();
        if(min>curr)
        {
            min=curr;
        }
        if(max<curr)
        {
            max=curr;
        }
        i++;
    }
    cout<<"max="<<max<<"\nmin="<<min<<endl<<"end.\n";
    getch();
    return 0;
}
//---------------------------------------------------------------------------
 