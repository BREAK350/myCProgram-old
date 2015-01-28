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
        /*Конструктори та деструктори*/
        T_Point();
        T_Point(const float &,const float &);
        T_Point(const TPoint &);
        T_Point(const T_Point &);
        ~T_Point(){}
        /*********Оператори***********/
        bool operator == (const T_Point &)const;
        bool operator !=(const T_Point &)const;
        operator TPoint()const;
        T_Point& operator = (const T_Point &);
        /***********Функції***********/
        T_Point Symetry(const T_Point &);
        char* toChar(const int &)const;
        float Distance(const T_Point &)const;
        int Comparison(const T_Point &p)const; // повертає чверть на координатній
            // площині, в якій знаходиться дана точка відносно p
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
