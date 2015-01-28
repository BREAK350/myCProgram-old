//---------------------------------------------------------------------------
#pragma hdrstop
#include "square_equation.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbSquareEquation::TbSquareEquation(const double &a, const double &b,
	const double &c)
{
	this->a = a;
	this->b = b;
	this->c = c;

	step = 0;
}
//---------------------------------------------------------------------------
TbContentsHTML* TbSquareEquation::nextStep()
{
	TbContentsHTML *contents = NULL;
	if(step == 0)
	{
        contents = formulationOfTheProblem();
	}
	else if(step == 1)
	{
		contents = calcD();
	}
	else if(step == 2)
	{
		contents = resultForD();
	}
	return contents;
}
//---------------------------------------------------------------------------
TbContentsHTML* TbSquareEquation::formulationOfTheProblem()
{
	String a_s = a, b_s = b, c_s = c;
	if(a == 1)
	{
		a_s = "";
	}
	else if(a == -1)
	{
    	a_s = "-";
	}

	if(b >= 0)
	{
		if(b == 1)
		{
            b_s = "+";
		}
		else
		{
			b_s = "+" + b_s;
        }
	}
	else if(b == -1)
	{
    	b_s = "-";
	}

	if(c >= 0)
	{
		c_s = "+" + c_s;
	}
	String text = String("Розв'язати квадратне рівняння: ") +
		a_s + "x<sup>2</sup>" + b_s + "x" + c_s + ".";
	TbTextHTML *textHTML = new TbTextHTML(text);
	TbTagHTML *h3 = new TbTagHTML("h3", false);
	h3->setContents(textHTML);
	step = 1;
	return h3;
}
//---------------------------------------------------------------------------
TbContentsHTML* TbSquareEquation::calcD()
{
	String b_s = b;
	if(b < 0)
	{
		b_s = "(" + b_s + ")";
	}
	String a_s = a;
	if(a < 0)
	{
    	a_s = "(" + a_s + ")";
	}
	String c_s = c;
	if(c < 0)
	{
		c_s = "(" + c_s + ")";
	}
	String text = String("Знаходимо дискримінант:<br>") +
		"D = " + b_s + "<sup>2</sup>" + " - 4 * " + a_s + " * " + c_s +
		" = " + (b * b - 4 * a * c);
	TbTextHTML *textHTML = new TbTextHTML(text);
	step = 2;
	return textHTML;
}
//---------------------------------------------------------------------------
TbContentsHTML* TbSquareEquation::resultForD()
{
	double D = b * b - 4 * a * c;
	String text = "";
	if(D >= 0)
	{
		double x1 = (-b - sqrt(D))/(2 * a);
		double x2 = (-b + sqrt(D))/(2 * a);
		text = String("x<sub>1</sub> = (") + "-" + b +
			"-sqrt(" + D + "))/(2 * " + a + ") = " + x1 + ";<br>";
		text += String("x<sub>2</sub> = (") + "-" + b +
			"+sqrt(" + D + "))/(2 * " + a + ") = " + x2;

		step = -1;
	}
	else
	{
		text = "Оскільки D < 0, то дане рівняння в полі дійсних чисел розв'язків на має.";
    	step = -1;
	}
	//text = "<img src=\"http://latex.numberempire.com/render?\huge {x}_{1,2}=\frac{-b\pm\sqrt{b^2-4ac}}{2a}\">";
	TbTextHTML *textHTML = new TbTextHTML(text);
	return textHTML;
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
