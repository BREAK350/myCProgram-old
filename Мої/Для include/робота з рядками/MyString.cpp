//---------------------------------------------------------------------------
#pragma hdrstop
#include "MyString.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
int ChangeWord(char *&a,char *w1,char *w2)
{
    int i,j,d1,d2;
    if((!a[0])||(!w1[0]))
    {
        return 0;
    }
    i=0;
    while(a[i])
    {
        j=0;
        while((a[i+j])&&(a[i+j]==w1[j]))
        {
            j++;
        }
        if(!w1[j])
        {
            d2=0;
            while(w2[d2])
            {
                d2++;
            }
            d1=0;
            while(w1[d1])
            {
                d1++;
            }
            j=0;
            if(d1<d2)
            {
                while(a[i+j+d1])
                {
                    j++;
                }
                while(j>=0)
                {
                    a[i+j+d2]=a[i+j+d1];
                    j--;
                }
            }
            if(d1>d2)
            {
                while(a[i+j+d2])
                {
                    a[i+j+d2]=a[i+j+d1];
                    j++;
                }
            }
            for(j=0;j<d2;j++)
            {
                a[i+j]=w2[j];
            }
            return 1;
        }
        i++;
    }
    return 0;
}
//---------------------------------------------------------------------------
int ChangeAllWord(char *&a,char *w1,char *w2)
{
    int i,j,d1,d2,k=0;
    if((!a[0])||(!w1[0]))
    {
        return 0;
    }
    i=0;
    while(a[i])
    {
        j=0;
        while((a[i+j])&&(a[i+j]==w1[j]))
        {
            j++;
        }
        if(!w1[j])
        {
            d2=0;
            while(w2[d2])
            {
                d2++;
            }
            d1=0;
            while(w1[d1])
            {
                d1++;
            }
            j=0;
            if(d1<d2)
            {
                while(a[i+j+d1])
                {
                    j++;
                }
                while(j>=0)
                {
                    a[i+j+d2]=a[i+j+d1];
                    j--;
                }
            }
            if(d1>d2)
            {
                while(a[i+j+d2])
                {
                    a[i+j+d2]=a[i+j+d1];
                    j++;
                }
            }
            for(j=0;j<d2;j++)
            {
                a[i+j]=w2[j];
            }
            k++;
        }
        i++;
    }
    return k;
}
//---------------------------------------------------------------------------
int SearchWord(char*b,char*a)
{
    int i,j;
    i=0;
    while(a[i])
    {
        if(a[i]==b[0])
        {
            j=0;
            while((b[j])&&(a[i+j])&&(a[i+j]==b[j]))
            {
                j++;
            }
            if(!b[j])
            {
                return i;
            }
        }
        i++;
    }
    return -1;
}
//---------------------------------------------------------------------------
int NumberOfIdenticalWords(char*b,char*a)
{
    int i,k,d;
    k=0;
    i=0;
    while(a[i])
    {
        d=SearchWord(b,&a[i]);
        i=i+d;
        if(d!=-1)
        {
            i++;
            k++;
        }
        else
        {
            break;
        }
    }
    return k;
}
//---------------------------------------------------------------------------
int SortChar(char**s,int n)
{
    int i,j;
    char *p;
    for(i=0;i<n-1;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(strcmp(s[i],s[j])>0)
            {
                p=s[i];
                s[i]=s[j];
                s[j]=p;
            }
        }
    }
}
//---------------------------------------------------------------------------
int NumberWord(char*fname)
{
    int n=0;
    char w[100];
    FILE *f;
    fclose(f);
    if((f=fopen(fname,"rt")))
    {
        while(fscanf(f,"%s",w)==1)
        {
            n++;
        }
    }
    return n;
}
//---------------------------------------------------------------------------
int NumberLine(char*fname)
{
    int n=0;
    char w[1000];
    FILE *f;
    fclose(f);
    if((f=fopen(fname,"rt")))
    {
        while(fgets(w,1000,f))
        {
            n++;
        }
    }
    return n;
}
//---------------------------------------------------------------------------
