//---------------------------------------------------------------------------
#ifndef Draw2DH
#define Draw2DH
#include "Unit1.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#define USI unsigned short int
//---------------------------------------------------------------------------
class point2D
{
    public:
        float     x,y;
        bool      operator==(point2D);
        point2D   operator*(float);
        point2D   InitXY(float,float);
        point2D   InitAlphaD(float,float);
        point2D   Draw2D(TColor,Graphics::TBitmap*);
        point2D   MoveTo(Graphics::TBitmap*);
        point2D   LineTo(TColor,Graphics::TBitmap*);
        float     DistanceToPoint(point2D);
        float     DistanceToLine(point2D,point2D);
        point2D   SymmetryToPoint(point2D);
        point2D   SymmetryToLine(point2D,point2D);
        point2D   TurnToPoint(point2D,float);
        point2D   operator+(point2D);
        point2D   operator-(point2D);
        float     Alpha();
        float     D();
};
//---------------------------------------------------------------------------
class detail
{
    public:
        int     Npoint,
                Nline;
        float   alpha,
                S;
        point2D *point,
                loc;
        USI     *line;
        TColor  *clline;
                detail();
        int     AddNewLine(int n1,int n2,TColor coll);
        int     AddNewPoint(point2D p);
        void    SaveToFile(char*fname);
        void    LoadFromFile(char*fname);
        void    DrawDetail(Graphics::TBitmap*);
        void    operator=(detail);
};
//---------------------------------------------------------------------------
class Skeleton
{
    public:
        int     Npoint;
        point2D *point;
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
//---------------------------------------------------------------------------
#endif
