//---------------------------------------------------------------------------
#ifndef TbNumberH
#define TbNumberH
#include "TbIntFraction.h";
//---------------------------------------------------------------------------
/*
	�� ����� ���� a/c*M+b/d, �� a, b - ���, c, d - ���������.
	�������� ��������:
		+
		-
		* (�� �����, �� ���� ���� ������� ������ M)
		/ (�� �����, �� ���� ��������� ������ M)
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
