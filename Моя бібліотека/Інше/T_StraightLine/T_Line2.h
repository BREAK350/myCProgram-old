//---------------------------------------------------------------------------
#ifndef T_Line2H
#define T_Line2H
#include "T_Point.h"
//---------------------------------------------------------------------------
class T_Line// or vector
{
    public:
        T_Point A,B;
    public:
        T_Line(){}
        T_Line(T_Point);
        T_Line(T_Point,T_Point);
        T_Line(float,float,float,float);
        T_Line& operator = (T_Line);
        T_Line operator + (T_Line);
        T_Line operator - (T_Line);
        T_Line operator + (T_Point);
        T_Line operator - (T_Point);
        T_Line Rotate(T_Point,float);
        T_Point GetVector();
        ~T_Line(){}
        bool isCrossingLines(T_Line);
        float Length();
        float ValueInPoint(float);
        float ValueInPoint(T_Point);
        float LineEquation_GetA();
        float LineEquation_GetB();
        float LineEquation_GetC();
        float Scalar(T_Line);
        float GetAngleRadian();
        void Draw(TCanvas *);
        void Draw(TCanvas *,const TColor &);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
