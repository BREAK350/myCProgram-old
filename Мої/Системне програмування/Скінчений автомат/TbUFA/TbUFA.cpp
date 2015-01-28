//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbUFA.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbUFA::TbUFA():Symbols(),FinalState()
{
    CountQ=0;
    Table=NULL;
}
//---------------------------------------------------------------------------
TbUFA::TbUFA(const TbUFA &UFA):Symbols(UFA.Symbols),FinalState(UFA.FinalState)
{
    CountQ=UFA.CountQ;
    if(CountQ>0)
    {
        int i=0,j;
        Table=new TbSeti* [CountQ];
        while(i<CountQ)
        {
            Table[i]=new TbSeti [Symbols.GetCount()];
            for(j=0;j<Symbols.GetCount();j++)
            {
                Table[i][j]=UFA.Table[i][j];
            }
            i++;
        }
    }
    else
    {
        Table=NULL;
    }
}
//---------------------------------------------------------------------------
TbUFA& TbUFA::operator = (const TbUFA &UFA)
{
    if(this!=&UFA)
    {
        int i=0;
        if(CountQ>0)
        {
            for(i=0;i<CountQ;i++)
            {
                delete[] Table[i];
            }
            delete Table;
        }
        CountQ=UFA.CountQ;
        if(CountQ>0)
        {
            int j;
            Symbols=UFA.Symbols;
            FinalState=UFA.FinalState;
            Table=new TbSeti* [CountQ];
            for(i=0;i<CountQ;i++)
            {
                Table[i]=new TbSeti [Symbols.GetCount()];
                for(j=0;j<Symbols.GetCount();j++)
                {
                    Table[i][j]=UFA.Table[i][j];
                }
            }
            }
        else
        {
            Table=NULL;
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
TbUFA::~TbUFA()
{
    Clear();
}
//---------------------------------------------------------------------------
void TbUFA::Clear()
{
    if(CountQ>0)
    {
        for(int i=0;i<CountQ;i++)
        {
            delete[] Table[i];
        }
        delete Table;
        Table=NULL;
        CountQ=0;
        FinalState.Clear();
        Symbols.Clear();
    }
}
//---------------------------------------------------------------------------
void TbUFA::CreateNew(const char *Expression) // Expression - це лише термінальні символи,
{                                             // без операцій, дожук,
    Clear();                                  // Expression!=0 && Expression[0]!=0
    CountQ=strlen(Expression)+1;
    int i=0,j;
    while(i<CountQ-1)
    {
        Symbols.Add(Expression[i]);
        i++;
    }
    Table=new TbSeti* [CountQ];
    for(i=0;i<CountQ;i++)
    {
        Table[i]=new TbSeti [Symbols.GetCount()];
    }
    for(i=0;i<CountQ-1;i++)
    {
        Table[i][Symbols.GetIndex(Expression[i])].Add(i+1);
    }
    FinalState.Add(CountQ-1);
}
//---------------------------------------------------------------------------
TbUFA TbUFA::Alternative(const TbUFA &UFA)const
{
    int i,j,k;
    TbUFA res;
    TbSeti buf;
    res.Symbols=Symbols+UFA.Symbols;
    res.CountQ=CountQ+UFA.CountQ-1;
    res.Table=new TbSeti* [res.CountQ];
    for(i=0;i<res.CountQ;i++)
    {
        res.Table[i]=new TbSeti [res.Symbols.GetCount()];
    }
    for(i=0;i<res.Symbols.GetCount();i++)
    {
        j=Symbols.GetIndex(res.Symbols.GetElements()[i]);
        if(j!=-1)
        {
            res.Table[0][i].Add(Table[0][j]);
        }
        j=UFA.Symbols.GetIndex(res.Symbols.GetElements()[i]);
        if(j!=-1)
        {
            buf=UFA.Table[0][j];
            buf.Shift(CountQ-1);
            res.Table[0][i].Add(buf);
        }
    }
    for(i=1;i<CountQ;i++)
    {
        for(j=0;j<Symbols.GetCount();j++)
        {
            res.Table[i][res.Symbols.GetIndex(Symbols.GetElements()[j])]=Table[i][j];
        }
    }
    for(;i<res.CountQ;i++)
    {
        for(j=0;j<UFA.Symbols.GetCount();j++)
        {
            buf=UFA.Table[i-CountQ+1][j];
            buf.Shift(CountQ-1);
            res.Table[i][res.Symbols.GetIndex(UFA.Symbols.GetElements()[j])]=buf;
        }
    }
    res.FinalState=FinalState;
    buf=UFA.FinalState;
    buf.Shift(CountQ-1);
    res.FinalState.Add(buf);
    if(FinalState.Search(0) || UFA.FinalState.Search(0))
    {
        res.FinalState.Add(0);
    }
    return res;
}
//---------------------------------------------------------------------------
void TbUFA::Print()const
{
    int i,j;
    cout<<"Symbols: ";
    Symbols.Print();
    cout<<endl;
    for(i=0;i<CountQ;i++)
    {
        for(j=0;j<Symbols.GetCount();j++)
        {
            cout<<'[';
            Table[i][j].Print();
            cout<<']';
        }
        cout<<endl;
    }
    cout<<"Final state: ";
    FinalState.Print();
}
//---------------------------------------------------------------------------
TbUFA TbUFA::operator | (const TbUFA &UFA)const
{
    return Alternative(UFA);
}
//---------------------------------------------------------------------------
TbUFA TbUFA::Concatenation(const TbUFA &UFA)const
{
    TbUFA res;
    int i,j;
    TbSeti buf;
    res.CountQ=CountQ+UFA.CountQ-1;
    res.Symbols=Symbols+UFA.Symbols;
    res.Table=new TbSeti* [res.CountQ];
    for(i=0;i<res.CountQ;i++)
    {
        res.Table[i]=new TbSeti [res.Symbols.GetCount()];
    }
    for(i=0;i<CountQ;i++)
    {
        for(j=0;j<Symbols.GetCount();j++)
        {
            res.Table[i][res.Symbols.GetIndex(Symbols.GetElements()[j])]=Table[i][j];
        }
    }
    for(;i<res.CountQ;i++)
    {
        for(j=0;j<UFA.Symbols.GetCount();j++)
        {
            buf=UFA.Table[i-CountQ+1][j];
            buf.Shift(CountQ-1);
            res.Table[i][res.Symbols.GetIndex(UFA.Symbols.GetElements()[j])]=buf;
        }
    }
    for(i=0;i<FinalState.GetCount();i++)
    {
        for(j=0;j<UFA.Symbols.GetCount();j++)
        {
            buf=UFA.Table[0][j];
            buf.Shift(CountQ-1);
            res.Table[FinalState.GetElements()[i]]
                     [res.Symbols.GetIndex(UFA.Symbols.GetElements()[j])]
                     .Add(buf);
        }
    }
    if(UFA.FinalState.Search(0))
    {
        res.FinalState=FinalState;
    }
    buf=UFA.FinalState;
    buf.Shift(CountQ-1);
    res.FinalState.Add(buf);
    return res;
}
//---------------------------------------------------------------------------
TbUFA TbUFA::Iteration()const
{
    TbUFA res(*this);
    TbSeti buf;
    int i,j;
    for(i=0;i<FinalState.GetCount();i++)
    {
        for(j=0;j<Symbols.GetCount();j++)
        {
            res.Table[FinalState.GetElements()[i]][j].Add(Table[0][j]);
        }
    }
    res.FinalState.Add(0);
    return res;
}
//---------------------------------------------------------------------------
TbUFA::TbUFA(const char *Expression):Symbols(),FinalState()
{
    CountQ=0;
    Table=NULL;
    CreateNew(Expression);    
}
//---------------------------------------------------------------------------
TbSeti TbUFA::GetElement(const int &Q,const int &S)const
{
    TbSeti res;
    if(Q>=0 && Q<GetCountQ())
    {
        int i=Symbols.GetIndex(S);
        if(i!=-1)
        {
            res=Table[Q][i];
        }
    }
    return res;
}
//---------------------------------------------------------------------------
bool TbUFA::isEmpty()const
{
    return CountQ==0;
}
//---------------------------------------------------------------------------
TbSeti TbUFA::GetElement(const TbSeti &Qs,const int &S)const
{
    TbSeti res;
    int is=Symbols.GetIndex(S);
    if(is!=-1)
    {
        for(int i=0;i<Qs.GetCount();i++)
        {
            if(Qs.GetElements()[i]>=0 && Qs.GetElements()[i]<GetCountQ())
            {
                res.Add(Table[Qs.GetElements()[i]][is]);
            }
        }
    }
    return res;
}
//---------------------------------------------------------------------------
void TbUFA::Create(const char *Expression)
{
    *this=Create(Expression,0,strlen(Expression));
}
//---------------------------------------------------------------------------
TbUFA TbUFA::Create(const char *Expression,const int &iBegin,const int &iEnd)const
{
    TbUFA res;
    int i=iBegin,d=0;
    if(iBegin>=iEnd)
    {
        res.CreateNew("");
    }
    else
    {
        while(i<iEnd && (Expression[i]!='|' || d>0))
        {
            if(Expression[i]=='(')
            {
                d++;
            }
            else
            if(Expression[i]==')')
            {
                d--;
            }
            i++;
        }
        if(i<iEnd)
        {
            res=Create(Expression,iBegin,i);
            res=res.Alternative(Create(Expression,i+1,iEnd));
        }
        else
        {
            i=iBegin;
            if(Expression[iBegin]=='(')
            {
                d=1;
                i++;
                while(i<iEnd && d>0)
                {
                    if(Expression[i]=='(')
                    {
                        d++;
                    }
                    else
                    if(Expression[i]==')')
                    {
                        d--;
                    }
                    i++;
                }
                int r=i-1; // закрита дужка
                while(i<iEnd && Expression[i]=='*')
                {
                    i++;
                }
                res=Create(Expression,iBegin+1,r);
                if(r!=i-1)
                {
                    res=res.Iteration();
                }
                if(i<iEnd)
                {
                    res=res.Concatenation(Create(Expression,i,iEnd));
                }
            }
            else
            {
                while(i<iEnd && Expression[i]!='(')
                {
                    i++;
                }
                if(i<iEnd)
                {
                    res=Create(Expression,iBegin,i);
                    res=res.Concatenation(Create(Expression,i,iEnd));
                }
                else
                {
                    i=iBegin;
                    while(i<iEnd && Expression[i]!='*')
                    {
                        i++;
                    }
                    if(i<iEnd)
                    {
                        if(i-iBegin>1)
                        {
                            char *str=new char [i-iBegin];
                            strncpy(str,&Expression[iBegin],i-iBegin-1);
                            str[i-iBegin-1]=0;
                            res.CreateNew(str);
                            str[0]=Expression[i-1];
                            str[1]=0;
                            if(str[0]!='e')
                            {
                                TbUFA buf(str);
                                buf=buf.Iteration();
                                res=res.Concatenation(buf);
                            }
                            res=res.Concatenation(Create(Expression,i+1,iEnd));
                            delete str;
                        }
                        else
                        {
                            char str[2];
                            str[0]=Expression[i-1];
                            str[1]=0;
                            if(str[0]!='e')
                            {
                                res.CreateNew(str);
                                res=res.Iteration();
                            }
                            else
                            {
                                res.CreateNew("");
                            }
                            res=res.Concatenation(Create(Expression,i+1,iEnd));
                        }
                    }
                    else
                    {
                        char *str=new char [iEnd-iBegin+1];
                        strncpy(str,&Expression[iBegin],iEnd-iBegin);
                        str[iEnd-iBegin]=0;
                        if(iEnd-iBegin==1 && str[0]=='e')
                        {
                            res.CreateNew("");
                        }
                        else
                        {
                            res.CreateNew(str);
                        }
                        delete str;
                    }
                }
            }
        }
    }
    return res;
}
//---------------------------------------------------------------------------
int TbUFA::GetCountLink()const
{
    int k=0;
    for(int i=0;i<GetCountQ();i++)
    {
        for(int j=0;j<GetCountS();j++)
        {
            k+=Table[i][j].GetCount();
        }
    }
    return k;
}
//---------------------------------------------------------------------------
TbSeti TbUFA::GetElementIndex(const int &iQ,const int &iS)const
{
    TbSeti res;
    if(iQ>=0 && iQ<GetCountQ() && iS>=0 && iS<GetCountS())
    {
        res=Table[iQ][iS];
    }
    return res;
}
//---------------------------------------------------------------------------
bool TbUFA::isEndQ(const int &iQ)const
{
    return FinalState.Search(iQ);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

