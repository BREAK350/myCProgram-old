//---------------------------------------------------------------------------
#pragma hdrstop
#include "oT_Point3.h"
#pragma package(smart_init)
#include "T_Matrix4.h"
//---------------------------------------------------------------------------
oT_Point3 oT_Point3::operator * (const T_Matrix4 &M)
{
    int i,j;
    oT_Point3 r;
    for(i=0;i<4;++i)
    {
        for(j=0;j<4;++j)
        {
            r.c[i]+=c[j]*M.e[j][i];
        }
    }
    return r;
}
/*
    ����� �� ������ ��������� �� �������
*/
//---------------------------------------------------------------------------
T_Point3 oT_Point3::toT_Point3()
{
    T_Point3 R;
    if(c[3])
    {
        R.x=c[0]/c[3];
        R.y=c[1]/c[3];
        R.z=c[2]/c[3];
    }
    return R;
}
/*
    � ��������� ��������� ������� �������� ����������
*/
//---------------------------------------------------------------------------

