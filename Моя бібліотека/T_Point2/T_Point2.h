//---------------------------------------------------------------------------
#ifndef T_Point2H
#define T_Point2H
//---------------------------------------------------------------------------
struct T_Point2
{
    float x,y;
    T_Point2() { x=y=0; }
    T_Point2(const float &_x,const float &_y) { x=_x; y=_y; }
    int operator == (const T_Point2 &p) { return x==p.x && y==p.y; }
};
//---------------------------------------------------------------------------
#endif
