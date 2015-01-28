//---------------------------------------------------------------------------
#ifndef T_PoligonH
#define T_PoligonH
#include <vcl.h>
#include <stdio.h>
#include "T_Vector.h"
//---------------------------------------------------------------------------
class T_Poligon
{
    protected:
        int n;
        T_Point *p;
    public:
        void SaveToFile(FILE *);
        void LoadFromFile(FILE *);
        TColor clPen;
        TColor clBrush;
        T_Poligon();
        T_Poligon(int,TColor,TColor,T_Point *);
        T_Poligon(const T_Poligon &);
        ~T_Poligon();
        T_Point operator [] (int);
        T_Point& operator [] (const int &i);
        void Init(int,TColor,TColor,T_Point *);
        void Delete();
        T_Poligon& operator = (const T_Poligon &);
        void Draw(TCanvas *,T_Point,float,float);
        void SaveToFile(char *);
        void LoadFromFile(char *);
        void Rotate(const T_Point &Point,const float &angle);
        void Shift(const T_Vector &Vector);
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
 