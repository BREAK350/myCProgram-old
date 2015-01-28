//---------------------------------------------------------------------------
#pragma hdrstop
#include "field.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Field::T_Field_Item::T_Field_Item(const char &s,const TPoint &l):Location(l)
{
    Symbol=s;
    Quarter[0]=Quarter[1]=Quarter[2]=Quarter[3]=NULL;
}
//---------------------------------------------------------------------------
T_Field::T_Field()
{
    Root=NULL;
}
//---------------------------------------------------------------------------
int T_Field::Add(const char &s,const TPoint &l)
{
    int q=0,i;
    if(Root)
    {
        T_Field_Item *p=Root;
        while(q==0)
        {
            if(l!=p->Location)
            {
                i=GetIndexQuarter(l,p->Location);
                if(p->Quarter[i])
                {
                    p=p->Quarter[i];
                }
                else
                {
                    p->Quarter[i]=new T_Field_Item(s,l);
                    q=1;
                }
            }
            else
            {
                q=-1;
            }
        }
    }
    else
    {
        Root=new T_Field_Item(s,l);
        q=1;
    }
    return q;
}
//---------------------------------------------------------------------------
int GetIndexQuarter(const TPoint &first,const TPoint &second)
{
    int q=0;
    if(first.x>second.x)
    {
        if(first.y<second.y)
        {
            q=3;
        }
    }
    else
    {
        if(first.y>second.y)
        {
            q=1;
        }
        else
        {
            q=2;
        }
    }
    return q;
}
//---------------------------------------------------------------------------
int operator == (const TPoint &a,const TPoint &b)
{
    return a.x==b.x && a.y==b.y;
}
//---------------------------------------------------------------------------
int operator != (const TPoint &a,const TPoint &b)
{
    return !(a==b);
}
//---------------------------------------------------------------------------
char T_Field::Search(const TPoint &l)const
{
    char s;
    T_Field_Item *p=Root;
    int i,q=0;
    while(q==0)
    {
        if(p)
        {
            if(l==p->Location)
            {
                s=p->Symbol;
                q=1;
            }
            else
            {
                i=GetIndexQuarter(l,p->Location);
                if(p->Quarter[i])
                {
                    p=p->Quarter[i];
                }
                else
                {
                    s=0;
                    q=1;
                }
            }
        }
        else
        {
            s=0;
            q=1;
        }
    }
    return s;
}
//---------------------------------------------------------------------------
void T_Field::Delete(T_Field_Item *&fi)
{
    if(fi)
    {
        Delete(fi->Quarter[0]);
        Delete(fi->Quarter[1]);
        Delete(fi->Quarter[2]);
        Delete(fi->Quarter[3]);
        delete fi;
    }
}
//---------------------------------------------------------------------------
T_Field::T_Field(const char *word)
{
    if(word)
    {
        int i=1;
        Root=new T_Field_Item(word[0],TPoint(0,0));
        while(word[i])
        {
            Add(word[i],i,0);
            i++;
        }
    }
    else
    {
        Root=NULL;
    }
}
//---------------------------------------------------------------------------
void T_Field::Draw(T_Field_Item *fi,TCanvas *Canvas,const TPoint &c,const int &s)const
{
    if(fi)
    {
        Canvas->TextOutA(fi->Location.x*s+c.x,fi->Location.y*s+c.y,fi->Symbol);
        Draw(fi->Quarter[0],Canvas,c,s);
        Draw(fi->Quarter[1],Canvas,c,s);
        Draw(fi->Quarter[2],Canvas,c,s);
        Draw(fi->Quarter[3],Canvas,c,s);
    }
}
//---------------------------------------------------------------------------
void T_Field::Draw(TCanvas *Canvas,const TPoint &c,const int &s)const
{
    Draw(Root,Canvas,c,s);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 