//---------------------------------------------------------------------------
#ifndef T_intPoligonH
#define T_intPoligonH
#include <vcl.h>
#include "T_Array.h"
//---------------------------------------------------------------------------
class T_intPoligon:public T_Array <TPoint>
{
    public:
        T_intPoligon():T_Array <TPoint>() {}
        T_intPoligon(const T_intPoligon &intPoligon):T_Array <TPoint>(intPoligon) {}
        ~T_intPoligon() {}
        T_intPoligon(const TPoint *array,const int &n):T_Array <TPoint>(n,array) {}
        T_intPoligon& operator = (const T_intPoligon &intPoligon);
        
        void Draw(TCanvas *Canvas);
        void Shift(const TPoint &vector);
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
