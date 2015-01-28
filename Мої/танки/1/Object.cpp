//---------------------------------------------------------------------------
#pragma hdrstop
#include "Object.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Object::T_Object()
{
    n=0;
    pn=NULL;
    p=NULL;
    cl=NULL;
    Scale=0;
    Where.x=Where.y=0;
    angle=0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void T_Object::Draw(TCanvas *Canvas)
{
    int i;
    for(i=0;i<n;i++)
    {
        DrawPoligon(Canvas,i);
    }
}
//---------------------------------------------------------------------------
void T_Object::DrawPoligon(TCanvas *Canvas,int i)
{
    int j;
    TColor col;
    if(n==0)
    {
        return;
    }
    TPoint *point=new TPoint[pn[i]];
    for(j=0;j<pn[i];j++)
    {
        point[j]=toTPoint(GC(Rotate(Zoom(p[i][j]))));
    }
    col=Canvas->Brush->Color;
    Canvas->Brush->Color=cl[i];
    Canvas->Polygon(point,pn[i]-1);
    Canvas->Brush->Color=col;
    delete point;
}
//---------------------------------------------------------------------------
T_Point T_Object::GC(const T_Point &p)
{
    T_Point r;
    r.x=p.x+Where.x;
    r.y=p.y+Where.y;
    return r;
}
//---------------------------------------------------------------------------
T_Point T_Object::Rotate(const T_Point &p)
{
    T_Point r;
    r.x=p.x*cos(angle)-p.y*sin(angle);
    r.y=p.x*sin(angle)+p.y*cos(angle);
    return r;
}
//---------------------------------------------------------------------------
T_Point T_Object::Zoom(const T_Point &p)
{
    T_Point r;
    r.x=p.x*Scale;
    r.y=p.y*Scale;
    return r;
}
//---------------------------------------------------------------------------
T_Point T_Object::Move(const T_Point &p)
{
    return p;
}
//---------------------------------------------------------------------------
T_Object::T_Object(int _n,int *_pn,T_Point **_p,TColor *_cl,float _Scale,T_Point _Where, float _angle)
{
    int i,j;
    n=_n;
    pn=new int[n];
    p=new T_Point*[n];
    cl=new TColor[n];
    for(i=0;i<n;i++)
    {
        pn[i]=_pn[i];
        p[i]=new T_Point[pn[i]];
        for(j=0;j<pn[i];j++)
        {
            p[i][j]=_p[i][j];
        }
        cl[i]=_cl[i];
    }
    Scale=_Scale;
    Where=_Where;
    angle=_angle;
}
//---------------------------------------------------------------------------
T_Object::~T_Object()
{
    int i;
    delete[] pn;
    for(i=0;i<n;i++)            
    {
        delete[] p[i];
    }
    delete[] p;
    delete[] cl;
    n=0;
    pn=NULL;
    p=NULL;
    cl=NULL;
    Scale=0;
    Where.x=Where.y=0;
    angle=0;
}
//---------------------------------------------------------------------------
void T_Object::Init(int _n,int *_pn,T_Point **_p,TColor *_cl,float _Scale,T_Point _Where,float _angle)
{
    int i,j;
    delete[] pn;
    for(i=0;i<n;i++)
    {
        delete[] p[i];
    }
    delete[] p;
    delete[] cl;
    n=_n;
    pn=new int[n];
    p=new T_Point*[n];
    cl=new TColor[n];
    for(i=0;i<n;i++)
    {
        pn[i]=_pn[i];
        p[i]=new T_Point[pn[i]];
        for(j=0;j<pn[i];j++)
        {
            p[i][j]=_p[i][j];
        }
        cl[i]=_cl[i];
    }
    Scale=_Scale;
    Where=_Where;
    angle=_angle;
}
//---------------------------------------------------------------------------
void T_Object::SaveToFile(FILE *f)
{
    int i;
    fwrite(&n,sizeof(int),1,f);
    fwrite(pn,sizeof(int),n,f);
    for(i=0;i<n;i++)
    {
        fwrite(p[i],sizeof(T_Point),pn[i],f);
    }
    fwrite(cl,sizeof(TColor),n,f);
    fwrite(&Scale,sizeof(float),1,f);
    fwrite(&Where,sizeof(T_Point),1,f);
    fwrite(&angle,sizeof(float),1,f);
}
//---------------------------------------------------------------------------
void T_Object::SaveToFile(const char *fname)
{
    FILE *f;
    f=fopen(fname,"wb");
    SaveToFile(f);
    fclose(f);
}
//---------------------------------------------------------------------------
void T_Object::LoadFromFile(FILE *f)
{
    int i;
    delete[] pn;
    for(i=0;i<n;i++)
    {
        delete[] p[i];
    }
    delete[] p;
    delete[] cl;
    fread(&n,sizeof(int),1,f);
    pn=new int[n];
    fread(pn,sizeof(int),n,f);
    p=new T_Point*[n];
    for(i=0;i<n;i++)
    {
        p[i]=new T_Point[pn[i]];
        fread(p[i],sizeof(T_Point),pn[i],f);
    }
    cl=new TColor[n];
    fread(cl,sizeof(TColor),n,f);
    fread(&Scale,sizeof(float),1,f);
    fread(&Where,sizeof(T_Point),1,f);
    fread(&angle,sizeof(float),1,f);
}
//---------------------------------------------------------------------------
void T_Object::LoadFromFile(const char *fname)
{
    FILE *f;
    f=fopen(fname,"rb");
    if(!f)
    {
        return;
    }
    LoadFromFile(f);
    fclose(f);
}
//---------------------------------------------------------------------------
void T_Object::SetAngleGradus(float _angle)
{
    angle=_angle*M_PI/180;
}
//---------------------------------------------------------------------------
void T_Object::SetWhere(T_Point _Where)
{
    Where=_Where;
}
//---------------------------------------------------------------------------
float T_Object::GetDiametr()
{
    int i,j;
    float diam=0,d=0;
    for(i=0;i<n;i++)
    {
        diam=0;
        for(j=0;j<pn[i]-1;j++)
        {
            d=pDistance(p[i][j],p[i][j+1]);
            if(d>diam)
            {
                diam=d;
            }
        }
    }
    return diam;
}
//---------------------------------------------------------------------------
T_Point T_Object::SearchCenter()
{
    int i,j,k=0;
    T_Point center={0,0};
    for(i=0;i<n;i++)
    {
        k+=pn[i];
        for(j=0;j<pn[i];j++)
        {
            center=center+p[i][j];
        }
    }
    if(k!=0)
    {
        center.x=center.x/k;
        center.y=center.y/k;
    }
    return center;
}
//---------------------------------------------------------------------------
float T_Object::Distance(const T_Object &obj)
{
    return pDistance(SearchCenter(),obj.SearchCenter());
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
