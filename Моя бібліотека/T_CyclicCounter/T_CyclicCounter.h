//---------------------------------------------------------------------------
#ifndef T_CyclicCounterH
#define T_CyclicCounterH
//---------------------------------------------------------------------------
class T_CyclicCounter
{
    private:
        int Cyclic;
        int Counter;
    public:
        T_CyclicCounter();
        T_CyclicCounter(const int &c);
        T_CyclicCounter(const int &cy,const int &co);
        T_CyclicCounter(const T_CyclicCounter &cc);
        T_CyclicCounter& operator ++ ();
        T_CyclicCounter operator ++ (int);
        T_CyclicCounter& operator -- ();
        T_CyclicCounter operator -- (int);
        T_CyclicCounter operator + (const int &c)const;
        T_CyclicCounter operator - (const int &c)const;
        T_CyclicCounter operator * (const int &c)const;
        T_CyclicCounter& operator = (const T_CyclicCounter &cc);
        operator int() { return Counter; }
        void SetCyclic(const int &c);
        void Next();
        void Converse() { Counter=Cyclic-Counter; }
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
