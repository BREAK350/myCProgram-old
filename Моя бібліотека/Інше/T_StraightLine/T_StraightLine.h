//---------------------------------------------------------------------------
#ifndef T_StraightLineH
#define T_StraightLineH
#include "T_AnyVector.h"
//---------------------------------------------------------------------------
class T_StraightLine:public T_AnyVector
{
    public:
        /*Конструктори та деструктори*/
        T_StraightLine():T_AnyVector(){}
        T_StraightLine(const T_Vector &v1,const T_Vector &v2):T_AnyVector(v1,v2) {}
        T_StraightLine(const float &x1,const float &y1,const float &x2,const float &y2)
            :T_AnyVector(x1,y1,x2,y2) {}
        T_StraightLine(const float &,const float &,const float &);
        T_StraightLine(const T_StraightLine &l):T_AnyVector(l) {}
        T_StraightLine(const T_AnyVector &v):T_AnyVector(v) {}
        ~T_StraightLine(){}
        /*********Оператори***********/
        T_StraightLine& operator = (const T_StraightLine &l);
        T_StraightLine operator + (const T_Vector &)const;
        T_StraightLine operator - (const T_Vector &)const;
        /***********Функції***********/
        bool CrossPoint(const T_StraightLine &,T_Point &)const;
        bool isParallel(const T_StraightLine &)const;
        bool isBelongSegment(const T_Point &)const;
        char* LineEquation()const;
        float ValueInPointX(const float &)const;
        float ValueInPointY(const float &)const;
        float ValueInPoint(const T_Point &)const;
        float LineEquation_GetA()const;
        float LineEquation_GetB()const;
        float LineEquation_GetC()const;
        float GetAngleRadian()const;
        float AngleBetween(const T_StraightLine &)const;
        T_Point CrossPoint(const T_StraightLine &)const; //???
        void Draw(TCanvas *,TRect ,const TColor &)const;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
