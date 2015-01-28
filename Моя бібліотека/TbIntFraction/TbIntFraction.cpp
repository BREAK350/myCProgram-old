//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbIntFraction.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
int nsd(int a,int b)
{
	while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*********class IntFraction**************/
TbIntFraction::TbIntFraction()
{
	numerator = 0;
	denominator = 1;
}
//---------------------------------------------------------------------------
TbIntFraction::TbIntFraction(const int &numerator)
{
	this->numerator = numerator;
	denominator = 1;
}
//---------------------------------------------------------------------------
TbIntFraction::TbIntFraction(const int &numerator, const int &denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
	reduce();
}
//---------------------------------------------------------------------------
String TbIntFraction::toString ()const
{
	String res = String(numerator);
	if(numerator != 0 && denominator != 1)
	{
		res = res + '/' + String(denominator);
	}
	return res;
}
//---------------------------------------------------------------------------
//TbIntFraction::operator double ()const
//{
//	return numerator / denominator;
//}
//---------------------------------------------------------------------------
void TbIntFraction::reduce()
{
	if(denominator < 0)
	{
		numerator = - numerator;
		denominator = - denominator;
    }
	int gcd = nsd(abs(numerator), abs(denominator));
	if(gcd > 1)
	{
		numerator /= gcd;
        denominator /= gcd;
    }
}
//---------------------------------------------------------------------------
TbIntFraction TbIntFraction::operator + (const TbIntFraction &fract)const
{
	return TbIntFraction(numerator * fract.denominator +
		fract.numerator * denominator,
		denominator * fract.denominator);
}
//---------------------------------------------------------------------------
TbIntFraction TbIntFraction::operator - (const TbIntFraction &fract)const
{
	return TbIntFraction(numerator * fract.denominator -
		fract.numerator * denominator,
		denominator * fract.denominator);
}
//---------------------------------------------------------------------------
TbIntFraction TbIntFraction::operator * (const TbIntFraction &fract)const
{
	return TbIntFraction(numerator * fract.numerator,
		denominator * fract.denominator);
}
//---------------------------------------------------------------------------
TbIntFraction TbIntFraction::operator / (const TbIntFraction &fract)const
{
	return TbIntFraction(numerator * fract.denominator,
		denominator * fract.numerator);
}
//---------------------------------------------------------------------------
bool TbIntFraction::operator == (const TbIntFraction &fract)const
{
	return numerator == fract.numerator && denominator == fract.denominator;
}
//---------------------------------------------------------------------------
bool TbIntFraction::operator != (const TbIntFraction &fract)const
{
	return !operator == (fract);
}
//---------------------------------------------------------------------------
TbIntFraction TbIntFraction::convertFrom(const String &str)
{
	TbIntFraction res;
	if(str.Length() > 0)
	{
		int i = str.Pos("/");
		if(i > 0)
		{
			String num = str.SubString(0, i - 1);
			String den = str.SubString(i + 1, str.Length() - i);
			res = TbIntFraction(num.ToInt(), den.ToInt());
		}
		else
		{
        	res = TbIntFraction(str.ToInt());
        }
	}
	return res;
}
//---------------------------------------------------------------------------
bool TbIntFraction::operator > (const TbIntFraction &fract)const
{
	return numerator / denominator > fract.numerator / fract.denominator;
}
//---------------------------------------------------------------------------
bool TbIntFraction::operator >= (const TbIntFraction &fract)const
{
	return numerator / denominator >= fract.numerator / fract.denominator;
}
//---------------------------------------------------------------------------
bool TbIntFraction::operator < (const TbIntFraction &fract)const
{
	return numerator / denominator < fract.numerator / fract.denominator;
}
//---------------------------------------------------------------------------
bool TbIntFraction::operator <= (const TbIntFraction &fract)const
{
	return numerator / denominator <= fract.numerator / fract.denominator;
}
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
