//---------------------------------------------------------------------------
#ifndef TbUFAH
#define TbUFAH
#include "TbSet.h"
//---------------------------------------------------------------------------
class TbUFA // недетермінований скінченний автомат (Undetermined finite automaton)
{
    // початковий стан знаходиться у першому рядку
    private:
        int CountQ;
        TbSeti Symbols,**Table,FinalState;
    protected:
        void Clear();
        TbUFA Create(const char *Expression,const int &iBegin,const int &iEnd)const;
        void CreateNew(const char *Expression);
    public:
        TbUFA();
        TbUFA(const TbUFA &UFA);
        TbUFA(const char *Expression);
        //TbUFA(const int &CountQ,const int &CountS);
        TbUFA& operator = (const TbUFA &UFA);
        ~TbUFA();

        void Print()const;
        bool isEmpty()const;
        TbSeti GetElement(const int &Q,const int &S)const;
        TbSeti GetElement(const TbSeti &Qs,const int &S)const;
        TbSeti GetElementIndex(const int &iQ,const int &iS)const;
        const TbSeti& GetSymbols()const { return Symbols; }
        const TbSeti& GetFinalState()const { return FinalState; }
        int GetCountQ()const { return CountQ; }
        int GetCountS()const { return Symbols.GetCount(); }
        int GetCountLink()const;
        TbUFA operator | (const TbUFA &UFA)const;
        TbUFA Alternative(const TbUFA &UFA)const;
        TbUFA Concatenation(const TbUFA &UFA)const;
        TbUFA Iteration()const;
        bool isEndQ(const int &iQ)const;
        void Create(const char *Expression);

};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
