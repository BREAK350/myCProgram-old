//---------------------------------------------------------------------------
#ifndef T_VectorH
#define T_VectorH
#include "T_Point.h"
//---------------------------------------------------------------------------
class T_Vector:public T_Point
{
    public:
        /*Конструктори та деструктори*/
        T_Vector():T_Point(){}
        T_Vector(const T_Point &p):T_Point(p){}
        T_Vector(const T_Vector &);
        T_Vector(const T_Vector &,const T_Vector &); // вектор між двома точками
        T_Vector(const float &,const float &);
        ~T_Vector(){}
        /*********Оператори***********/
        T_Vector operator + (const T_Vector &)const;
        T_Vector operator - (const T_Vector &)const;
        T_Vector operator * (const float &)const;
        /***********Функції***********/
        T_Vector Rotate(const float &angle); // повертає вектор на кут angle
        T_Vector Normalization(); // змінює довжину на 1
        bool isPerpendicular(const T_Vector &v)const { return Scalar(v)==0; }
        float Scalar(const T_Vector &)const;
        float Length()const;
        float GetAngleRadian()const;
        float AngleBetween(const T_Vector &)const;
        void Draw(TCanvas *,const TColor &)const;
        void SetLength(const float &);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
