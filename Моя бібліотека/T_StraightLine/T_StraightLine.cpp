//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_StraightLine.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void T_StraightLine::Init(const float &a,const float &b,const float &c)
{
    A=a;
    B=b;
    C=c;
}
//---------------------------------------------------------------------------
T_StraightLine::T_StraightLine(const float &a,const float &b,const float &c)
{
    Init(a,b,c);
}
//---------------------------------------------------------------------------
T_StraightLine::T_StraightLine(const T_StraightLine &sl)
{
    Init(sl.A,sl.B,sl.C);
}
//---------------------------------------------------------------------------
T_StraightLine::T_StraightLine(const float &k,const float &b)
{
    Init(k,-1,b);
}
//---------------------------------------------------------------------------
T_StraightLine& T_StraightLine::operator = (const T_StraightLine &sl)
{
    Init(sl.A,sl.B,sl.C);
    return *this;
}
//---------------------------------------------------------------------------
T_StraightLine::T_StraightLine(const T_Point &p1,const T_Point &p2)
{
    Init(p2.Y-p1.Y,p1.X-p2.X,p1.Y*(p2.X-p1.X)-p1.X*(p2.Y-p1.Y));
}
//---------------------------------------------------------------------------
int T_StraightLine::isParallel(const T_StraightLine &sl)const
{
    return GetAngleRadian()==sl.GetAngleRadian();
}
//---------------------------------------------------------------------------
float T_StraightLine::GetAngleRadian()const
{
    float Angle=0;
    if(A!=0)
    {
        if(B==0)
        {
            Angle=M_PI/2;
        }
        else
        {
            Angle=atan(-A/B);    
        }
    }
    return Angle;
}
//---------------------------------------------------------------------------
T_StraightLine::T_StraightLine(const T_Vector &v)
{
    if(v.Length())
    {
        Init(v.Y,-v.X,0);
    }
    else
    {
        Init(0,0,0);
    }
}
//---------------------------------------------------------------------------
int T_StraightLine::isCorrectLine()const
{
    return A*A+B*B;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
