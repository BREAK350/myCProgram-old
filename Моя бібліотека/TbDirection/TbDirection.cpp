//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbDirection.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbDirection::TbDirection()
{
	Radian=0;
}
//---------------------------------------------------------------------------
TbDirection::TbDirection(const double &Radian)
{
	SetDirection(Radian);
}
//---------------------------------------------------------------------------
void TbDirection::SetDirection(const double &Radian)
{
	int k=Radian/GetPeriod();
	this->Radian=Radian-GetPeriod()*k;
	if(this->Radian<0)
	{
		this->Radian=GetPeriod()-this->Radian;
    }
}
//---------------------------------------------------------------------------
double TbDirection::GetPeriod()const
{
	return 2*M_PI;
}
//---------------------------------------------------------------------------
double TbDirection::GetMinAngle(const TbDirection &Direction)const
{
	double MinAngle=fabs(Radian-Direction.Radian);
	return (MinAngle<GetPeriod()-MinAngle)?(MinAngle):(GetPeriod()-MinAngle);
}
//---------------------------------------------------------------------------
double TbDirection::GetMaxAngle(const TbDirection &Direction)const
{
	return GetPeriod()-GetMinAngle(Direction);
}
//---------------------------------------------------------------------------
void TbDirection::Rotate(const double &Radian)
{
	SetDirection(this->Radian+Radian);
}
//---------------------------------------------------------------------------
void TbDirection::RotateTo(const TbDirection &Direction,
	const TbDirection &SpeedRotate)
{
	double Dir=GetDirection(Direction);
	if(Dir>=0)
	{
		Radian+=SpeedRotate.Radian;
	}
	else
	{
		Radian-=SpeedRotate.Radian;
    }
}
//---------------------------------------------------------------------------
double TbDirection::GetDirection()const
{
	return Radian;
}
//---------------------------------------------------------------------------
double TbDirection::GetDirection(const TbDirection &Direction)const
{
	TbDirection dDirection(Direction.Radian-Radian);
	double retDirection=dDirection.Radian;
	if(dDirection.Radian>M_PI)
	{
		retDirection=-retDirection;
	}
	return retDirection;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
