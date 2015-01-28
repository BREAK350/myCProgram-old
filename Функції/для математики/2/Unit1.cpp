//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "Unit2.h"
#include <iostream.h>
//---------------------------------------------------------------------------
void mymain()
{
    float x;
    int l,r;
    char s[100];
    _func_ func=NULL;
    TElement f;
    while(*s)
    {
        cout<<"f=";
        gets(s);
        l=0;
        r=strlen(s);
        cout<<_FUNCS_::WhatIsIt(s,l,r,x,func)<<": l="<<l<<" r="<<r<<endl;
        cout<<"l="<<l<<" r="<<r<<" x="<<x<<endl;
    }
    cout<<"\nEnd.";
    cin.get();

    /*f.Create(s);
    f.Print();
    cout<<'='<<f.Return();*/
}
//---------------------------------------------------------------------------
void z()
{
    TElement f;
    f.Create("3+4*sin(6)");
}
//---------------------------------------------------------------------------
int Init()
{
    TElement f;
    char s[100];
    cout<<"f=";
    gets(s);
    f.Create(s);
    f.Print();
    cout<<'='<<f.Return()<<endl;
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    while(1)
    {
        Init();
    }
    cout<<"\nEnd.";
    cin.get();
    return 0;
}
//---------------------------------------------------------------------------
 