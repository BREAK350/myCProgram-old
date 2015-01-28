//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <conio.h>

#include <tchar.h>
#include "Unit1.h"
#pragma argsused
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void test1()
{
	RefString *str = new RefString();
	str->toString();
	str->toString();
	str->toString();
	str->toString();
	str->toString();
	str->toString();
}
void test2()
{
	Test t(new RefString());
	RefString *str = (RefString*)t.get();
}
//---------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	test2();
	getch();
	return 0;
}
//---------------------------------------------------------------------------
