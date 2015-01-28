//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma argsused
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#define AlphaToRad(a) ((a)*M_PI/180)
#define RadToAlpha(r) ((r)*180/M_PI)
#define ALPHA(x,y) (((x)>=0)?(((x)==0)?(90):(atan((y)/(x))*180/M_PI)):(atan((y)/(x))*180/M_PI+180))
#define RAD(x,y) (((x)>=0)?(((x)==0)?(M_PI/2):(atan((y)/(x)))):(atan((y)/(x))+M_PI))
#define St2(n) (1<<(n))
#define St(n) ((3<<(n)))
#define ReadBit(a,n) ((((a)&St2(n))>0)?(1):(0))
#define WriteBit(a,n) ((a)|St2(n))
#define p2(n) (n/2)
//---------------------------------------------------------------------------
int fuctN(int n)
{
    int i=n-1;
    while(i>0)
    {
        n*=(i--);
    }
    return n;
}
//---------------------------------------------------------------------------
void tr()
{
    int r;
    r=random(3);
    if(r==0)
    {
        throw r;
    }
    else
    {
        if(r==1)
        {
            throw r;
        }
        else
        {
            if(r==2)
            {
                throw r;
            }
        }
    }
    return;
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    int i;
    char a[20],*g=a;
    randomize();
    i=0;
    /*try
    {
        tr();
    }
    catch(int n)
    {
        printf("%d",n);
    }*/
    itoa(9999999,a,36);
    puts(a);
    printf("%ld",strtol(a,&g,36));
    getch();
    return 0;
}
//---------------------------------------------------------------------------
