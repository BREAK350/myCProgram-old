//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include "T_Geometry.h"
const double G = 10;
//---------------------------------------------------------------------------
class T_Planet
{
    public:
		T_Vector Where,Power;
        double m;
    public:
        void Interection(T_Planet &p);
		void Draw(TCanvas *Canvas);
		void Draw(TCanvas *Canvas, const T_Planet &planet,
			const T_Vector &shift, const int &scale);
        void Move();
};
//---------------------------------------------------------------------------
class T_Space
{
    protected:
        T_Planet *Planet;
		int N;
		TRect r;
		int currPlanet;
		int scale;
    public:
		T_Space(const int &n,const int &mmin,const int &mmax,
			const TRect &r);
        void Interection();
		void Draw(TCanvas *Canvas);
		void Draw(TCanvas *Canvas, const int &iPlanet);
		void Draw(TCanvas *Canvas, const bool &drawCurr);
		void Move();

		void nextPlanet();
		void prevPlanet();

		void setScale(const int &newScale);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 