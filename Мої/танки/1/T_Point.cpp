//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Point.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void T_PointInit(T_Point &p,float _x,float _y)
{
    p.x=_x;
    p.y=_y;
}
//---------------------------------------------------------------------------
T_Point operator + (const T_Point &l,const T_Point &r)
{
    T_Point t;
    t.x=l.x+r.x;
    t.y=l.y+r.y;
    return t;
}
//---------------------------------------------------------------------------
TPoint toTPoint(const T_Point &p)
{
    TPoint r;
    r.x=p.x;
    r.y=p.y;
    return r;
}
//---------------------------------------------------------------------------
float pDistance(const T_Point &l,const T_Point &r)
{
    return sqrt((r.x-l.x)*(r.x-l.x)+(r.y-l.y)*(r.y-l.y));
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 