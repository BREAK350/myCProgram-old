//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbOrientation.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbOrientation::TbOrientation():Shift(0,0),Scale(1.0,1.0)
{
    Up=false;
    Right=true;
}
//---------------------------------------------------------------------------
TbOrientation::TbOrientation(TCanvas *Canvas):Shift(0,0),Scale(1.0,1.0)
{
    Up=false;
    Right=true;
    this->Canvas=Canvas;
}
//---------------------------------------------------------------------------
void TbOrientation::MoveTo(const double &X,const double &Y)const
{
    Canvas->MoveTo(OrientX(X),OrientY(Y));
}
//---------------------------------------------------------------------------
void TbOrientation::LineTo(const double &X,const double &Y)const
{
    Canvas->LineTo(OrientX(X),OrientY(Y));
}
//---------------------------------------------------------------------------
TPoint TbOrientation::Orient(const TPoint &Point)const
{
    return TPoint(OrientX(Point.x),OrientY(Point.y));
}
//---------------------------------------------------------------------------
double TbOrientation::OrientX(const double &X)const
{
    return ((Right)?(1):(-1))*Scale.X*X+Shift.X;
}
//---------------------------------------------------------------------------
double TbOrientation::OrientY(const double &Y)const
{
    return ((Up)?(-1):(1))*Scale.Y*Y+Shift.Y;
}
//---------------------------------------------------------------------------
double TbOrientation::UnOrientX(const double &X)const
{
    return (X-Shift.X)/(((Right)?(1):(-1))*Scale.X);
}
//---------------------------------------------------------------------------
double TbOrientation::UnOrientY(const double &Y)const
{
    return (Y-Shift.Y)/(((Up)?(-1):(1))*Scale.Y);
}
//---------------------------------------------------------------------------
void TbOrientation::Rectangle(const double &X1,const double &Y1,
                                              const double &X2,const double &Y2)const
{
    Canvas->Rectangle(OrientX(X1),OrientY(Y1),OrientX(X2),OrientY(Y2));
}
//---------------------------------------------------------------------------
void TbOrientation::Ellipse(const double &X1,const double &Y1,
                                              const double &X2,const double &Y2)const
{
    Canvas->Ellipse(OrientX(X1),OrientY(Y1),OrientX(X2),OrientY(Y2));
}
//---------------------------------------------------------------------------
void TbOrientation::Pixel(const double &X,const double &Y)const
{
    if(Scale.X==1 && Scale.Y==1)
    {
        Canvas->Pixels[OrientX(X)][OrientY(Y)]=Canvas->Pen->Color;
    }
    else
    {
        if(Scale.X>=1 && Scale.Y>=1)
        {
            Rectangle(X,Y,X+1,Y+1);
        }
    }
}
//---------------------------------------------------------------------------
void TbOrientation::Circle(const T_Vector2d &Centre,const double &Radius)const
{
    Ellipse(Centre.X-Radius,Centre.Y-Radius,Centre.X+Radius,Centre.Y+Radius);
}
//---------------------------------------------------------------------------
TPoint TbOrientation::UnOrient(const TPoint &Point)const
{
    return TPoint(UnOrientX(Point.x),UnOrientY(Point.y));
}
//---------------------------------------------------------------------------
void TbOrientation::Polygon(const T_Vector2d *Point,const int &Count)const
{
    TPoint *p=new TPoint [Count];
    for(int i=0;i<Count;i++)
    {
        p[i].x=OrientX(Point[i].X);
        p[i].y=OrientY(Point[i].Y);
    }
    Canvas->Polygon(p,Count-1);
    delete p;
}
//---------------------------------------------------------------------------
void TbOrientation::Rectangle(const T_Vector2d &V1,const T_Vector2d &V2)const
{
    Rectangle(V1.X,V1.Y,V2.X,V2.Y);
}
//---------------------------------------------------------------------------
void TbOrientation::Rectangle(const T_Vector2d &LeftTop,const double &Width,
        const double &Height)const
{
    Rectangle(LeftTop.X,LeftTop.Y,LeftTop.X+Width,LeftTop.Y+Height);
}
//---------------------------------------------------------------------------
void TbOrientation::MoveTo(const T_Vector2d &V)const
{
    MoveTo(V.X,V.Y);
}
void TbOrientation::LineTo(const T_Vector2d &V)const
{
    LineTo(V.X,V.Y);
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
