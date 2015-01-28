//---------------------------------------------------------------------------
#ifndef T_Vector2dH
#define T_Vector2dH
#include <math.h>
#include <vcl.h>
//---------------------------------------------------------------------------
class TbVector2d
{
    public:
        double X,Y;
    public:
                    TbVector2d();
                    TbVector2d(const TPoint &Point);
                    TbVector2d(const double &x,const double &y);

                    operator TPoint()const;
                    operator bool()const;
        
        TbVector2d  operator + (const TbVector2d &V)const;
        TbVector2d  operator - (const TbVector2d &V)const;
        TbVector2d  operator * (const double &d)const;
        TbVector2d  operator / (const double &d)const;

        TbVector2d& operator += (const TbVector2d &V);
        TbVector2d& operator -= (const TbVector2d &V);
        TbVector2d& operator *= (const double &d);
        TbVector2d& operator /= (const double &d);
        
        TbVector2d& Rotate(const double &Angle);
        TbVector2d& SetLength(const double &NewLength);
        TbVector2d& Normalization();
        TbVector2d& Init(const double &x,const double &y);

        bool        operator == (const TbVector2d &V)const;
        bool        operator != (const TbVector2d &V)const;

        double      Length()const;
        double      AngleR()const;
        double      Scalar(const TbVector2d &V)const;
        double      AngleBetween(const TbVector2d &V)const;
        
        double      GetSignedAngleBetweenR(const TbVector2d &V)const;
        double      GetAngleBetweenR(const TbVector2d &V)const;
        double      GetSignedAngleR()const;
        double      GetAngleR()const;
        double      GetSquareLength()const;
        double      GetLength()const;

        void        MoveTo(TCanvas *Canvas)const;
        void        LineTo(TCanvas *Canvas)const;
        void        Reverse();
};
//---------------------------------------------------------------------------
typedef TbVector2d T_Vector2d;
//---------------------------------------------------------------------------
void GetLineCoefficientOnthePlane(const TbVector2d &Point1,const TbVector2d &Point2,
    double &A,double &B,double &C);
double GetDistanceFromPointToLine(const TbVector2d &Point,
    const TbVector2d &LinePoint1,const TbVector2d &LinePoint2);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
