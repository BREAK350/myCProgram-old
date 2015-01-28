//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
//---------------------------------------------------------------------------
char *punctuation="+-*/,";
//---------------------------------------------------------------------------
AnsiString func::CreateAS(char*p,int n)
{
    text="";
    while(n>0)
    {
        text=text+*p;
        n--;
        p++;
    }
    return text;
}
//---------------------------------------------------------------------------
AnsiString func::Change(char symb,char*ch)
{
    char *t=text.c_str();
    AnsiString d;
    while(*t!='\0')
    {
        if(*t!=symb)
        {
            d=d+*t;
        }
        else
        {
            d=d+ch;
        }
        t++;
    }
    return text=d;
}
//---------------------------------------------------------------------------
AnsiString func::Change(char*w,char*ch)
{
    char       *t=text.c_str();
    AnsiString d,
               p=w;
    int        n=p.Length();
    func       as;
    while(*t!='\0')
    {
        if(*t==*w)
        {
            if(p==as.CreateAS(t,n))
            {
                d=d+ch;
                t+=n;
            }
        }
        d=d+*t;
        t++;
    }
    return text=d;
}
//---------------------------------------------------------------------------
AnsiString func::ChangeFX(char*f,char*g)
{
    AnsiString d,
               Arg,
               _f;
    char       *t=text.c_str(),
               arg;
    func       as;
    int i,n,l;
    l=0;
    while(f[l]!='\0' && f[l]!='(')
    {
        l++;
    }
    if(f[l]=='(')
    {
        l++;
        _f=as.CreateAS(f,l);
    }
    else
    {
        throw "Error";
    }
    i=l;
    while(f[i]!='\0' && f[i]!=')')
    {
        i++;
    }
    arg=f[l];
    while(*t!='\0')
    {
        if(*t==*f)
        {
            if(_f==as.CreateAS(t,l))
            {
                t+=l;
                n=1;
                i=0;
                while(t[i]!='\0' && n!=0)
                {
                    if(t[i]=='(')
                    {
                        n++;
                    }
                    if(t[i]==')')
                    {
                        n--;
                    }
                    i++;
                }
                Arg=as.CreateAS(t,i-1);
                t+=i;
                i=0;
                while(g[i]!='\0')
                {
                    if(g[i]!=arg)
                    {
                        d=d+g[i];
                    }
                    else
                    {
                        d=d+Arg;
                    }
                    i++;
                }
            }
        }
        d=d+*t;
        t++;
    }
    return text=d;
}
//---------------------------------------------------------------------------
bool func::operator==(char*a)
{
    AnsiString t=a;
    if(text==t)
    {
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------
AnsiString func::operator=(char*a)
{
    size=strlen(a);
    return text=a;
}
//---------------------------------------------------------------------------
AnsiString func::operator+(char*a)
{
    size+=strlen(a);
    return text=text+a;
}
//---------------------------------------------------------------------------
func func::SelectLN(int l,int n)
{
    func D;
    char*a;
    a=text.c_str();
    D.CreateAS(&a[l],n);
    D.size=n;
    return D;
}
//---------------------------------------------------------------------------
char* func::ReturnChar()
{
    return text.c_str();
}
//---------------------------------------------------------------------------
int RightBracket(char*left)// ')'
{
    int n=1,i;
    if(*left!='(')
    {
        throw "Error:-1!=>0";
    }
    i=1;
    while(left[i]!='\0' && n!=0)
    {
        if(left[i]=='(')
        {
            n++;
        }
        if(left[i]==')')
        {
            n--;
        }
        i++;
    }
    return i;
}
//---------------------------------------------------------------------------
func func::NextLevel()
{

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
