//---------------------------------------------------------------------------
#ifndef T_PoligonH
#define T_PoligonH
#include <vcl.h>
#include "T_Point.h"
#include <stdio.h>
//---------------------------------------------------------------------------
class T_Poligon
{
    protected:
        int n;
        T_Point *p;
    public:
        TColor clPen;
        TColor clBrush;
        T_Poligon();
        T_Poligon(int,TColor,TColor,T_Point *);
        T_Poligon(const T_Poligon &);
        ~T_Poligon();
        T_Point operator [] (int);
        void Init(int,TColor,TColor,T_Point *);
        void Delete();
        T_Poligon& operator = (const T_Poligon &);
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
#endif
 