//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbArrayPoint2d.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbArrayPoint2d::TbArrayPoint2d(const int &PointCount,const TbVector2d *Point)
	:TbMatrix_d(PointCount,3)
{
	if(PointCount>0 && Point)
	{
		for(int i=0;i<PointCount;i++)
		{
        	proSetPoint(i,Point[i]);
        }
    }
}
//---------------------------------------------------------------------------
TbArrayPoint2d::TbArrayPoint2d(const int &PointCount,const TPoint *Point)
	:TbMatrix_d(PointCount,3)
{
	if(PointCount>0 && Point)
	{
		for(int i=0;i<PointCount;i++)
		{
        	proSetPoint(i,Point[i]);
        }
    }
}
//---------------------------------------------------------------------------
void TbArrayPoint2d::proSetPoint(const int &Index,const TbVector2d &Point)
{
	proSetElement(Index,0,Point.X);
	proSetElement(Index,1,Point.Y);
	proSetElement(Index,2,1);
}
//---------------------------------------------------------------------------
TbVector2d TbArrayPoint2d::proGetPoint(const int &Index)const
{
	return TbVector2d(proGetElement(Index,0)/proGetElement(Index,2),
					  proGetElement(Index,1)/proGetElement(Index,2));
}
//---------------------------------------------------------------------------
void TbArrayPoint2d::SetPoint(const int &Index,const TbVector2d &Point)
{
	if(isCorrectIndex(Index))
	{
		proSetPoint(Index,Point);
	}
}
//---------------------------------------------------------------------------
TbVector2d TbArrayPoint2d::GetPoint(const int &Index)const
{
	TbVector2d Point(0,0);
	if(isCorrectIndex(Index))
	{
		Point=proGetPoint(Index);
	}
	return Point;
}
//---------------------------------------------------------------------------
int TbArrayPoint2d::GetPointCount()const
{
	return GetRowCount();
}
//---------------------------------------------------------------------------
TbVector2d* TbArrayPoint2d::GetArrayVector2d()const
{
	TbVector2d *Points=NULL;
	if(GetPointCount()>0)
	{
		Points=new TbVector2d [GetPointCount()];
		for(int i=0;i<GetPointCount();i++)
		{
			Points[i]=GetPoint(i);
		}
	}
	return Points;
}
//---------------------------------------------------------------------------
TPoint* TbArrayPoint2d::GetArrayPoint()const
{
	TPoint *Points=NULL;
	if(GetPointCount()>0)
	{
		Points=new TPoint [GetPointCount()];
		for(int i=0;i<GetPointCount();i++)
		{
			Points[i]=GetPoint(i);
		}
	}
	return Points;
}
//---------------------------------------------------------------------------
bool TbArrayPoint2d::isCorrectIndex(const int &Index)const
{
	return Index>=0 && Index<GetPointCount();
}
//---------------------------------------------------------------------------
TbArrayPoint2d& TbArrayPoint2d::operator = (const TbArrayPoint2d &ArrayPoint)
{
	TbMatrix_d::operator =(ArrayPoint);
	return *this;
}
//---------------------------------------------------------------------------
TbArrayPoint2d& TbArrayPoint2d::operator = (const TbMatrix_d &Matrix)
{
	if(Matrix.GetColCount()==3)
	{
		TbMatrix_d::operator =(Matrix);
	}
	return *this;
}
//---------------------------------------------------------------------------
TbArrayPoint2d::TbArrayPoint2d(const TbArrayPoint2d &ArrayPoint)
	:TbMatrix_d(ArrayPoint)
{
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
