//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Energy::operator float()const
{
    return Mechanical+Electromagnetic+Chemical+Nuclear+Thermal+Gravitational;
}
//---------------------------------------------------------------------------
bool T_Energy::operator >= (const T_Energy &e)const
{
    return Mechanical>=e.Mechanical &&
           Electromagnetic>=e.Electromagnetic &&
           Chemical>=e.Chemical &&
           Nuclear>=e.Nuclear &&
           Thermal>=e.Thermal &&
           Gravitational>=e.Gravitational;
}
//---------------------------------------------------------------------------
bool T_Energy::operator <= (const T_Energy &e)const
{
    return Mechanical<=e.Mechanical &&
           Electromagnetic<=e.Electromagnetic &&
           Chemical<=e.Chemical &&
           Nuclear<=e.Nuclear &&
           Thermal<=e.Thermal &&
           Gravitational<=e.Gravitational;
}
//---------------------------------------------------------------------------
void T_Energy::Init(const float &m,const float &e,const float &c,const float &n,
                    const float &t,const float &g)
{
    Mechanical=m;
    Electromagnetic=e;
    Chemical=c;
    Nuclear=n;
    Thermal=t;
    Gravitational=g;
}
//---------------------------------------------------------------------------
T_Energy T_Energy::operator + (const T_Energy &e)const
{
    return T_Energy(Mechanical+e.Mechanical,Electromagnetic+e.Electromagnetic,
                    Chemical+e.Chemical,Nuclear+e.Nuclear,
                    Thermal+e.Thermal,Gravitational+e.Gravitational);
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 