//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbMatrix_3d.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbMatrix_3d::TbMatrix_3d(const double &e00,const double &e01,const double &e02,
                    const double &e10,const double &e11,const double &e12,
                    const double &e20,const double &e21,const double &e22)
                    :TbMatrix_d(3,3)
{
	proSetElement(0,0,e00);
	proSetElement(0,1,e01);
	proSetElement(0,2,e02);
	proSetElement(1,0,e10);
	proSetElement(1,1,e11);
	proSetElement(1,2,e12);
	proSetElement(2,0,e20);
	proSetElement(2,1,e21);
	proSetElement(2,2,e22);
}
//---------------------------------------------------------------------------
TbMatrix_3d::TbMatrix_3d(const TbMatrix_3d &Matrix)
	:TbMatrix_d(Matrix)
{
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
TbMatrix_3d TbMatrix_3d::GetRotation(const double &fi)
{
	return TbMatrix_3d( cos(fi),sin(fi),0,
					   -sin(fi),cos(fi),0,
						   0,      0,   1);
}
//---------------------------------------------------------------------------
TbMatrix_3d TbMatrix_3d::GetDilation(const double &dx,const double &dy)
{
	return TbMatrix_3d(dx,0 ,0,
					   0 ,dy,0,
					   0 ,0 ,1);
}
//---------------------------------------------------------------------------
TbMatrix_3d TbMatrix_3d::GetTranslation(const double &dx,const double &dy)
{
	return TbMatrix_3d(1 ,0 ,0,
					   0 ,1 ,0,
					   dx,dy,1);
}
//---------------------------------------------------------------------------
TbMatrix_3d TbMatrix_3d::GetReflectionX()
{
	return TbMatrix_3d(1 ,0 ,0,
					   0 ,-1,0,
					   0 ,0 ,1);
}
//---------------------------------------------------------------------------
TbMatrix_3d TbMatrix_3d::GetReflectionY()
{
	return TbMatrix_3d(-1,0 ,0,
					   0 ,1 ,0,
					   0 ,0 ,1);
}
//---------------------------------------------------------------------------
double TbMatrix_3d::GetDesignator()const
{
	return proGetElement(0,0)*proGetElement(1,1)*proGetElement(2,2)+
		   proGetElement(0,1)*proGetElement(1,2)*proGetElement(2,0)+
		   proGetElement(1,0)*proGetElement(2,1)*proGetElement(0,2)-
		   proGetElement(2,0)*proGetElement(1,1)*proGetElement(0,2)-
		   proGetElement(1,0)*proGetElement(0,1)*proGetElement(2,2)-
		   proGetElement(2,1)*proGetElement(1,2)*proGetElement(0,0);
}
//---------------------------------------------------------------------------
TbMatrix_3d TbMatrix_3d::GetInverse()const
{
	TbMatrix_3d Inverse;
	double det=GetDesignator();
	if(det!=0)
	{
		Inverse.proSetElement(0,0, GetMinor(1,1,1,2,2,1,2,2));
		Inverse.proSetElement(1,0,-GetMinor(1,0,1,2,2,0,2,2));
		Inverse.proSetElement(2,0, GetMinor(1,0,1,1,2,0,2,1));
		Inverse.proSetElement(0,1,-GetMinor(0,1,0,2,2,1,2,2));
		Inverse.proSetElement(1,1, GetMinor(0,0,0,2,2,0,2,2));
		Inverse.proSetElement(2,1,-GetMinor(0,0,0,1,2,0,2,1));
		Inverse.proSetElement(0,2, GetMinor(0,1,0,2,1,1,1,2));
		Inverse.proSetElement(1,2,-GetMinor(0,0,0,2,1,0,1,2));
		Inverse.proSetElement(2,2, GetMinor(0,0,0,1,1,0,1,1));
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				Inverse.proSetElement(i,j,Inverse.proGetElement(i,j)/det);
            }
		}
	}
	return Inverse;
}
//---------------------------------------------------------------------------
double TbMatrix_3d::GetMinor(const int &i00,const int &j00,
							 const int &i01,const int &j01,
							 const int &i10,const int &j10,
							 const int &i11,const int &j11)const
{
	return proGetElement(i00,j00)*proGetElement(i11,j11)-
		   proGetElement(i01,j01)*proGetElement(i10,j10);
}
//---------------------------------------------------------------------------
TbMatrix_3d& TbMatrix_3d::operator = (const TbMatrix_d &Matrix)
{
	if(Matrix.GetRowCount()==3 && Matrix.GetColCount()==3)
	{
		TbMatrix_d::operator =(Matrix);
	}
	return *this;
}
//---------------------------------------------------------------------------
TbMatrix_3d& TbMatrix_3d::operator = (const TbMatrix_3d &Matrix)
{
	TbMatrix_d::operator =(Matrix);
	return *this;
}
//---------------------------------------------------------------------------
TbMatrix_3d TbMatrix_3d::GetBasicTriangle()
{
	return TbMatrix_3d( 0,2,1,
					   -1,0,1,
					    1,0,1);
}
//---------------------------------------------------------------------------
TbMatrix_3d TbMatrix_3d::GetMatrixConverting(const TbMatrix_3d &From,
							   const TbMatrix_3d &To)
{
	TbMatrix_3d FromInvers=From.GetInverse();
	FromInvers=FromInvers*To;
	return FromInvers;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

