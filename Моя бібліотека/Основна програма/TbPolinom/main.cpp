//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <tchar.h>
#include "TbNumber.h"
#include <conio.h>
//---------------------------------------------------------------------------

#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
	TbNumber a(2,5), b(-9);
	TbNumber c = a + b;
	cout << c.toString().t_str() << endl;
	while(c != 0)
	{
		char str[100];
		cin >> str;
		c = TbNumber::convertFrom(str);
		cout << c.toString().t_str() << endl;
    }
	getch();
	return 0;
}
//---------------------------------------------------------------------------
