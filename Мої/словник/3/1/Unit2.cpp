//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Word::T_Word()
{
    Amount=0;
    Word=NULL;
}
//---------------------------------------------------------------------------
T_Word::T_Word(const T_Word &w)
{
    int i;
    Amount=w.Amount;
    Word=new char*[Amount];
    for(i=0;i<Amount;i++)
    {
        Word[i]=strdup(w.Word[i]);
    }
}
//---------------------------------------------------------------------------
T_Word::~T_Word()
{
    Delete();
}
//---------------------------------------------------------------------------
void T_Word::Delete()
{
    int i;
    for(i=0;i<Amount;i++)
    {
        delete Word[i];
        Word[i]=NULL;
    }
    delete Word;
    Word=NULL;
    Amount=0;
}
//---------------------------------------------------------------------------
void T_Word::Create(const char *w)
{
    int i=0,l=0,r=0,j;
    Delete();
    Amount=AmountWord(w);
    if(Amount>0)
    {
        Word=new char*[Amount];
        l=0;
        for(i=0;i<Amount;i++)
        {
            SearchWord(l,r,w);
            if(l!=-1)
            {
                Word[i]=new char[r-l];
                for(j=0;j<r-l;j++)
                {
                    Word[i][j]=w[j+l];
                }
                Word[i][j]=0;
                l=r+1;
            }
        }
    }
}
//---------------------------------------------------------------------------
int T_Word::AmountWord(const char *w)const
{
    int i=0,l=0,r=0;
    while(w[i])
    {
        if(w[i]==cLeft)
        {
            l++;
        }
        if(w[i]==cRight)
        {
            r++;
        }
        i++;
    }
    if(l==r)
    {
        i=l;
    }
    else
    {
        i=0;
    }
    return i;
}
//---------------------------------------------------------------------------
void T_Word::SearchWord(int &l,int &r,const char *w)const
{
    while(w[l] && w[l]!=cLeft)
    {
        l++;
    }
    if(w[l]==cLeft)
    {
        l++;
        r=l;
        while(w[r] && w[r]!=cRight)
        {
            r++;
        }
        if(w[r]==cRight)
        {
            // good
        }
        else
        {
            r=l=-1;
        }
    }
    else
    {
        r=l=-1;
    }
}
//---------------------------------------------------------------------------
char* T_Word::operator [] (const int &k)
{
    if(k<0 || k>=Amount)
    {
        return "";
    }
    return strdup(Word[k]);
}
//---------------------------------------------------------------------------
char* T_Word::CreateForSave()
{
    int i,j,l=0;
    char *w;
    for(i=0;i<Amount;i++)
    {
        l+=strlen(Word[i]);
    }
    l+=Amount*2;
    w=new char[l+1];
    l=0;
    for(i=0;i<Amount;i++)
    {
        w[l]=cLeft;
        l++;
        j=0;
        while(Word[i][j])
        {
            w[l]=Word[i][j];
            j++;
            l++;
        }
        w[l]=cRight;
        l++;
    }
    w[l]=0;
    return w;
}
//---------------------------------------------------------------------------
T_Word_Translation::T_Word_Translation()
{
}
//---------------------------------------------------------------------------
T_Word_Translation::T_Word_Translation(const T_Word_Translation &wt)
    :Eng(wt.Eng),Ukr(wt.Ukr)
{
}
//---------------------------------------------------------------------------
void T_Word_Translation::Create(char *w)
{
    int i=0;
    while(w[i] && w[i]!=cTranslation)
    {
        i++;
    }
    if(w[i]==cTranslation)
    {
        w[i]=0;
        Eng.Create(w);
        w[i]=cTranslation;
        Ukr.Create(&w[i+1]);
    }
}
//---------------------------------------------------------------------------
char* T_Word_Translation::CreateForSave()
{
    char *eng=Eng.CreateForSave(),
         *ukr=Ukr.CreateForSave();
    char *w=new char[strlen(eng)+strlen(ukr)+2];
    sprintf(w,"%s=%s\0",eng,ukr);
    delete[] eng;
    delete[] ukr;
    return w;
}
//---------------------------------------------------------------------------
void T_Word_Translation::SaveToFile(FILE *f)
{
    char *w=CreateForSave();
    fputs(w,f);
}
//---------------------------------------------------------------------------
int T_Word_Translation::LoadFromFile(FILE *f)
{
    char buf[1024];
    if(fgets(buf,1024,f))
    {
        Create(buf);
        return 1;
    }
    return 0;
}
//---------------------------------------------------------------------------
T_Words::T_Words():List(Compare)
{
}
//---------------------------------------------------------------------------
bool Compare(const void *v1,const void *v2)
{
    //T_Word_Translation *wt1,*wt2;
    //wt1=(T_Word_Translation *)v1;
    //wt2=(T_Word_Translation *)v2;
    return false;
}
//---------------------------------------------------------------------------
void T_Words::LoadFromFile()
{
    FILE *f=fopen(fName.c_str(),"r");
    T_Word_Translation wt;
    while(wt.LoadFromFile(f))
    {
        List.Add(wt);
    }
    fclose(f);
}
//---------------------------------------------------------------------------
T_Word& T_Word::operator = (const T_Word &w)
{
    if(this!=&w)
    {
        int i;
        Delete();
        Amount=w.Amount;
        Word=new char*[Amount];
        for(i=0;i<Amount;i++)
        {
            Word[i]=strdup(w.Word[i]);
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
T_Word_Translation& T_Word_Translation::operator = (const T_Word_Translation &wt)
{
    if(this!=&wt)
    {
        Eng=wt.Eng;
        Ukr=wt.Ukr;
    }
    return *this;
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
