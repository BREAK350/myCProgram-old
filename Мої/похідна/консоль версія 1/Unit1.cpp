//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#include <stdio.h>
#include <conio.h>
//---------------------------------------------------------------------------
#pragma argsused
func p;
char*t="tg(x)";
int main(int argc, char* argv[])
{
    char*a="(1(2(3(4()5()6()7()8()9((1)2)3)4)5)6)34)56)";
    p=t;
    puts(p.ChangeFX("tg(x)","1/pow(cos(x),2)").c_str());
    puts(p.SelectLN(2,3).ReturnChar());
    printf("%d\n",RightBracket(a));
    puts(p.CreateAS(a,RightBracket(a)).c_str());
    getch();
    return 0;
}
//---------------------------------------------------------------------------
