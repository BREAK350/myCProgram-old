//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Vector.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Vector::T_Vector(const T_Vector &v):T_Point(v)
{
}
//---------------------------------------------------------------------------
T_Vector::T_Vector(const float &_x,const float &_y):T_Point(_x,_y)
{
}
//---------------------------------------------------------------------------
T_Vector T_Vector::operator + (const T_Vector &v)const
{
    return T_Vector(X+v.X,Y+v.Y);
}
//---------------------------------------------------------------------------
T_Vector T_Vector::operator - (const T_Vector &v)const
{
    return T_Vector(X-v.X,Y-v.Y);
}
//---------------------------------------------------------------------------
T_Vector T_Vector::operator * (const float &f)const
{
    return T_Vector(f*X,f*Y);
}
//---------------------------------------------------------------------------
float T_Vector::Length()const
{
    return sqrt(X*X+Y*Y);
}
//---------------------------------------------------------------------------
T_Vector T_Vector::Rotate(const float &angle)
{
    T_Vector p;
    p.X=X*cos(angle)-Y*sin(angle);
    p.Y=X*sin(angle)+Y*cos(angle);
    return *this=p;
}
//---------------------------------------------------------------------------
float T_Vector::GetAngleRadian()const
{
    if(X==0)
    {
        if(Y>=0)
        {
            return M_PI/2;
        }
        return 3*M_PI/2;
    }
    if(X>0)
    {
        return atan(Y/X);
    }
    return M_PI+atan(Y/X);
}
//---------------------------------------------------------------------------
T_Vector T_Vector::Normalization()
{
    SetLength(1);
    return *this;
}
//---------------------------------------------------------------------------
void T_Vector::Draw(TCanvas *Canvas,const TColor &cl)const
{
    TColor pen=Canvas->Pen->Color;
    Canvas->Pen->Color=cl;
    Canvas->MoveTo(0,0);
    Canvas->LineTo(X,Y);
    Canvas->Pen->Color=pen;
}
//---------------------------------------------------------------------------
float T_Vector::AngleBetween(const T_Vector &v)const
{
    T_Vector vector=*this;
    vector.Rotate(-v.GetAngleRadian());
    return vector.GetAngleRadian();
}
//---------------------------------------------------------------------------
float T_Vector::Scalar(const T_Vector &v)const
{
    return X*v.X+Y*v.Y;
}
//---------------------------------------------------------------------------
void T_Vector::SetLength(const float &l)
{
    float L=Length();
    if(L)
    {
        Y=l*Y/L;
        X=l*X/L;
    }
}
//---------------------------------------------------------------------------
T_Vector::T_Vector(const T_Vector &From,const T_Vector &To):
    T_Point(To-From)
{
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
