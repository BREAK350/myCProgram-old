//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Matrix4.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Matrix4::T_Matrix4()
{
    int i,j;
    for(i=0;i<4;++i)
    {
        for(j=0;j<4;++j)
        {
            e[i][j]=0;
        }
    }
}
//---------------------------------------------------------------------------
T_Matrix4::T_Matrix4(const float &e00,const float &e01,const float &e02,const float &e03,
                     const float &e10,const float &e11,const float &e12,const float &e13,
                     const float &e20,const float &e21,const float &e22,const float &e23,
                     const float &e30,const float &e31,const float &e32,const float &e33)
{
    e[0][0]=e00;
    e[0][1]=e01;
    e[0][2]=e02;
    e[0][3]=e03;
    e[1][0]=e10;
    e[1][1]=e11;
    e[1][2]=e12;
    e[1][3]=e13;
    e[2][0]=e20;
    e[2][1]=e21;
    e[2][2]=e22;
    e[2][3]=e23;
    e[3][0]=e30;
    e[3][1]=e31;
    e[3][2]=e32;
    e[3][3]=e33;
}
//---------------------------------------------------------------------------
T_Matrix4 T_Matrix4::operator * (const T_Matrix4 &M)
{
    int i,j,k;
    T_Matrix4 R;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            R.e[i][j]=0;
            for(k=0;k<4;k++)
            {
                R.e[i][j]+=e[i][k]*M.e[k][j];
            }
        }
    }
    return R;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
