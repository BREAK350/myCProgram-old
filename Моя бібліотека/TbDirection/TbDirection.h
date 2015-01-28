//---------------------------------------------------------------------------
#ifndef TbDirectionH
#define TbDirectionH
#include <math.h>
//---------------------------------------------------------------------------
class TbDirection
{
	private:
		double Radian; // кут напрямку, від 0 до 2*M_PI
	public:
		TbDirection();
		TbDirection(const double &Radian);

		void SetDirection(const double &Radian);
		double GetPeriod()const;
		double GetDirection()const;

		double GetMinAngle(const TbDirection &Direction)const;
		double GetMaxAngle(const TbDirection &Direction)const;
		double GetDirection(const TbDirection &Direction)const;

		void Rotate(const double &Radian);
		void RotateTo(const TbDirection &Direction,
			const TbDirection &SpeedRotate);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
