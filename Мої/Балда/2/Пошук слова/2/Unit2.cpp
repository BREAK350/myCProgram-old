//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void T_Balda::Delete(bT_Data *&Item)
{
    if(Item)
    {
        Delete(Item->Next);
        delete Item;
        Item=NULL;
    }
}
//---------------------------------------------------------------------------
void T_Balda::Add(const bT_Data::T_Data &data,const int &i,T_Dictionary &D)
{
    if(data.S)
    {
        if(First==NULL)
        {
            First=new bT_Data(data);
            Last=First;
        }
        else
        {
            if(!pSearch(data.C))
            {
                Last->Next=new bT_Data(data);
                Last=Last->Next;
            }
        }
        D.Used.Add(i);
    }
}
//---------------------------------------------------------------------------
void T_Balda::Add(const bT_Data::T_Data &data)
{
    if(data.S)
    {
        if(First==NULL)
        {
            First=new bT_Data(data);
            Last=First;
        }
        else
        {
            if(!pSearch(data.C))
            {
                Last->Next=new bT_Data(data);
                Last=Last->Next;
            }
        }
    }
}
//---------------------------------------------------------------------------
int operator == (const TPoint &a,const TPoint &b)
{
    return a.x==b.x && a.y==b.y;
}
//---------------------------------------------------------------------------
int T_Balda::Search(const TPoint &c)const
{
    int q=0;
    bT_Data *p=pSearch(c);
    if(p)
    {
        q=1;
    }
    return q;
}
//---------------------------------------------------------------------------
T_Balda::T_Balda(const char *w)
{
    int i=1;
    if(w)
    {
        First=new bT_Data(bT_Data::T_Data(w[0],TPoint(0,0)));
        Last=First;
        while(w[i])
        {
            Add(bT_Data::T_Data(w[i],TPoint(i,0)));
            i++;
        }
    }
    else
    {
        Last=First=NULL;
    }
}
//---------------------------------------------------------------------------
void T_Balda::CreateFirstWord(const char *w)
{
    if(w)
    {
        int i=1;
        Delete();
        First=new bT_Data(bT_Data::T_Data(w[0],TPoint(0,0)));
        Last=First;
        while(w[i])
        {
            Add(bT_Data::T_Data(w[i],TPoint(i,0)));
            i++;
        }
    }
    else
    {
        Last=First=NULL;
    }
}
//---------------------------------------------------------------------------
T_Balda::T_Balda(const T_Dictionary &D)
{
    CreateFirstWord(D);
}
//---------------------------------------------------------------------------
void T_Balda::CreateFirstWord(const T_Dictionary &D)
{
    randomize();
    int n=random(D.GetN());
    CreateFirstWord(D.operator [](n));
    D.Used.Add(n);
}
//---------------------------------------------------------------------------
void T_Balda::Draw(TCanvas *Canvas,const TPoint &c,const int &s)const
{
    bT_Data *p=First;
    while(p)
    {
        /*Canvas->Rectangle(p->Data.C.x*s+c.x,p->Data.C.y*s+c.y,
                          p->Data.C.x*s+s+c.x,p->Data.C.y*s+s+c.y); */
        Canvas->TextOutA(p->Data.C.x*s+c.x,p->Data.C.y*s+c.y,p->Data.S);
        p=p->Next;
    }
}
//---------------------------------------------------------------------------
bT_Data* T_Balda::pSearch(const TPoint &c)const
{
    bT_Data *p=First;
    while(p && !(p->Data.C==c))
    {
        p=p->Next;
    }
    return p;
}
//---------------------------------------------------------------------------
void T_Balda::CreateBorder(T_Balda &Border)const
{
    TPoint c;
    bT_Data *p=First;
    Border.Delete();
    while(p)
    {
        c=TPoint(p->Data.C.x,p->Data.C.y+1);
        if(!pSearch(c))
        {
            Border.Add(bT_Data::T_Data('+',c));
        }
        c=TPoint(p->Data.C.x+1,p->Data.C.y);
        if(!pSearch(c))
        {
            Border.Add(bT_Data::T_Data('+',c));
        }
        c=TPoint(p->Data.C.x,p->Data.C.y-1);
        if(!pSearch(c))
        {
            Border.Add(bT_Data::T_Data('+',c));
        }
        c=TPoint(p->Data.C.x-1,p->Data.C.y);
        if(!pSearch(c))
        {
            Border.Add(bT_Data::T_Data('+',c));
        }
        p=p->Next;
    }
}
//---------------------------------------------------------------------------
TPoint T_Balda::SearchMin()const
{
    TPoint c(0,0);
    bT_Data *p=First;
    while(p)
    {
        if(c.x>p->Data.C.x)
        {
            c.x=p->Data.C.x;
        }
        if(c.y>p->Data.C.y)
        {
            c.y=p->Data.C.y;
        }
        p=p->Next;
    }
    return c;
}
//---------------------------------------------------------------------------
char* T_Balda::toChar()const
{
    bT_Data *p=First;
    int i=0;
    const int max=32;
    char buf[max];
    buf[0]=0;
    while(p && i<max)
    {
        buf[i]=p->Data.S;
        i++;
        p=p->Next;
    }
    buf[i]=0;
    return strdup(buf);
}
//---------------------------------------------------------------------------
int isNear(const TPoint &a,const TPoint &b)
{
    return abs(a.x-b.x)+abs(a.y-b.y)==1;
}
//---------------------------------------------------------------------------
int isNear(const bT_Data *a,const bT_Data *b)
{
    return isNear(a->Data.C,b->Data.C);
}
//---------------------------------------------------------------------------
bT_Data* T_Balda::SearchWord(const char *w,T_Balda &Border)
{
    int i=1,q=0;
    bT_Data *b=Border.First;
    while(b && q==0)
    {
        SearchWord(w,i,b->Data.C,q);
        if(q==0)
        {
            b=b->Next;
        }
    }
    return b;
}
//---------------------------------------------------------------------------
void T_Balda::SearchWord(const char *w,const int &i,const TPoint &c,int &q)
    //q=0 - слово не знайдено q=1 - слово знайдено
{
    if(q==0)
    {
        if(w[i])
        {
            bT_Data *p=First;
            while(p && q==0)
            {
                while(p && p->Data.S!=w[i])
                {
                    p=p->Next;
                }
                if(p && q==0)
                {
                    if(p->Data.Use==0 && isNear(p->Data.C,c))
                    {
                        p->Data.Use=1;
                        SearchWord(w,i+1,p->Data.C,q);
                        p->Data.Use=0;
                    }
                    p=p->Next;
                }
            }
        }
        else
        {
            q=1;
        }
    }
}
//---------------------------------------------------------------------------
bT_Data::T_Data T_Balda::SearchMaxWordFB(T_Dictionary &D,T_Balda &Border,int &i)
{
    i=0;
    bT_Data *b=NULL;
    bT_Data::T_Data Data;
    char *w=NULL;
    while(i<D.GetN() && Data.S==0)
    {
        while(i<D.GetN() && !(b=SearchWord(w=D[i],Border)))
        {
            i++;
            delete[] w;
        }
        if(i<D.GetN())
        {
            if(D.Used.Search(i)==0)
            {
                Data.S=w[0];
                Data.C=b->Data.C;
            }
            else
            {
                i++;
            }
            delete[] w;
        }
    }
    return Data;
}
//---------------------------------------------------------------------------
bT_Data::T_Data T_Balda::SearchMaxWordLB(T_Dictionary &D,T_Balda &Border,int &i)
{
    i=0;
    bT_Data *b;
    char *back=NULL;
    bT_Data::T_Data Data;
    while(i<D.GetN() && Data.S==0)
    {
        while(i<D.GetN() && !(b=SearchWord(back=DoBack(D[i]),Border)))
        {
            i++;
            delete[] back;
        }
        if(i<D.GetN())
        {
            if(D.Used.Search(i)==0)
            {
                Data.S=back[0];
                Data.C=b->Data.C;
            }
            else
            {
                i++;
            }
            delete[] back;
        }
    }
    return Data;
}
//---------------------------------------------------------------------------
char* DoBack(char *w)
{
    if(w)
    {
        int i,n=strlen(w);
        char c;
        for(i=0;i<n/2;i++)
        {
            c=w[i];
            w[i]=w[n-i-1];
            w[n-i-1]=c;
        }
    }
    return w;
}
//---------------------------------------------------------------------------
bT_Data::T_Data T_Balda::SearchMaxWord(T_Dictionary &D,int &i)
{
    T_Balda Border;
    int l=0;
    i=0;
    bT_Data::T_Data Dataf,Datal;
    CreateBorder(Border);
    Dataf=SearchMaxWordFB(D,Border,i);
    Datal=SearchMaxWordLB(D,Border,l);
    if(i>l)
    {
        i=l;
        Dataf=Datal;
    }
    Border.Delete();
    return Dataf;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*T_Balda::T_Balda(const char *fname):Dictionary(fname),List(Dictionary)
{
}*/
//---------------------------------------------------------------------------
void T_Balda::Again(const T_Dictionary &D)
{
    D.Used.Delete();
    Delete();
    CreateFirstWord(D);
}
//---------------------------------------------------------------------------
/*void T_Balda::LoadDictionary(const char *fname)
{
    Dictionary;
}*/
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

