//---------------------------------------------------------------------------
#ifndef TbMatrix_3dH
#define TbMatrix_3dH
#include "TbMatrix_d.h"
#include <math.h>
//---------------------------------------------------------------------------
class TbMatrix_3d:public TbMatrix_d
{
	public:
		enum TbConverting
		{
			ROTATION,     // 0 поворот
			DILATION,     // 1 масштабування
			TRANSLATION,  // 2 перенесення
			REFLECTION_X, // 3 дзеркальне відображення відносно осі X
			REFLECTION_Y  // 4 дзеркальне відображення відносно осі Y
		};
	protected:
		double GetDesignator()const; // визначник
		double GetMinor(const int &i00,const int &j00,
						const int &i01,const int &j01,
						const int &i10,const int &j10,
						const int &i11,const int &j11)const;
	public:
		TbMatrix_3d():TbMatrix_d(3,3) {}
		TbMatrix_3d(const TbMatrix_3d &Matrix);
		TbMatrix_3d(const double &e00,const double &e01,const double &e02,
					const double &e10,const double &e11,const double &e12,
					const double &e20,const double &e21,const double &e22);
		// створення матриць перетворення
		static TbMatrix_3d GetRotation(const double &fi);
		static TbMatrix_3d GetDilation(const double &dx,const double &dy);
		static TbMatrix_3d GetTranslation(const double &dx,const double &dy);
		static TbMatrix_3d GetReflectionX();
		static TbMatrix_3d GetReflectionY();
		static TbMatrix_3d GetBasicTriangle();
		static TbMatrix_3d GetMatrixConverting(const TbMatrix_3d &From,
							   const TbMatrix_3d &To); // From*M=To, M-?

		TbMatrix_3d GetInverse()const;
		TbMatrix_3d& operator = (const TbMatrix_3d &Matrix);
		TbMatrix_3d& operator = (const TbMatrix_d &Matrix);

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
