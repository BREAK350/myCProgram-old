//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void bT_List::ShowLink(TCanvas *Canvas,const TPoint &c,const int &s)const
{
    bT_ListItem *p=First;
    if(First)
    {
        Canvas->MoveTo(p->Data.C.x*s+c.x,p->Data.C.y*s+c.y);
        p=p->Next;
    }
    while(p)
    {
        Canvas->LineTo(p->Data.C.x*s+c.x,p->Data.C.y*s+c.y);
        p=p->Next;
    }
}
//---------------------------------------------------------------------------
void bT_List::Delete(bT_ListItem *&Item)
{
    if(Item)
    {
        Delete(Item->Next);
        delete Item;
        Item=NULL;
    }
}
//---------------------------------------------------------------------------
void bT_List::Add(const bT_ListItem::T_Data &data,const int &i,T_Dictionary &D)
{
    if(data.S)
    {
        if(First==NULL)
        {
            First=new bT_ListItem(data);
            Last=First;
        }
        else
        {
            if(!pSearch(data.C))
            {
                Last->Next=new bT_ListItem(data);
                Last=Last->Next;
            }
        }
        D.Used.Add(i);
    }
}
//---------------------------------------------------------------------------
void bT_List::Add(const bT_ListItem::T_Data &data)
{
    if(data.S)
    {
        if(First==NULL)
        {
            First=new bT_ListItem(data);
            Last=First;
        }
        else
        {
            if(!pSearch(data.C))
            {
                Last->Next=new bT_ListItem(data);
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
int bT_List::Search(const TPoint &c)const
{
    int q=0;
    bT_ListItem *p=pSearch(c);
    if(p)
    {
        q=1;
    }
    return q;
}
//---------------------------------------------------------------------------
bT_List::bT_List(const char *w)
{
    int i=1;
    if(w)
    {
        First=new bT_ListItem(bT_ListItem::T_Data(w[0],TPoint(0,0)));
        Last=First;
        while(w[i])
        {
            Add(bT_ListItem::T_Data(w[i],TPoint(i,0)));
            i++;
        }
    }
    else
    {
        Last=First=NULL;
    }
}
//---------------------------------------------------------------------------
void bT_List::CreateFirstWord(const char *w)
{
    if(w)
    {
        int i=1;
        Delete();
        First=new bT_ListItem(bT_ListItem::T_Data(w[0],TPoint(0,0)));
        Last=First;
        while(w[i])
        {
            Add(bT_ListItem::T_Data(w[i],TPoint(i,0)));
            i++;
        }
    }
    else
    {
        Last=First=NULL;
    }
}
//---------------------------------------------------------------------------
bT_List::bT_List(const T_Dictionary &D)
{
    CreateFirstWord(D);
}
//---------------------------------------------------------------------------
void bT_List::CreateFirstWord(const T_Dictionary &D)
{
    CreateFirstWord(D.GetRandomWord());
}
//---------------------------------------------------------------------------
void bT_List::Draw(TCanvas *Canvas,const TPoint &c,const int &s)const
{
    bT_ListItem *p=First;
    while(p)
    {
        /*if(p->Data.Use)
        {
            Canvas->Rectangle(p->Data.C.x*s+c.x,p->Data.C.y*s+c.y,
                          p->Data.C.x*s+s+c.x,p->Data.C.y*s+s+c.y); }*/
        Canvas->TextOutA(p->Data.C.x*s+c.x,p->Data.C.y*s+c.y,p->Data.S);
        p=p->Next;
    }
}
//---------------------------------------------------------------------------
bT_ListItem* bT_List::pSearch(const TPoint &c)const
{
    bT_ListItem *p=First;
    while(p && !(p->Data.C==c))
    {
        p=p->Next;
    }
    return p;
}
//---------------------------------------------------------------------------
void bT_List::CreateBorder(bT_List &Border)const
{
    TPoint c;
    bT_ListItem *p=First;
    Border.Delete();
    while(p)
    {
        c=TPoint(p->Data.C.x,p->Data.C.y+1);
        if(!pSearch(c))
        {
            Border.Add(bT_ListItem::T_Data('+',c));
        }
        c=TPoint(p->Data.C.x+1,p->Data.C.y);
        if(!pSearch(c))
        {
            Border.Add(bT_ListItem::T_Data('+',c));
        }
        c=TPoint(p->Data.C.x,p->Data.C.y-1);
        if(!pSearch(c))
        {
            Border.Add(bT_ListItem::T_Data('+',c));
        }
        c=TPoint(p->Data.C.x-1,p->Data.C.y);
        if(!pSearch(c))
        {
            Border.Add(bT_ListItem::T_Data('+',c));
        }
        p=p->Next;
    }
}
//---------------------------------------------------------------------------
TPoint bT_List::SearchMin()const
{
    TPoint c(0,0);
    bT_ListItem *p=First;
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
char* bT_List::toChar()const
{
    bT_ListItem *p=First;
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
int isNear(const bT_ListItem *a,const bT_ListItem *b)
{
    return isNear(a->Data.C,b->Data.C);
}
//---------------------------------------------------------------------------
bT_ListItem* bT_List::SearchWord(const char *w,bT_List &Border,bT_Stack &bs)
{
    int i=1,q=0;
    bT_ListItem *b=Border.First;
    while(b && q==0)
    {
        bs.Write(b->Data.C);
        SearchWord(w,i,b->Data.C,q,bs);
        if(q==0)
        {
            b=b->Next;
            bs.Again();
        }
    }
    return b;
}
//---------------------------------------------------------------------------
void bT_List::SearchWord(const char *w,const int &i,const TPoint &c,int &q,bT_Stack &bs)
    //q=0 - слово не знайдено q=1 - слово знайдено
{
    if(q==0)
    {
        if(w[i])
        {
            bT_ListItem *p=First;
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
                        bs.Write(p->Data.C);
                        SearchWord(w,i+1,p->Data.C,q,bs);
                        p->Data.Use=0;
                        if(q==0)
                        {
                            TPoint point;
                            bs.Read(point);
                        }
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
bT_ListItem::T_Data bT_List::SearchMaxWordFB(T_Dictionary &D,bT_List &Border,int &i,bT_Stack &bs)
{
    i=0;
    bT_ListItem *b=NULL;
    bT_ListItem::T_Data Data;
    char *w=NULL;
    while(i<D.GetN() && Data.S==0)
    {
        while(i<D.GetN() && !(b=SearchWord(w=D[i],Border,bs)))
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
                bs.Again();
            }
            delete[] w;
        }
    }
    return Data;
}
//---------------------------------------------------------------------------
bT_ListItem::T_Data bT_List::SearchMaxWordLB(T_Dictionary &D,bT_List &Border,int &i,bT_Stack &bs)
{
    i=0;
    bT_ListItem *b;
    char *back=NULL;
    bT_ListItem::T_Data Data;
    while(i<D.GetN() && Data.S==0)
    {
        while(i<D.GetN() && !(b=SearchWord(back=DoBack(D[i]),Border,bs)))
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
                bs.Again();
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
bT_ListItem::T_Data bT_List::SearchMaxWord(T_Dictionary &D,int &i,bT_Stack &bs)
{
    bT_List Border;
    bT_Stack left;
    int l=0;
    i=0;
    bT_ListItem::T_Data Dataf,Datal;
    CreateBorder(Border);
    Dataf=SearchMaxWordFB(D,Border,i,bs);
    Datal=SearchMaxWordLB(D,Border,l,left);
    if(i>l)
    {
        i=l;
        Dataf=Datal;
        bs=left;
    }
    Border.Delete();
    return Dataf;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
T_Balda::T_Balda(const char *fname):Dictionary(fname),List(Dictionary)
{
}
//---------------------------------------------------------------------------
void bT_List::Again(const T_Dictionary &D)
{
    D.Used.Delete();
    Delete();
    CreateFirstWord(D);
}
//---------------------------------------------------------------------------
void T_Balda::LoadDictionary(const char *fname)
{
    Dictionary;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int bT_Player::GetWord(bT_Stack &bs)
{
    int q=-1,i;
    bT_ListItem::T_Data Data;
    Data=List->SearchMaxWord(*D,i,bs);
    if(Data.S)
    {
        List->Add(Data,i,*D);
        q=i;
    }
    return q;
}
//---------------------------------------------------------------------------
int bT_Player::SearchWord(const char &c,bT_Stack &bs)
{
}
//---------------------------------------------------------------------------
char bT_List::GetChar(const TPoint &p)const
{
    char c=0;
    bT_ListItem *t=First;
    while(t && !(t->Data.C==p))
    {
        t=t->Next;
    }
    if(t)
    {
        c=t->Data.S;
    }
    return c;
}
//---------------------------------------------------------------------------
int bT_Player::SearchWord(const char *w)
{
    return D->SearchPathWord(w);
}
//---------------------------------------------------------------------------
int bT_Player::AddWord(const char *w)
{
    int i=SearchWord(w)-1;
    if(i>-1)
    {
        D->Used.Add(i);
        i=1;
    }
    else
    {
        i=0;
    }
    return i;
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

