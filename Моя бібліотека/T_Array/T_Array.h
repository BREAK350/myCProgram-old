//---------------------------------------------------------------------------
#ifndef T_ArrayH
#define T_ArrayH
#include <stdio.h>
#include <fstream.h>
//---------------------------------------------------------------------------
template <class Type>
class T_Array
{
    private:
        int N;
        Type *Array;
    public:
        T_Array();
        T_Array(const int &n);
        T_Array(const int &n,const Type *array);
        T_Array(const T_Array &array);
        ~T_Array();
        T_Array& operator = (const T_Array &array);

        int GetElement(const int &i,Type &Element)const;
        int SetElement(const int &i,const Type &Element);
        int GetN()const { return N; }

        void SetN(const int &n);
        void SaveToFile(ofstream &ofs);

        Type& operator [] (const int &i) { return Array[i]; }
        
        const Type* GetArray()const { return Array; }
};
/*
    ����� ����� ���� Type (��������� ����, ������)
*/
//---------------------------------------------------------------------------
template <class Type>
T_Array <Type> ::T_Array()
{
    N=0;
    Array=NULL;
}
//---------------------------------------------------------------------------
template <class Type>
T_Array <Type> ::T_Array(const int &n)
{
    N=(n>0)?(n):(0);
    if(N>0)
    {
        Array=new Type[N];
    }
    else
    {
        Array=NULL;
    }
}
//---------------------------------------------------------------------------
template <class Type>
T_Array <Type> ::T_Array(const T_Array &array)
{
    N=array.N;
    if(N>0)
    {
        int i;
        Array=new Type[N];
        for(i=0;i<N;i++)
        {
            Array[i]=array.Array[i];
        }
    }
    else
    {
        Array=NULL;
    }
}
//---------------------------------------------------------------------------
template <class Type>
T_Array <Type> ::~T_Array()
{
    if(N>0)
    {
        delete[] Array;
        Array=NULL;
        N=0;
    }
}
//---------------------------------------------------------------------------
template <class Type>
T_Array <Type> ::T_Array(const int &n,const Type *array)
{
    N=(n>0)?(n):(0);
    if(N>0)
    {
        int i;
        Array=new Type[N];
        for(i=0;i<N;i++)
        {
            Array[i]=array[i];
        }
    }
    else
    {
        Array=NULL;
    }
}
//---------------------------------------------------------------------------
template <class Type>
T_Array <Type>& T_Array <Type> ::operator = (const T_Array &array)
{
    if(this!=&array)
    {
        if(N>0)
        {
            delete[] Array;
        }
        N=array.N;
        if(N>0)
        {
            int i;
            Array=new Type[N];
            for(i=0;i<N;i++)
            {
                Array[i]=array.Array[i];
            }
        }
        else
        {
            Array=NULL;
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
template <class Type>
int T_Array <Type> ::GetElement(const int &i,Type &Element)const
{
    int q=0;
    if(i>=0 && i<N)
    {
        Element=Array[i];
        q=1;
    }
    return q;
}
/*
    ������ � Element i-� ������� � ������ Array
*/
//---------------------------------------------------------------------------
template <class Type>
int T_Array <Type> ::SetElement(const int &i,const Type &Element)
{
    int q=0;
    if(i>=0 && i<N)
    {
        Array[i]=Element;
        q=1;
    }
    return q;
}
/*
    ������ � ����� Array ������� Element �� i-�� ����
*/
//---------------------------------------------------------------------------
template <class Type>
void T_Array <Type> ::SetN(const int &n)
{
    if(n>=0)
    {
        if(N!=n)
        {
            delete[] Array;
            N=n;
            if(N>0)
            {
                Array=new Type[N];
            }
            else
            {
                Array=NULL;
            }
        }
    }
}
/*
    ���������� ��������� ������ (������� ������� ��������� �����, ���� ����
    ��������� �� ���� ���������)
*/
//---------------------------------------------------------------------------
template <class Type>
void T_Array <Type> ::SaveToFile(ofstream &ofs)
{
    ofs<<N<<endl;
    int i;
    for(i=0;i<N;i++)
    {
        
    }
}
/*
*/
//---------------------------------------------------------------------------
#endif
