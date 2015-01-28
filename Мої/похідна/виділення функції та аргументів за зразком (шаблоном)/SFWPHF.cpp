//---------------------------------------------------------------------------
#pragma hdrstop
#include "SFWPHF.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
char *Func[] = { "sin(_)", "cos(_)", "tg(_)", "pow(_,_)" }; //....
//---------------------------------------------------------------------------
char* place( char *p, char *search )
{
    int level=0;
    while(*p!=END)
    {
        if(level==0)
        {
            if( *search==A13 && ACTION13(*p) )
            {
                return p;
            }
            if( *search==A12 && ACTION12(*p) )
            {
                return p;
            }
            if( *search==MA && MATH_ACTION(*p) )
            {
                return p;
            }
            if( *search==AA && ANY_ACTION(*p) )
            {
                return p;
            }
            if( *p==*search)
            {
                return p;
            }
        }
        if(*p==levelUp)
        {
            level++;
        }
        if(*p==levelDown)
        {
            level--;
        }
        p++;
    }
    return p;
}
//---------------------------------------------------------------------------
char* CreateChr(char*a,int n)
{
    AnsiString text="";
    int i;
    for(i=0;i<n;i++)
    {
        text=text+a[i];
    }
    return text.c_str();
}
//---------------------------------------------------------------------------
char *SFWP( char *a, char *pattern, char *&func, char **&arg, int &N )
{
    char *p=pattern,
         *t=a;
    char *RETURN;
    int i,
        n=0;
    N=0;
    while(*p!=END)
    {
        if( *p!=ARG )
        {
            if( *t!=*p || *t==END )
            {
                return NULL;
            }
        }
        else
        {
            n++;
            p++;
            if( ANY_ACTION(*p) )
            {
                t=place(t,p);
            }
            else
            {
                return NULL;
            }
        }
        p++;
        t++;
    }
    if( *t==END )
    {
        return NULL;
    }
    RETURN=t;
    N=n;
    func=new char[t-a];
    strncpy(func,a,t-a);
    func[t-a]=END;
    arg=new char*[n];
    p=pattern;
    t=func;
    n=0;
    while(*p!=END)
    {
        if(*p!=ARG)
        {
        }
        else
        {
            p++;
            if( ANY_ACTION(*p) )
            {
                a=t;
                t=place(t,p);
                arg[n]=new char[t-a];
                strncpy(arg[n],a,t-a);
                arg[n][t-a]=END;
                n++;
            }
        }
        p++;
        t++;
    }
    return RETURN;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
