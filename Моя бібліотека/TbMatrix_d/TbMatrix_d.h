//---------------------------------------------------------------------------
#ifndef TbMatrix_dH
#define TbMatrix_dH
#include <stdio.h>
//---------------------------------------------------------------------------
class TbMatrix_d
{
    private:
		int RowCount,ColCount;
		double **Element;
	protected:
		void proSetElement(const int &irow,const int &icol,const double &Value);
		double proGetElement(const int &irow,const int &icol)const;
		bool isCorrect(const int &irow,const int &icol)const;
	public:
		TbMatrix_d();
		TbMatrix_d(const TbMatrix_d &Matrix);
		TbMatrix_d(const int &RowCount,const int &ColCount);
		~TbMatrix_d();

		TbMatrix_d&  operator = (const TbMatrix_d &Matrix);
		TbMatrix_d&  operator += (const TbMatrix_d &Matrix);
		TbMatrix_d&  operator -= (const TbMatrix_d &Matrix);
		TbMatrix_d&  operator *= (const TbMatrix_d &Matrix);
		TbMatrix_d   operator + (const TbMatrix_d &Matrix)const;
		TbMatrix_d   operator - (const TbMatrix_d &Matrix)const;
		TbMatrix_d   operator * (const TbMatrix_d &Matrix)const;
        TbMatrix_d   operator * (const double &value)const;

        int          GetRowCount()const { return RowCount; }
		int          GetColCount()const { return ColCount; }

		double GetElement(const int &irow,const int &icol)const;
        void SetElement(const int &irow,const int &icol,const double &Value);
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
