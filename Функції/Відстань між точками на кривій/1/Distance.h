//---------------------------------------------------------------------------
#ifndef DistanceH
#define DistanceH
#include <math.h>
//---------------------------------------------------------------------------
class T_Distance
{
    protected:
        double Epsilon;
    public:
        struct TPoint
        {
            double x,y;
        };
    protected:
        double Dist(const TPoint &p1,const TPoint &p2);
        double t;
    public:
        T_Distance(const double &e) { Epsilon=(e>=0)?(e):(-e); }
        typedef TPoint (*pfunc)(const double &t);
        T_Distance(const double &e,pfunc pF) { Epsilon=(e>=0)?(e):(-e); pFunction=pF; }
        pfunc pFunction;
        TPoint NextPoint(const double &t0,const double &d);
        void SetEpsilon(const double &e) { Epsilon=(e>=0)?(e):(-e); }
        double Get_t() { return t; }
};
//---------------------------------------------------------------------------
double Normalization(const double &t);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
