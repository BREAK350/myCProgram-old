//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void T_Planet::Interection(T_Planet &p)
{
    double d=Where.Distance(p.Where),h=0;
    if(d>m+p.m)
    {
        h=G*m*p.m/(d*d);
        T_Vector p1(Where,p.Where),p2(p.Where,Where);
        p1.SetLength(h/m);
        p2.SetLength(h/p.m);
        Power=Power+p1;
        p.Power=p.Power+p2;
    }
}
//---------------------------------------------------------------------------
T_Space::T_Space(const int &n,const int &mmin,const int &mmax,
	const TRect &r)
{
	this->r = r;
	N=(n>0)?(n):(0);
	currPlanet = 0;
	scale = 1;
    if(N)
    {
        int i;
        Planet=new T_Planet[N];
        randomize();
        for(i=0;i<N;i++)
        {
            Planet[i].m=random(mmax)+mmin;
            Planet[i].Where.Init(random(r.Right-r.Left)+r.Left,random(r.Bottom-r.Top)+r.Top);
        }
    }
    else
    {
        Planet=NULL;
    }
}
//---------------------------------------------------------------------------
void T_Space::Interection()
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            Planet[i].Interection(Planet[j]);
        }
    }
}
//---------------------------------------------------------------------------
void T_Planet::Draw(TCanvas *Canvas)
{
	Canvas->Ellipse(Where.X - m, Where.Y - m, Where.X + m, Where.Y + m);
}
//---------------------------------------------------------------------------
void T_Planet::Draw(TCanvas *Canvas, const T_Planet &planet,
	const T_Vector &shift, const int &scale)
{
	Canvas->Ellipse((Where.X - planet.Where.X)/scale + shift.X - m,
					(Where.Y - planet.Where.Y)/scale + shift.Y - m,
					(Where.X - planet.Where.X)/scale + shift.X + m,
					(Where.Y - planet.Where.Y)/scale + shift.Y + m);
}
//---------------------------------------------------------------------------
void T_Space::Draw(TCanvas *Canvas)
{
	int i;
	for(i=0;i<N;i++)
	{
		Planet[i].Draw(Canvas);
	}
}
//---------------------------------------------------------------------------
void T_Space::Draw(TCanvas *Canvas, const int &iPlanet)
{
	T_Vector shift(r.Width()/2, r.Height()/2);
	for(int i=0; i < N ; i++)
	{
		Planet[i].Draw(Canvas, Planet[iPlanet], shift, scale);
	}
	Canvas->TextOutA(5, 5, Planet[iPlanet].Power.Length());
}
//---------------------------------------------------------------------------
void T_Space::Draw(TCanvas *Canvas, const bool &drawCurr)
{
	if(drawCurr)
	{
		Draw(Canvas, currPlanet);
	}
	else
	{
		Draw(Canvas);
    }
}
//---------------------------------------------------------------------------
void T_Space::nextPlanet()
{
	currPlanet++;
	if(currPlanet >= N)
	{
		currPlanet = 0;
	}
}
//---------------------------------------------------------------------------
void T_Space::prevPlanet()
{
	currPlanet--;
	if(currPlanet<0)
	{
        currPlanet = N - 1;
    }
}
//---------------------------------------------------------------------------
void T_Space::setScale(const int &newScale)
{
	scale = newScale;
}
//---------------------------------------------------------------------------
void T_Planet::Move()
{
    Where=Where+Power;
}
//---------------------------------------------------------------------------
void T_Space::Move()
{
    int i;
    for(i=0;i<N;i++)
    {
        Planet[i].Move();
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 