//---------------------------------------------------------------------------
#ifndef TbCartesianSpaceH
#define TbCartesianSpaceH
#include "TbVirtualSpace.h"
//---------------------------------------------------------------------------
class TbCartesianSpace:public TbVirtualSpace
{
	public:
		TbCartesianSpace();

		double GetDistance(const TbSpacePoint2Data &First,
								   const TbSpacePoint2Data &Second)const;
		TPoint GetTPoint(const TbSpacePoint2Data &Point)const;
		double GetModule(const TbSpacePoint2Data &Point)const;
		TbSpacePoint2Data Summ(const TbSpacePoint2Data &First,
								   const TbSpacePoint2Data &Second)const;
		TbSpacePoint2Data Different(const TbSpacePoint2Data &First,
								   const TbSpacePoint2Data &Second)const;
		TbSpacePoint2Data Mult(const TbSpacePoint2Data &Point,
								   const double &Number)const;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
