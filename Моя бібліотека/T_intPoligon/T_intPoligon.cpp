//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_intPoligon.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_intPoligon& T_intPoligon::operator = (const T_intPoligon &intPoligon)
{
    if(this!=&intPoligon)
    {
        T_Array <TPoint>::operator = (intPoligon);
    }
    return *this;
}
//---------------------------------------------------------------------------
void T_intPoligon::Draw(TCanvas *Canvas)
{
    Canvas->Polygon(GetArray(),GetN()-1);
}
//---------------------------------------------------------------------------
void T_intPoligon::Shift(const TPoint &vector)
{
    int i,n=GetN();
    for(i=0;i<n;i++)
    {
        this->operator [](i).x=this->operator [](i).x+vector.x;
        this->operator [](i).y=this->operator [](i).y+vector.y;
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
