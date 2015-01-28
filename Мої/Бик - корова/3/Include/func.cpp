//---------------------------------------------------------------------------
#pragma hdrstop
#include "func.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbGame::TbGame()
{
    nStep=0;
    nSet=1;
    nDigit=10;
    int i;
    for(i=0;i<10;i++)
    {
        Digit[i]='0'+i;
        Set[0][i]=1;
    }
    Set[0][10]=4;
}
//---------------------------------------------------------------------------
void TbGame::SetSub(const int &i,const int &j,const int &r)
{
    int k=0;
    while(k<10)
    {
        if(Set[i][k]==1)
        {
            
        }
        k++;
    }
}
//---------------------------------------------------------------------------
bool TbGame::SetEquals(const int &i,const int &j)const
{
    bool res=true;
    int k=0;
    while(k<10 && res)
    {
        res=(Set[i][k]==Set[j][k]);
        k++;
    }
    return res;
}
//---------------------------------------------------------------------------
int TbGame::SetGetCommon(const int &i,const int &j)const
{
    int n=0,k=0;
    while(k<10)
    {
        n+=(Set[i][k]==Set[j][k] && Set[i][k]==1);
        k++;
    }
    return n;
}
//---------------------------------------------------------------------------
int TbGame::SetGetCount(const int &i)const
{
    int k=0,n=0;
    while(k<10)
    {
        n+=Set[i][k];
        k++;
    }
    return n;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
bool Add(TbCPlural_char *Set,int &n,const TbCPlural_char &pl) // Set!=NULL
{
    bool add=false;
    if(pl.GetCount()>0)
    {
        bool equals=false;
        if(pl.GetFound()==0)
        {
            Delete(Set,n,pl);
        }
        else
        if(pl.GetFound()==pl.GetCount() && pl.GetCount()>1)
        {
            TbCPlural_char buf=pl.GetFirst(1);
            buf.Found=1;
            Add(Set,n,buf);
            buf=pl-buf;
            buf.Found=pl.Found-1;
            Add(Set,n,buf);
        }
        else
        {
            int i=0;
            TbCPlural_char buf,A,B;
            bool used=false;
            while(i<n)
            {
                equals=(pl==Set[i]);
                if((Set[i]*pl).GetCount()==pl.GetCount())
                {
                    buf=Set[i]-pl;
                    buf.Found=Set[i].Found-pl.Found;
                    Set[i]=pl;
                    bool badd=Add(Set,n,buf);
                    if(badd)
                    {
                        add=true;
                    }
                    used=true;
                }
                else
                if((Set[i]*pl).GetCount()==Set[i].GetCount())
                {
                    buf=pl-Set[i];
                    buf.Found=pl.Found-Set[i].Found;
                    bool badd=Add(Set,n,buf);
                    if(badd)
                    {
                        add=true;
                    }
                    used=true;
                }
                else
                {
                    if(Set[i].GetCount()==pl.GetCount())
                    {
                        if(Set[i].Found-pl.Found+(Set[i]*pl).GetCount()==Set[i].GetCount())
                        {
                            B=Set[i];
                            A=pl;
                            buf=B-A;
                            buf.Found=buf.GetCount();
                            bool badd=Add(Set,n,buf);
                            if(badd)
                            {
                                add=true;
                            }
                            buf=A-B;
                            Delete(Set,n,buf);
                        }
                        else
                        {
                            if(pl.Found-Set[i].Found+(Set[i]*pl).GetCount()==Set[i].GetCount())
                            {
                                B=pl;
                                A=Set[i];
                                buf=B-A;
                                buf.Found=buf.GetCount();
                                bool badd=Add(Set,n,buf);
                                if(badd)
                                {
                                    add=true;
                                }
                                buf=A-B;
                                Delete(Set,n,buf);
                            }
                        }
                    }
                }
                i++;
            }
            if(i>=n && !used && equals==false)
            {
                Set[n]=pl;
                add=true;
                n++;
            }
        }
    }
    return add;
}
//---------------------------------------------------------------------------
void Delete(TbCPlural_char *Set,int &n,const TbCPlural_char &pl) // Set!=NULL
{
    if(pl.GetCount()>0)
    {
        int i=0,f=0;
        while(i<n)
        {
            f=Set[i].Found;
            Set[i]=Set[i]-pl;
            Set[i].Found=f;
            if(Set[i].GetCount()==0)
            {
                int j=i;
                while(j<n-1)
                {
                    Set[j]=Set[j+1];
                    j++;
                }
            }
            i++;
        }
    }
}
//---------------------------------------------------------------------------
void Equals(TbCPlural_char *Set,int &n)
{
    int i=0,j,k;
    while(i<n-1)
    {
        j=i+1;
        while(j<n)
        {
            if(Set[j]==Set[i])
            {
                k=j;
                while(k<n-1)
                {
                    Set[k]=Set[k+1];
                    k++;
                }
                n--;
            }
            j++;
        }
        i++;
    }
}
//---------------------------------------------------------------------------
int GetFound(const TbPlural_char &Set,const TbPlural_char &Search)
{
    TbPlural_char buf=Set*Search;
    return buf.GetCount();
}
//---------------------------------------------------------------------------
TbPlural_char CreateNumber(TbCPlural_char *Set,int &n,TbPlural_char &NotUsed)
{
    TbPlural_char res;
    bool err=true;
    int i;
    while(err || res.GetCount()!=4)
    {
        i=0;
        if(NotUsed.GetCount()>0)
        {
            if(NotUsed.GetCount()>=4)
            {
                res=NotUsed.GetFirst(4);
                NotUsed=NotUsed-res;
                err=false;
            }
            else
            {
                int f=0;
                i=0;
                while(i<n)
                {
                    f+=Set[i].GetFound();
                    i++;
                }
                if(f<4)
                {
                    Set[n]=NotUsed;
                    NotUsed=TbPlural_char();
                    Set[n].Found=4-f;
                    n++;
                }
            }
        }
        if(n>=2 && res.GetCount()!=4)
        {
            int undefined=GetUndefined(Set,n);
            i=0;
            if(undefined>4)
            {
                i=0;
                while(i<n && res.GetCount()<4)
                {
                    if(Set[i].GetCount()>Set[i].Found)
                    {
                        if(res.GetCount()==0)
                        {
                            if(Set[i].GetCount()>3)
                            {
                                res=Set[i].GetFirst(3);
                            }
                            else
                            {
                                res=Set[i];
                            }
                        }
                        else
                        {
                            if(Set[i].GetCount()>4-res.GetCount())
                            {
                                TbPlural_char r=Set[i]-res;
                                if(r.GetCount()>4-res.GetCount())
                                {
                                    res=res+r.GetFirst(4-res.GetCount());
                                }
                                else
                                {
                                    res=res+r;
                                }
                                //res=res+Set[i].GetFirst(4-res.GetCount());
                            }
                            else
                            if(Set[i].GetCount()<4-res.GetCount())
                            {
                                res=res+Set[i];
                            }
                        }
                    }
                    else
                    {
                        /*if(Set[i].GetCount()+res.GetCount()<4)
                        {
                            res=res+Set[i];
                        }*/
                    }
                    i++;
                }
            }
            else
            {
                int k=4-undefined+1;
                i=0;
                while(i<n && k>0)
                {
                    if(Set[i].GetCount()==Set[i].GetFound())
                    {
                        if(Set[i].GetCount()>k)
                        {
                            res=res+Set[i].GetFirst(k);
                            k=0;
                        }
                        else
                        {
                            res=res+Set[i];
                            k-=Set[i].GetCount();
                        }
                    }
                    i++;
                }
                i=0;
                while(i<n && res.GetCount()<4)
                {
                    if(Set[i].GetCount()>Set[i].GetFound())
                    {
                        if(Set[i].GetCount()>4-res.GetCount())
                        {
                            res=res+Set[i].GetFirst(4-res.GetCount());
                        }
                        else
                        if(Set[i].GetCount()<4-res.GetCount())
                        {
                            res=res+Set[i];
                        }
                    }
                    i++;
                }
            }
        }
        if(err)
        {
            i=0;
            while(i<n && res!=Set[i])
            {
                i++;
            }
            if(i<n)
            {
                TbPlural_char r=res.GetFirst(1);
                res=res-r;
                TbCPlural_char buf=Set[0];
                i=0;
                while(i<n-1)
                {
                    Set[i]=Set[i+1];
                    i++;
                }
                Set[i]=buf;
                i=0;
                while(i<n)
                {
                    int j=0;
                    char s=Set[i][0];
                    while(j<Set[i].GetCount()-1)
                    {
                        Set[i][j]=Set[i][j+1];
                        j++;
                    }
                    Set[i][j]=s;
                    i++;
                }
            }
            else
            {
                err=false;
            }
        }
    }
    return res;
}
//---------------------------------------------------------------------------
int GetUndefined(const TbCPlural_char *Set,const int &n)
{
    int i=0;
    TbPlural_char undef;
    while(i<n)
    {
        if(Set[i].GetCount()>Set[i].Found)
        {
            undef=undef+Set[i];
        }
        else
        {
            undef=undef-Set[i];
        }
        i++;
    }
    return undef.GetCount();
}
//---------------------------------------------------------------------------
int GetDefined(const TbCPlural_char *Set,const int &n)
{
    int i=0;
    TbPlural_char def;
    while(i<n)
    {
        if(Set[i].GetCount()==Set[i].Found)
        {
            def=def+Set[i];
        }
        else
        {
            def=def-Set[i];
        }
        i++;
    }
    return def.GetCount();
}
//---------------------------------------------------------------------------
void CheckDefined(TbCPlural_char *Set,int &n)
{
    int i=0;
    while(i<n)
    {
        if(Set[i].GetCount()==Set[i].GetFound() && Set[i].GetCount()>1)
        {
            TbCPlural_char buf=Set[i];
            int j=i;
            while(j<n-1)
            {
                Set[j]=Set[j+1];
                j++;
            }
            n--;
            while(buf.GetCount()>1)
            {
                Add(Set,n,buf.GetFirst(1));
                buf=buf-buf.GetFirst(1);
            }
        }
        i++;
    }
}
//---------------------------------------------------------------------------
/*void CheckSet(TbCPlural_char *Set,int &n)
{
    int i=0,found=0,j=0;
    while(i<n)
    {
        if(Set[i].GetCount()>Set[i].GetFound())
        {
            j=0;
            //while()
        }
        i++;
    }
}*/
//---------------------------------------------------------------------------
void AddAgain(TbCPlural_char *Set,int &n)
{
    int i=0;
    bool add=true,badd;
    while(add)
    {
        i=0;
        add=false;
        while(i<n)
        {
            badd=Add(Set,n,Set[i]);
            if(badd)
            {
                add=true;
            }
            i++;
        }
    }
}
//---------------------------------------------------------------------------
bool GetCowBull(const TbPlural_char &Set,const TbPlural_char &Search,int &Cow,int &Bull)
{
    bool no_err=false;
    if(Set.GetCount()==Search.GetCount())
    {
        int f=GetFound(Set,Search),n=Set.GetCount(),i=0;
        Bull=0;
        while(i<n)
        {
            if(Set[i]==Search[i])
            {
                Bull++;
            }
            i++;
        }
        Cow=f-Bull;
        no_err=true;
    }
    return no_err;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void WritePos(TbPosition &Pos,const TbBCPlural_char &num)
{
    if(num.GetCount()==4)
    {
        int i=0,j=0;
        while(i<4)
        {
            if(num.GetFound()==0)
            {
                j=0;
                while(j<4)
                {
                    Pos.Pos[num[i]-'0'][j]='0';
                    j++;
                }
            }
            else
            {
                if(num.GetBull()==0)
                {
                    Pos.Pos[num[i]-'0'][i]='0';
                }
                else
                {
                    Pos.Pos[num[i]-'0'][i]='2';
                }
            }
            i++;
        }
    }
}
//---------------------------------------------------------------------------
void CreateCorrPos(TbPosition &Pos,TbPlural_char &num)
{
    if(num.GetCount()==4)
    {
        char buf[4][4],newnum[5];
        int i,j,k;
        i=0;
        while(i<4)
        {
            j=0;
            while(j<4)
            {
                buf[i][j]=Pos.Pos[num[i]-'0'][j];
                j++;
            }
            newnum[i]=0;
            i++;
        }
        newnum[i]=0;
        j=0;
        int imax,max;
        while(j<4)
        {
            i=0;
            max=-1;
            imax=0;
            while(i<4)
            {
                if(buf[i][j]!='0' && buf[i][j]!='2')
                {
                    if(max==-1)
                    {
                        max=0;
                        imax=i;
                    }
                    int kmax=0;
                    k=j+1;
                    while(k<4)
                    {
                        kmax+=(buf[i][k]=='0' || buf[i][k]=='2');
                        k++;
                    }
                    if(kmax>max)
                    {
                        max=kmax;
                        imax=i;
                    }
                }
                i++;
            }
            if(max==-1)
            {
                i=0;
                while(i<4 && buf[i][0]=='+')
                {
                    i++;
                }
                if(i<4)
                {
                    imax=i;
                }
            }
            newnum[j]=num[imax];
            buf[imax][0]='+';
            i=1;
            while(i<4)
            {
                buf[imax][i]='0';
                i++;
            }
            j++;
        }
        num=TbPlural_char(newnum);
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

