//---------------------------------------------------------------------------
#ifndef TbNumberH
#define TbNumberH
#include "TbIntFraction.h";
//---------------------------------------------------------------------------
/*
	Це число виду a/c*M+b/d, де a, b - цілі, c, d - натуральні.
	Дозволені операції:
		+
		-
		* (за умови, що лише один множник містить M)
		/ (за умови, що лише чисельник містить M)
*/
class TbNumber
{
	private:
		TbIntFraction A, B;
	public:
		TbNumber();
		TbNumber(const TbIntFraction &B);
		TbNumber(const int &a, const int &b); // c = d = 1
		TbNumber(const int &b);
		TbNumber(const TbIntFraction &A, const TbIntFraction &B);
        TbNumber(const int &a, const int &c, const int &b, const int &d);

		TbNumber operator + (const TbNumber &num)const;
		TbNumber operator - (const TbNumber &num)const;
		TbNumber operator * (const TbNumber &num)const;
		TbNumber operator / (const TbNumber &num)const;

		String toString ()const;

		bool operator == (const TbNumber &num)const;
		bool operator != (const TbNumber &num)const;
		bool operator > (const TbNumber &num)const;
		bool operator >= (const TbNumber &num)const;
		bool operator < (const TbNumber &num)const;
		bool operator <= (const TbNumber &num)const;
	// STATIC
	public:
		static TbNumber convertFrom(const String &str);
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
#endif
