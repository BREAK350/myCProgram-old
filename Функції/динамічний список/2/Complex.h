//---------------------------------------------------------------------------
#ifndef ComplexH
#define ComplexH
#include <iostream.h>
//---------------------------------------------------------------------------
class TComplex
{
    private:
        int u,v;
    public:
        TComplex();
        void Input();
        void print();
        void Init(int,int);
        TComplex operator + (const TComplex)const;
        TComplex operator - (const TComplex)const;
        TComplex operator * (const TComplex)const;
        inline bool operator == (const TComplex)const;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#endif
