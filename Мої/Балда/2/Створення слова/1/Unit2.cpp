//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_List::T_ListItem::T_ListItem()
{
    Word=NULL;
    Next=NULL;
}
//---------------------------------------------------------------------------
T_List::T_ListItem::T_ListItem(const char *w)
{
    if(w)
    {
        Word=strdup(w);
    }
    else
    {
        Word=NULL;
    }
    Next=NULL;
}
//---------------------------------------------------------------------------
T_List::T_ListItem::~T_ListItem()
{
    delete Word;
    Word=NULL;
    Next=NULL;
}
//---------------------------------------------------------------------------
int T_List::T_ListItem::operator == (const T_ListItem &li)
{
    return strcmp(Word,li.Word)==0;
}
//---------------------------------------------------------------------------
int T_List::Add(const char *w)
{
    int q=0;
    if(First==NULL)
    {
        First=new T_ListItem (w);
        q=1;
    }
    else
    {
        T_ListItem buf(w),*p=First,*prev=NULL;
        while(p && !(*p==buf))
        {
            prev=p;
            p=p->Next;
        }
        if(p==NULL)
        {
            prev->Next=new T_ListItem (w);
            q=1;
        }
    }
    return q;
}
//---------------------------------------------------------------------------
void T_List::Delete(T_ListItem *&li)
{
    if(li)
    {
        Delete(li->Next);
        delete li;
        li=NULL;
    }
}
//---------------------------------------------------------------------------
T_Words::T_Words()
{
    MaxSize=0;
    Row=NULL;
    N=0;
}
//---------------------------------------------------------------------------
T_Words::T_Words(const int &ms)
{
    MaxSize=(ms>0)?(ms):(0);
    if(MaxSize>0)
    {
        Row=new T_List[MaxSize];
    }
    else
    {
        Row=NULL;
    }
    N=0;
}
//---------------------------------------------------------------------------
T_Words::~T_Words()
{
    delete[] Row;
    Row=NULL;
    MaxSize=0;
    N=0;
}
//---------------------------------------------------------------------------
int T_Words::Add(const char *w)
{
    int len=0;
    if(w)
    {
        len=strlen(w);
        if(len>0 && len<MaxSize)
        {
            len=Row[len].Add(w);
        }
    }
    N+=len;
    return len;
}
//---------------------------------------------------------------------------
void T_Words::LoadFromFile(const char *fname)
{
    if(fname)
    {
        ifstream F(fname);
        if(F.is_open())
        {
            int n;
            F>>n;
            if(n>0)
            {
                int i;
                const int ms=64;
                char buf[ms];
                for(i=0;i<n;i++)
                {
                    F>>buf;
                    Add(buf);
                }
            }
            F.close();
        }
    }
}
//---------------------------------------------------------------------------
void T_Words::SetSize(const int &ms)
{
    if(ms>0)
    {
        delete[] Row;
        MaxSize=ms;
        Row=new T_List[MaxSize];
        N=0;
    }
}
//---------------------------------------------------------------------------
void T_List::SaveToFile(FILE *f)
{
    T_ListItem *p=First;
    while(p)
    {
        fprintf(f,"%s\n",p->Word);
        p=p->Next;
    }
}
//---------------------------------------------------------------------------
void T_Words::SaveToFile(const char *fname)
{
    FILE *f=fopen(fname,"wt");
    int i;
    fprintf(f,"%d\n",N);
    for(i=MaxSize-1;i>0;i--)
    {
        Row[i].SaveToFile(f);
    }
    fclose(f);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
