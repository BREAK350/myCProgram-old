//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <tchar.h>
#include <conio.h>
#include <iostream.h>
//---------------------------------------------------------------------------

#pragma argsused
//---------------------------------------------------------------------------
int calc(int n)
{
	int summ = 0;
	if(n > 0)
	{
		int k = 1;
		int dec = 1;
		int t = n;
		while(t / 10)
		{
			t /= 10;
			summ += k * 9 * dec;
			k++;
			dec *= 10;
		}
		summ += (n - dec + 1) * k;
	}
	return summ;
}
//---------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	cout<<calc(123)<<endl;
	getch();
	return 0;
}
//---------------------------------------------------------------------------
