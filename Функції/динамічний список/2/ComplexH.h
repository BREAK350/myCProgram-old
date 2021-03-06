//---------------------------------------------------------------------------
#ifndef ComplexHH
#define ComplexHH
#include <iostream.h>
//---------------------------------------------------------------------------
class TComplex
{
    private:
        float u,v;
    public:
        TComplex();
        void Input();
        void print();
        void Init(int,int);
        TComplex& operator = (const TComplex);
        TComplex& operator = (float);
        TComplex operator + (const TComplex)const;
        TComplex operator - (const TComplex)const;
        TComplex operator * (const TComplex)const;
        inline bool operator == (const TComplex)const;
        friend TComplex operator * (TComplex,float);
        friend TComplex operator * (float,TComplex);
        friend TComplex operator + (TComplex,float);
        friend TComplex operator + (float,TComplex);
        friend TComplex operator - (TComplex,float);
        friend TComplex operator - (float,TComplex);
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 