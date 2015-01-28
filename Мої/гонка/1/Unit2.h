//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <math.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
class p2d;
class v2d;
class l2d;
class func;
//---------------------------------------------------------------------------
class p2d
{
    public:
        float x,y;
        p2d initxy(float,float);
        p2d initdalpha(float,float);
        float distance00();
        float angle();
        p2d operator + (p2d);
        p2d operator - (p2d);
        p2d operator * (float);
        p2d operator / (float);
};
//---------------------------------------------------------------------------
class v2d
{
    public:
        p2d p;
        float d,alpha;
        v2d init(p2d,p2d);
        v2d init(p2d,float,float);
        v2d init(float,float,float,float);
        v2d infuture();
        func tofunc();
        void move();
        v2d operator + (v2d);
        v2d operator - (v2d);
};
//---------------------------------------------------------------------------
class l2d
{
    public:
        p2d l1,l2,center;
        l2d init(p2d,p2d);
        l2d init(float,float,float,float);
        void drawcanvas(TCanvas*);
        func tofunc();
};
//---------------------------------------------------------------------------
class dv2d: public v2d
{
    public:
        p2d center;
        void drawcanvas(TCanvas*);
        l2d* rightmove(l2d*,int);
};
//---------------------------------------------------------------------------
class func
{
    public:
        float A,B,C;
        func init(float,float,float);
        float value(p2d);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
