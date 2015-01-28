//---------------------------------------------------------------------------
#ifndef ElementSpaceH
#define ElementSpaceH
#include <math.h>
//---------------------------------------------------------------------------
struct TbSpaceNumber
{
	double X;
};
//---------------------------------------------------------------------------
struct TbSpacePoint2:public TbSpaceNumber
{
	double Y;
};
//---------------------------------------------------------------------------
class TbTestSpace
{
	public:
		double GetModule(const double &X,const double &Y)const
		{
			return sqrt(X*X+Y*Y);
		}
};
//---------------------------------------------------------------------------
class TbTestElem
{
	private:
		double X,Y;
	public:
		double GetModule(const TbTestSpace &TestSpace)const
		{
			return TestSpace.GetModule(X,Y);
        }
};
//---------------------------------------------------------------------------
#endif
