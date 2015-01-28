//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbSphericalSpace.h"
#pragma package(smart_init)
TColor cl;
double stZ;
//---------------------------------------------------------------------------
TbSphericalSpace::TbSphericalSpace(const double &Eye,const double &Projection,
			const double &Radius)
{
	this->Radius=this->Eye=this->Projection=1;
	SetRadius(Radius);
	SetEye(Eye);
	SetProjection(Projection);
}
//---------------------------------------------------------------------------
TPoint TbSphericalSpace::GetTPoint(const TbSpacePoint2Data &Point)const
{
	TPoint res(0,0);
	double X,Y,Z;
	GetCoordinate(X,Y,Z,Point);
	res.x=Eye*X/(Eye+Projection+Radius-Z);
	res.y=Eye*Y/(Eye+Projection+Radius-Z);
	stZ=Z;
	if(Review-GetModule(Point)>=0)
	{
		cl=clBlack;
	}
	else
	{
		cl=clWhite;
    }
	return res;
}
//---------------------------------------------------------------------------
void TbSphericalSpace::SetRadius(const double &Radius)
{
	if(Radius>0)
	{
		this->Radius=Radius;
	}
	else
	{
		this->Radius=1;
	}
	SetReview();
}
//---------------------------------------------------------------------------
void TbSphericalSpace::SetEye(const double &Eye)
{
	if(Eye>0)
	{
		this->Eye=Eye;
	}
	else
	{
		this->Eye=1;
	}
	SetReview();
}
//---------------------------------------------------------------------------
void TbSphericalSpace::SetProjection(const double &Projection)
{
	if(Projection>0)
	{
		this->Projection=Projection;
	}
	else
	{
		this->Projection=0;
	}
	SetReview();
}
//---------------------------------------------------------------------------
void TbSphericalSpace::SetReview()
{
	Review=Radius*acos(Radius/(Eye+Projection+Radius));
}
//---------------------------------------------------------------------------
double TbSphericalSpace::GetPeriod()const
{
	return 2*M_PI*Radius;
}
//---------------------------------------------------------------------------
void TbSphericalSpace::Init(TbSpacePoint2Data &Point,
			const double &X,const double &Y)const
{
	int t=X/GetPeriod();
	Point.X=X-t*GetPeriod();
	if(Point.X<0)
	{
		Point.X+=GetPeriod();
	}
	t=2*Y/GetPeriod();
	Point.Y=Y-t*GetPeriod();
	if(Point.Y<0)
	{
		Point.Y+=GetPeriod();
	}
	Point.Y-=GetPeriod()/2;
}
//---------------------------------------------------------------------------
TbVirtualSpace::TbSpacePoint2Data TbSphericalSpace::
	Summ(const TbSpacePoint2Data &First,const TbSpacePoint2Data &Second)const
{
	TbSpacePoint2Data res;
	Init(res,First.X+Second.X,First.Y+Second.Y);
	return res;
}
//---------------------------------------------------------------------------
void TbSphericalSpace::GetCoordinate(double &X,double &Y,double &Z,
	const TbSpacePoint2Data &Point)const
{
	double sina=sin(Point.X/Radius);
	double cosa=cos(Point.X/Radius);
	double sinb=sin(Point.Y/Radius);
	double cosb=cos(Point.Y/Radius);
	X=Radius*cosb*sina;
	Y=Radius*sinb;
	Z=Radius*cosb*cosa;
}
//---------------------------------------------------------------------------
double TbSphericalSpace::GetModule(const TbSpacePoint2Data &Point)const
{
	double X,Y,Z;
	GetCoordinate(X,Y,Z,Point);
	double D=sqrt(X*X+Y*Y+(Z-Radius)*(Z-Radius));
	double Angle=M_PI;
	if(D/(2*Radius)<1)
	{
		Angle=2*asin(D/(2*Radius));
    }
	return Angle*Radius;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
