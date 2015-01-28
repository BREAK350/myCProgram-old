//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_AnyVector.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_AnyVector::T_AnyVector(const T_AnyVector &av):T_Vector(av)
{
    Begin=av.Begin;
}
//---------------------------------------------------------------------------
void T_AnyVector::SetEnd(const T_Point &end)
{
    this->T_Vector::operator=(T_Vector(end)-Begin);
}
//---------------------------------------------------------------------------
T_AnyVector& T_AnyVector::operator = (const T_AnyVector &av)
{
    if(this==&av)
    {
        return *this;
    }
    T_Vector::operator = (av);
    Begin=av.Begin;
    return *this;
}
//---------------------------------------------------------------------------
T_AnyVector T_AnyVector::operator + (const T_AnyVector &av)const
{
    T_AnyVector r;
    r=T_Vector::operator + (av);
    r.Begin=Begin;
    return r;
}
//---------------------------------------------------------------------------
char* T_AnyVector::toChar(const int &n)const
{
    char buf[128];
    char *b,*e;
    b=Begin.toChar(n);
    e=GetEnd().toChar(n);
    sprintf(buf,"[%s;%s]",b,e);
    delete b;
    delete e;
    return strdup(buf);
}
//---------------------------------------------------------------------------
T_AnyVector::T_AnyVector(const T_Vector &b,const T_Vector &e):T_Vector(e.operator -(b))
{
    Begin=b;
}
//---------------------------------------------------------------------------
void T_AnyVector::Draw(TCanvas *Canvas,const TColor &cl)const
{
    TColor pen=Canvas->Pen->Color;
    Canvas->Pen->Color=cl;
    Canvas->MoveTo(Begin.X,Begin.Y);
    Canvas->LineTo(GetEnd().X,GetEnd().Y);
    Canvas->Pen->Color=pen;
}
//---------------------------------------------------------------------------
T_AnyVector T_AnyVector::Rotate(const T_Point &p,const float &angle)
{
    T_Vector v1(Begin-T_Vector(p));
    T_Vector v2(GetEnd()-T_Vector(p));
    v1.Rotate(angle);
    v2.Rotate(angle);
    SetBegin(v1+p);
    SetEnd(v2+p);
    return *this;
}
//---------------------------------------------------------------------------
void T_AnyVector::Move()
{
    Begin=Begin+(T_Vector)(*this);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
