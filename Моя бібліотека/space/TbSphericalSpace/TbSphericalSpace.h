//---------------------------------------------------------------------------
#ifndef TbSphericalSpaceH
#define TbSphericalSpaceH
#include "TbVirtualSpace.h"
extern TColor cl;
extern double stZ;
//---------------------------------------------------------------------------
class TbSphericalSpace:public TbVirtualSpace
{
	private:
		double Radius,Eye,Projection,
			Review; // מבחמנ
		void SetReview();
		void GetCoordinate(double &X,double &Y,double &Z,
			const TbSpacePoint2Data &Point)const;
	public:
		TbSphericalSpace(const double &Eye,const double &Projection,
			const double &Radius);
		void SetRadius(const double &Radius);
		void SetEye(const double &Eye);
		void SetProjection(const double &Projection);
		TPoint GetTPoint(const TbSpacePoint2Data &Point)const;
		void Init(TbSpacePoint2Data &Point,
			const double &X,const double &Y)const;
		TbSpacePoint2Data Summ(const TbSpacePoint2Data &First,
								   const TbSpacePoint2Data &Second)const;
		double GetModule(const TbSpacePoint2Data &Point)const;
		double GetPeriod()const;
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
