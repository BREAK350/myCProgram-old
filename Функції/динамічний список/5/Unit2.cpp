//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
/***********TLISTITEM**********/
TListItem::TListItem()
{
    value=0;
    next=NULL;
}
//---------------------------------------------------------------------------
TListItem::~TListItem()
{                                          
    value=0;
    next=NULL;
}
//---------------------------------------------------------------------------
change TListItem::GetValue()
{
    return value;
}
//---------------------------------------------------------------------------
void TListItem::SetValue(change v)
{
    value=v;
}
//---------------------------------------------------------------------------
void TListItem::SetNext(TListItem *t)
{
    next=t;
}
//---------------------------------------------------------------------------
TListItem* TListItem::GetNext()
{
    return next;
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
/***********TLIST**********/
TList::TList()
{
    n=0;
    first=NULL;
}
//---------------------------------------------------------------------------
TList::~TList()
{
    n=0;
    _Delete_(*this);
    first=NULL;
}
//---------------------------------------------------------------------------
TList& TList::operator = (const TList &L)
{
    _Delete_(*this);
    n=L.n;
    TListItem *p,*r,*l;
    if(n<=0)
    {
        n=0;
        first=NULL;
    }
    else
    {
        first=new TListItem;
        first->SetValue(L.first->GetValue());
        l=L.first->GetNext();
        p=first;
        while(l)
        {
            r=new TListItem;
            r->SetValue(l->GetValue());
            p->SetNext(r);
            l=l->GetNext();
            p=p->GetNext();
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
TList TList::operator + (const TList &L)const
{
    TList S;
    TListItem *p,*r,*l,*h;
    if( n<=0 )
    {
        if( L.n<=0 )
        {
            return S;
        }
        return L;
    }
    if( L.n<=0 )
    {
        return *this;
    }
    S.n=(n>L.n)?(n):(L.n);
    S.first=new TListItem;
    S.first->SetValue(first->GetValue()+L.first->GetValue());
    p=S.first;
    r=first->GetNext();
    l=L.first->GetNext();
    while( r || l )
    {
        h=new TListItem;
        h->SetValue(0);
        if(r)
        {
            h->SetValue(h->GetValue()+r->GetValue());
            r=r->GetNext();
        }
        if(l)
        {
            h->SetValue(h->GetValue()+l->GetValue());
            l=l->GetNext();
        }
        p->SetNext(h);
        p=p->GetNext();
    }
    return S;
}
//---------------------------------------------------------------------------
TList::TList(const TList &L)
{
    n=L.n;
    TListItem *p,*r,*l;
    if(n<=0)
    {
        n=0;
        first=NULL;
    }
    else
    {
        first=new TListItem;
        first->SetValue(L.first->GetValue());
        l=L.first->GetNext();
        p=first;
        while(l)
        {
            r=new TListItem;
            r->SetValue(l->GetValue());
            p->SetNext(r);
            l=l->GetNext();
            p=p->GetNext();
        }
    }
}
//---------------------------------------------------------------------------
void TList::Init(int N,change *v)
{
    int i;
    TListItem *p,*r;
    _Delete_(*this);
    if(N<=0)
    {
        n=0;
        first=NULL;
        return;
    }
    n=N;
    first=new TListItem;
    first->SetValue(v[0]);
    p=first;
    for(i=1;i<N;i++)
    {
        r=new TListItem;
        r->SetValue(v[i]);
        p->SetNext(r);
        p=p->GetNext();
    }
}
//---------------------------------------------------------------------------
void TList::Display()const
{
    TListItem *p=first;
    cout<<endl<<'('<<n<<"): ";
    while(p)
    {
        cout<<p->GetValue();
        if(p->GetNext())
        {
            cout<<'+';
        }
        p=p->GetNext();
    }
    cout<<endl;
}
//---------------------------------------------------------------------------
TList TList::operator - (const TList &L)const
{
    TList S;
    TListItem *p,*r,*l,*h;
    if( n<=0 )
    {
        if( L.n<=0 )
        {
            return S;
        }
        return L;
    }
    if( L.n<=0 )
    {
        return *this;
    }
    S.n=(n>L.n)?(n):(L.n);
    S.first=new TListItem;
    S.first->SetValue(first->GetValue()-L.first->GetValue());
    p=S.first;
    r=first->GetNext();
    l=L.first->GetNext();
    while( r || l )
    {
        h=new TListItem;
        h->SetValue(0);
        if(r)
        {
            h->SetValue(h->GetValue()+r->GetValue());
            r=r->GetNext();
        }
        if(l)
        {
            h->SetValue(h->GetValue()-l->GetValue());
            l=l->GetNext();
        }
        p->SetNext(h);
        p=p->GetNext();
    }
    return S;
}
//---------------------------------------------------------------------------
TList TList::operator * (const TList &R)const
{
    int stl,str;
    TList D;
    TListItem *h,*p;
    if( n<=0 || R.n<=0 )
    {
        return D;
    }
    D.n=n+R.n;
    D.first=new TListItem;
    p=D.first;
    for(stl=2;stl<D.n;stl++)
    {
        h=new TListItem;
        p->SetNext(h);
        p=p->GetNext();
    }
    for(stl=0;stl<n;stl++)
    {
        for(str=0;str<R.n;str++)
        {
            D.SetValue(D.GetValue(stl+str)+GetValue(stl)*R.GetValue(str),stl+str);
        }
    }
    return D;
}
//---------------------------------------------------------------------------
change TList::GetValue(int k)
{
    int i;
    TListItem *p;
    if( k<0 || k>=n )
    {
        return 0;
    }
    p=first;
    for(i=0;i<k;i++)
    {
        p=p->GetNext();
    }
    return p->GetValue();
}
//---------------------------------------------------------------------------
void TList::SetValue(change c,int k)
{
    int i;
    TListItem *p;
    if( k<0 || k>=n )
    {
        return;
    }
    p=first;
    for(i=0;i<k;i++)
    {
        p=p->GetNext();
    }
    p->SetValue(c);
}
//---------------------------------------------------------------------------
bool TList::operator == (const TList &R)const
{
    TListItem *l,*r;
    if( n!=R.n )
    {
        return false;
    }
    l=first;
    r=R.first;
    while( l && r && l->GetValue()==r->GetValue() )
    {
        l=l->GetNext();
        r=r->GetNext();
    }
    if( !l && !r )
    {
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------
change TList::ValueIn(change c)
{
    change d,s;
    TListItem *p;
    s=0;
    d=1;
    p=first;
    while(p)
    {
        s=s+d*p->GetValue();
        d=d*c;
        p=p->GetNext();
    }
    return s;
}
//---------------------------------------------------------------------------
int Fuctorial(int n)
{
    if(n<=1)
    {
        return 1;
    }
    return n*Fuctorial(n-1);
}
//---------------------------------------------------------------------------
int Combination(int n,int k)
{
    return Fuctorial(n)/(Fuctorial(k)*Fuctorial(n-k));
}
//---------------------------------------------------------------------------
TList TList::ChangeXToXPlusA(change a)const
{
    int i,k,j;
    TList C;
    change ai,ak;
    TListItem *p,*h;
    if(a==0)
    {                                      
        return *this;
    }
    C.n=n;
    C.first=new TListItem;
    p=C.first;
    for(i=1;i<C.n;i++)
    {
        h=new TListItem;
        p->SetNext(h);
        p=p->GetNext();
    }
    p=first;
    i=0;
    while(p)
    {
        ai=0;
        for(k=i;k<n;k++)
        {
            ak=1;
            for(j=0;j<k-i;j++)
            {
                ak=ak*a;
            }
            int dd=GetValue(k);
            dd=Combination(k,i);
            ai=ai+Combination(k,i)*GetValue(k)*ak;
        }
        C.SetValue(ai,i);
        p=p->GetNext();
        i++;
    }
    return C;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/***********FRIEND**********/
void _Delete_(TList &L)
{
    if(L.first)
    {
        _delete_(L.first);
    }
    L.n=0;
    L.first=NULL;
}
//---------------------------------------------------------------------------
void _delete_(TListItem *&p)
{
    if(p->next)                      
    {
        _delete_(p->next);
    }
    delete p;
    p=NULL;
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

