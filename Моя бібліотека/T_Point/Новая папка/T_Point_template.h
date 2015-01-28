//---------------------------------------------------------------------------
#ifndef T_Point_templateH
#define T_Point_templateH
#include <vcl.h>
#include <math.h>
#include <stdio.h>
//---------------------------------------------------------------------------
export template <class Type>
class T_Point
{
    protected:
        Type x,y;
    public:
        /*Конструктори та деструктори*/
        T_Point();
        T_Point(Type,Type);
        T_Point(TPoint);
        T_Point(const T_Point &);
        ~T_Point(){}
        /*********Оператори***********/
        bool operator == (T_Point);
        bool operator !=(T_Point);
        operator TPoint();
        T_Point& operator = (const T_Point &);
        /***********Функції***********/
        T_Point Symetry(T_Point);
        char* toChar(int);
        float Distance(T_Point);
        Type GetX(){return x;}
        Type GetY(){return y;}
        void Draw(TCanvas *,const TColor &);
        void Init(Type,Type);
        void SetX(Type _x){x=_x;}
        void SetY(Type _y){y=_y;}
};
//---------------------------------------------------------------------------
typedef T_Point < float > fT_Point;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
