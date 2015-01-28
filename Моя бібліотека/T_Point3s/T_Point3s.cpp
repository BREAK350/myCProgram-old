//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Point3s.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Point3s::T_Point3s()
{
    Point=NULL;
    N=0;
}
//---------------------------------------------------------------------------
T_Point3s::T_Point3s(const int &n)
{
    N=(n>0)?(n):(0);
    if(N>0)
    {
        Point=new T_Point3[N];
    }
    else
    {
        Point=NULL;
    }
}
//---------------------------------------------------------------------------
T_Point3s::T_Point3s(const T_Point3s &Point3s)
{
    N=Point3s.N;
    if(N>0)
    {
        int i;
        Point=new T_Point3[N];
        for(i=0;i<N;i++)
        {
            Point[i]=Point3s.Point[i];
        }
    }
    else
    {
        Point=NULL;
    }
}
//---------------------------------------------------------------------------
T_Point3s::~T_Point3s()
{
    delete[] Point;
    Point=NULL;
    N=0;
}
//---------------------------------------------------------------------------
T_Point3s& T_Point3s::operator = (const T_Point3s &Point3s)
{
    if(this!=&Point3s)
    {
        if(N!=Point3s.N)
        {
            delete[] Point;
            N=Point3s.N;
            if(N>0)
            {
                Point=new T_Point3[N];
            }
            else
            {
                Point=NULL;
            }
        }
        int i;
        for(i=0;i<N;i++)
        {
            Point[i]=Point3s.Point[i];
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
oT_Point3s T_Point3s::GetoT_Point3s()
{
    oT_Point3s R(N);
    int i;
    for(i=0;i<N;i++)
    {
        R.SetoPoint(i,Point[i]);
    }
    return R;
}
//---------------------------------------------------------------------------
int T_Point3s::SetPoint(const int &i,const T_Point3 &p)
{
    int q=0;
    if(i>=0 && i<N)
    {
        Point[i]=p;
        q=1;
    }
    return q;
}
//---------------------------------------------------------------------------
int T_Point3s::GetPoint(const int &i,T_Point3 &p)const
{
    int q=0;
    if(i>=0 && i<N)
    {
        p=Point[i];
        q=1;
    }
    return q;
}
//---------------------------------------------------------------------------
void T_Point3s::SetN(const int &n)
{
    if(n>=0)
    {
        if(N!=n)
        {
            delete[] Point;
            N=n;
            if(N>0)
            {
                Point=new T_Point3[N];
            }
            else
            {
                Point=NULL;
            }
        }
    }
}
//---------------------------------------------------------------------------
void T_Point3s::SaveToFile(ofstream &ofs)
{
    ofs<<N<<endl;
    int i;
    for(i=0;i<N;i++)
    {
        Point[i].SaveToFile(ofs);
        ofs<<endl;
    }
}
//---------------------------------------------------------------------------
void T_Point3s::LoadFromFile(ifstream &ifs)
{
    delete[] Point;
    ifs>>N;
    if(N>0)
    {
        Point=new T_Point3[N];
        int i;
        for(i=0;i<N;i++)
        {
            Point[i].LoadFromFile(ifs);
        }
    }
    else
    {
        N=0;
        Point=NULL;
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
