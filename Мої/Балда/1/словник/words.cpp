//---------------------------------------------------------------------------
#pragma hdrstop
#include "words.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TWords::TWords()
{
    N=0;
    words=NULL;
}
//---------------------------------------------------------------------------
void TWords::AddWord(char *w)
{
    int i,j;
    TSymbol *pt;
    if(!w || !*w)
    {
        return;
    }
    if(N==0)
    {
        words=new TSymbol;
        N++;
        words[0].S=w[0];
        words[0].N=0;
        words[0].next=NULL;
        j=0;
    }
    else
    {
        i=0;
        while(i<N && w[0]!=words[i].S)
        {
            i++;
        }
        if(i<N)
        {
            j=i;
        }
        else
        {
            pt=new TSymbol[N+1];
            for(i=0;i<N;i++)
            {
                pt[i]=words[i];
            }
            delete words;
            N++;
            words=new TSymbol[N];
            i=0;
            while(i<N-1 && w[0]>pt[i].S)
            {
                words[i]=pt[i];
                i++;
            }
            words[i].S=w[0];
            words[i].N=0;
            words[i].next=NULL;
            j=i;
            i++;
            while(i<N)
            {
                words[i]=pt[i-1];
                i++;
            }
            delete pt;
        }
    }
    AddSymbol(w+1,words[j]);
}
//---------------------------------------------------------------------------
TWords::~TWords()
{
    int i;
    TSymbol t;
    for(i=0;i<N;i++)
    {
        Delete(words[i]);
    }
    delete words;
    words=NULL;
}
//---------------------------------------------------------------------------
void TWords::Delete(TSymbol &t)
{
    int i;
    for(i=0;i<t.N;i++)
    {
        Delete(t.next[i]);
    }
    delete t.next;
    t.next=NULL;
}
//---------------------------------------------------------------------------
void TWords::AddSymbol(char *p,TSymbol &ts)
{
    int i;
    TSymbol *pt;
    if(!*(p-1))
    {
        return;
    }
    if(ts.N==0)
    {
        ts.N++;
        ts.next=new TSymbol;
        ts.next[0].S=p[0];
        ts.next[0].next=NULL;
        ts.next[0].N=0;
        AddSymbol(p+1,ts.next[0]);
    }
    else
    {
        i=0;
        while(i<ts.N && p[0]!=ts.next[i].S)
        {
            i++;
        }
        if(i<ts.N)
        {
            AddSymbol(p+1,ts.next[i]);
        }
        else
        {
            pt=new TSymbol[ts.N+1];
            for(i=0;i<ts.N;i++)
            {
                pt[i]=ts.next[i];
            }
            delete ts.next;
            ts.N++;
            ts.next=new TSymbol[ts.N];
            i=0;
            while(i<ts.N-1 && p[0]>pt[i].S)
            {
                ts.next[i]=pt[i];
                i++;
            }
            ts.next[i].S=p[0];
            ts.next[i].N=0;
            ts.next[i].next=NULL;
            AddSymbol(p+1,ts.next[i]);
            i++;
            while(i<ts.N)
            {
                ts.next[i]=pt[i-1];
                i++;
            }
            delete pt;
        }
    }
}
//---------------------------------------------------------------------------
void PrintK(int k)
{
    int i;
    for(i=0;i<k;i++)
    {
        cout<<' ';
    }
}
//---------------------------------------------------------------------------
void TWords::PrintAll()
{
    int i;
    for(i=0;i<N;i++)
    {
        PrintSymbols(words[i],0);
    }
    cout<<endl;
}
//---------------------------------------------------------------------------
int TWords::PrintSymbols(TSymbol s,int k)
{
    int i,p=0;
    cout<<s.S;
    if(s.S==0 || s.N==0 )
    {
        cout<<endl;
        return 1;
    }
    if(s.N==1)
    {
        p=PrintSymbols(s.next[0],k+1);
        if(p==1)
        {
            PrintK(k+1);
        }
    }
    else
    {
        for(i=0;i<s.N;i++)
        {
            p=PrintSymbols(s.next[i],k+1);
            if(p==1)
            {
                PrintK(k+1);
            }
        }
    }
    return 0;
}
//---------------------------------------------------------------------------
void TWords::SaveToFile(FILE *f,TSymbol s)
{
    int i;
    fwrite(&s.S,1,sizeof(char),f);
    fwrite(&s.N,1,sizeof(char),f);
    for(i=0;i<s.N;i++)
    {
        SaveToFile(f,s.next[i]);
    }
}
//---------------------------------------------------------------------------
void TWords::SaveToFile(char *fname)
{
    int i;
    FILE *f;
    f=fopen(fname,"wb");
    fwrite(&N,1,sizeof(char),f);
    for(i=0;i<N;i++)
    {
        SaveToFile(f,words[i]);
    }
    fclose(f);
}
//---------------------------------------------------------------------------
void TWords::Free()
{
    int i;
    TSymbol t;
    for(i=0;i<N;i++)
    {
        Delete(words[i]);
    }
    delete words;
    words=NULL;
    N=0;
}
//---------------------------------------------------------------------------
void TWords::LoadFromFile(char *fname)
{
    int i;
    FILE *f;
    f=fopen(fname,"rb");
    if(!f)
    {
        return;
    }
    this->Free();
    fread(&N,1,sizeof(char),f);
    if(N>0 && N<256)
    {
        words=new TSymbol[N];
        for(i=0;i<N;i++)
        {
            words[i].S=0;
            words[i].N=0;
            words[i].next=NULL;
            LoadFromFile(f,words[i]);
        }
    }
    fclose(f);
}
//---------------------------------------------------------------------------
void TWords::LoadFromFile(FILE *f,TSymbol &s)
{
    int i;
    fread(&s.S,1,sizeof(char),f);
    fread(&s.N,1,sizeof(char),f);
    if(s.N>0)
    {
        s.next=new TSymbol[s.N];
        for(i=0;i<s.N;i++)
        {
            s.next[i].S=0;
            s.next[i].N=0;
            s.next[i].next=NULL;
            LoadFromFile(f,s.next[i]);
        }
    }
}
//---------------------------------------------------------------------------
bool TWords::SearchWord(char *w)
{
    int i;
    if(!w || !*w)
    {
        return false;
    }
    i=0;
    while(i<N && *w!=words[i].S)
    {
        i++;
    }
    if(i<N)
    {
        return SearchWord(w+1,words[i]);
    }
    return false;
}
//---------------------------------------------------------------------------
bool TWords::SearchWord(char *w,TSymbol s)
{
    int i;
    i=0;
    while(i<s.N && *w!=s.next[i].S)
    {
        i++;
    }
    if(i<s.N)
    {
        if(!*w)
        {
            return true;
        }
        return SearchWord(w+1,s.next[i]);
    }
    return false;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 