//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "func.h"
#include <iostream.h>
#include <conio.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
bool Good(TbCPlural_char *Set,const int &n)
{
    int i=0,c=0,f=0;
    while(i<n)
    {
        c+=Set[i].GetCount();
        f+=Set[i].Found;
        i++;
    }
    return f==4 && c==f;
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    char buf[10];
    int i=0,n=0,Bull=0,Cow=0;
    bool add;
    TbCPlural_char Set[100];
    TbBCPlural_char pl;
    TbPlural_char num,NotUsed("0123456789");
    TbPosition Pos;

    cout<<"Number=";
    cin>>buf;
    while(i<20 && !Good(Set,n))
    {
        num=CreateNumber(Set,n,NotUsed);
        CreateCorrPos(Pos,num);
        cout<<"check="<<num.GetStr()<<"   ";
        cout<<"found=";
        if(GetCowBull(buf,num,Cow,Bull))
        {
            cout<<(Cow+Bull);
            pl=TbBCPlural_char(num.GetStr(),Cow+Bull,Bull);
            WritePos(Pos,pl);
            add=Add(Set,n,pl);
            AddAgain(Set,n);
            Equals(Set,n);
            cout<<"(add="<<add<<")"<<endl;
        }
        i++;
    }
    cout<<"result:\n";
    if(i<20)
    {
        i=0;
        while(i<n)
        {
            cout<<Set[i].GetStr()<<endl;
            i++;
        }
    }
    else
    {
        cout<<"Error\n";
    }
    getch();
    return 0;
}
//---------------------------------------------------------------------------
