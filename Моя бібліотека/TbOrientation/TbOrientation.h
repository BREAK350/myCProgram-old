//---------------------------------------------------------------------------
#ifndef TbOrientationH
#define TbOrientationH
#include "T_Vector2d.h"
//---------------------------------------------------------------------------
struct TbOrientation
{
    bool Up,Right;
    TbVector2d Shift;
    TbVector2d Scale;
    TCanvas *Canvas;

           TbOrientation();
           TbOrientation(TCanvas *Canvas);

    double OrientX(const double &X)const;
    double OrientY(const double &Y)const;
    double UnOrientX(const double &X)const;
    double UnOrientY(const double &Y)const;
    TPoint Orient(const TPoint &Point)const;
    TPoint UnOrient(const TPoint &Point)const;
    void   MoveTo(const double &X,const double &Y)const;
    void   LineTo(const double &X,const double &Y)const;
    void   MoveTo(const T_Vector2d &V)const;
    void   LineTo(const T_Vector2d &V)const;
    void   Rectangle(const double &X1,const double &Y1,const double &X2,const double &Y2)const;
    void   Rectangle(const T_Vector2d &V1,const T_Vector2d &V2)const;
    void   Rectangle(const T_Vector2d &LeftTop,const double &Width,const double &Height)const;
    void   Ellipse(const double &X1,const double &Y1,const double &X2,const double &Y2)const;
    void   Pixel(const double &X,const double &Y)const;
    void   Circle(const T_Vector2d &Centre,const double &Radius)const;
    void   Polygon(const T_Vector2d *Point,const int &Count)const;
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
