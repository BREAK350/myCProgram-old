//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
char GetFound(const char *Row)
{
    char res=UNDEFINED;
    if(Row[0]!=UNDEFINED && Row[1]!=UNDEFINED)
    {
        res=Row[0]-'0'+Row[1];
    }
    return res;
}
//---------------------------------------------------------------------------
int SearchPos(const char *Row,const char &ch)
{
    int i=2;
    while(Row[i] && ch!=Row[i])
    {
        i++;
    }
    if(Row[i]==0)
    {
        i=-1;
    }
    return i;
}
//---------------------------------------------------------------------------
char* Union(const char *Row1,const char *Row2)
{
    char *buf=new char[GetCount(Row1)+GetCount(Row2)+2+1];
    buf[0]=buf[1]=UNDEFINED;
    int i=2,j;
    while(Row1[i])
    {
        buf[i]=Row1[i];
        i++;
    }
    buf[i]=0;
    j=2;
    while(Row2[j])
    {
        if(SearchPos(buf,Row2[j])==-1)
        {
            buf[i]=Row2[j];
            i++;
            buf[i]=0;
        }
        j++;
    }
    if(GetCount(buf)==GetCount(Row1)+GetCount(Row2))
    {
        if(GetFound(Row1)!=UNDEFINED && GetFound(Row2)!=UNDEFINED)
        {
            buf[0]=Row1[0]-'0'+Row2[0];
            buf[1]=Row1[1]-'0'+Row2[1];
        }
    }
    char *res=strdup(buf);
    delete buf;
    return res;
}
//---------------------------------------------------------------------------
int GetCount(const char *Row)
{
    return strlen(Row)-2;
}
//---------------------------------------------------------------------------
bool Search(const char *Row,const char &ch)
{
    return SearchPos(Row,ch)!=-1;
}
//---------------------------------------------------------------------------
char* Intersection(const char *Row1,const char *Row2)
{
    int n=0,i=2;
    while(Row1[i])
    {
        if(Search(Row2,Row1[i]))
        {
            n++;
        }
        i++;
    }
    char *res=new char [n+3];
    if(n>0)
    {
        res[0]=res[1]=UNDEFINED;
    }
    else
    {
        res[0]=res[1]='0';
    }
    i=n=2;
    while(Row1[i])
    {
        if(Search(Row2,Row1[i]))
        {
            res[n]=Row1[i];
            n++;
        }
        i++;
    }
    res[n]=0;
    return res;
}
//---------------------------------------------------------------------------
char* Sub(const char *Row1,const char *Row2)
{
    int n=0,i=2;
    while(Row1[i])
    {
        if(!Search(Row2,Row1[i]))
        {
            n++;
        }
        i++;
    }
    char *res=new char [n+3];
    if(n==GetCount(Row1))
    {
        res[0]=Row1[0];
        res[1]=Row1[1];
    }
    else
    {
        if(n==0)
        {
            res[0]=res[1]='0';
        }
        else
        {
            res[0]=res[1]=UNDEFINED;
        }
    }
    i=n=2;
    while(Row1[i])
    {
        if(!Search(Row2,Row1[i]))
        {
            res[n]=Row1[i];
            n++;
        }
        i++;
    }
    res[n]=0;
    return res;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
char* CheckRows(int &Do,const char *A,const char *B)
{
    char *res=NULL;
    if(GetCount(A)==GetCount(B))
    {
        char *C=Intersection(A,B);
        if(GetFound(B)==GetFound(A)+4-GetCount(C))
        {
            res=Sub(A,B);
            Do=DELETE;
        }
    }
    return res;
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
