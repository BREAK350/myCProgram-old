//---------------------------------------------------------------------------
#pragma hdrstop
#include "Display.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Display::T_Display()
{
    N=M=0;
    Zmin=Zmax=0;
    Data=NULL;
}
//---------------------------------------------------------------------------
T_Display::T_Display(const int &n,const int &m)
{
    N=(n>0)?(n):(0);
    M=(m>0)?(m):(0);
    if(N>0 && M>0)
    {
        int i;
        Data=new T_Data* [N];
        for(i=0;i<N;i++)
        {
            Data[i]=new T_Data[M];
        }
    }
    else
    {
        N=M=0;
        Data=NULL;
    }
}
//---------------------------------------------------------------------------
T_Display::T_Display(const T_Display &Display)
{
    N=Display.N;
    M=Display.M;
    if(N>0 && M>0)
    {
        int i,j;
        Data=new T_Data* [N];
        for(i=0;i<N;i++)
        {
            Data[i]=new T_Data[M];
            for(j=0;j<M;j++)
            {
                Data[i][j]=Display.Data[i][j];
            }
        }
    }
    else
    {
        N=M=0;
        Data=NULL;
    }
}
//---------------------------------------------------------------------------
T_Display::~T_Display()
{
    if(N>0 && M>0)
    {
        int i;
        for(i=0;i<N;i++)
        {
            delete[] Data[i];
        }
        delete[] Data;
        Data=NULL;
        N=M=0;
    }
}
//---------------------------------------------------------------------------
T_Display& T_Display::operator = (const T_Display &Display)
{
    if(this!=&Display)
    {
        if(N==Display.N)
        {
            if(M!=Display.M)
            {
                int i;
                M=Display.M;
                for(i=0;i<N;i++)
                {
                    delete[] Data[i];
                    Data[i]=new T_Data[M];
                }
            }
        }
        else
        {
            int i;
            M=Display.M;
            for(i=0;i<N;i++)
            {
                delete[] Data[i];
            }
            delete[] Data;
            N=Display.N;
            Data=new T_Data* [N];
            for(i=0;i<N;i++)
            {
                Data[i]=new T_Data[M];
            }
        }
        int i,j;
        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                Data[i][j]=Display.Data[i][j];
            }
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
void T_Display::Draw(TCanvas *Canvas,const int &x,const int &y)
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            Canvas->Pixels[i+x][j+y]=Data[i][j].Color;
        }
    }
}
//---------------------------------------------------------------------------
void T_Display::SetData(const int &i,const int &j,const T_Data &D)
{
    if(i>=0 && i<N && j>=0 && j<M)
    {
        if(D.Z>=Zmin && D.Z<Zmax)
        {
            if(Data[i][j].Z>D.Z)
            {
                Data[i][j]=D;
            }
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
