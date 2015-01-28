//---------------------------------------------------------------------------
#ifndef TbArrayPoint2dH
#define TbArrayPoint2dH
#include "TbMatrix_d.h"
#include <T_Vector2d.h>
//---------------------------------------------------------------------------
class TbArrayPoint2d:public TbMatrix_d
{
	protected:
		void proSetPoint(const int &Index,const TbVector2d &Point);
		TbVector2d proGetPoint(const int &Index)const;
		bool isCorrectIndex(const int &Index)const;
	public:
		TbArrayPoint2d():TbMatrix_d() {}
		TbArrayPoint2d(const TbArrayPoint2d &ArrayPoint);
		TbArrayPoint2d(const int &PointCount):TbMatrix_d(PointCount,3) {}
		TbArrayPoint2d(const int &PointCount,const TbVector2d *Point);
		TbArrayPoint2d(const int &PointCount,const TPoint *Point);

		void SetPoint(const int &Index,const TbVector2d &Point);
		TbVector2d GetPoint(const int &Index)const;

		int GetPointCount()const;
		TbVector2d* GetArrayVector2d()const;
		TPoint* GetArrayPoint()const;

		TbArrayPoint2d& operator = (const TbArrayPoint2d &ArrayPoint);
		TbArrayPoint2d& operator = (const TbMatrix_d &Matrix);
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
