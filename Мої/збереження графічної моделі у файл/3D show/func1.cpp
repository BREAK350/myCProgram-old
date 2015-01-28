//---------------------------------------------------------------------------
#pragma hdrstop
#include "func1.h"
#include "Unit1.h"
Point3D P;
extern Point3D XY;
//---------------------------------------------------------------------------
int is_Line(graf *grf,int point1,int point2)
{
    if(_is_Line(grf,point1,point2)==-1)
    {
        return 1;
    }
    return 0;
}
//---------------------------------------------------------------------------
int _is_Line(graf *grf,int point1,int point2)
{
    int k,i;
    grafbit r;
    if(point1==point2 || point1<=0 || point2<=0)
    {
        return 0;
    }
    if(point1<point2)
    {
        point1=point1+point2;
        point2=point1-point2;
        point1=point1-point2;
    }
    k=0;
    point1--;
    for(i=0;i<point1;i++)
    {
        k+=i;
    }
    k=k+point2-1;
    r.d=grf[k/8];
    k=k-8*(k/8);
    switch(k)
    {
        case 0:return r.bit.b7;
        case 1:return r.bit.b6;
        case 2:return r.bit.b5;
        case 3:return r.bit.b4;
        case 4:return r.bit.b3;
        case 5:return r.bit.b2;
        case 6:return r.bit.b1;
        case 7:return r.bit.b0;
    }
}
//---------------------------------------------------------------------------
graf* _CreateGraf(int n_point)
{
    int i,k;
    for(i=0,k=0;i<n_point;i++)
    {
        k+=i;
    }
    k=k/8+1;
    return (graf*)calloc(k,sizeof(graf));
}
//---------------------------------------------------------------------------
int _CreateLine(graf*&grf,int point1,int point2)
{
    grafbit r;
    int i,k,p;
    if(point1<point2)
    {
        point1=point1+point2;
        point2=point1-point2;
        point1=point1-point2;
    }
    k=0;
    point1--;
    for(i=0;i<point1;i++)
    {
        k+=i;
    }
    k=k+point2-1;
    p=k/8;
    r.d=grf[p];
    k=k-8*(k/8);
    switch(k)
    {
        case 0:r.bit.b7=-1;break;
        case 1:r.bit.b6=-1;break;
        case 2:r.bit.b5=-1;break;
        case 3:r.bit.b4=-1;break;
        case 4:r.bit.b3=-1;break;
        case 5:r.bit.b2=-1;break;
        case 6:r.bit.b1=-1;break;
        case 7:r.bit.b0=-1;break;
    }
    grf[p]=r.d;
    return 1;
}
//---------------------------------------------------------------------------
void TModel::CreateGraf()
{
    grf=_CreateGraf(n_point);
}
//---------------------------------------------------------------------------
void TModel::CreateLine(int point1,int point2)
{
    _CreateLine(grf,point1,point2);
}
//---------------------------------------------------------------------------
void TModel::DeleteLine(int point1,int point2)
{
    _DeleteLine(grf,point1,point2);
}
//---------------------------------------------------------------------------
int TModel::isLine(int point1,int point2)
{
    return is_Line(grf,point1,point2);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void TModel::Show(Point3D XY)
{
    int i,j;
    for(i=1;i<=n_point;i++)
    {
        for(j=1;j<i;j++)
        {
            P=point[i-1];
            P=_3DTo2D(P);
            Form1->Canvas->MoveTo(P.x+XY.x,XY.y-P.y);
            if(isLine(i,j)==1)
            {
                P=point[j-1];
                P=_3DTo2D(P);
                Form1->Canvas->LineTo(P.x+XY.x,XY.y-P.y);
            }
        }
    }
}
//---------------------------------------------------------------------------
int _DeleteLine(graf*&grf,int point1,int point2)
{
    grafbit r;
    int i,k,p;
    if(point1<point2)
    {
        point1=point1+point2;
        point2=point1-point2;
        point1=point1-point2;
    }
    k=0;
    point1--;
    for(i=0;i<point1;i++)
    {
        k+=i;
    }
    k=k+point2-1;
    p=k/8;
    r.d=grf[p];
    k=k-8*(k/8);
    switch(k)
    {
        case 0:r.bit.b7=0;break;
        case 1:r.bit.b6=0;break;
        case 2:r.bit.b5=0;break;
        case 3:r.bit.b4=0;break;
        case 4:r.bit.b3=0;break;
        case 5:r.bit.b2=0;break;
        case 6:r.bit.b1=0;break;
        case 7:r.bit.b0=0;break;
    }
    grf[p]=r.d;
    return 1;
}
//---------------------------------------------------------------------------
void FormXY(Point3D XY)
{
    Form1->Canvas->Pen->Color=clYellow;
    Form1->Canvas->MoveTo(XY.x,0);
    Form1->Canvas->LineTo(XY.x,2*XY.y);
    Form1->Canvas->MoveTo(0,XY.y);
    Form1->Canvas->LineTo(2*XY.x,XY.y);
}
//---------------------------------------------------------------------------
void ShowPoint(Point3D p)
{
    if(p.z>10)
    {
        
    }
}
//---------------------------------------------------------------------------
Point3D _3DTo2D(Point3D p)
{
    float d;
    Point3D t;
    t=p;
    if(p.z-XY.z>=10)
    {
        d=10/(float)p.z;
        t.x=t.x*d;
        t.y=t.y*d;
    }
    else
    {
        t.z=-1;
    }
    return t;
}
//---------------------------------------------------------------------------
Point3D TModel::Move(Point3D p)
{
    p.Move(loc.p3d);
    return p;
}
//---------------------------------------------------------------------------
location::location()
{
    p3d.x=p3d.y=p3d.z=0;
    alpha=p3d;
}
//---------------------------------------------------------------------------
Point3D TModel::TurnOX(Point3D p)
{
    p.TurnOX(loc.alpha);
    return p;
}
//---------------------------------------------------------------------------
Point3D TModel::TurnOY(Point3D p)
{
    p.TurnOY(loc.alpha);
    return p;
}
//---------------------------------------------------------------------------
Point3D TModel::TurnOZ(Point3D p)
{
    p.TurnOZ(loc.alpha);
    return p;
}
//---------------------------------------------------------------------------
void TModel::CreateCHP()
{
    int i;
    free(chp);
    chp=(Point3D*)malloc(n_point*sizeof(Point3D));
    for(i=0;i<n_point;i++)
    {
        chp[i]=point[i];
    }
}
//---------------------------------------------------------------------------
void TModel::ChangeCHP()
{
    int i;
    for(i=0;i<n_point;i++)
    {
        chp[i].x=scale*point[i].x+loc.p3d.x;
        chp[i].y=scale*point[i].y+loc.p3d.y;
        chp[i].z=scale*point[i].z+loc.p3d.z;
        chp[i]=TurnOX(chp[i]);
        chp[i]=TurnOY(chp[i]);
        chp[i]=TurnOZ(chp[i]);
    }
}
//---------------------------------------------------------------------------
void TModel::ShowCHP(location l)
{
    int i,j;
    for(i=1;i<=n_point;i++)
    {
        for(j=1;j<i;j++)
        {
            P=chp[i-1];
            //P.Move(l.p3d);
            //P.TurnOXOYOZ(l.alpha);
            //P=_3DTo2D(P);
            Form1->Canvas->MoveTo(P.x+XY.x,XY.y-P.y);
            if(isLine(i,j)==1)
            {
                P=chp[j-1];
                //P.Move(l.p3d);
                //P.TurnOXOYOZ(l.alpha);
                //P=_3DTo2D(P);
                Form1->Canvas->LineTo(P.x+XY.x,XY.y-P.y);
            }
        }
    }
}
//---------------------------------------------------------------------------
void Point3D::Move(Point3D p)
{
    x=x+p.x;
    y=y+p.y;
    z=z+p.z;
}
//---------------------------------------------------------------------------
void Point3D::TurnOX(Point3D alpha)
{
    y=y*cos(alpha.x*M_PI/180)-z*sin(alpha.x*M_PI/180);
    z=y*sin(alpha.x*M_PI/180)+z*cos(alpha.x*M_PI/180);
}
//---------------------------------------------------------------------------
void Point3D::TurnOY(Point3D alpha)
{
    z=z*cos(alpha.y*M_PI/180)-x*sin(alpha.y*M_PI/180);
    x=z*sin(alpha.y*M_PI/180)+x*cos(alpha.y*M_PI/180);
}
//---------------------------------------------------------------------------
void Point3D::TurnOZ(Point3D alpha)
{
    x=x*cos(alpha.z*M_PI/180)-y*sin(alpha.z*M_PI/180);
    y=x*sin(alpha.z*M_PI/180)+y*cos(alpha.z*M_PI/180);
}
//---------------------------------------------------------------------------
void Point3D::TurnOXOYOZ(Point3D alpha)
{
    TurnOX(alpha);
    TurnOY(alpha);
    TurnOZ(alpha);
}
//---------------------------------------------------------------------------
TMatrix CreateOX(float alpha)
{
    TMatrix r;
    r.n=r.m=3;
    MemoryAllocation(r);
    r.e[0][0]=1;
    r.e[0][1]=r.e[0][2]=r.e[1][0]=r.e[2][0]=0;
    r.e[1][1]=r.e[2][2]=cos(alpha*M_PI/180);
    r.e[1][2]=sin(alpha*M_PI/180);
    r.e[1][2]=-sin(alpha*M_PI/180);
    return r;
}
//---------------------------------------------------------------------------
TMatrix Point3D::ToMatrix()
{
    TMatrix r;
    r.n=1;
    r.m=3;
    MemoryAllocation(r);
    r.e[0][0]=x;
    r.e[0][1]=y;
    r.e[0][2]=z;
    return r;
}
//---------------------------------------------------------------------------
void Point3D::MatrixToPoint3D(TMatrix r)
{
    x=r.e[0][0];
    y=r.e[0][1];
    z=r.e[0][2];
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#pragma package(smart_init)
