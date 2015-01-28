//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TListItem::TListItem()
{
    value=-1;
    next=NULL;
}
//---------------------------------------------------------------------------
TListItem* TListItem::Init(int v)
{
    value=v;
    return this;
}
//---------------------------------------------------------------------------
TListItem* TListItem::Add(int v)
{
    TListItem *r;
    r=next;
    next=new TListItem;
    next->value=v;
    next->next=r;
    return next;
}
//---------------------------------------------------------------------------
void Delete(TListItem *&li)
{
    if( li )
    {
        Delete(li->next);
    }
    delete li;
    li=NULL;
}
//---------------------------------------------------------------------------
TList Input(TList &L)
{
    int n,i;
    int v;
    TListItem *p=NULL;
    Delete(L.first->next);
    p=L.first;
    cout<<"n=";
    cin>>n;
    if(n<0)
    {
        return L;
    }
    p->Init(n);
    for(i=0;i<=n;i++)
    {
        cin>>v;
        p=p->Add(v);
    }
    return L;
}
//---------------------------------------------------------------------------
void DeleteList(TList &L)
{
    Delete(L.first->next);
    L.first->value=-1;
}
//---------------------------------------------------------------------------
void PrintList(TList L)
{
    int i;
    TListItem *p;
    if(L.first->value==-1)
    {
        cout<<"не визначений многочлен";
        return;
    }
    p=L.first->next;
    i=0;
    while(p)
    {
        //cout<<p->value<<"*x^"<<i<<'+';
        cout<<p->value<<' ';
        i++;
        p=p->next;
    }
}
//---------------------------------------------------------------------------
TList operator + (TList L,TList R)
{
    TList S;
    TListItem *l,*r,*s;
    int n,i;
    if( GetN(L)<0 || GetN(R)<0 )
    {
        return S;
    }
    SetN(S,(GetN(L)>GetN(R))?(GetN(L)):(GetN(R)));
    n=(GetN(L)<GetN(R))?(GetN(L)):(GetN(R));
    l=L.first->next;
    r=R.first->next;
    s=S.first;
    for(i=0;i<=n;i++)
    {
        s=s->Add(l->value+r->value);
        l=l->next;
        r=r->next;
    }
    l=(l)?(l):(r);
    for(;i<=GetN(S);i++)
    {
        s=s->Add(l->value);
        l=l->next;
    }
    return S;
}
//---------------------------------------------------------------------------
TList::TList()
{
    first=new TListItem;
}
//---------------------------------------------------------------------------
int GetN(TList L)
{
    return L.first->value;
}
//---------------------------------------------------------------------------
TList operator - (TList L,TList R)
{
    TList S;
    TListItem *l,*r,*s;
    int n,i;
    if( GetN(L)<0 || GetN(R)<0 )
    {
        return S;
    }
    SetN(S,(GetN(L)>GetN(R))?(GetN(L)):(GetN(R)));
    n=(GetN(L)<GetN(R))?(GetN(L)):(GetN(R));
    l=L.first->next;
    r=R.first->next;
    s=S.first;
    for(i=0;i<=n;i++)
    {
        s=s->Add(l->value-r->value);
        l=l->next;
        r=r->next;
    }
    if(l)
    {
        for(;i<=GetN(S);i++)
        {
            s=s->Add(l->value);
            l=l->next;
        }
    }
    else
    {
        for(;i<=GetN(S);i++)
        {
            s=s->Add(-r->value);
            r=r->next;
        }
    }
    return S;
}
//---------------------------------------------------------------------------
bool operator == (TList L,TList R)
{
    TListItem *l,*r;
    if(GetN(L)!=GetN(R))
    {
        return false;
    }
    l=L.first->next;
    r=R.first->next;
    while( l && r && l->value==r->value )
    {
        l=l->next;
        r=r->next;
    }
    if( l || r )
    {
        return false;
    }
    return true;
}
//---------------------------------------------------------------------------
TList operator * (TList L,TList R)
{
    int pd,pl,pr,i;
    TList D;
    TListItem *l,*r,*d;
    if( GetN(L)<0 || GetN(R)<0 )
    {
        return D;
    }
    SetN(D,GetN(L)+GetN(R));
    l=L.first->next;
    d=D.first;
    pd=pl=0;
    while(pl<=GetN(L))
    {
        pr=0;
        r=R.first->next;
        while(pr<=GetN(R))
        {
            while(pd<pl+pr)
            {
                pd++;
                d=d->next;
            }
            if(pd>pl+pr)
            {
                d=D.first;
                pd=0;
                while(pd<pl+pr)
                {
                    pd++;
                    d=d->next;
                }                               
            }
            if(d->next)
            {
                d->next->value=d->next->value+l->value*r->value;
            }
            else
            {
                d->Add(l->value*r->value);
            }
            pr++;
            r=r->next;
        }
        pl++;
        l=l->next;
    }
    return D;
}
//---------------------------------------------------------------------------
int SetN(TList &L,int n)
{
    return L.first->value=(n>=0)?(n):(-1);
}
//---------------------------------------------------------------------------
TList Copy(TList L)
{
    TList C;
    TListItem *p,*c;
    C.first->Init(L.first->value);
    p=L.first->next;
    c=C.first;
    while(p)
    {
        c=c->Add(p->value);
        p=p->next;
    }
    return C;
}
//---------------------------------------------------------------------------
int ValueAtThePoint(TList L,int a)
{
    int st=1,s=0;
    TListItem *p;
    p=L.first->next;
    while(p)
    {
        s+=p->value*st;
        p=p->next;
        st*=a;
    }
    return s;
}
//---------------------------------------------------------------------------
TList ValueAtXPlusA(TList L,int a)
{
    TList R,D,St;
    TListItem *p;
    SetN(D,1);
    D.first->Add(a);
    D.first->next->Add(1);
    SetN(St,0);
    St.first->Add(1);
    SetN(R,0);
    R.first->Add(0);
    p=L.first->next;
    while(p)
    {
        R=R+St*p->value;
        p=p->next;
        St=St*D;
    }
    return R;
}
//---------------------------------------------------------------------------
TList::~TList()
{
    //DeleteList(*this);
}
//---------------------------------------------------------------------------
TList operator * (TList L,int a)
{
    TList R;
    TListItem *p;
    R=Copy(L);
    p=R.first->next;
    while(p)
    {
        p->value=p->value*a;
        p=p->next;
    }
    return R;
}
/*/---------------------------------------------------------------------------
void TList::operator = (TList L)
{
    *this=Copy(L);
}
/*///---------------------------------------------------------------------------
