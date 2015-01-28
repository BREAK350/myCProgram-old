//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void CreateDark(const int **Track,int **Dark) 
{
    int i,j;
    TOrientation or;
    for(i=0;i<11;++i)
    {
        for(j=0;j<11;++j)
        {
            Dark[i][j]=0;
        }
    }
    or.Init(5,5,1,1);
}
//---------------------------------------------------------------------------
int Min(const int &A,const int &B)
{
    return (A>B)?(B):(A);
}
//---------------------------------------------------------------------------
void CreateDark(const int **Track,int **Dark,const TOrientation &or)
{

}
//---------------------------------------------------------------------------
void TOrientation::Init(const int &_i,const int &_j,const int &_si,const int &_sj)
{
    i=_i;
    j=_j;
    si=_si;
    sj=_sj;
}
//---------------------------------------------------------------------------
int Away(const int &i,const int &di) // віддалити
{
    return i+((i>0)?(di):(-di));
}
//---------------------------------------------------------------------------
void CreateDark(const int **Track,int **Dark,const int &ci,const int &cj)
    // all Dark[i][j]=0  ci=cj=5
{
    int i,j,v;
    for(v=0;v<8;++v)
    {
        i=1;
        j=0;
        Index(v,i,j);
        Dark[ci+i][cj+j]=0;
        int k;
        for(k=1;k<=4;k++)
        {
            Dark[ci+Away(i,k)*i][cj+Away(j,k)*j]=Track[ci+Away(i,k-1)*i][cj+Away(j,k-1)*j]+
                                                 Dark[ci+Away(i,k-1)*i][cj+Away(j,k-1)*j];
        }
    }
    for(v=0;v<8;++v)
    {
        i=1;
        j=1;
        Index(v,i,j);
        Dark[ci+i][cj+j]=Min(Track[ci+i][cj],Track[ci][cj+j]);
    }
    for(v=0;v<8;++v)
    {
        i=2;
        j=2;
        Index(v,i,j);
        Dark[ci+i][cj+j]=Track[ci+Away(i,-1)][cj+Away(j,-1)]+
                         Min(Track[ci+Away(i,-2)][cj+Away(j,-1)]+Track[ci+Away(i,-1)][cj+j],
                             Track[ci+Away(i,-1)][cj+Away(j,-2)]+Track[ci+i][cj+Away(j,-1)]);
    }
    for(v=0;v<8;++v)
    {
        i=2;
        j=0;
        Index(v,i,j);
        Dark[ci+i][cj+j]=Track[ci+i][cj+j]+Dark[ci+i][cj+j];
    }
    for(v=0;v<8;++v)
    {
        i=2;
        j=1;
        Index(v,i,j);
        Dark[ci+i][cj+j]=Min(Track[ci+i][cj+0]+Dark[ci+i][cj+0],
                             Track[ci+j][cj+j]+Dark[ci+j][cj+j]);
    }
    for(v=0;v<8;++v)
    {
        i=3;
        j=1;
        Index(v,i,j);
        Dark[ci+i][cj+j]=Min(Track[ci+i][cj+0]+Dark[ci+i][cj+0],
                             Track[ci+Away(i,-1)][cj+j]+Dark[ci+Away(i,-1)][cj+j]);
    }
    for(v=0;v<8;++v)
    {
        i=3;
        j=2;
        Index(v,i,j);
        Dark[ci+i][cj+j]=Min(Track[ci+i][cj+Away(j,-1)]+Dark[ci+i][cj+Away(j,-1)],
                             Track[ci+Away(i,-1)][cj+j]+Dark[ci+Away(i,-1)][cj+j]);
    }
}
//---------------------------------------------------------------------------
void Index(const int &V,int &i,int &j) // i,j>=0
{
    if(V & 4) // 100
    {
        int r=i;
        i=j;
        j=r;
    }
    if(V & 2) // 010
    {
        i=-i;
    }
    if(V & 1) // 001
    {
        j=-j;
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
