//---------------------------------------------------------------------------
#ifndef TbDisplacementH
#define TbDisplacementH
#include "T_Vector2d.h"
#include "TbDirection.h"
//---------------------------------------------------------------------------
class TbDisplacement // ����������
{
	protected:
		TbVector2d Location;
	public:
		TbDisplacement();
		TbDisplacement(const TbVector2d &Location);

		TbVector2d GetLocation()const;
		virtual void Move();
		virtual TbDirection GetDirection()const; // ������ � ������� �� 0 �� 2*M_PI
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif

