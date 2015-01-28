//---------------------------------------------------------------------------
#ifndef TbPoint2dH
#define TbPoint2dH
#include <vcl.h>
#include <math.h>
//---------------------------------------------------------------------------
struct TbPoint2d
{
    double x,y;
    TbPoint2d() { x=0; y=0; }
    TbPoint2d(const double &x,const double &y) { this->x=x; this->y=y; }
    void Init(const double &x,const double &y) { this->x=x; this->y=y; }
    void MoveTo(TCanvas *Canvas) { Canvas->MoveTo(x,y); }
    void LineTo(TCanvas *Canvas) { Canvas->LineTo(x,y); }
    void Pixel(TCanvas *Canvas,const TColor &Color) { Canvas->Pixels[x][y]=Color; }
};
//---------------------------------------------------------------------------
double Distance(const TbPoint2d &point1,const TbPoint2d &point2);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
