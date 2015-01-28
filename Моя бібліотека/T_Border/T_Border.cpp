//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Border.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void T_Border::Draw(TCanvas *Canvas,const T_Point3s &Point3s,const T_Point3 &Norm)
{
    int i,_i,n;
    T_Point3 Normal=GetNotmal(Point3s);
    if(Normal.Scalar(Norm)<=0)
    {
        T_Point3 p3;
        TPoint *p=new TPoint[n=Index.GetN()];
        for(i=0;i<n;i++)
        {
            Index.GetElement(i,_i);
            Point3s.GetPoint(_i,p3);
            p[i].x=p3.x;
            p[i].y=p3.y;
        }
        Canvas->Polygon(p,n-1);
    }
}
//---------------------------------------------------------------------------
void T_Border::Draw(TCanvas *Canvas,const T_Point3s &Point3s,const T_Point3 &Norm,
    const int &cx,const int &cy)
{
    int i,_i,n;
    T_Point3 Normal=GetNotmal(Point3s);
    if(Normal.Scalar(Norm)<=0)
    {
        T_Point3 p3;
        TPoint *p=new TPoint[n=Index.GetN()];
        for(i=0;i<n;i++)
        {
            Index.GetElement(i,_i);
            Point3s.GetPoint(_i,p3);
            p[i].x=p3.x+cx;
            p[i].y=-p3.y+cy;
        }
        Canvas->Polygon(p,n-1);
    }
}
//---------------------------------------------------------------------------
T_Point3 T_Border::GetNotmal(const T_Point3s &Point3s)
{
    T_Point3 a,b,c;
    int i;
    Index.GetElement(0,i);
    Point3s.GetPoint(i,a);
    Index.GetElement(1,i);
    Point3s.GetPoint(i,b);
    Index.GetElement(2,i);
    Point3s.GetPoint(i,c);
    a=b-a;
    b=c-b;
    return a.Vector(b);
}
//---------------------------------------------------------------------------
void T_Border::SaveToFile(ofstream &ofs)
{
    int i,_i,n;
    n=Index.GetN();
    ofs<<n<<endl;
    for(i=0;i<n;i++)
    {
        Index.GetElement(i,_i);
        ofs<<_i<<' ';
    }
    ofs<<endl;
}
//---------------------------------------------------------------------------
void T_Border::LoadFromFile(ifstream &ifs)
{
    int i,_i,n;
    ifs>>n;
    Index.SetN(n);
    for(i=0;i<n;i++)
    {
        ifs>>_i;
        Index.SetElement(i,_i);
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
