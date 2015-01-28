//---------------------------------------------------------------------------
#ifndef TbVirtualSpaceH
#define TbVirtualSpaceH
#include "ElementSpace.h"
#include <vcl.h>
//---------------------------------------------------------------------------
class TbVirtualSpace
{
	protected:
		struct TbSpacePoint2Data
		{
			double X,Y;
			TbSpacePoint2Data();
			TbSpacePoint2Data(const double &X,const double &Y);
		};
	public:
		class TbSpacePoint2
		{
			protected:
				TbSpacePoint2Data Point;
			public:
				TbSpacePoint2(const TbVirtualSpace *VSpace);
				TbSpacePoint2(const double &X,const double &Y,
								const TbVirtualSpace *VSpace);
				double GetDistance(const TbSpacePoint2 &Point,
								const TbVirtualSpace *VSpace)const;
				void Init(const double &X,const double &Y,
								const TbVirtualSpace *VSpace);
				TPoint GetTPoint(const TbVirtualSpace *VSpace)const;
		};
	public:
		virtual double GetDistance(const TbSpacePoint2Data &First,
								   const TbSpacePoint2Data &Second)const;
		virtual TPoint GetTPoint(const TbSpacePoint2Data &Point)const;
		virtual double GetModule(const TbSpacePoint2Data &Point)const;
		virtual void InitDefault(TbSpacePoint2Data &Point)const;
		virtual void Init(TbSpacePoint2Data &Point,
			const double &X,const double &Y)const;
		virtual TbSpacePoint2Data Summ(const TbSpacePoint2Data &First,
								   const TbSpacePoint2Data &Second)const;
		virtual TbSpacePoint2Data Different(const TbSpacePoint2Data &First,
								   const TbSpacePoint2Data &Second)const;
		virtual TbSpacePoint2Data Mult(const TbSpacePoint2Data &Point,
								   const double &Number)const;
};
//---------------------------------------------------------------------------
class TbSpaceVector2d:public TbVirtualSpace::TbSpacePoint2
{
	public:
		TbSpaceVector2d(const TbVirtualSpace *VSpace);
		TbSpaceVector2d(const double &X,const double &Y,
			const TbVirtualSpace *VSpace);

		double GetModule(const TbVirtualSpace *VSpace)const;
		TbSpaceVector2d Add(const TbSpaceVector2d &SVector,
			const TbVirtualSpace *VSpace)const;
		TbSpaceVector2d Sub(const TbSpaceVector2d &SVector,
			const TbVirtualSpace *VSpace)const;
		TbSpaceVector2d Mult(const double &Number,
			const TbVirtualSpace *VSpace)const;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
