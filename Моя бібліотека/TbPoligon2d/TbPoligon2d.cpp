//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbPoligon2d.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void TbPoligon2d::Draw(TbOrientation &Or)const
{
    if(GetCount()>1)
    {
        Or.Polygon(*this,GetCount());
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
