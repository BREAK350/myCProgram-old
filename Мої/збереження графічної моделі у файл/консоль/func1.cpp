//---------------------------------------------------------------------------
#pragma hdrstop
#include "func1.h"
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
int SaveToFile(char*fname)
{
    FILE *f;
}
//---------------------------------------------------------------------------
void TModel::SaveToFile(char*fname)
{
    int i,k;
    FILE *f;
    if(n_point<=0)
    {
        return;
    }
    f=fopen(fname,"wb");
    fwrite(&n_point,1,sizeof(int),f);
    fwrite(point,n_point,sizeof(Point2D),f);
    for(i=0,k=0;i<n_point;i++)
    {
        k+=i;
    }
    k=k/8+1;
    fwrite(grf,k,sizeof(graf),f);
    fclose(f);
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
int TModel::isLine(int point1,int point2)
{
    return is_Line(grf,point1,point2);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
 