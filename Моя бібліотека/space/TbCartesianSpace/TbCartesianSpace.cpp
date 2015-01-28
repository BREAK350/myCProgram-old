//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbCartesianSpace.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbCartesianSpace::TbCartesianSpace()
{
}
//---------------------------------------------------------------------------
double TbCartesianSpace::GetDistance(const TbSpacePoint2Data &First,
								   const TbSpacePoint2Data &Second)const
{
	return (First.X-Second.X)*(First.X-Second.X)+
		(First.Y-Second.Y)*(First.Y-Second.Y);
}
//---------------------------------------------------------------------------
TPoint TbCartesianSpace::GetTPoint(const TbSpacePoint2Data &Point)const
{
	return TPoint(Point.X,Point.Y);
}
//---------------------------------------------------------------------------
double TbCartesianSpace::GetModule(const TbSpacePoint2Data &Point)const
{
	return sqrt(Point.X*Point.X+Point.Y*Point.Y);
}
//---------------------------------------------------------------------------
TbVirtualSpace::TbSpacePoint2Data TbCartesianSpace::
	Summ(const TbSpacePoint2Data &First,const TbSpacePoint2Data &Second)const
{
	return TbSpacePoint2Data(First.X+Second.X,First.Y+Second.Y);
}
//---------------------------------------------------------------------------
TbVirtualSpace::TbSpacePoint2Data TbCartesianSpace::
	Different(const TbSpacePoint2Data &First,
			  const TbSpacePoint2Data &Second)const
{
	return TbSpacePoint2Data(First.X-Second.X,First.Y-Second.Y);
}
//---------------------------------------------------------------------------
TbVirtualSpace::TbSpacePoint2Data TbCartesianSpace::
	Mult(const TbSpacePoint2Data &Point,
		 const double &Number)const
{
	return TbSpacePoint2Data(Point.X*Number,Point.Y*Number);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
