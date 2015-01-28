//---------------------------------------------------------------------------
#ifndef T_VectorH
#define T_VectorH
#include "T_Point.h"
//---------------------------------------------------------------------------
class T_Vector:public T_Point
{
    public:
        /*������������ �� �����������*/
        T_Vector():T_Point(){}
        T_Vector(const T_Point &p):T_Point(p){}
        T_Vector(const T_Vector &);
        T_Vector(const T_Vector &,const T_Vector &); // ������ �� ����� �������
        T_Vector(const float &,const float &);
        ~T_Vector(){}
        /*********���������***********/
        T_Vector operator + (const T_Vector &)const;
        T_Vector operator - (const T_Vector &)const;
        T_Vector operator * (const float &)const;
        /***********�������***********/
        T_Vector Rotate(const float &angle); // ������� ������ �� ��� angle
        T_Vector Normalization(); // ����� ������� �� 1
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
