//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbDFA.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbDFA::TbDFA()
{
    CountQ=0;
    CountS=0;
    Table=NULL;
}
//---------------------------------------------------------------------------
TbDFA& TbDFA::operator = (const TbDFA &DFA)
{
    if(this!=&DFA)
    {
        CreateNew(DFA.CountQ,DFA.CountS);
        int i,j;
        for(i=0;i<CountQ;i++)
        {
            for(j=0;j<CountS;j++)
            {
                Table[i][j]=DFA.Table[i][j];
            }
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
TbDFA::TbDFA(const TbDFA &DFA)
{
    CountQ=DFA.CountQ;
    CountS=DFA.CountS;
    if(CountQ>0)
    {
        int i,j;
        Table=new int* [CountQ];
        for(i=0;i<CountQ;i++)
        {
            Table[i]=new int [CountS];
            for(j=0;j<CountS;j++)
            {
                Table[i][j]=DFA.Table[i][j];
            }
        }
    }
}
//---------------------------------------------------------------------------
TbDFA::~TbDFA()
{
    Clear();
}
//---------------------------------------------------------------------------
void TbDFA::Clear()
{
    if(CountQ)
    {
        for(int i=0;i<CountQ;i++)
        {
            delete Table[i];
        }
        delete Table;
        CountQ=CountS=0;
        Table=NULL;
    }
}
//---------------------------------------------------------------------------
void TbDFA::CreateFull(const TbUFA &UFA)
{
    Clear();
    if(!UFA.isEmpty())
    {
        int nQ=(1<<UFA.GetCountQ())-1,i,j,k;
        CreateNew(nQ+1,UFA.GetCountS()+1);
        TbSeti *QSet=CreateQSet(UFA.GetCountQ()),buf;
        for(i=0;i<CountS-1;i++)
        {
            Table[nQ][i]=UFA.GetSymbols().GetElements()[i];
        }
        for(i=0;i<CountQ-1;i++)
        {
            for(j=0;j<CountS-1;j++)
            {
                buf.Clear();
                for(k=0;k<QSet[i].GetCount();k++)
                {
                    buf.Add(UFA.GetElement(QSet[i].GetElements()[k],Table[nQ][j]));
                }
                if(!buf.isEmpty())
                {
                    k=0;
                    while(k<nQ && buf!=QSet[k])
                    {
                        k++;
                    }
                    if(k<nQ)
                    {
                        Table[i][j]=k;
                    }
                }
            }
            Table[i][CountS-1]=(QSet[i].GetCommon(UFA.GetFinalState())>0);
        }
        delete[] QSet;
    }
}
//---------------------------------------------------------------------------
void TbDFA::CreateNew(const int &CountQ,const int &CountS)
{
    if(CountQ>0 && CountS>0)
    {
        Clear();
        int i,j;
        this->CountQ=CountQ;
        this->CountS=CountS;
        Table=new int* [CountQ];
        for(i=0;i<CountQ;i++)
        {
            Table[i]=new int [CountS];
            for(j=0;j<CountS-1;j++)
            {
                Table[i][j]=-1;
            }
            Table[i][j]=0;
        }
    }
}
//---------------------------------------------------------------------------
TbSeti* CreateQSet(const int &CountQ)
{
    TbSeti *Set=NULL;
    if(CountQ>0)
    {
        int iSet=0;
        Set=new TbSeti [(1<<CountQ)-1];
        int CountDigit=1,*Q=new int [CountQ],i;
        Q[0]=0;
        while(CountDigit<CountQ)
        {
            for(i=0;i<CountDigit;i++)
            {
                Set[iSet].Add(Q[i]);
            }
            iSet++;
            i=CountDigit-1;
            if(Q[i]<CountQ-1)
            {
                Q[i]++;
            }
            else
            {
                if(i==0)
                {
                    CountDigit++;
                    for(;i<CountDigit;i++)
                    {
                        Q[i]=i;
                    }
                }
                else
                {
                    while(i>0 && Q[i]-Q[i-1]==1)
                    {
                        i--;
                    }
                    if(i>0)
                    {
                        Q[i-1]++;
                        for(;i<CountDigit;i++)
                        {
                            Q[i]=Q[i-1]+1;
                        }
                    }
                    else
                    {
                        CountDigit++;
                        for(;i<CountDigit;i++)
                        {
                            Q[i]=i;
                        }
                    }
                }
            }
        }
        for(i=0;i<CountQ;i++)
        {
            Set[iSet].Add(i);
        }
        iSet++;
        delete Q;
    }
    return Set;
}
//---------------------------------------------------------------------------
void TbDFA::Print()const
{
    if(!isEmpty())
    {
        printf("     ");
        for(int i=0;i<CountS;i++)
        {
            printf(" %3c",Table[CountQ-1][i]);
        }
        cout<<"\n\n";
        for(int i=0;i<CountQ-1;i++)
        {
            printf("%3d  ",i);
            for(int j=0;j<CountS;j++)
            {
                printf(" %3d",Table[i][j]);
            }
            cout<<endl;
        }
    }
}
//---------------------------------------------------------------------------
bool TbDFA::isEmpty()const
{
    return CountQ==0;
}
//---------------------------------------------------------------------------
void TbDFA::RemoveUnreachableStates()
{
    if(!isEmpty())
    {
        stack <int> s;
        int *Matrix=new int [CountQ-1];
        int *Delta=new int [CountQ-1];
        int i,j;
        for(i=0;i<CountQ-1;i++)
        {
            Matrix[i]=0;
        }
        s.push(0);
        while(!s.empty())
        {
            i=s.top();
            s.pop();
            if(Matrix[i]==0)
            {
                for(j=0;j<CountS-1;j++)
                {
                    if(Table[i][j]!=-1)
                    {
                        s.push(Table[i][j]);
                    }
                }
                Matrix[i]=1;
            }
        }
        int NewCountQ=0,k=0;
        Delta[0]=0;
        for(i=1;i<CountQ-1;i++)
        {
            if(Matrix[i]==0)
            {
                Delta[i]=Delta[i-1];
            }
            else
            {
                k=1;
                /*iPrev=iNext;
                iNext=i;
                for(j=0;j<CountS && k==1;j++)
                {
                    k=Table[iPrev][j]==Table[iNext][j];
                } */
                Delta[i]=Delta[i-1]+k;
                //Matrix[i]=!k;
            }
        }
        for(i=0;i<CountQ-1;i++)
        {
            NewCountQ+=Matrix[i];
        }
        int **NewTable=new int* [NewCountQ+1];
        for(i=0;i<NewCountQ+1;i++)
        {
            NewTable[i]=new int [CountS];
        }
        k=0;
        for(i=0;i<NewCountQ;i++)
        {
            while(k<CountQ-1 && Matrix[k]==0)
            {
                k++;
            }
            if(k<CountQ-1)
            {
                for(j=0;j<CountS-1;j++)
                {
                    if(Table[k][j]==-1)
                    {
                        NewTable[i][j]=-1;
                    }
                    else
                    {
                        NewTable[i][j]=Delta[Table[k][j]];
                    }
                }
                NewTable[i][j]=Table[k][j];
            }
            k++;
        }
        for(j=0;j<CountS;j++)
        {
            NewTable[NewCountQ][j]=Table[CountQ-1][j];
        }
        i=CountS;
        Clear();
        Table=NewTable;
        CountQ=NewCountQ+1;
        CountS=i;
        delete Matrix;
        delete Delta;
    }
}
//---------------------------------------------------------------------------
bool TbDFA::isOwn(const char *Expression)const
{
    bool res=false;
    if(Expression && !isEmpty())
    {
        int q=0,i=0,is=0;
        while(Expression[i] && q!=-1 && is!=-1)
        {
            is=GetSymbolIndex(Expression[i]);
            if(is!=-1)
            {
                q=Table[q][is];
                i++;
            }

        }
        if(q!=-1)
        {
            res=Expression[i]==0 && Table[q][CountS-1]==1;
        }
    }
    return res;
}
//---------------------------------------------------------------------------
bool TbDFA::isOwnStepByStep(const char *Expression,const int &Action,
    int &currQ,int &currS)const
{
    static int q=0;
    static int i=0;
    static int is=0;
    bool res=false;
    if(Expression && !isEmpty())
    {
        if(Action==0) // Again
        {
            q=0;
            i=0;
            is=0;
        }
        if(Expression[i] && q!=-1 && is!=-1)
        {
            is=GetSymbolIndex(Expression[i]);
            if(is!=-1)
            {
                q=Table[q][is];
                i++;
                res=true;
            }
        }
        currQ=q;
        currS=i;
    }
    return res;
}
//---------------------------------------------------------------------------
int TbDFA::GetSymbolIndex(const int &Symbol)const
{
    int i=-1;
    if(!isEmpty())
    {
        i=0;
        while(i<CountS-1 && Symbol!=Table[CountQ-1][i])
        {
            i++;
        }
        if(i>=CountS-1)
        {
            i=-1;
        }
    }
    return i;
}
//---------------------------------------------------------------------------
void TbDFA::LoadFromFile(const char *fName)
{
    ifstream ifs(fName);
    int nq,ns;
    ifs>>nq>>ns;
    this->CreateNew(nq,ns);
    for(int i=0;i<CountQ;i++)
    {
        for(int j=0;j<CountS;j++)
        {
            ifs>>Table[i][j];
        }
    }
    ifs.close();
}
//---------------------------------------------------------------------------
TbDFA::TbListItem* TbDFA::SearchItem(TbListItem *Item,const TbSeti &Set)const
{
    TbListItem *res=NULL;
    TbListItem *p=Item;
    while(p && p->Set!=Set)
    {
        p=p->Prev;
    }
    if(p)
    {
        res=p;
    }
    return res;
}
//---------------------------------------------------------------------------
void TbDFA::CreateFrom(const TbUFA &UFA)
{
    if(!UFA.isEmpty())
    {
        int qCurr=1,qLast=2,i;
        TbListItem *Q;
        TbSeti S=UFA.GetSymbols();
        UFA.GetCountS();
        TbListItem *First=new TbListItem(UFA.GetElement(0,S.GetElements()[0]));
        if(First->Set.isEmpty())
        {
            First->Q=-1;
            qLast=1;
            //qCurr=0;
        }
        else
        {
            First->Q=1;
        }
        TbListItem *Last=First;
        for(i=1;i<UFA.GetCountS();i++)
        {
            Q=SearchItem(Last,UFA.GetElement(0,S.GetElements()[i]));
            Last->Next=new TbListItem(UFA.GetElement(0,S.GetElements()[i]));
            Last->Next->Prev=Last;
            Last=Last->Next;
            if(Q)
            {
                Last->Q=Q->Q;
            }
            else
            {
                if(Last->Set.isEmpty())
                {
                    Last->Q=-1;
                }
                else
                {
                    Last->Q=qLast;
                    qLast++;
                }
            }
            if(Last->Set.isEmpty())
            {
                Last->Q=-1;
            }
        }
        while(qCurr<qLast)
        {
            for(i=0;i<UFA.GetCountS();i++)
            {
                Q=SearchItem(Last,qCurr);
                if(Q)
                {
                    Last->Next=new TbListItem(UFA.GetElement(Q->Set,S.GetElements()[i]));
                    Last->Next->Prev=Last;
                    Last=Last->Next;
                    Q=SearchItem(Last->Prev,Last->Set);
                    if(Q)
                    {
                        Last->Q=Q->Q;
                    }
                    else
                    {
                        if(Last->Set.isEmpty())
                        {
                            Last->Q=-1;
                        }
                        else
                        {
                            Last->Q=qLast;
                            qLast++;
                        }
                    }
                }
            }
            qCurr++;
        }
        CreateNew(qLast+1,S.GetCount()+1);
        Q=First;
        qCurr=0;
        TbSeti temp;
        temp.Add(0);
        if(UFA.GetFinalState().GetCommon(temp)>0)
        {
            Table[0][UFA.GetCountS()]=1;
        }
        while(Q)
        {
            for(i=0;i<UFA.GetCountS();i++)
            {
                Table[qCurr][i]=Q->Q;
                if(Q->Set.GetCommon(UFA.GetFinalState())>0)
                {
                    Table[Q->Q][UFA.GetCountS()]=1;
                }
                Q=Q->Next;
            }
            qCurr++;
        }
        for(i=0;i<UFA.GetCountS();i++)
        {
            Table[CountQ-1][i]=UFA.GetSymbols().GetElements()[i];
        }

        Q=First;
        while(Q->Next)
        {
            Q=Q->Next;
            delete Q->Prev;
        }
        delete Q;
    }
}
//---------------------------------------------------------------------------
TbDFA::TbListItem* TbDFA::SearchItem(TbListItem *Item,const int &Q)const
{
    TbListItem *res=NULL;
    TbListItem *p=Item;
    while(p && p->Q!=Q)
    {
        p=p->Prev;
    }
    if(p)
    {
        res=p;
    }
    return res;
}
//---------------------------------------------------------------------------
void TbDFA::DoFullyDefined()
{
    int i=0,j,end=0;
    while(i<CountQ-1 && end==0)
    {
        j=0;
        while(j<CountS-1 && end==0)
        {
            end=Table[i][j]==-1;
            j++;
        }
        i++;
    }
    if(end)
    {
        int **NewTable = new int* [CountQ+1];
        for(i=0;i<CountQ-1;i++)
        {
            NewTable[i]=new int [CountS];
            for(j=0;j<CountS-1;j++)
            {
                if(Table[i][j]==-1)
                {
                    NewTable[i][j]=CountQ-1;
                }
                else
                {
                    NewTable[i][j]=Table[i][j];
                }
            }
            NewTable[i][j]=Table[i][j];
        }
        NewTable[i]=new int [CountS];
        NewTable[i+1]=new int [CountS];
        for(j=0;j<CountS-1;j++)
        {
            NewTable[i][j]=CountQ-1;
            NewTable[i+1][j]=Table[i][j];
        }
        NewTable[i][j]=0;
        NewTable[i+1][j]=0;
        i=CountQ+1;
        j=CountS;
        this->Clear();
        Table=NewTable;
        CountQ=i;
        CountS=j;
    }
}
//---------------------------------------------------------------------------
void TbDFA::MinimizeBase()
{
    int *Group=new int [CountQ-1],*Next=new int [CountQ-1],*First=new int [CountQ-1];
    TbSet <TbG> *Set=new TbSet <TbG>[CountQ-1];
    int i,j,CountGroup=2,Last1=-1,Last0=-1,g;
    for(i=0;i<CountQ-1;i++)
    {
        Group[i]=Table[i][CountS-1];
        Next[i]=-1;
        if(Last0!=-1 && Group[i]==0)
        {
            Next[Last0]=i;
            Last0=i;
        }
        if(Last1!=-1 && Group[i]==1)
        {
            Next[Last1]=i;
            Last1=i;
        }
        if(Last0==-1 && Group[i]==0)
        {
            Last0=i;
            if(Table[0][CountS-1]==0)
            {
                First[0]=i;
            }
            else
            {
                First[1]=i;
            }
        }
        if(Last1==-1 && Group[i]==1)
        {
            Last1=i;
            if(Table[0][CountS-1]==0)
            {
                First[1]=i;
            }
            else
            {
                First[0]=i;
            }
        }
    }
    int CountG;
    do
    {
        if(Last0==-1)
        {
            CountG=CountGroup=1;
        }
        else
        {
            CountG=CountGroup;
        }
        for(i=0;i<CountQ-1;i++)
        {
            Set[i].Clear();
            for(j=0;j<CountS-1;j++)
            {
                Set[i].Add(TbG(Group[Table[i][j]],j));
            }
        }
        g=0;
        while(g<CountGroup)
        {
            j=First[g];
            i=Next[First[g]];
            while(i!=-1 && Set[First[g]]==Set[i])
            {
                j=i;
                i=Next[i];
            }
            if(i!=-1)
            {
                First[CountGroup]=i;
                Last0=j;
                Last1=i;
                Group[i]=CountGroup;
                i=Next[i];
                while(i!=-1)
                {
                    if(Set[i]==Set[First[g]])
                    {
                        Next[Last0]=i;
                        Last0=i;
                    }
                    else
                    {
                        Next[Last1]=i;
                        Last1=i;
                        Group[i]=CountGroup;
                    }
                    i=Next[i];
                }
                Next[Last0]=-1;
                Next[Last1]=-1;
                CountGroup++;
            }
            g++;
        }
    }
    while(CountG!=CountGroup);
    
    for(g=0;g<CountGroup;g++)
    {
        i=First[g];
        while(i!=-1)
        {
            j=Next[i];
            Next[i]=g;
            i=j;
        }
    }
    int **NewTable= new int* [CountGroup+1];
    for(i=0;i<CountGroup;i++)
    {
        NewTable[i]=new int [CountS];
        for(j=0;j<CountS-1;j++)
        {
            NewTable[i][j]=Next[Table[First[i]][j]];
        }
        NewTable[i][j]=Table[First[i]][j];
    }
    NewTable[i]=new int [CountS];
    for(j=0;j<CountS;j++)
    {
        NewTable[i][j]=Table[CountQ-1][j];
    }
    Clear();
    CountQ=CountGroup+1;
    CountS=j;
    Table=NewTable;
    delete Next;
    delete First;
    delete Group;
    delete[] Set;
}
//---------------------------------------------------------------------------
void Add(int &n,int *w,const int &notation)
{
    if(n==0)
    {
        n=1;
        w[0]=0;
    }
    else
    {
        w[0]++;
        int i=0;
        while(i<n-1 && w[i]>=notation)
        {
            w[i]=0;
            w[i+1]++;
            i++;
        }
        if(i==n-1 && w[i]>=notation)
        {
            w[i]=0;
            w[i]=1;
            n++;
        }
    }
}
//---------------------------------------------------------------------------
int TbDFA::DistinguishStates(const int &q1,const int &q2,int *Symbols)
{
    int Length=-1;
    if(!isEmpty())
    {
        int q,f=1,res1,res2;
        Length=0;
        while(f && Length<CountS)
        {
            res1=GetNextState(q1,Length,Symbols);
            res2=GetNextState(q2,Length,Symbols);
            if(res1!=-1 && res2!=-1 &&
                Table[res1][CountS-1]!=Table[res2][CountS-1])
            {
                f=0;
            }
            else
            {
                Add(Length,Symbols,this->CountS-1);
            }
        }
    }
    return Length;
}
//---------------------------------------------------------------------------
int TbDFA::GetNextState(const int &StartQ,const int &CountS,const int *SymbolsIndex)const
{   // справа на ліво
    int q=StartQ,i=CountS-1;
    while(i>=0 && q!=-1)
    {
        q=Table[q][SymbolsIndex[i]];
        i++;
    }
    return q;
}
//---------------------------------------------------------------------------
void TbDFA::Minimize()
{
    if(!isEmpty())
    {
        DoFullyDefined();
        MinimizeBase();
    }
}
//---------------------------------------------------------------------------
int TbDFA::GetSymbol(const int &Index)const
{
    int s=-1;
    if(!isEmpty() && Index>=0 && Index<CountS-1)
    {
        s=Table[CountQ-1][Index];
    }
    return s;
}
//---------------------------------------------------------------------------
int TbDFA::GetElement(const int &iQ,const int &iS)const
{
    int el=-1;
    if(iQ>=0 && iQ<CountQ-1 && iS>=0 && iS<CountS-1)
    {
        el=Table[iQ][iS];
    }
    return el;
}
//---------------------------------------------------------------------------
bool TbDFA::isEndQ(const int &iQ)const
{
    int el=-1;
    if(iQ>=0 && iQ<CountQ-1)
    {
        el=Table[iQ][CountS-1];
    }
    return el;
}
//---------------------------------------------------------------------------
int TbDFA::GetCountFinaleState()const
{
    int k=0;
    for(int i=0;i<CountQ;i++)
    {
        k+=Table[i][CountS-1];
    }
    return k;
}
//---------------------------------------------------------------------------
void TbDFA::DoNotFullyDefined()
{
    int q=0,s;
    int deathQ=-1;
    while(q<CountQ-1 && deathQ==-1)
    {
        s=0;
        while(s<CountS-1 && Table[q][s]==q)
        {
            s++;
        }
        if(s==CountS-1)
        {
            deathQ=q;
        }
        q++;
    }
    if(deathQ!=-1)
    {
        int **NewTable=new int *[CountQ-1];
        for(q=0;q<deathQ;q++)
        {
            NewTable[q]=new int [CountS];
            for(s=0;s<CountS-1;s++)
            {
                if(Table[q][s]==deathQ)
                {
                    NewTable[q][s]=-1;
                }
                else
                {
                    if(Table[q][s]>deathQ)
                    {
                        NewTable[q][s]=Table[q][s]-1;
                    }
                    else
                    {
                        NewTable[q][s]=Table[q][s];
                    }
                }
            }
            NewTable[q][s]=Table[q][s];
        }
        for(;q<CountQ-2;q++)
        {
            NewTable[q]=new int [CountS];
            for(s=0;s<CountS-1;s++)
            {
                if(Table[q+1][s]==deathQ)
                {
                    NewTable[q][s]=-1;
                }
                else
                {
                    if(Table[q+1][s]>deathQ)
                    {
                        NewTable[q][s]=Table[q+1][s]-1;
                    }
                    else
                    {
                        NewTable[q][s]=Table[q+1][s];
                    }
                }
            }
            NewTable[q][s]=Table[q+1][s];
        }
        NewTable[q]=new int [CountS];
        for(s=0;s<CountS;s++)
        {
            NewTable[q][s]=Table[q+1][s];
        }
        q=CountQ-1;
        this->Clear();
        CountQ=q;
        CountS=s;
        Table=NewTable;
    }
}
//---------------------------------------------------------------------------

