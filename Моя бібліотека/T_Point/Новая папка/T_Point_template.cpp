//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Point_template.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
template <class Type>
float T_Point< Type >::Distance(T_Point p)
{
    return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
}
//---------------------------------------------------------------------------
template <class Type>
T_Point< Type >::T_Point(Type _x,Type _y)
{
    x=_x;
    y=_y;
}
//---------------------------------------------------------------------------
template <class Type>
T_Point< Type >::T_Point(TPoint p)
{
    x=p.x;
    y=p.y;
}
//---------------------------------------------------------------------------
template <class Type>
T_Point< Type >::T_Point(const T_Point &p)
{
    x=p.x;
    y=p.y;
}
//---------------------------------------------------------------------------
template <class Type>
T_Point< Type >::operator TPoint()
{
    return TPoint(x,y);
}
//---------------------------------------------------------------------------
template <class Type>
T_Point< Type >& T_Point< Type >::operator = (const T_Point &p)
{
    x=p.x;                             
    y=p.y;
    return *this;
}
//---------------------------------------------------------------------------
template <class Type>
bool T_Point< Type >::operator == (T_Point p)
{
    return (x==p.x && y==p.y);
}
//---------------------------------------------------------------------------
template <class Type>
bool T_Point< Type >::operator != (T_Point p)
{
    return !(*this==p);
}
//---------------------------------------------------------------------------
template <class Type>
void T_Point< Type >::Init(Type _x,Type _y)
{
    x=_x;
    y=_y;
}
//---------------------------------------------------------------------------
template <class Type>
T_Point< Type >::T_Point()
{
    x=y=0;
}
//---------------------------------------------------------------------------
template <class Type>
char* T_Point< Type >::toChar(int n)
{
    if(n<0)
    {
        return NULL;
    }
    char buf[32];
    sprintf(buf,"(%1.2f;%1.2f)",x,y);
    return strdup(buf);
}
//---------------------------------------------------------------------------
template <class Type>
void T_Point< Type >::Draw(TCanvas *Canvas,const TColor &cl)
{
    Canvas->Pixels[x][y]=cl;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 