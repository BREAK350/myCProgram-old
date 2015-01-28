//---------------------------------------------------------------------------
#ifndef TbIntFractionH
#define TbIntFractionH
#include <vcl.h>
//---------------------------------------------------------------------------
class TbIntFraction
{
	private:
		int numerator; // ���������
		int denominator; // ���������

		void reduce(); // ��������� ���, ���� �������
	public:
		TbIntFraction();
		TbIntFraction(const int &numerator);
		TbIntFraction(const int &numerator, const int &denominator);

		String toString ()const;
		//operator double ()const;
		TbIntFraction operator + (const TbIntFraction &fract)const;
		TbIntFraction operator - (const TbIntFraction &fract)const;
		TbIntFraction operator * (const TbIntFraction &fract)const;
		TbIntFraction operator / (const TbIntFraction &fract)const;

		bool operator == (const TbIntFraction &fract)const;
		bool operator != (const TbIntFraction &fract)const;
		bool operator > (const TbIntFraction &fract)const;
		bool operator >= (const TbIntFraction &fract)const;
		bool operator < (const TbIntFraction &fract)const;
		bool operator <= (const TbIntFraction &fract)const;
	// STATIC
	public:
		static TbIntFraction convertFrom(const String &str);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
