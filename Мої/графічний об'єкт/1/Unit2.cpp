//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Char_Matrix::T_Char_Matrix()
{
    E=NULL;
    n=m=0;
}
//---------------------------------------------------------------------------
T_Char_Matrix::T_Char_Matrix(const T_Char_Matrix &cm)
{
    Copy(cm);
}
//---------------------------------------------------------------------------
T_Char_Matrix::~T_Char_Matrix()
{
    Delete();
}
//---------------------------------------------------------------------------
void T_Char_Matrix::Delete()
{
    char i;
    for(i=0;i<n;i++)
    {
        delete E[i];
        E[i]=NULL;
    }
    delete E;
    E=NULL;
    n=m=0;
}
//---------------------------------------------------------------------------
T_Char_Matrix& T_Char_Matrix::operator = (const T_Char_Matrix &cm)
{
    if(this==&cm)
    {
        return *this;
    }
    Delete();
    Copy(cm);
    return *this;
}
//---------------------------------------------------------------------------
void T_Char_Matrix::Copy(const T_Char_Matrix &cm)
{
    char i,j;
    if(cm.E)
    {
        E=new char*[n=cm.n];
        m=cm.m;
        for(i=0;i<n;i++)
        {
            E[i]=new char[m];
            for(j=0;j<m;j++)
            {
                E[i][j]=cm.E[i][j];
            }
        }
    }
    else
    {
        E=NULL;
        n=m=0;
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
