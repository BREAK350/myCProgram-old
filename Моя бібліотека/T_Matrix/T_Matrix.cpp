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
int T_Matrix::GetE(const int &i,const int &j,int &e)const
{
    int q=0;
    if(i>=0 && i<N && j>=0 && j<M)
    {
        e=E[i][j];
        q=1;
    }
    return q;
}
//---------------------------------------------------------------------------
int T_Matrix::SetE(const int &i,const int &j,const int &e)
{
    int q=0;
    if(i>=0 && i<N && j>=0 && j<M)
    {
        E[i][j]=e;
        q=1;
    }
    return q;
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
            Matrix.GetE(i+pi,j+pj,E[i][j]);
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
void T_Matrix::MirroringRow()
{
    int i,j,k=M/2,t;
    for(i=0;i<N;i++)
    {
        for(j=0;j<k;j++)
        {
            t=E[i][j];
            E[i][j]=E[i][M-j-1];
            E[i][M-j-1]=t;
        }
    }
}
//---------------------------------------------------------------------------
void T_Matrix::MirroringCol()
{
    int i,j,k=N/2,t;
    for(i=0;i<k;i++)
    {
        for(j=0;j<M;j++)
        {
            t=E[i][j];
            E[i][j]=E[N-i-1][j];
            E[N-i-1][j]=t;
        }
    }
}
//---------------------------------------------------------------------------
void T_Matrix::Rotation90()
{
    T_Matrix R(M,N);
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            R.E[M-j-1][i]=E[i][j];
        }
    }
    this->operator =(R);
}
//---------------------------------------------------------------------------
void T_Matrix::Rotation180()
{
    int i,j,n=N/2,t;
    for(i=0;i<n;i++)
    {
        for(j=0;j<M;j++)
        {
            t=E[i][j];
            E[i][j]=E[N-i-1][M-j-1];
            E[N-i-1][M-j-1]=t;
        }
    }
    if(N%2==1)
    {
        for(j=0;j<M/2;j++)
        {
            t=E[n][j];
            E[n][j]=E[n][M-j-1];
            E[n][M-j-1]=t;
        }
    }
}
//---------------------------------------------------------------------------
void T_Matrix::Paste(const T_Matrix &Matrix,const int &pi,const int &pj)
{
    int i=0,j;
    if(i<pi)
    {
        i=pi;
    }
    while(i<N && i-pi<Matrix.N)
    {
        j=0;
        if(j<pj)
        {
            j=pj;
        }
        while(j<M && j-pj<Matrix.M)
        {
            E[i][j]=Matrix.E[i-pi][j-pj];
            j++;
        }
        i++;
    }
}
//---------------------------------------------------------------------------
void T_Matrix::PasteAdd(const T_Matrix &Matrix,const int &pi,const int &pj)
{
    int i=0,j;
    if(i<pi)
    {
        i=pi;
    }
    while(i<N && i-pi<Matrix.N)
    {
        j=0;
        if(j<pj)
        {
            j=pj;
        }
        while(j<M && j-pj<Matrix.M)
        {
            E[i][j]+=Matrix.E[i-pi][j-pj];
            j++;
        }
        i++;
    }
}
//---------------------------------------------------------------------------
void T_Matrix::Cut(T_Matrix &Matrix,const int &pi,const int &pj,const int &Insert)
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
            Matrix.GetE(i+pi,j+pj,E[i][j]);
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
void T_Matrix::Sub(const T_Matrix &Matrix,const int &pi,const int &pj)
{
    int i=0,j;
    if(i<pi)
    {
        i=pi;
    }
    while(i<N && i-pi<Matrix.N)
    {
        j=0;
        if(j<pj)
        {
            j=pj;
        }
        while(j<M && j-pj<Matrix.M)
        {
            E[i][j]-=Matrix.E[i-pi][j-pj];
            j++;
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

