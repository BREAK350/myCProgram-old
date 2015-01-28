//---------------------------------------------------------------------------
#pragma hdrstop
#include "oT_Point3s.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
oT_Point3s::oT_Point3s()
{
    oPoint=NULL;
    N=0;
}
//---------------------------------------------------------------------------
oT_Point3s::oT_Point3s(const int &n)
{
    N=(n>0)?(n):(0);
    if(N>0)
    {
        oPoint=new oT_Point3[N];
    }
    else
    {
        oPoint=NULL;
    }
}
//---------------------------------------------------------------------------
oT_Point3s::oT_Point3s(const oT_Point3s &oPoint3s)
{
    N=oPoint3s.N;
    if(N>0)
    {
        int i;
        oPoint=new oT_Point3[N];
        for(i=0;i<N;i++)
        {
            oPoint[i]=oPoint3s.oPoint[i];
        }
    }
    else
    {
        oPoint=NULL;
    }
}
//---------------------------------------------------------------------------
oT_Point3s::~oT_Point3s()
{
    delete[] oPoint;
    oPoint=NULL;
    N=0;
}
//---------------------------------------------------------------------------
oT_Point3s& oT_Point3s::operator = (const oT_Point3s &oPoint3s)
{
    if(this!=&oPoint3s)
    {
        if(N!=oPoint3s.N)
        {
            delete[] oPoint;
            N=oPoint3s.N;
            if(N>0)
            {
                oPoint=new oT_Point3[N];
            }
            else
            {
                oPoint=NULL;
            }
        }
        int i;
        for(i=0;i<N;i++)
        {
            oPoint[i]=oPoint3s.oPoint[i];
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
int oT_Point3s::SetoPoint(const int &i,const oT_Point3 &op)
{
    int q=0;
    if(i>=0 && i<N)
    {
        oPoint[i]=op;
        q=1;
    }
    return q;
}
/*
    записує точку op в масив oPoint на i-му місці
*/
//---------------------------------------------------------------------------
T_Point3s oT_Point3s::GetT_Point3s()
{
    T_Point3s R(N);
    int i;
    for(i=0;i<N;i++)
    {
        R.SetPoint(i,oPoint[i].toT_Point3());
    }
    return R;
}
/*
    перетворює масив однорідних координат в масив декартових
*/
//---------------------------------------------------------------------------
oT_Point3s oT_Point3s::operator * (const T_Matrix4 &M)
{
    int i;
    oT_Point3s R(N);
    for(i=0;i<N;i++)
    {
        R.oPoint[i]=oPoint[i]*M;
    }
    return R;
}
/*
    кожну точку множить на матрицю-перетворення
*/
//---------------------------------------------------------------------------
void oT_Point3s::SetN(const int &n)
{
    if(n>=0)
    {
        if(N!=n)
        {
            delete[] oPoint;
            N=n;
            if(N>0)
            {
                oPoint=new oT_Point3[N];
            }
            else
            {
                oPoint=NULL;
            }
        }
    }
}
/*
    встановлює розмір масиву
*/
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 