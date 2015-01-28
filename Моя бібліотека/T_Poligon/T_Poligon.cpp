//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Poligon.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Poligon::T_Poligon()
{
    n=0;
    p=NULL;
    clPen=clBlack;
    clBrush=clWhite;
}
//---------------------------------------------------------------------------
T_Poligon::T_Poligon(int _n,TColor _clPen,TColor _clBrush,T_Point *_p)
{
    int i;
    if(_n<=0)
    {
        n=0;
        p=NULL;
    }
    n=_n;
    p=new T_Point[n];
    for(i=0;i<n;i++)
    {
        p[i]=_p[i];
    }
    clPen=_clPen;
    clBrush=_clBrush;
}
//---------------------------------------------------------------------------
T_Poligon::~T_Poligon()
{
    Delete();
}
//---------------------------------------------------------------------------
T_Point T_Poligon::operator [] (int i)
{
    if(i<0 || i>=n)
    {
        return p[0];
    }
    return p[i];
}
//---------------------------------------------------------------------------
void T_Poligon::Delete()
{
    delete[] p;
    p=NULL;
    n=0;
    clPen=clBlack;
    clBrush=clWhite;
}
//---------------------------------------------------------------------------
void T_Poligon::Init(int _n,TColor _clPen,TColor _clBrush,T_Point *_p)
{
    int i;
    if(_n<=0)
    {
        return;
    }
    Delete();
    n=_n;
    p=new T_Point[n];
    for(i=0;i<n;i++)
    {
        p[i]=_p[i];
    }
    clPen=_clPen;
    clBrush=_clBrush;
}
//---------------------------------------------------------------------------
T_Poligon::T_Poligon(const T_Poligon &Pol)
{
    int i;
    n=Pol.n;
    p=new T_Point[n];
    for(i=0;i<n;i++)
    {
        p[i]=Pol.p[i];
    }
    clPen=Pol.clPen;
    clBrush=Pol.clBrush;
}
//---------------------------------------------------------------------------
T_Poligon& T_Poligon::operator = (const T_Poligon &Pol)
{
    int i;
    if(this==&Pol)
    {
        return *this;
    }
    Delete();
    n=Pol.n;
    p=new T_Point[n];
    for(i=0;i<n;i++)
    {
        p[i]=Pol.p[i];
    }
    clPen=Pol.clPen;
    clBrush=Pol.clBrush;
    return *this;
}
//---------------------------------------------------------------------------
void T_Poligon::Draw(TCanvas *Canvas,T_Point tp,float s,float angle)
{
    int i;
    TColor clP,clB;
    TPoint *point=new TPoint[n];
    for(i=0;i<n;i++)
    {
        T_Vector v(p[i]);
        v=v*s;
        v.Rotate(angle);
        v=v+tp;
        point[i]=v;
    }
    clP=Canvas->Pen->Color;
    clB=Canvas->Brush->Color;
    Canvas->Pen->Color=clPen;
    Canvas->Brush->Color=clBrush;
    Canvas->Polygon(point,n-1);
    Canvas->Pen->Color=clP;
    Canvas->Brush->Color=clB;
    delete point;
    point=NULL;
}
//---------------------------------------------------------------------------
void T_Poligon::SaveToFile(FILE *f)
{
    fwrite(&n,sizeof(int),1,f);
    fwrite(p,sizeof(T_Point),n,f);
    fwrite(&clPen,sizeof(TColor),1,f);
    fwrite(&clBrush,sizeof(TColor),1,f);
}
//---------------------------------------------------------------------------
void T_Poligon::LoadFromFile(FILE *f)
{
    fread(&n,sizeof(int),1,f);
    if(n<=0)
    {
        return;
    }
    p=new T_Point[n];
    fread(p,sizeof(T_Point),n,f);
    fread(&clPen,sizeof(TColor),1,f);
    fread(&clBrush,sizeof(TColor),1,f);
}
//---------------------------------------------------------------------------
void T_Poligon::SaveToFile(char *fname)
{
    FILE *f;
    f=fopen(fname,"wb");
    SaveToFile(f);
    fclose(f);
}
//---------------------------------------------------------------------------
void T_Poligon::LoadFromFile(char *fname)
{
    FILE *f;
    f=fopen(fname,"rb");
    if(!f)
    {
        return;
    }
    Delete();
    LoadFromFile(f);
    fclose(f);
}
//---------------------------------------------------------------------------
T_Point& T_Poligon::operator [] (const int &i)
{
    return p[i];
}
//---------------------------------------------------------------------------
void T_Poligon::Rotate(const T_Point &Point,const float &angle)
{
    int i;
    T_Vector v;
    for(i=0;i<n;i++)
    {
        v=T_Vector(p[i])-Point;
        v.Rotate(angle);
        p[i]=v+Point;
    }
}
//---------------------------------------------------------------------------
void T_Poligon::Shift(const T_Vector &Vector)
{
    int i;
    for(i=0;i<n;i++)
    {
        p[i]=Vector+p[i];
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 