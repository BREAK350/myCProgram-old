//---------------------------------------------------------------------------
#pragma hdrstop
#include "plural.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbPlural10::TbPlural10()
{
    Count=0;
}
//---------------------------------------------------------------------------
TbPlural10::TbPlural10(const char *Element)
{
    this->Count=(Element)?(strlen(Element)):(0);
    if(this->Count>0)
    {
        if(Element)
        {
            int i=0;
            while(i<this->Count && Element[i]>='0' && Element[i]<='9')
            {
                i++;
            }
            if(i==this->Count)
            {
                int n=this->Count;
                this->Count=0;
                for(i=0;i<n;i++)
                {
                    if(Search(Element[i])==false)
                    {
                        this->Element[this->Count]=Element[i];
                        this->Count++;
                    }
                }
            }
            else
            {
                this->Count=0;
            }
        }
        else
        {
            this->Count=0;
        }
    }
}
//---------------------------------------------------------------------------
TbResult TbPlural10::Equal(const TbPlural10 &Pl)const
{
    TbResult res;
    int n=(Count>Pl.Count)?(Pl.Count):(Count),i;
    for(i=0;i<n;i++)
    {
        if(Element[i]==Pl.Element[i])
        {
            res.Bull++;
        }
        else
        {
            res.Cow+=Search(Pl.Element[i]);
        }
    }
    return res;
}
//---------------------------------------------------------------------------
bool TbPlural10::Search(const char &el)const
{
    bool res=false;
    if(Count>0 && el>='0' && el<='9')
    {
        int i=0;
        while(i<Count && Element[i]!=el)
        {
            i++;
        }
        res=(i<Count);
    }
    return res;
}
//---------------------------------------------------------------------------
TbPlural10 TbPlural10::operator + (const TbPlural10 &Pl)const
{
    TbPlural10 res=*this;
    int i=0;
    while(i<Pl.Count && res.Count<10)
    {
        if(res.Search(Pl.Element[i])==false)
        {
            res.Element[res.Count]=Pl.Element[i];
            res.Count++;
        }
        i++;
    }
    return res;
}
//---------------------------------------------------------------------------
TbPlural10 TbPlural10::Take_4()
{
    TbPlural10 res;
    if(Count>4)
    {
        Count-=4;
        res.Count=4;
        int i;
        for(i=0;i<4;i++)
        {
            res.Element[i]=Element[Count+i];
        }
    }
    return res;
}
//---------------------------------------------------------------------------
TbPlural10 TbPlural10::operator * (const TbPlural10 &Pl)const
{
    TbPlural10 res;
    int i=0;
    while(i<Count)
    {
        if(Pl.Search(Element[i]))
        {
            res.Element[res.Count]=Element[i];
            res.Count++;
        }
        i++;
    }
    return res;
}
//---------------------------------------------------------------------------
TbPlural10 TbPlural10::operator - (const TbPlural10 &Pl)const
{
    TbPlural10 res;
    int i=0;
    while(i<Count)
    {
        if(Pl.Search(Element[i])==false)
        {
            res.Element[res.Count]=Element[i];
            res.Count++;
        }
        i++;
    }
    return res;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
TbProgress::TbProgress()
{
    Cow=Bull=0;
    Number.Digit[0]=Number.Digit[1]=Number.Digit[2]=Number.Digit[3]=-1;
}
//---------------------------------------------------------------------------
void TbProgress::Init(const int &num0,const int &num1,const int &num2,const int &num3)
{
    Number.Digit[0]=num0;
    Number.Digit[1]=num1;
    Number.Digit[2]=num2;
    Number.Digit[3]=num3;
    Cow=Bull=0;
}
//---------------------------------------------------------------------------
int TbProgress::SearchNumber(const int &num)const
{
    int i=0;
    while(i<4 && num!=Number.Digit[i])
    {
        i++;
    }
    i=(i<4)?(i):(-1);
    return i;
}
//---------------------------------------------------------------------------
int TbProgress::CommonNumbers(const TbProgress &Prog)const
{
    int n=0,i=0;
    while(i<4)
    {
        if(Prog.SearchNumber(Number.Digit[i])!=-1)
        {
            n++;
        }
        i++;
    }
    return n;
}
//---------------------------------------------------------------------------
void TbProgress::Check(const TbNumber &num)
{
    int i;
    Cow=Bull=0;
    for(i=0;i<4;i++)
    {
        if(num.Digit[i]==Number.Digit[i])
        {
            Bull++;
        }
        else
        {
            if(SearchNumber(num.Digit[i])!=-1)
            {
                Cow++;
            }
        }
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
