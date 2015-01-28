//---------------------------------------------------------------------------
#ifndef T_PointH
#define T_PointH
#include <vcl.h>
#include <math.h>
#include <stdio.h>
//---------------------------------------------------------------------------
class T_Point
{
    public:
        float X,Y;
    public:
        /*������������ �� �����������*/
        T_Point();
        T_Point(const float &,const float &);
        T_Point(const TPoint &);
        T_Point(const T_Point &);
        ~T_Point(){}
        /*********���������***********/
        bool operator == (const T_Point &)const;
        bool operator !=(const T_Point &)const;
        operator TPoint()const;
        T_Point& operator = (const T_Point &);
        /***********�������***********/
        T_Point Symetry(const T_Point &);
        char* toChar(const int &)const;
        float Distance(const T_Point &)const;
        int Comparison(const T_Point &p)const; // ������� ������ �� �����������
            // ������, � ��� ����������� ���� ����� ������� p
        void Draw(TCanvas *,const TColor &)const;
        void Init(const float &,const float &);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
