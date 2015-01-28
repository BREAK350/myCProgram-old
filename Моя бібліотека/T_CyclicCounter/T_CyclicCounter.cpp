//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_CyclicCounter.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_CyclicCounter::T_CyclicCounter()
{
    Cyclic=0;
    Counter=0;
}
//---------------------------------------------------------------------------
T_CyclicCounter::T_CyclicCounter(const int &c)
{
    SetCyclic(c);
}
//---------------------------------------------------------------------------
T_CyclicCounter T_CyclicCounter::operator ++ (int)
{
    T_CyclicCounter c(*this);
    Counter++;
    if(Counter>=Cyclic)
    {
        Counter=0;
    }
    return c;
}
//---------------------------------------------------------------------------
T_CyclicCounter& T_CyclicCounter::operator ++ ()
{
    Counter++;
    if(Counter>=Cyclic)
    {
        Counter=0;
    }
    return *this;
}
//---------------------------------------------------------------------------
T_CyclicCounter T_CyclicCounter::operator + (const int &c)const
{
    T_CyclicCounter r(Cyclic,(Counter+c)%Cyclic);
    if(c<0)
    {
        r.Converse();
    }
    return r;
}
//---------------------------------------------------------------------------
T_CyclicCounter T_CyclicCounter::operator -- (int)
{
    T_CyclicCounter c(*this);
    Counter--;
    if(Counter<0)
    {
        Counter=Cyclic-1;
    }
    return c;
}
//---------------------------------------------------------------------------
T_CyclicCounter& T_CyclicCounter::operator -- ()
{
    Counter--;
    if(Counter<0)
    {
        Counter=Cyclic-1;
    }
    return *this;
}
//---------------------------------------------------------------------------
T_CyclicCounter T_CyclicCounter::operator - (const int &c)const
{
    T_CyclicCounter r(Cyclic,Cyclic-(Counter+c)%Cyclic);
    if(c<0)
    {
        r.Converse();
    }
    return r;
}
//---------------------------------------------------------------------------
void T_CyclicCounter::SetCyclic(const int &c)
{
    Cyclic=(c>0)?(c):(0);
    Counter=0;
}
//---------------------------------------------------------------------------
T_CyclicCounter T_CyclicCounter::operator * (const int &c)const
{
    return T_CyclicCounter(Cyclic,(Counter*c)%Cyclic);
}
//---------------------------------------------------------------------------
T_CyclicCounter& T_CyclicCounter::operator = (const T_CyclicCounter &cc)
{
    Cyclic=cc.Cyclic;
    Counter=cc.Counter;
    return *this;
}
//---------------------------------------------------------------------------
T_CyclicCounter::T_CyclicCounter(const T_CyclicCounter &cc)
{
    Cyclic=cc.Cyclic;
    Counter=cc.Counter;
}
//---------------------------------------------------------------------------
T_CyclicCounter::T_CyclicCounter(const int &cy,const int &co)
{
    Cyclic=(cy>0)?(cy):(0);
    Counter=(co>=0 && co<Cyclic)?(co):(0);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
