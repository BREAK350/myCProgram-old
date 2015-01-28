//---------------------------------------------------------------------------
#pragma hdrstop
#include "stack.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
int T_Stack::Write(const int &x,const int &y)
{
    int q=0;
    if(Top<Size && Search(TPoint(x,y))==0)
    {
        Stack[Top]=TPoint(x,y);
        Top++;
        q=1;
    }
    return q;
}
//---------------------------------------------------------------------------
int T_Stack::Search(const TPoint &p)const
{
    int i=0,q=0;
    while(i<Top && q==0)
    {
        if(p.x==Stack[i].x && p.y==Stack[i].y)
        {
            q=1;
        }
        else
        {
            i++;
        }
    }
    return q;
}
//---------------------------------------------------------------------------
int T_Stack::Read(TPoint &p)
{
    int q=0;
    if(Top>0)
    {
        Top--;
        p=Stack[Top];
        q=1;
    }
    return q;
}
//---------------------------------------------------------------------------
T_Stack& T_Stack::operator = (const T_Stack &s)
{
    if(this!=&s)
    {
        delete[] Stack;
        Size=s.Size;
        Top=s.Top;
        if(Size>0)
        {
            int i;
            Stack=new TPoint[Size];
            for(i=0;i<Top;i++)
            {
                Stack[i]=s.Stack[i];
            }
        }
        else
        {
            Stack=NULL;
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
T_Stack::T_Stack()
{
    Size=Top=0;
    Stack=NULL;
}
//---------------------------------------------------------------------------
T_Stack::T_Stack(const int &s)
{
    Size=(s>0)?(s):(0);
    if(Size>0)
    {
        Stack=new TPoint[Size];
    }
    else
    {
        Stack=NULL;
    }
    Top=0;
}
//---------------------------------------------------------------------------
T_Stack::T_Stack(const T_Stack &s)
{
    Size=s.Size;
    Top=s.Top;
    if(Size>0)
    {
        int i;
        Stack=new TPoint[Size];
        for(i=0;i<Top;i++)
        {
            Stack[i]=s.Stack[i];
        }
    }
    else
    {
        Stack=NULL;
    }
}
//---------------------------------------------------------------------------
T_Stack::~T_Stack()
{
    delete[] Stack;
    Stack=NULL;
    Size=Top=0;
}
//---------------------------------------------------------------------------
TPoint T_Stack::GetElement(const int &i)
{
    TPoint p(0,0);
    if(i>=0 && i<Size)
    {
        p=Stack[i];
    }
    return p;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

