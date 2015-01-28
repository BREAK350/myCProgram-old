//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void T_List::Delete(T_ListItem *&Item)
{
    if(Item)
    {
        Delete(Item->Next);
        delete Item;
        Item=NULL;
    }
}
//---------------------------------------------------------------------------
void T_List::Add(const T_Data &data)
{
    if(First==NULL)
    {
        First=new T_ListItem(data);
        Last=First;
    }
    else
    {
        if(!pSearch(data.C))
        {
            Last->Next=new T_ListItem(data);
            Last=Last->Next;
        }
    }
}
//---------------------------------------------------------------------------
int operator == (const TPoint &a,const TPoint &b)
{
    return a.x==b.x && a.y==b.y;
}
//---------------------------------------------------------------------------
int T_List::Search(const TPoint &c)const
{
    int q=0;
    T_ListItem *p=pSearch(c);
    if(p)
    {
        q=1;
    }
    return q;
}
//---------------------------------------------------------------------------
T_List::T_List(const char *w)
{
    int i=1;
    if(w)
    {
        First=new T_ListItem(T_Data(w[0],TPoint(0,0)));
        Last=First;
        while(w[i])
        {
            Add(T_Data(w[i],TPoint(i,0)));
            i++;
        }
    }
    else
    {
        Last=First=NULL;
    }
}
//---------------------------------------------------------------------------
void T_List::Draw(TCanvas *Canvas,const TPoint &c,const int &s)const
{
    T_ListItem *p=First;
    while(p)
    {
        /*Canvas->Rectangle(p->Data.C.x*s+c.x,p->Data.C.y*s+c.y,
                          p->Data.C.x*s+s+c.x,p->Data.C.y*s+s+c.y); */
        Canvas->TextOutA(p->Data.C.x*s+c.x,p->Data.C.y*s+c.y,p->Data.S);
        p=p->Next;
    }
}
//---------------------------------------------------------------------------
T_ListItem* T_List::pSearch(const TPoint &c)const
{
    T_ListItem *p=First;
    while(p && !(p->Data.C==c))
    {
        p=p->Next;
    }
    return p;
}
//---------------------------------------------------------------------------
void T_List::CreateBorder(const char &s,T_List &Border)const
{
    TPoint c;
    T_ListItem *p=First;
    Border.Delete();
    while(p)
    {
        c=TPoint(p->Data.C.x,p->Data.C.y+1);
        if(!pSearch(c))
        {
            Border.Add(T_Data(s,c));
        }
        c=TPoint(p->Data.C.x+1,p->Data.C.y);
        if(!pSearch(c))
        {
            Border.Add(T_Data(s,c));
        }
        c=TPoint(p->Data.C.x,p->Data.C.y-1);
        if(!pSearch(c))
        {
            Border.Add(T_Data(s,c));
        }
        c=TPoint(p->Data.C.x-1,p->Data.C.y);
        if(!pSearch(c))
        {
            Border.Add(T_Data(s,c));
        }
        p=p->Next;
    }
}
//---------------------------------------------------------------------------
TPoint T_List::SearchMin()const
{
    TPoint c(0,0);
    T_ListItem *p=First;
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
char* T_List::toChar()const
{
    T_ListItem *p=First;
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
int isNear(const T_ListItem *a,const T_ListItem *b)
{
    return isNear(a->Data.C,b->Data.C);
}
//---------------------------------------------------------------------------
T_ListItem* T_List::SearchWord(const char *w,T_List &Border)const
{
    int i=1,q=0;
    T_ListItem *b=Border.First;
    while(b)
    {
        SearchWord(w,i,b->Data.C,q);
        if(q==1)
        {
            break;
        }
        else
        {
            b=b->Next;
        }
    }
    return b;
}
//---------------------------------------------------------------------------
void T_List::SearchWord(const char *w,const int &i,const TPoint &c,int &q)const
    //q=0 - слово не знайдено q=1 - слово знайдено
{
    if(q==0)
    {
        if(w[i])
        {
            T_ListItem *p=First;
            while(p && q==0)
            {
                while(p && p->Data.S!=w[i])
                {
                    p=p->Next;
                }
                if(p && q==0)
                {
                    if(isNear(p->Data.C,c))
                    {
                        SearchWord(w,i+1,p->Data.C,q);
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
T_Data T_List::SearchMaxWordFB(T_Dictionary &D,T_List &Border,int &i)const
{
    i=0;
    T_ListItem *b;
    T_Data Data('+',TPoint(0,0));
    while(i<D.GetN() && !(b=SearchWord(D[i],Border)))
    {
        i++;
    }
    if(i<D.GetN())
    {
        Data.S=D[i][0];
        Data.C=b->Data.C;
    }
    return Data;
}
//---------------------------------------------------------------------------
T_Data T_List::SearchMaxWordLB(T_Dictionary &D,T_List &Border,int &i)const
{
    i=0;
    T_ListItem *b;
    char *back;
    T_Data Data('+',TPoint(0,0));
    while(i<D.GetN() && !(b=SearchWord(back=DoBack(D[i]),Border)))
    {
        i++;
    }
    if(i<D.GetN())
    {
        Data.S=back[0];
        Data.C=b->Data.C;
    }
    delete back;
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
T_Data T_List::SearchMaxWord(T_Dictionary &D,int &i)const
{
    T_List Border;
    int l=0;
    i=0;
    T_Data Dataf('+',TPoint(0,0)),Datal('+',TPoint(0,0));
    CreateBorder('+',Border);
    Dataf=SearchMaxWordFB(D,Border,i);
    Datal=SearchMaxWordLB(D,Border,l);
    if(i>l)
    {
        Dataf=Datal;
        i=l;
    }
    return Dataf;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
