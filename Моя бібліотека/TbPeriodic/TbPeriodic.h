//---------------------------------------------------------------------------
#ifndef TbPeriodicH
#define TbPeriodicH
#include <math.h>
//---------------------------------------------------------------------------
template <class TbPeriodicType>
class TbPeriodic
{
	private:
		TbPeriodicType Value,
					   Period;
	public:
		TbPeriodic(const TbPeriodicType &Period)
		{
			Value=0;
			SetPeriod(Period);
		}
		TbPeriodic(const TbPeriodicType &Period,
			const TbPeriodicType &Value)
		{
			this->Value=Value;
			SetPeriod(Period);
		}
		void SetPeriod(const TbPeriodicType &Period)
		{
			if(Period>0)
			{
				this->Period=Period;
			}
			else
			{
				this->Period=0;
			}
			SetValue(Value);
		}
		void SetValue(const TbPeriodicType &Value)
		{
			int t=Value/GetPeriod();
			this->Value=Value-t*GetPeriod();
			if(this->Value<0)
			{
				this->Value=GetPeriod()+this->Value;
			}
		}
		TbPeriodicType GetPeriod()const
		{
			return Period;
		}
		TbPeriodicType GetValue()const
		{
			return Value;
		}
		operator TbPeriodicType ()const
		{
			return GetValue();
		}
		TbPeriodicType& operator = (const TbPeriodicType& Value)
		{
			SetValue(Value);
		}
		TbPeriodicType GetSignedDistance(const TbPeriodicType& Value)const
		{
			TbPeriodic V(GetPeriod(),Value);
			TbPeriodicType Distance1=V.GetValue()-this->Value;
			TbPeriodicType Distance2=V.GetValue()-this->Value+GetPeriod();
			TbPeriodicType Distance3=V.GetValue()-this->Value-GetPeriod();
			TbPeriodicType Distance=0;
			if(fabs(Distance1)<fabs(Distance2))
			{
				if(fabs(Distance1)<fabs(Distance3))
				{
					Distance=Distance1;
				}
				else
				{
					Distance=Distance3;
				}
			}
			else
			{
				if(fabs(Distance3)<fabs(Distance2))
				{
					Distance=Distance3;
				}
				else
				{
					Distance=Distance2;
				}
			}
			return Distance;
		}
		TbPeriodicType GetDistance(const TbPeriodicType& Value)const
		{
			return fabs(GetSignedDistance(Value));
		}
};
//---------------------------------------------------------------------------
typedef TbPeriodic <int>    TbPeriodici;
typedef TbPeriodic <double> TbPeriodicd;
typedef TbPeriodic <char>   TbPeriodicc;
typedef TbPeriodic <float>  TbPeriodicf;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
