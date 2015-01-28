//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbNumber.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbNumber::TbNumber():A(),B()
{

}
//---------------------------------------------------------------------------
TbNumber::TbNumber(const TbIntFraction &A, const TbIntFraction &B)
	:A(A), B(B)
{
}
//---------------------------------------------------------------------------
TbNumber::TbNumber(const int &a, const int &c, const int &b, const int &d)
	:A(a, c), B(b, d)
{
}
//---------------------------------------------------------------------------
TbNumber::TbNumber(const TbIntFraction &B): A(), B(B)
{
}
//---------------------------------------------------------------------------
TbNumber::TbNumber(const int &a, const int &b): A(a), B(b)
{
}
//---------------------------------------------------------------------------
TbNumber::TbNumber(const int &b): A(), B(b)
{
}
//---------------------------------------------------------------------------
TbNumber TbNumber::operator + (const TbNumber &num)const
{
	return TbNumber(A + num.A, B + num.B);
}
//---------------------------------------------------------------------------
TbNumber TbNumber::operator - (const TbNumber &num)const
{
	return TbNumber(A - num.A, B - num.B);
}
//---------------------------------------------------------------------------
TbNumber TbNumber::operator * (const TbNumber &num)const
{
	if(A == 0)
	{
		return TbNumber(num.A * B, num.B * B);
	}
	if(num.A == 0)
	{
    	return TbNumber(A * num.B, B * num.B);
	}
	throw ("недопустимий множник");
}
//---------------------------------------------------------------------------
TbNumber TbNumber::operator / (const TbNumber &num)const
{
	if(num.A == 0)
	{
    	return TbNumber(A / num.B, B / num.B);
	}
	throw ("недопустимий знаменник");
}
//---------------------------------------------------------------------------
String TbNumber::toString ()const
{
	String res = "";
	if(A != 0)
	{
		if(A != 1)
		{
			res = A.toString() + "M";
		}
		else
		{
            res = "M";
        }
		if(B != 0)
		{
			if(B > 0)
			{
				res = res + "+";
			}
			res = res + B.toString();
        }
	}
	else
	{
		res = B.toString();
    }
	return res;
}
//---------------------------------------------------------------------------
bool TbNumber::operator == (const TbNumber &num)const
{
	return A == num.A && B == num.B;
}
//---------------------------------------------------------------------------
bool TbNumber::operator != (const TbNumber &num)const
{
	return !operator ==(num);
}
//---------------------------------------------------------------------------
bool TbNumber::operator > (const TbNumber &num)const
{
	if(A > num.A)
	{
		return true;
	}
	if(A < num.A)
	{
		return false;
	}
	if(B > num.B)
	{
		return true;
	}
	return false;
}
//---------------------------------------------------------------------------
bool TbNumber::operator >= (const TbNumber &num)const
{
	return *this == num && *this > num;
}
//---------------------------------------------------------------------------
bool TbNumber::operator < (const TbNumber &num)const
{
	if(A < num.A)
	{
		return true;
	}
	if(A > num.A)
	{
		return false;
	}
	if(B < num.B)
	{
		return true;
	}
	return false;
}
//---------------------------------------------------------------------------
bool TbNumber::operator <= (const TbNumber &num)const
{
	return *this == num && *this < num;
}
//---------------------------------------------------------------------------
TbNumber TbNumber::convertFrom(const String &str)
{
	TbNumber res;
	if(str.Length() > 0)
	{
		int i = str.Pos("M");
		if(i > 0)
		{
			String strA = str.SubString(0, i - 1);
			String strB = str.SubString(i + 1, str.Length() - i);

			TbIntFraction A(1);
			if(i > 1)
			{
				A = TbIntFraction::convertFrom(strA);
			}
			TbIntFraction B = TbIntFraction::convertFrom(strB);
			res = TbNumber(A, B);
		}
		else
		{
			res = TbNumber(TbIntFraction::convertFrom(str));
        }
    }
	return res;
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

