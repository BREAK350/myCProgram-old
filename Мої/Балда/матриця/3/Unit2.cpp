//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Balda::T_Balda()
{
    M=N=0;
    Element=NULL;
}
//---------------------------------------------------------------------------
T_Balda::T_Balda(const T_Balda &balda)
{
    N=balda.N;
    M=balda.M;
    if(N>0 && M>0)
    {
        int i,j;
        Element=new T_Element*[N];
        for(i=0;i<N;i++)
        {
            Element[i]=new T_Element[M];
            for(j=0;j<M;j++)
            {
                Element[i][j]=balda.Element[i][j];
            }
        }
    }
    else
    {
        N=M=0;
        Element=NULL;
    }
}
//---------------------------------------------------------------------------
T_Balda::T_Balda(const int &n,const int &m)
{
    N=(n>0)?(n):(0);
    M=(m>0)?(m):(0);
    if(N>0 && M>0)
    {
        int i;
        Element=new T_Element*[N];
        for(i=0;i<N;i++)
        {
            Element[i]=new T_Element[M];
        }
    }
    else
    {
        N=M=0;
        Element=NULL;
    }
}
//---------------------------------------------------------------------------
T_Element T_Balda::operator [] (const T_C &c)
{
    T_Element e(0);
    e.Used=-1;
    if(c.i>=0 && c.i<N && c.j>=0 && c.j<M)
    {
        e=Element[c.i][c.j];
    }
    return e;
}
//---------------------------------------------------------------------------
int max(const int &a,const int &b)
{
    return (a>b)?(a):(b);
}
//---------------------------------------------------------------------------
int max(const int &a,const int &b,const int &c,const int &d)
{
    return max(max(a,b),max(c,d));
}
//---------------------------------------------------------------------------
void T_Balda::SearchWord_4(const char *w,T_Stack &stack,int &q) // з пробілом
{
    T_C c;
    while(q==0 && c.i<N)
    {
        c.j=0;
        while(q==0 && c.j<M)
        {
            SearchWord_4(w,c,stack,q);
            c.j++;
        }
        c.i++;
    }
}
//---------------------------------------------------------------------------
void T_Balda::SearchWord_8(const char *w,T_Stack &stack,int &q) // з пробілом
{
    T_C c;
    while(q==0 && c.i<N)
    {
        c.j=0;
        while(q==0 && c.j<M)
        {
            SearchWord_8(w,c,stack,q);
            c.j++;
        }
        c.i++;
    }
}
//---------------------------------------------------------------------------
void T_Balda::Draw(TCanvas *Canvas,const TPoint &c,const int &s)
{
    int i,j,d=abs(Canvas->Font->Size-s)/2.0;
    for(i=0;i<N;++i)
    {
        for(j=0;j<M;++j)
        {
            Canvas->Rectangle(j*s+c.x,i*s+c.y,(j+1)*s+c.x,(i+1)*s+c.y);
            Canvas->TextOutA(j*s+c.x+d,i*s+c.y+d,Element[i][j].Symbol);
        }
    }
}
//---------------------------------------------------------------------------
void T_Balda::InsertWord(const char *w,const T_C &c)
{
    int i=0;
    while(w[i] && i+c.j<M)
    {
        Element[c.i][i+c.j]=w[i];
        i++;
    }
}
//---------------------------------------------------------------------------
T_Balda::T_Balda(const char *w)
{
    if(w)
    {
        N=M=strlen(w);
        if(N>0)
        {
            int i,j;
            T_C c(N/2.0,0);
            Element=new T_Element*[N];
            for(i=0;i<N;++i)
            {
                Element[i]=new T_Element[M];
            }
            InsertWord(w,c);
        }
        else
        {
            Element=NULL;
        }
    }
    else
    {
        M=N=0;
        Element=NULL;
    }
}
//---------------------------------------------------------------------------
T_Balda::T_Balda(const int &n,const int &m,const char *w)
{
    N=(n>0)?(n):(0);
    M=(m>0)?(m):(0);
    if(N>0 && M>0)
    {
        int l=strlen(w);
        if(N<l)
        {
            N=l;
        }
        if(M<l)
        {
            M=l;
        }
        int i;
        Element=new T_Element*[N];
        for(i=0;i<N;i++)
        {
            Element[i]=new T_Element[M];
        }
        T_C c(N/2.0,(M-l)/2.0);
        InsertWord(w,c);
    }
    else
    {
        N=M=0;
        Element=NULL;
    }
}
//---------------------------------------------------------------------------
void T_Balda::SearchWord_4(const char *w,const T_C &c,T_Stack &stack,int &q)
{
    if(q==0)
    {
        if(w[0])
        {
            if(this->operator [](c).Used==0)
            {
                if(w[0]==isHere(c))
                {
                    DoUsed(c);
                    stack.Write(c.i,c.j);
                    SearchWord_4(w+1,T_C(c.i+1,c.j),stack,q);
                    SearchWord_4(w+1,T_C(c.i,c.j+1),stack,q);
                    SearchWord_4(w+1,T_C(c.i-1,c.j),stack,q);
                    SearchWord_4(w+1,T_C(c.i,c.j-1),stack,q);
                    if(q==0)
                    {
                        stack.Read(TPoint());
                    }
                    DoNotUsed(c);
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
void T_Balda::SearchWord_8(const char *w,const T_C &c,T_Stack &stack,int &q)
{
    if(q==0)
    {
        if(w[0])
        {
            if(this->operator [](c).Used==0)
            {
                if(w[0]==isHere(c))
                {
                    DoUsed(c);
                    stack.Write(c.i,c.j);
                    SearchWord_8(w+1,T_C(c.i+1,c.j),stack,q);
                    SearchWord_8(w+1,T_C(c.i,c.j+1),stack,q);
                    SearchWord_8(w+1,T_C(c.i-1,c.j),stack,q);
                    SearchWord_8(w+1,T_C(c.i,c.j-1),stack,q);

                    SearchWord_8(w+1,T_C(c.i+1,c.j+1),stack,q);
                    SearchWord_8(w+1,T_C(c.i+1,c.j-1),stack,q);
                    SearchWord_8(w+1,T_C(c.i-1,c.j+1),stack,q);
                    SearchWord_8(w+1,T_C(c.i-1,c.j-1),stack,q);
                    if(q==0)
                    {
                        stack.Read(TPoint());
                    }
                    DoNotUsed(c);
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
void T_Balda::DoUsed(const T_C &c)
{
    if(c.i>=0 && c.i<N && c.j>=0 && c.j<M)
    {
        Element[c.i][c.j].Used=1;
    }
}
//---------------------------------------------------------------------------
void T_Balda::DoNotUsed(const T_C &c)
{
    if(c.i>=0 && c.i<N && c.j>=0 && c.j<M)
    {
        Element[c.i][c.j].Used=0;
    }
}
//---------------------------------------------------------------------------
int T_Balda::SearchWord(const char *w,T_Stack &stack,T_C &add,int &index,const int &type)
{
    int q=0;
    char *buf=strdup(w),c;
    int i=0;
    while(q==0)
    {
        if(buf[i])
        {
            c=buf[i];
            buf[i]=' ';
            if(type==FOUR)
            {
                SearchWord_4(buf,stack,q);
            }
            else
            if(type==EIGHT)
            {
                SearchWord_8(buf,stack,q);
            }
            if(q==0)
            {
                buf[i]=c;
            }
            else
            {
                TPoint p=stack.GetElement(i);
                add.i=p.x;
                add.j=p.y;
                index=i;
            }
        }
        else
        {
            q=-1;
        }
        i++;
    }
    delete buf;
    return q;
}
//---------------------------------------------------------------------------
void T_Balda::SetSymbol(const T_C &c,const char &s)
{
    if(c.i>=0 && c.i<N && c.j>=0 && c.j<M)
    {
        Element[c.i][c.j].Symbol=s;
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void T_Balda::SearchWord(T_SWWA &SWWA,const int &type)
{
    SWWA.Stack.Clear();
    SWWA.Q=0;
    if(type==FOUR)
    {
        SearchWord_4(SWWA.Word.c_str(),SWWA.Stack,SWWA.Q);
    }
    else
    if(type==EIGHT)
    {
        SearchWord_8(SWWA.Word.c_str(),SWWA.Stack,SWWA.Q);
    }
}
//---------------------------------------------------------------------------
void T_Balda::SearchWord(T_SWBA &SWBA,const int &type)
{
    SWBA.Stack.Clear();
    SWBA.Q=0;
    SWBA.Index=0;
    SWBA.Q=SearchWord(SWBA.Word.c_str(),SWBA.Stack,SWBA.Add,SWBA.Index,type);
}
//---------------------------------------------------------------------------
void T_Balda::AddWord(T_SWBA &SWBA,const int &type)
{
    SearchWord(SWBA,type);
    if(SWBA.Q==1)
    {
        SetSymbol(SWBA.Add,SWBA.Word[SWBA.Index]);
    }
}
//---------------------------------------------------------------------------
T_SearchWordsWithoutAdding::T_SearchWordsWithoutAdding(const char *w):
    Word(w),Stack(strlen(w)+1)
{
    Q=0;
}
//---------------------------------------------------------------------------
T_SearchWordsByAdding::T_SearchWordsByAdding(const char *w):
    Word(w),Stack(strlen(w)+1),Add(0,0)
{
    Q=0;
    Index=0;
}
//---------------------------------------------------------------------------
void T_Balda::Again(const char *w)
{
    if(w)
    {
        Delete();
        N=M=strlen(w);
        if(N>0)
        {
            int i;
            T_C c(N/2.0,0);
            Element=new T_Element*[N];
            for(i=0;i<N;++i)
            {
                Element[i]=new T_Element[M];
            }
            InsertWord(w,c);
        }
        else
        {
            Element=NULL;
        }
    }
}
//---------------------------------------------------------------------------
void T_Balda::Delete()
{
    int i;
    for(i=0;i<N;++i)
    {
        delete[] Element[i];
    }
    delete[] Element;
    Element=NULL;
    N=M=0;
}
//---------------------------------------------------------------------------
T_Balda::~T_Balda()
{
    Delete();
}
//---------------------------------------------------------------------------
TRect T_Balda::GetRect(const TPoint &c,const int &s)const
{
    return TRect(c.x,c.y,M*s+c.x,N*s+c.y);
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

