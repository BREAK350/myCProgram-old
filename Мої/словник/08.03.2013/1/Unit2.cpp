//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_V::T_V()
{
    FileName=NULL;
    File=NULL;
    Regime=0;
}
//---------------------------------------------------------------------------
T_V::T_V(const T_V &v)
{
    FileName=strdup(v.FileName);
    File=v.File;
    Regime=v.Regime;
}
//---------------------------------------------------------------------------
T_V::~T_V()
{
    delete FileName;
    FileName=NULL;
    fclose(File);
    File=NULL;
}
//---------------------------------------------------------------------------
T_V::T_V(const char *fname)
{
    FileName=strdup(fname);
    File=fopen(FileName,"rt");
    if(File)
    {
        Regime=1;
    }
    else
    {
        Regime=0;
    }
}
//---------------------------------------------------------------------------
int T_V::OpenToRead()
{
    if(FileName)
    {
        fclose(File);
        File=fopen(FileName,"rt");
        if(File)
        {
            Regime=1;
        }
        else
        {
            Regime=0;
        }
    }
    return Regime;
}
//---------------------------------------------------------------------------
int T_V::OpenToWrite()
{
    if(FileName)
    {
        fclose(File);
        File=fopen(FileName,"wt");
        if(File)
        {
            Regime=2;
        }
        else
        {
            Regime=0;
        }
    }
    return Regime;
}
//---------------------------------------------------------------------------
int T_V::Search(const char *sw,char **&rw,int *&nr)
{
    int n=0,i,k=0;
    char Buf[1024];
    char **buf=NULL;
    int *bufn=NULL;
    if(OpenToRead())
    {
        while(fgets(Buf,1024,File))
        {
            if(strstr(Buf,sw))
            {
                buf=new char*[n];
                bufn=new int [n];
                for(i=0;i<n;i++)
                {
                    buf[i]=rw[i];
                    bufn[i]=nr[i];
                }
                delete[] rw;
                delete[] nr;
                n=n+1;
                rw=new char*[n];
                nr=new int [n];
                for(i=0;i<n-1;i++)
                {
                    rw[i]=buf[i];
                    nr[i]=bufn[i];
                }
                rw[i]=strdup(Buf);
                nr[i]=k;
                delete buf;
                delete bufn;
            }
            k++;
        }
    }
    return n;
}
//---------------------------------------------------------------------------
int T_V::OpenToAdd()
{
    if(FileName)
    {
        fclose(File);
        File=fopen(FileName,"at");
        if(File)
        {
            Regime=3;
        }
        else
        {
            Regime=0;
        }
    }
    return Regime;
}
//---------------------------------------------------------------------------
int T_V::Add(const char *w)
{
    int g;
    if(OpenToAdd())
    {
        fprintf(File,"%s\n",w);
        g=1;
    }
    fclose(File);
    return g;
}
//---------------------------------------------------------------------------
int T_V::ChangeRow(const int &n,const char *w)
{
    int k=-1;
    if(n>=0)
    {
        if(OpenToRead())
        {
            char Buf[1024];
            FILE *tf=fopen("Temporary File","wt");
            k=0;
            while(k<n && fgets(Buf,1024,File))
            {
                k++;
                fprintf(tf,"%s",Buf);
            }
            if(w && k>=n)
            {
                fprintf(tf,"%s\n",w);
            }
            fgets(Buf,1024,File);
            while(fgets(Buf,1024,File))
            {
                fprintf(tf,"%s",Buf);
            }
            fclose(tf);
            fclose(File);
            remove(FileName);
            rename("Temporary File",FileName);
        }
    }
    return k;
}
//---------------------------------------------------------------------------
int T_V::SetFileName(const char *w)
{
    int q=0;
    fclose(File);
    delete FileName;
    FileName=strdup(w);
    if(OpenToRead())
    {
        fclose(File);
        q=1;
    }
    return q;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 