//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void T_Corpus::Init(const float &_x1,const float &_y1,const float &_x2,const float &_y2,
              const float &_xp,const float &_yp,const float &_rp,const float &_dp,
              const float &_angle,const TColor &corpus,const TColor &pushka)
{
    x1=_x1;
    y1=_y1;
    x2=_x2;
    y2=_y2;
    xp=_xp;
    yp=_yp;
    rp=_rp;
    dp=_dp;
    angle=_angle;
    Corpus=corpus;
    Pushka=pushka;
}
//---------------------------------------------------------------------------
T_Corpus::T_Corpus(const float &_x1,const float &_y1,const float &_x2,const float &_y2,
             const float &_xp,const float &_yp,const float &_rp,const float &_dp,
             const float &_angle,const TColor &corpus,const TColor &pushka)
{
    Init(_x1,_y1,_x2,_y2,_xp,_yp,_rp,_dp,_angle,corpus,pushka);
}
//---------------------------------------------------------------------------
T_Corpus::T_Corpus()
{
    Init(-150,200,150,-200,0,50,100,250,0,clWhite,clWhite);
}
//---------------------------------------------------------------------------
void T_Corpus::Draw(TCanvas *Canvas,const TPoint &Centre)
{
    TPoint pol[4];
    pol[0];
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
