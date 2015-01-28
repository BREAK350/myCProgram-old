//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit4.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void dT_Matrix::DoZero()
{
    int i,j;
    for(i=0;i<Elem_SIZE;++i)
    {
        for(j=0;j<Elem_SIZE;++j)
        {
            Elem[i][j]=0;
        }
    }
}
//---------------------------------------------------------------------------
void CreateDark(const dT_Matrix &Track,dT_Matrix &Dark)
{
    int i,j;
    float amin,amax;
    T_List List;
    Dark.DoZero();
    for(i=1;i<=Elem_SIZE/2;++i)
    {
        MinMaxAngle(Elem_SIZE/2+i,Elem_SIZE/2,amin,amax);
        Dark.Elem[Elem_SIZE/2+i][Elem_SIZE/2]=List.Add(amin,amax,Track.Elem[Elem_SIZE/2+i][Elem_SIZE/2]);

        MinMaxAngle(Elem_SIZE/2,Elem_SIZE/2+i,amin,amax);
        Dark.Elem[Elem_SIZE/2][Elem_SIZE/2+i]=List.Add(amin,amax,Track.Elem[Elem_SIZE/2][Elem_SIZE/2+i]);

        MinMaxAngle(Elem_SIZE/2-i,Elem_SIZE/2,amin,amax);
        Dark.Elem[Elem_SIZE/2-i][Elem_SIZE/2]=List.Add(amin,amax,Track.Elem[Elem_SIZE/2-i][Elem_SIZE/2]);

        MinMaxAngle(Elem_SIZE/2,Elem_SIZE/2-i,amin,amax);
        Dark.Elem[Elem_SIZE/2][Elem_SIZE/2-i]=List.Add(amin,amax,Track.Elem[Elem_SIZE/2][Elem_SIZE/2-i]);

    }
    for(i=1;i<=Elem_SIZE/2;++i)
    {
        for(j=1;j<=Elem_SIZE/2;++j)
        {
            MinMaxAngle(Elem_SIZE/2+i,Elem_SIZE/2+j,amin,amax);
            Dark.Elem[Elem_SIZE/2+i][Elem_SIZE/2+j]=List.Add(amin,amax,Track.Elem[Elem_SIZE/2+i][Elem_SIZE/2+j]);

            MinMaxAngle(Elem_SIZE/2+i,Elem_SIZE/2-j,amin,amax);
            Dark.Elem[Elem_SIZE/2+i][Elem_SIZE/2-j]=List.Add(amin,amax,Track.Elem[Elem_SIZE/2+i][Elem_SIZE/2-j]);

            MinMaxAngle(Elem_SIZE/2-i,Elem_SIZE/2+j,amin,amax);
            Dark.Elem[Elem_SIZE/2-i][Elem_SIZE/2+j]=List.Add(amin,amax,Track.Elem[Elem_SIZE/2-i][Elem_SIZE/2+j]);

            MinMaxAngle(Elem_SIZE/2-i,Elem_SIZE/2-j,amin,amax);
            Dark.Elem[Elem_SIZE/2-i][Elem_SIZE/2-j]=List.Add(amin,amax,Track.Elem[Elem_SIZE/2-i][Elem_SIZE/2-j]);
        }
    }
}
//---------------------------------------------------------------------------
void MinMaxAngle(const int &i,const int &j,float &min,float &max)
    // (i,j),(i+1,j),(i,j+1),(i+1,j+1)
{
    float a;
    min=max=GetAngle(i,j,Elem_SIZE/2.0,Elem_SIZE/2.0);
    a=GetAngle(i+1,j,Elem_SIZE/2.0,Elem_SIZE/2.0);
    if(min>a)
    {
        min=a;
    }
    if(max<a)
    {
        max=a;
    }
    a=GetAngle(i,j+1,Elem_SIZE/2.0,Elem_SIZE/2.0);
    if(min>a)
    {
        min=a;
    }
    if(max<a)
    {
        max=a;
    }
    a=GetAngle(i+1,j+1,Elem_SIZE/2.0,Elem_SIZE/2.0);
    if(min>a)
    {
        min=a;
    }
    if(max<a)
    {
        max=a;
    }
    if(max-min>=180)
    {
        a=max+min;
        min=max;
        max=a;
    }
}
//---------------------------------------------------------------------------
void dT_Matrix::Draw(TCanvas *Canvas,const TPoint &Centre,const int &Scale)
{
    int i,j;
    for(i=0;i<Elem_SIZE;++i)
    {
        for(j=0;j<Elem_SIZE;++j)
        {
            Canvas->Brush->Color=RGB(0,255-Elem[i][j],0);
            Canvas->Rectangle(i*Scale+Centre.x,j*Scale+Centre.y,
                              (i+1)*Scale+Centre.x,(j+1)*Scale+Centre.y);
        }
    }
}
//---------------------------------------------------------------------------
void dT_Matrix::Draw(TCanvas *Canvas,const TPoint &Centre,const int &Scale,const dT_Matrix &Dark)
{
    int i,j;
    for(i=0;i<Elem_SIZE;++i)
    {
        for(j=0;j<Elem_SIZE;++j)
        {
            if(Dark.Elem[i][j]<50)
            {
                Canvas->Brush->Color=RGB(0,255-Elem[i][j],0);
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
void dT_Matrix::Init(const int **Track,const int &ci,const int &cj,const int &n,const int &m)
{
    int i,j;
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
