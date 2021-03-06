//---------------------------------------------------------------------------
#ifndef T_StraightLineH
#define T_StraightLineH
#include "T_Vector.h"
//---------------------------------------------------------------------------
class T_StraightLine // Ax+By+C=0
{
    public:
        float A,B,C;
    public:
        /*������������ �� �����������*/
        T_StraightLine() { A=B=C=0; }
        T_StraightLine(const T_StraightLine &sl);
        T_StraightLine(const float &a,const float &b,const float &c); // ax+by+c=0
        T_StraightLine(const float &k,const float &b); // y=kx+b
        T_StraightLine(const T_Point &p1,const T_Point &p2);
        T_StraightLine(const T_Vector &v);
        ~T_StraightLine() {}
        /*********���������***********/
        T_StraightLine& operator = (const T_StraightLine &sl);
        /***********�������***********/
        int isCorrectLine()const;
        int isParallel(const T_StraightLine &sl)const;
        float GetAngleRadian()const;
        void Init(const float &a,const float &b,const float &c);
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
//---------------------------------------------------------------------------
#endif
