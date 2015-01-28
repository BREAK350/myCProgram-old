//---------------------------------------------------------------------------
#pragma hdrstop
#include "CreateModel.h"
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
void CreateLine(TModel mod,int point1,int point2)
{
    _CreateLine(mod.grf,point1,point2);
}
//---------------------------------------------------------------------------
void DeleteLine(TModel mod,int point1,int point2)
{
    _DeleteLine(mod.grf,point1,point2);
}
//---------------------------------------------------------------------------
void CreateGraf(TModel &mod)
{
    int i,k;
    for(i=0,k=0;i<mod.n_point;i++)
    {
        k+=i;
    }
    k=k/8+1;
    mod.grf=(graf*)calloc(k,sizeof(graf));
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
void CreateCHP(TModel &mod)
{
    int i;
    free(mod.chp);
    mod.chp=(Point3D*)malloc(mod.n_point*sizeof(Point3D));
    for(i=0;i<mod.n_point;i++)
    {
        mod.chp[i]=mod.point[i];
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
