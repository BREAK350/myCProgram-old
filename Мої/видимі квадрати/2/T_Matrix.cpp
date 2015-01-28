//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Matrix.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Matrix::T_Matrix()
{
    N=M=0;
    E=NULL;
}
//---------------------------------------------------------------------------
T_Matrix::~T_Matrix()
{
    int i;
    for(i=0;i<N;++i)
    {
        delete E[i];
    }
    delete E;
    E=NULL;
    N=M=0;
}
//---------------------------------------------------------------------------
int T_Matrix::GetE(const int &i,const int &j)const
{
    int e=0;
    if(i>=0 && i<N && j>=0 && j<M)
    {
        e=E[i][j];
    }
    return e;
}
//---------------------------------------------------------------------------
void T_Matrix::SetE(const int &i,const int &j,const int &e)
{
    if(i>=0 && i<N && j>=0 && j<M)
    {
        E[i][j]=e;
    }
}
//---------------------------------------------------------------------------
T_Matrix::T_Matrix(const int &n,const int &m)
{
    N=(n>0)?(n):(0);
    M=(m>0)?(m):(0);
    if(N>0 && M>0)
    {
        int i;
        E=new int* [N];
        for(i=0;i<N;++i)
        {
            E[i]=new int [M];
        }
    }
    else
    {
        N=M=0;
        E=NULL;
    }
}
//---------------------------------------------------------------------------
T_Matrix::T_Matrix(const int &n,const int &m,const int &e)
{
    N=(n>0)?(n):(0);
    M=(m>0)?(m):(0);
    if(N>0 && M>0)
    {
        int i,j;
        E=new int* [N];
        for(i=0;i<N;++i)
        {
            E[i]=new int [M];
            for(j=0;j<M;++j)
            {
                E[i][j]=e;
            }
        }
    }
    else
    {
        N=M=0;
        E=NULL;
    }
}
//---------------------------------------------------------------------------
T_Matrix::T_Matrix(const T_Matrix &Matrix)
{
    N=Matrix.N;
    M=Matrix.M;
    if(N>0 && M>0)
    {
        int i,j;
        E=new int* [N];
        for(i=0;i<N;++i)
        {
            E[i]=new int [M];
            for(j=0;j<M;++j)
            {
                E[i][j]=Matrix.E[i][j];
            }
        }
    }
    else
    {
        N=M=0;
        E=NULL;
    }
}
//---------------------------------------------------------------------------
T_Matrix& T_Matrix::operator = (const T_Matrix &Matrix)
{
    if(this!=&Matrix)
    {
        int i,j;
        for(i=0;i<N;++i)
        {
            delete E[i];
        }
        delete E;
        N=Matrix.N;
        M=Matrix.M;
        if(N>0 && M>0)
        {
            E=new int* [N];
            for(i=0;i<N;++i)
            {
                E[i]=new int [M];
                for(j=0;j<M;++j)
                {
                    E[i][j]=Matrix.E[i][j];
                }
            }
        }
        else
        {
            N=M=0;
            E=NULL;
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
void T_Matrix::Nullify()
{
    int i,j;
    for(i=0;i<N;++i)
    {
        for(j=0;j<M;++j)
        {
            E[i][j]=0;
        }
    }
}
//---------------------------------------------------------------------------
void T_Matrix::Copy(const T_Matrix &Matrix,const int &pi,const int &pj,const int &Insert)
{
    int i,j;
    i=0;
    while(i<N && i+pi<0)
    {
        for(j=0;j<M;j++)
        {
            E[i][j]=Insert;
        }
        i++;
    }
    while(i<N && i+pi<Matrix.GetN())
    {
        j=0;
        while(j<M && j+pj<0)
        {
            E[i][j]=Insert;
            j++;
        }
        while(j<M && j+pj<Matrix.GetM())
        {
            E[i][j]=Matrix.GetE(i+pi,j+pj);
            j++;
        }
        while(j<M)
        {
            E[i][j]=Insert;
            j++;
        }
        i++;
    }
    while(i<N)
    {
        for(j=0;j<M;j++)
        {
            E[i][j]=Insert;
        }
        i++;
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
