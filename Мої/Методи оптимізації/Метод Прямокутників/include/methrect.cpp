//---------------------------------------------------------------------------
#pragma hdrstop
#include "methrect.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
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
IntFraction::IntFraction()
{
	numerator = 0;
	denominator = 1;
}
//---------------------------------------------------------------------------
IntFraction::IntFraction(const int &numerator)
{
	this->numerator = numerator;
	denominator = 1;
}
//---------------------------------------------------------------------------
IntFraction::IntFraction(const int &numerator, const int &denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
	reduce();
}
//---------------------------------------------------------------------------
IntFraction::operator String ()const
{
	String res = String(numerator);
	if(numerator != 0 && denominator != 1)
	{
		res = res + '/' + String(denominator);
	}
	return res;
}
//---------------------------------------------------------------------------
//IntFraction::operator double ()const
//{
//	return numerator / denominator;
//}
//---------------------------------------------------------------------------
void IntFraction::reduce()
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
IntFraction IntFraction::operator + (const IntFraction &fract)const
{
	return IntFraction(numerator * fract.denominator +
		fract.numerator * denominator,
		denominator * fract.denominator);
}
//---------------------------------------------------------------------------
IntFraction IntFraction::operator - (const IntFraction &fract)const
{
	return IntFraction(numerator * fract.denominator -
		fract.numerator * denominator,
		denominator * fract.denominator);
}
//---------------------------------------------------------------------------
IntFraction IntFraction::operator * (const IntFraction &fract)const
{
	return IntFraction(numerator * fract.numerator,
		denominator * fract.denominator);
}
//---------------------------------------------------------------------------
IntFraction IntFraction::operator / (const IntFraction &fract)const
{
	return IntFraction(numerator * fract.denominator,
		denominator * fract.numerator);
}
//---------------------------------------------------------------------------
bool IntFraction::operator == (const IntFraction &fract)const
{
	return numerator == fract.numerator && denominator == fract.denominator;
}
//---------------------------------------------------------------------------
bool IntFraction::operator != (const IntFraction &fract)const
{
	return !operator == (fract);
}
//---------------------------------------------------------------------------
IntFraction convertFrom(const String &str)
{
	IntFraction res;
	if(str.Length() > 0)
	{
		int i = str.Pos("/");
		if(i > 0)
		{
			String num = str.SubString(0, i - 1);
			String den = str.SubString(i + 1, str.Length() - i);
			res = IntFraction(num.ToInt(), den.ToInt());
		}
		else
		{
        	res = IntFraction(str.ToInt());
        }
	}
	return res;
}
//---------------------------------------------------------------------------
bool IntFraction::operator > (const IntFraction &fract)const
{
	return numerator / denominator > fract.numerator / fract.denominator;
}
//---------------------------------------------------------------------------
bool IntFraction::operator >= (const IntFraction &fract)const
{
	return numerator / denominator >= fract.numerator / fract.denominator;
}
//---------------------------------------------------------------------------
bool IntFraction::operator < (const IntFraction &fract)const
{
	return numerator / denominator < fract.numerator / fract.denominator;
}
//---------------------------------------------------------------------------
bool IntFraction::operator <= (const IntFraction &fract)const
{
	return numerator / denominator <= fract.numerator / fract.denominator;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

