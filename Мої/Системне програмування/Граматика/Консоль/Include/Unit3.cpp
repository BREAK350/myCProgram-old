//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit3.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
char* CreateStructRG(const int &Length) // Length>0
{
    char *res=NULL;
    res=new char [Length+1+3];
    res[0]=STRUCT_N;
    res[1]='-';
    res[2]='>';
    int i=3;
    int N=random(2);
    while(i<Length+3-N)
    {
        res[i]=STRUCT_T;
        i++;
    }
    if(N==1)
    {
        res[i]=STRUCT_N;
        i++;
    }
    res[i]=0;
    return res;                 
}
//---------------------------------------------------------------------------
char* CreateStructLG(const int &Length) // Length>0
{
    char *res=NULL;
    res=new char [Length+1+3];
    res[0]=STRUCT_N;
    res[1]='-';
    res[2]='>';
    int i=3;
    int N=random(2);
    if(N==1)
    {
        res[i]=STRUCT_N;
        i++;
    }
    while(i<Length+3)
    {
        res[i]=STRUCT_T;
        i++;
    }
    res[i]=0;
    return res;                 
}
//---------------------------------------------------------------------------
char* CreateStructKVG(const int &Length)
{
    return NULL;
}
//---------------------------------------------------------------------------
char* CreateStructOperand(const int &Length,const int &Count_N)
    // Length>0,Count_N>=0 && Count_N<=Length
{
    char *res=new char [Length+1];
    int n=Count_N,i=0;
    while(i<Length)
    {
        res[i]=STRUCT_T;
        i++;
    }
    res[i]=0;
    while(n>0)
    {
        i=random(Length);
        if(res[i]==STRUCT_T)
        {
            res[i]=STRUCT_N;
            n--;
        }
    }
    return res;
}
//---------------------------------------------------------------------------
char* CreateStructOperandLeft(const int &Length,const int &Count_N)
{
    char *res=new char [Length+1];
    int i=0;
    while(i<Count_N)
    {
        res[i]=STRUCT_N;
        i++;
    }
    while(i<Length)
    {
        res[i]=STRUCT_T;
        i++;
    }
    res[i]=0;
    return res;
}
//---------------------------------------------------------------------------
char* CreateStructOperandRight(const int &Length,const int &Count_N)
{
    char *res=new char [Length+1];
    int i=0;
    while(i<Length-Count_N)
    {
        res[i]=STRUCT_T;
        i++;
    }
    while(i<Length)
    {
        res[i]=STRUCT_N;
        i++;
    }
    res[i]=0;
    return res;
}
//---------------------------------------------------------------------------
char* CreateRule(const char *Left,const char *Right) // Left!=NULL && Right!=NULL
{
    int l=strlen(Left),r=strlen(Right);
    char *res=new char (l+r+3);
    int i=0;
    while(i<l)
    {
        res[i]=Left[i];
        i++;
    }
    res[i]='-';
    res[i+1]='>';
    i+=2;
    while(i-2-l<r)
    {
        res[i]=Right[i-2-l];
        i++;
    }
    res[i]=0;
    return res;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
