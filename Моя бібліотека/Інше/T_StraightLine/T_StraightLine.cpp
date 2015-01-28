//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_StraightLine.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_StraightLine& T_StraightLine::operator = (const T_StraightLine &l)
{
    T_AnyVector::operator = (l);
    return *this;
}
//---------------------------------------------------------------------------
T_StraightLine T_StraightLine::operator + (const T_Vector &v)const
{
    return T_StraightLine(GetBegin()+v,GetEnd()+v);
}
//---------------------------------------------------------------------------
T_StraightLine T_StraightLine::operator - (const T_Vector &v)const
{
    return T_StraightLine(GetBegin()+v,GetEnd()+v);
}
//---------------------------------------------------------------------------
bool T_StraightLine::isParallel(const T_StraightLine &l)const
{
    if(GetAngleRadian()==l.GetAngleRadian())
    {
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------
float T_StraightLine::ValueInPoint(const T_Point &p)const
{
    return LineEquation_GetA()*p.GetX()+LineEquation_GetB()*p.GetY()+
           LineEquation_GetC();
}
//---------------------------------------------------------------------------
float T_StraightLine::ValueInPointX(const float &x)const
{
    if(LineEquation_GetB()!=0)
    {
        return -(LineEquation_GetC()+LineEquation_GetA()*x)/LineEquation_GetB();
    }
    return 0;
}
//---------------------------------------------------------------------------
float T_StraightLine::ValueInPointY(const float &y)const
{
    if(LineEquation_GetA()!=0)
    {
        return -(LineEquation_GetC()+LineEquation_GetB()*x)/LineEquation_GetA();
    }
    return 0;
}
//---------------------------------------------------------------------------
float T_StraightLine::LineEquation_GetA()const
{
    return GetEnd().GetY()-GetBegin().GetY();
}
//---------------------------------------------------------------------------
float T_StraightLine::LineEquation_GetB()const
{
    return GetBegin().GetX()-GetEnd().GetX();
}
//---------------------------------------------------------------------------
float T_StraightLine::LineEquation_GetC()const
{
    return GetBegin().GetY()*(GetEnd().GetX()-GetBegin().GetX())-
           GetBegin().GetX()*(GetEnd().GetY()-GetBegin().GetY());
}
//---------------------------------------------------------------------------
float T_StraightLine::GetAngleRadian()const
{
    float angle=T_Vector::GetAngleRadian();
    if(angle<0)
    {
        angle+=M_PI;
    }
    if(angle>=2*M_PI)
    {
        angle-=M_PI;
    }
    return angle;
}
//---------------------------------------------------------------------------
float T_StraightLine::AngleBetween(const T_StraightLine &l)const
{
    float angle=T_Vector::AngleBetween(l);
    if(angle<0)
    {
        angle+=M_PI/2;
    }
    if(angle>=M_PI)
    {
        angle-=M_PI/2;
    }
    return angle;
}
//---------------------------------------------------------------------------
T_Point T_StraightLine::CrossPoint(const T_StraightLine &l)const
{
    T_Point Point;
    if(!isParallel(l))
    {
        if(LineEquation_GetA()!=0)
        {
            Point.SetY((l.LineEquation_GetA()*LineEquation_GetC()-LineEquation_GetA()*l.LineEquation_GetC())/
                       (LineEquation_GetA()*l.LineEquation_GetB()-l.LineEquation_GetA()*LineEquation_GetB()));
            Point.SetX(-(LineEquation_GetC()+LineEquation_GetB()*Point.GetY())/LineEquation_GetA());
            return Point;
        }
        if(LineEquation_GetB()!=0)
        {
            Point.SetY(-LineEquation_GetC()/LineEquation_GetB());
            if(l.LineEquation_GetA()!=0)
            {
                Point.SetX(l.ValueInPointY(Point.GetY()));
            }
            return Point;
        }
    }
    return T_Point();
}
//---------------------------------------------------------------------------
char* T_StraightLine::LineEquation()const
{
    char buf[1024];
    sprintf(buf,"(%1.3f)*x+(%1.3f)*y+(%1.3f)=0",LineEquation_GetA(),LineEquation_GetB(),LineEquation_GetC());
    return strdup(buf);
}
//---------------------------------------------------------------------------
T_StraightLine::T_StraightLine(const float &A,const float &B,const float &C)
{
    if(A*A+B*B==0)
    {
        SetBegin(T_Point());
        SetEnd(T_Point());
        return;
    }
    if(B)
    {
        SetBegin(T_Point(0,-C/B));
        SetEnd(T_Point(1,(-C-A)/B));    
    }
    else
    {
        if(A)
        {
            SetBegin(T_Point(-C/A,0));
            SetEnd(T_Point((-C-B)/A,0));
        }
    }
}
//---------------------------------------------------------------------------
void T_StraightLine::Draw(TCanvas *Canvas,TRect Rect,const TColor &cl)const
{
    long int b;
    float A=LineEquation_GetA(),B=LineEquation_GetB(),C=LineEquation_GetC();
    if(A*A+B*B==0)
    {
        return;
    }
    if(Rect.Left>Rect.Right)
    {
        b=Rect.Left;
        Rect.Left=Rect.Right;
        Rect.Right=b;
    }
    if(Rect.Top<Rect.Bottom)
    {
        b=Rect.Top;
        Rect.Top=Rect.Bottom;
        Rect.Bottom=b;
    }
    if(A==0)
    {
        if(-C/B<=Rect.Top && -C/B>=Rect.Bottom)
        {
            T_AnyVector Line(T_Point(Rect.Left,-C/B),T_Point(Rect.Right,-C/B));
            Line.Draw(Canvas,cl);
        }
        return;
    }

}
//---------------------------------------------------------------------------
bool T_StraightLine::CrossPoint(const T_StraightLine &l,T_Point &p)const
{
    if(isParallel(l))
    {
        return false;
    }
    p=CrossPoint(l);
    return true;
}
//---------------------------------------------------------------------------
bool T_StraightLine::isBelongSegment(const T_Point &p)const
{
    if(ValueInPoint(p)==0)
    {
        T_Point A((GetBegin().GetX()<GetEnd().GetX())?(GetBegin().GetX()):(GetEnd().GetX()),
                  (GetBegin().GetY()<GetEnd().GetY())?(GetBegin().GetY()):(GetEnd().GetY()));
        T_Point B((GetBegin().GetX()>=GetEnd().GetX())?(GetBegin().GetX()):(GetEnd().GetX()),
                  (GetBegin().GetY()>=GetEnd().GetY())?(GetBegin().GetY()):(GetEnd().GetY()));
        if(p.GetX()>=A.GetX() && p.GetX()<=B.GetX() && p.GetY()>=A.GetY() && p.GetY()<=B.GetY())
        {
            return true;
        }
    }
    return false;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
