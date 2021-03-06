//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit3.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
char* SearchClosedBrackets(char *s)
{
    char *p=s;
    int b=1;
    if(*p!='(')
    {
        return p;
    }
    p++;
    while(*p && b)
    {
        if(*p=='(')
        {
            b++;
        }
        if(*p==')')
        {
            b--;
        }
        p++;
    }
    return p;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int SearchLevel1(char *s,int l,int r)  
{
    int i=l;
    while(i<r)
    {
        if(s[i]=='(')
        {
            i=i+(SearchClosedBrackets(&s[i])-&s[i]);
            if(i>=r)
            {
                return -1;
            }
        }
        if(s[i]=='+' || s[i]=='-')
        {
            return i;
        }
        i++;
    }
    return -1;
}
//---------------------------------------------------------------------------
int SearchLevel2(char *s,int l,int r)
{
    int i=l;
    while(i<r)
    {
        if(s[i]=='(')
        {
            i=i+(SearchClosedBrackets(&s[i])-&s[i]);
            if(i>=r)
            {
                return -1;
            }
        }
        if(s[i]=='*' || s[i]=='/')
        {
            return i;
        }
        i++;
    }
    return -1;
}
//---------------------------------------------------------------------------
int SearchLevel3(char *s,int l,int r)
{
    int i=l;
    while(i<r)
    {
        if(s[i]=='(')
        {
            i=i+(SearchClosedBrackets(&s[i])-&s[i]);
            if(i>=r)
            {
                return -1;
            }
        }
        if(s[i]=='^' )
        {
            return i;
        }
        i++;
    }
    return -1;
}
//---------------------------------------------------------------------------
int isNumber(char *s,int l,int r,float &f)
{
    int i,p=1;
    char *a;
    if(l==r && s[l]=='-')
    {
        f=0;
        return 1;
    }
    while(l<r && ( s[l]=='(' || s[l]==' ' ))
    {
        l++;
    }
    if(s[l]=='-')
    {
        p=-1;
        l++;
    }
    while(r>l && ( s[r-1]==')' || s[r-1]==' ' ))
    {
        r--;
    }
    i=l;
    while( i<r && ( ( s[i]>='0' && s[i]<='9' ) || s[i]=='.' ) )
    {
        i++;
    }
    if( i<r || l>=r )
    {
        return 0;
    }
    a=new char[r-l];
    for(i=0;i<r-l;i++)
    {
        a[i]=s[i+l];
        if(a[i]=='.')
        {
            a[i]=',';
        }
    }
    a[i]=0;
    f=p*StrToFloat(a);
    delete a;
    return 1;
}
//---------------------------------------------------------------------------
int SearchLevel(char *s,int l,int r)
{
    int d;
    while(s[l]=='(')
    {
        if(SearchClosedBrackets(&s[l])-&s[l]==r-l)
        {
            l++;
            r--;
        }
        else
        {
            break;
        }
    }
    d=SearchLevel1(s,l,r);
    if(d==-1)
    {
        d=SearchLevel2(s,l,r);
    }
    if(d==-1)
    {
        d=SearchLevel3(s,l,r);
    }
    
    return d;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int SearchOpendBrackets(char *s,int l,int r) // r-> ')'
{
    int p=r;
    int b=1;
    if(s[p]!=')')
    {
        return r;
    }
    p--;
    while(p>=l && b)
    {
        if(s[p]=='(')
        {
            b--;
        }
        if(s[p]==')')
        {
            b++;
        }
        p--;
    }
    return p+1;
}
//---------------------------------------------------------------------------
int _SearchLevel(char *s,int l,int r,int level)
{
    int i;
    while(SearchOpendBrackets(s,l,r-1)==l)
    {
        r--;
        l++;
    }
    i=r-1;
    while(i>=l)
    {
        if(s[i]==')')
        {
            i=SearchOpendBrackets(s,l,i);
            if(i<l)
            {
                return -1;
            }
        }
        switch(level)
        {
            case 1:
                if(s[i]=='+' || s[i]=='-')
                {
                    return i;
                }   break;
            case 2:
                if(s[i]=='*' || s[i]=='/')
                {
                    return i;
                }   break;
            case 3:
                if(s[i]=='^' )
                {
                    return i;
                }   break;
        }
        i--;
    }
    return -1;
}
//---------------------------------------------------------------------------
int _SearchLevel_(char *s,int l,int r)
{
    int i,d;
    i=1;
    d=-1;
    while(i<=3 && d==-1)
    {
        d=_SearchLevel(s,l,r,i);
        i++;
    }
    return d;
}
//---------------------------------------------------------------------------
_func_ isFunction(char *s,int &l,int &r)
{
    int i;
    while(r>=l && s[r-1]==' ')
    {
        r--;
    }
    while(l<=r && s[l]==' ')
    {
        l++;
    }
    if(s[r-1]!=')')
    {
        return NULL;
    }
    i=SearchOpendBrackets(s,l,r-1);
    if(l>=i)
    {
        return NULL;
    }
    if(s[l]=='s'&&s[l+1]=='i'&&s[l+2]=='n'&&l+3==i)
    {
        l+=3;
        return _sin_;
    }
    if(s[l]=='c'&&s[l+1]=='o'&&s[l+2]=='s'&&l+3==i)
    {
        l+=3;
        return _cos_;
    }
    return NULL;
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
