//---------------------------------------------------------------------------
#pragma hdrstop
#include "GeneralFunction.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
template <class T>
    T* Intersection(T *a,int na,T *b,int nb,int &size)
{
    T *r;
    int n,i,j,p;
    i=0;
    while(i<na && isBelongs(a[i],b,nb)==-1)
    {
        i++;
    }
    if(i>=na)
    {
        size=0;
        return NULL;
    }
    n=1;
    p=i;
    while(i<na)
    {
        if(isBelongs(a[i],b,nb)!=-1)
        {
            n++;
        }
        i++;
    }
    r=new T[n];
    r[0]=[p];
    i=p+1;
    j=1;
    while(i<na && j<n)
    {
        if(isBelongs(a[i],b,nb)!=-1)
        {
            r[j]=a[i];
            j++;
        }
        i++;
    }
    size=n;
    return r;
}
//---------------------------------------------------------------------------
template <class T>
    int isBelongs(T t,T *a,int n)
{
    int i=0;
    while(i<n && t!=a[i])
    {
        i++;
    }
    return (i<n)?(-1):(i);
}
//---------------------------------------------------------------------------
template <class T>
    void swap(T &a,T &b)
{
    T c;
    c=a;
    a=b;
    b=c;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 