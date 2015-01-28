//---------------------------------------------------------------------------
#ifndef T_AnyVectorH
#define T_AnyVectorH
#include "T_Vector.h"
//---------------------------------------------------------------------------
class T_AnyVector:public T_Vector
{
    protected:
        T_Vector Begin;
    public:
        /*Конструктори та деструктори*/
        T_AnyVector():T_Vector(0,0),Begin(0,0) {}
        T_AnyVector(const T_Vector &v):T_Vector(v),Begin(0,0) {}
        T_AnyVector(const T_AnyVector &);
        T_AnyVector(const T_Vector &,const T_Vector &);
        T_AnyVector(const float &x1,const float &y1,const float &x2,const float &y2)
            :T_Vector(x2-x1,y2-y1),Begin(x1,y1) {}
        ~T_AnyVector() {}
        /*********Оператори***********/
        T_AnyVector& operator = (const T_AnyVector &);
        T_AnyVector operator + (const T_AnyVector &)const;
        /***********Функції***********/
        T_Vector GetBegin()const { return Begin; }
        T_Vector GetEnd()const { return (T_Vector(*this)+Begin); }
        char* toChar(const int &)const;
        void Draw(TCanvas *,const TColor &)const;
        void Move();
        void SetBegin(const T_Point &b) { Begin=b; }
        void SetEnd(const T_Point &);
        T_AnyVector Rotate(const T_Point &,const float &);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif 
