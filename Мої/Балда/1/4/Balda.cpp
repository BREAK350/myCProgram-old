//---------------------------------------------------------------------------
#pragma hdrstop
#include "Balda.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void TMatrix::Create(int n)
{
    int i,j;
    if(n<3)
    {
        return;
    }
    if(Symbol)
    {
        Delete();
    }
    N=n;
    Symbol=new char*[n];
    for(i=0;i<N;i++)
    {
        Symbol[i]=new char[N];
        for(j=0;j<N;j++)
        {
            Symbol[i][j]=' ';
        }
    }
}
//---------------------------------------------------------------------------
void TMatrix::ReCreate()
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            Symbol[i][j]=' ';
        }
    }
}
//---------------------------------------------------------------------------
void TMatrix::Delete()
{
    int i;
    for(i=0;i<N;i++)
    {
        delete Symbol[i];
    }
    delete Symbol;
    N=0;
    Symbol=NULL;
}
//---------------------------------------------------------------------------
TPoint* TMatrix::SearchMaxWord(const TWords &w,const ABC &a,int &max)
{
    int i,j;
    TPoint kAddSymbol={-1,-1};
    TPoint *p=new TPoint[64];
    TPoint *pmax=new TPoint[64];
    char **was;
    was=new char*[N];
    for(i=0;i<N;i++)
    {
        was[i]=new char[N];
        for(j=0;j<N;j++)
        {
            was[i][j]=0;
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            NextSymbol(i,j,was,p,0,w,a,0,kAddSymbol,pmax,max);
            if(kAddSymbol.i==-1)
            {
                Symbol[kAddSymbol.i][kAddSymbol.j]=' ';
            }
        }
    }
    return pmax;
}
//---------------------------------------------------------------------------
int TMatrix::NextSymbol(int i,int j, //координати символа
                        char **was,  //матриц€, дл€ перев≥рки, чи не стали на кл≥тину к≥лька раз(можна лише раз)
                        TPoint *p,int n,//масив дл€ збереженн€ поточного слова
                        const TWords &w,//словник сл≥в
                        const ABC &a, //алфав≥т
                        int AddSymbol,//перев≥рка, чи дописували букву чи н≥
                        TPoint &kAddSymbol,//координати дописуваноњ букви
                        TPoint *pword, //масив максимального слова
                        int &max)      //довжина максимального слова
{
    int k;
    char *word;
    /**/
    if(i<0 || i>=N || j<0 || j>=N)
    {
        return 0;
    }
    if(was[i][j]==0)
    {
        if(Symbol[i][j]!=' ')
        {
            was[i][j]=1;
            p[n].i=i;
            p[n].j=j;
            NextSymbol(i,j+1,was,p,n+1,w,a,AddSymbol,kAddSymbol,pword,max);
            NextSymbol(i+1,j,was,p,n+1,w,a,AddSymbol,kAddSymbol,pword,max);
            NextSymbol(i,j-1,was,p,n+1,w,a,AddSymbol,kAddSymbol,pword,max);
            NextSymbol(i-1,j,was,p,n+1,w,a,AddSymbol,kAddSymbol,pword,max);
        }
        else
        {
            if(AddSymbol==0)
            {
                AddSymbol=1;
                was[i][j]=1;
                p[n].i=i;
                p[n].j=j;
                kAddSymbol.i=p[n].i;
                kAddSymbol.j=p[n].j;
                for(k=0;k<a.GetN();k++)
                {
                    Symbol[p[n].i][p[n].j]=a.operator [](k);
                    NextSymbol(i,j+1,was,p,n+1,w,a,AddSymbol,kAddSymbol,pword,max);
                    NextSymbol(i+1,j,was,p,n+1,w,a,AddSymbol,kAddSymbol,pword,max);
                    NextSymbol(i,j-1,was,p,n+1,w,a,AddSymbol,kAddSymbol,pword,max);
                    NextSymbol(i-1,j,was,p,n+1,w,a,AddSymbol,kAddSymbol,pword,max);
                }
            }
        }
    }
    /*if(j<N-1)
    {
        if(was[i][j+1]==0)
        {
            if(Symbol[i][j+1]!=' ')
            {
                was[i][j+1]=1;
                p[n].i=i;
                p[n].j=j+1;
                NextSymbol(i,j+1,was,p,n+1,w,a,AddSymbol,kAddSymbol,pword,max);
                was[i][j+1]=0;
            }
            else
            {
                if(AddSymbol==0)
                {
                    AddSymbol=1;
                    was[i][j+1]=1;
                    p[n].i=i;
                    p[n].j=j+1;
                    kAddSymbol.i=p[n].i;
                    kAddSymbol.j=p[n].j;
                    for(k=0;k<a.GetN();k++)
                    {
                        Symbol[p[n].i][p[n].j]=a.operator [](k);
                        NextSymbol(i,j+1,was,p,n+1,w,a,AddSymbol,kAddSymbol,pword,max);
                    }
                    was[i][j+1]=0;
                }
            }
        }
    }*/
    if(n>max && AddSymbol==1)
    {
        word=CreateChar(p,n);
        if(w.SearchWord(word))
        {
            max=n;
            for(k=0;k<max;k++)
            {
                pword[k]=p[k];
            }
        }
    }
}
//---------------------------------------------------------------------------
char* TMatrix::CreateChar(TPoint *p,int n)
{
    int i;
    char *ch=new char[n+1];
    for(i=0;i<n;i++)
    {
        ch[i]=Symbol[p[i].i][p[i].j];
    }
    ch[i]=0;
    return ch;
}
//---------------------------------------------------------------------------
void TMatrix::Write(int i,int j,char c)
{
    if(i>=0 && i<N && j>=0 && j<N)
    {
        Symbol[i][j]=c;
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 