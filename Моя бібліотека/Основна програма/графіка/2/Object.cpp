//---------------------------------------------------------------------------
#pragma hdrstop
#include "Object.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void T_Object::DoMatrix(const T_Matrix4 &M)
{
    oT_Point3s oBuf=Const.GetoT_Point3s();
    oBuf=oBuf*M;
    Buf=oBuf.GetT_Point3s();
}
//---------------------------------------------------------------------------
void T_Object::Draw(T_Display &Display,const int &x,const int &y)
{
    int i,n=Borders.GetN();
    for(i=0;i<n;i++)
    {
        DrawTriangle(i,Display,x,y);
    }
}
//---------------------------------------------------------------------------
int min(const int &a,const int &b)
{
    return (a>b)?(b):(a);
}
//---------------------------------------------------------------------------
int max(const int &a,const int &b)
{
    return (a>b)?(a):(b);
}
//---------------------------------------------------------------------------
int Cross(const T_Point3 &P1,const T_Point3 &P2,const int &y,T_Point3 &p)
{
    int q=0;
    int y1=P1.y,y2=P2.y;
    if(y2-y1)
    {
        float t=(float)(y-y1)/(y2-y1);
        if(t>=0 && t<=1)
        {
            q=1;
            p.x=(P2.x-P1.x)*t+P1.x;
            p.y=y;
            p.z=(P2.z-P1.z)*t+P1.z;
        }
    }
    else
    {
        if(y1==y)
        {
            q=-1;
        }
    }
    return q;
}
//---------------------------------------------------------------------------
int MinMaxX(const T_Point3 &P1,const T_Point3 &P2,const T_Point3 &P3,
    const int &y,T_Point3 &pmin,T_Point3 &pmax)
{
    int q=1,q12,q13,q23;
    T_Point3 x12,x13,x23;
    q12=Cross(P1,P2,y,x12);
    q13=Cross(P1,P3,y,x13);
    q23=Cross(P2,P3,y,x23);
    if(q12)
    {
        pmin=x12;
        pmax=x12;
    }
    else
    if(q13)
    {
        pmin=x13;
        pmax=x13;
    }
    else
    if(q23)
    {
        pmin=x23;
        pmax=x23;
    }
    else
    {
        q=0;
    }
    if(q12)
    {
        pmin=(pmin.x>x12.x)?(x12):(pmin);
        pmax=(pmax.x<x12.x)?(x12):(pmax);
    }
    if(q13)
    {
        pmin=(pmin.x>x13.x)?(x13):(pmin);
        pmax=(pmax.x<x13.x)?(x13):(pmax);
    }
    if(q23)
    {
        pmin=(pmin.x>x23.x)?(x23):(pmin);
        pmax=(pmax.x<x23.x)?(x23):(pmax);
    }
    return q;
}
//---------------------------------------------------------------------------
float TriangleColor(const T_Point3 &P1,const T_Point3 &P2,const T_Point3 &P3,const T_Point3 &N)
{
    T_Point3 P12,P13,P;
    P12.x=P2.x-P1.x;
    P12.y=P2.y-P1.y;
    P12.z=P2.z-P1.z;

    P13.x=P3.x-P1.x;
    P13.y=P3.y-P1.y;
    P13.z=P3.z-P1.z;

    P.x=P12.y*P13.z-P12.z*P13.y;
    P.y=P12.z*P13.x-P12.x*P13.z;
    P.z=P12.x*P13.y-P12.y*P13.x;

    float scalar=P.x*N.x+P.y*N.y+P.z*N.z;
    float cosfi=scalar/sqrt((P.x*P.x+P.y*P.y+P.z*P.z)*(N.x*N.x+N.y*N.y+N.z*N.z));
    float fi=acos(cosfi);
    if(fi>M_PI/2)
    {
        fi=M_PI-fi;
    }
    return fi*180/M_PI;
}
//---------------------------------------------------------------------------
void T_Object::DrawTriangle(const int &i,T_Display &Display,const int &_x,const int &_y)
{
    int y,z,ymax,cx=Display.GetM()/2,cy=Display.GetN()/2;
    T_Triangle T;
    Borders.GetElement(i,T);
    T_Point3 P[3],a,b;
    Buf.GetPoint(T.Point[0],P[0]);
    Buf.GetPoint(T.Point[1],P[1]);
    Buf.GetPoint(T.Point[2],P[2]);

    y=min(P[0].y,min(P[1].y,P[2].y));
    if(y<-cy)
    {
        y=-cy;
    }
    ymax=max(P[0].y,max(P[1].y,P[2].y));
    if(ymax>cy)
    {
        ymax=cy;
    }
    float fi=TriangleColor(P[0],P[1],P[2],T_Point3(0,0,1));
    T_Data Pixel;
    Pixel.Color=(TColor)RGB(256-256*(fi+9)/100,256-256*(fi+9)/100,256-256*(fi+9)/100);
    for(;y<ymax;y++)
    {
        if(MinMaxX(P[0],P[1],P[2],y,a,b)==1)
        {
            int n=fabs(b.x-a.x);
            if(n)
            {
                float h=1.0/n,t=0;
                while(t<1)
                {
                    Pixel.Z=(b.z-a.z)*t+a.z;
                    Display.SetData(a.x+cx,-y+cy,Pixel);
                    t+=h;
                    a.x++;
                }
            }
        }
    }
}
//---------------------------------------------------------------------------
void T_Object::SaveToFile(ofstream &ofs)
{
    Const.SaveToFile(ofs);
    ofs<<endl;
    int n=Borders.GetN();
    ofs<<n<<endl;
    T_Triangle tr;
    int i;
    for(i=0;i<n;i++)
    {
        Borders.GetElement(i,tr);
        tr.SaveToFile(ofs);
        ofs<<endl;
    }
}
//---------------------------------------------------------------------------
void T_Object::LoadFromFile(ifstream &ifs)
{
    Const.LoadFromFile(ifs);
    Buf=Const;
    int i,n;
    ifs>>n;
    T_Triangle tr;
    Borders.SetN(n);
    for(i=0;i<n;i++)
    {
        tr.LoadFromFile(ifs);
        Borders.SetElement(i,tr);
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

