//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#include "Unit5.h"
#pragma argsused
#include <conio.h>
#include <iostream.h>
#include "TbList2.h"
//---------------------------------------------------------------------------
void Test()
{
    char *res=NULL;
    while(1)
    {
        res=Intersection("0034","0125");
        delete res;
    }
}
//---------------------------------------------------------------------------
void FillRandom(char *Digit)
{
    int i,Count=0;
    while(Count<10)
    {
        do
        {
            i=0;
            Digit[Count]=random(10)+'0';
            while(i<Count && Digit[Count]!=Digit[i])
            {
                i++;
            }
        }
        while(i<Count);
        Count++;
    }
}
//---------------------------------------------------------------------------
void GetResult(const TbPlural_char &num,int &Cow,int &Bull)
{
    cout<<num.GetStr()<<endl<<"  Cow=";
    cin>>Cow;
    cout<<"  Bull=";
    cin>>Bull;
}
//---------------------------------------------------------------------------
void ConsolPlay()
{
    TbList2 <TbBCPlural_char> Progress;
    TbList2 <TbCPlural_char> Set;
    char Digit[11];
    FillRandom(Digit);
    Digit[10]=0;
    TbCPlural_char Begin(Digit,4);
    int Bull=0,Cow=0;
    TbPlural_char num;
    TbList2Iterator <TbCPlural_char> i(Set);
    i.IsFirst();
    while(Begin.GetCount()>4)
    {
        int Found=Begin.Found;
        num=Begin.GetFirst(4);
        Begin=Begin-num;
        GetResult(num,Cow,Bull);
        if(Cow+Bull>0)
        {
            Progress.Add(TbBCPlural_char(num.GetStr(),Cow+Bull,Bull));
            Set.Add(TbCPlural_char(num.GetStr(),Cow+Bull));
            Begin.Found=Found-Cow-Bull;
        }
    }
    while(Bull!=4)
    {
        Set.CurrSetFirst();
        if(Set.GetCurr().GetCount()>4)
        {
            num=Set.GetCurr().GetFirst(4);
            Set.GetCurr()=Set.GetCurr()-num;
        }
        else
        {
        }
        GetResult(num,Cow,Bull);
        if(Bull!=4)
        {
            Progress.Add(TbBCPlural_char(num.GetStr(),Cow+Bull,Bull));
        }
    }
    cout<<"end."<<endl;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    randomize();
    ConsolPlay();
    getch();
    return 0;
}
//---------------------------------------------------------------------------
 