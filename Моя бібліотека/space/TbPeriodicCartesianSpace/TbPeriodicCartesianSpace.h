//---------------------------------------------------------------------------
#ifndef TbPeriodicCartesianSpaceH
#define TbPeriodicCartesianSpaceH
#include <TbCartesianSpace.h>
//---------------------------------------------------------------------------
class TbPeriodicCartesianSpace:public TbCartesianSpace
{
	private:
		double PeriodX,PeriodY;
	public:
		virtual double GetPeriodX()const;
		virtual double GetPeriodY()const;
		void SetPeriodX(const double &PeriodX);
		void SetPeriodY(const double &PeriodY);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
