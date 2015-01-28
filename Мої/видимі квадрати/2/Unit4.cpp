//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit4.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void CreateDark(const T_Matrix_Odd &Track,T_Matrix_Odd &Dark)
{
    int i,j,n=Track.GetN()/2,m=Track.GetM()/2;
    float amin,amax,ci=Track.GetN()/2.0,cj=Track.GetM()/2.0;
    T_List List;
    Dark.Nullify();
    for(i=1;i<=n;++i)
    {
        MinMaxAngle(n+i,m,ci,cj,amin,amax);
        Dark.SetE(n+i,m,List.Add(amin,amax,Track.GetE(n+i,m)));

        MinMaxAngle(n,m+i,ci,cj,amin,amax);
        Dark.SetE(n,m+i,List.Add(amin,amax,Track.GetE(n,m+i)));

        MinMaxAngle(n-i,m,ci,cj,amin,amax);
        Dark.SetE(n-i,m,List.Add(amin,amax,Track.GetE(n-i,m)));

        MinMaxAngle(n,m-i,ci,cj,amin,amax);
        Dark.SetE(n,m-i,List.Add(amin,amax,Track.GetE(n,m-i)));

    }
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        {
            MinMaxAngle(n+i,m+j,ci,cj,amin,amax);
            Dark.SetE(n+i,m+j,List.Add(amin,amax,Track.GetE(n+i,m+j)));

            MinMaxAngle(n+i,m-j,ci,cj,amin,amax);
            Dark.SetE(n+i,m-j,List.Add(amin,amax,Track.GetE(n+i,m-j)));

            MinMaxAngle(n-i,m+j,ci,cj,amin,amax);
            Dark.SetE(n-i,m+j,List.Add(amin,amax,Track.GetE(n-i,m+j)));

            MinMaxAngle(n-i,m-j,ci,cj,amin,amax);
            Dark.SetE(n-i,m-j,List.Add(amin,amax,Track.GetE(n-i,m-j)));

        }
    }
}
//---------------------------------------------------------------------------
float AngleBetween(const float &a,const float &b)
{
    float c=fabs(b-a);
    if(c>180)
    {
        c=360-c;
    }
    return c;
}
//---------------------------------------------------------------------------
void MinMaxAngle(const float &i,const float &j,const float &ci,const float &cj,float &min,float &max)
    // (i,j),(i+1,j),(i,j+1),(i+1,j+1)
{
    float a,b,c,d,r;
    a=GetAngle(i,j,ci,cj);
    b=GetAngle(i+1,j,ci,cj);
    c=GetAngle(i,j+1,ci,cj);
    d=GetAngle(i+1,j+1,ci,cj);
    float ab,ac,ad,bc,bd,cd;
    ab=AngleBetween(a,b);
    ac=AngleBetween(a,c);
    ad=AngleBetween(a,d);
    bc=AngleBetween(b,c);
    bd=AngleBetween(b,d);
    cd=AngleBetween(c,d);
    r=MAX(MAX(MAX(ab,ac),MAX(ad,bc)),MAX(bd,cd));
    if(r==ab)
    {
        min=a;
        max=b;
    }
    else
    if(r==ac)
    {
        min=a;
        max=c;
    }
    else
    if(r==ad)
    {
        min=a;
        max=d;
    }
    else
    if(r==bc)
    {
        min=b;
        max=c;
    }
    else
    if(r==bd)
    {
        min=b;
        max=d;
    }
    else
    {
        min=c;
        max=d;
    }
    if(max-min<180)
    {
        r=(min>max)?(max):(min);
        max=(min>max)?(min):(max);
        min=r;
    }
    else
    {
        r=(min>max)?(max):(min);
        min=(min>max)?(min):(max);
        max=r;
    }
}
//---------------------------------------------------------------------------
void Draw(const T_Matrix_Odd &MOdd,TCanvas *Canvas,const TPoint &Centre,const int &Scale)
{
    int i,j;
    for(i=0;i<MOdd.GetN();++i)
    {
        for(j=0;j<MOdd.GetM();++j)
        {
            Canvas->Brush->Color=RGB(0,255-MOdd.GetE(i,j),0);
            Canvas->Rectangle(i*Scale+Centre.x,j*Scale+Centre.y,
                              (i+1)*Scale+Centre.x,(j+1)*Scale+Centre.y);
        }
    }
}
//---------------------------------------------------------------------------
void Draw(const T_Matrix_Odd &MOdd,TCanvas *Canvas,const TPoint &Centre,
    const int &Scale,const T_Matrix_Odd &Dark)
{
    int i,j;
    for(i=0;i<MOdd.GetN();++i)
    {
        for(j=0;j<MOdd.GetM();++j)
        {
            if(Dark.GetE(i,j)<50)
            {
                Canvas->Brush->Color=RGB(0,255-MOdd.GetE(i,j),0);
            }
            else
            {
                Canvas->Brush->Color=clBlue;
            }
            Canvas->Rectangle(i*Scale+Centre.x,j*Scale+Centre.y,
                              (i+1)*Scale+Centre.x,(j+1)*Scale+Centre.y);
        }
    }
}
//---------------------------------------------------------------------------
void Copy(int **A,const int &An,const int &Am,int **B,const int &Bn,const int &Bm,
          const int &ci,const int &cj,const int &Insert)
          // ci,cj - верхній лівий кут (0,0)
{
    int i,j;
    i=ci;
    while(i-ci<Bn)
    {
        while(i-ci<Bn && i<0)
        {
            for(j=0;j<Bm;++j)
            {
                B[i-ci][j]=Insert;
            }
            i++;
        }
        while(i-ci<Bn && i<Am)
        {
            j=cj;
            while(j-cj<Bm)
            {
                while(j-cj<Bm && j<0)
                {
                    B[i-ci][j-cj]=Insert;
                    j++;
                }
                while(j-cj<Bm && j<Am)
                {
                    B[i-ci][j-cj]=A[i][j];
                    j++;
                }
                while(j-cj<Bm)
                {
                    B[i-ci][j-cj]=Insert;
                    j++;
                }
            }
            i++;
        }
        while(i-ci<Bn)
        {
            for(j=0;j<Bm;++j)
            {
                B[i-ci][j]=Insert;
            }
            i++;
        }
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
