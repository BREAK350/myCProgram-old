//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbDFA.h"
#pragma argsused
#include <conio.h>
//---------------------------------------------------------------------------
void TestNext(const int &CountQ)
{
    if(CountQ>0)
    {
        int CountDigit=1,*Q=new int [CountQ],i,n=0;
        Q[0]=0;
        while(CountDigit<CountQ)
        {
            cout<<n<<")  ";
            for(i=0;i<CountDigit;i++)
            {
                cout<<Q[i];
            }
            cout<<endl;
            n++;

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
        cout<<n<<")  ";
        for(i=0;i<CountQ;i++)
        {
            cout<<i;
        }
        cout<<endl;
    }
}
//---------------------------------------------------------------------------
void TestTbSet()
{
    TbSeti *a=new TbSeti;
    for(int i=0;i<10;i++)
    {
        a->Add(i);
    }
    delete a;
}
//---------------------------------------------------------------------------
void TestTbUFA()
{
    TbUFA a,b,c;
    a.CreateNew("01");
    b.CreateNew("00");
    c=a.Alternative(b);
    c=c.Iteration();
    b.CreateNew("1");
    c=c.Concatenation(b);
    cout<<"c: ";c.Print(); cout<<endl;
    TbDFA DFA;
    DFA.CreateFull(c);
    DFA.Print();
    DFA.RemoveUnreachableStates();
    cout<<"DFA.RemoveUnreachableStates()\n";
    DFA.Print(); cout<<endl;
    char e[100];
    while(1)
    {
        cin>>e;
        cout<<DFA.isOwn(e)<<endl;
    }
}
//---------------------------------------------------------------------------
void TestIra()
{
    TbUFA q1,q2,q3,q4,q5,a,b;
    q1.CreateNew("k");
    q2.CreateNew("n");
    q3.CreateNew("kn");
    q4.CreateNew("n");
    q5.CreateNew("kk");
    a=q1.Alternative(q2);
    b=a.Iteration();
    a=a.Concatenation(b);
    b=q3.Iteration();
    a=a.Concatenation(b);
    b=q4.Alternative(q5);
    a=a.Concatenation(b);
    a.Print();

    TbDFA DFA;
    DFA.CreateFull(a);
    //DFA.Print();
    DFA.RemoveUnreachableStates();
    cout<<"DFA.RemoveUnreachableStates()\n";
    DFA.Print(); cout<<endl;
    char e[100];
    while(1)
    {
        cout<<"e=";
        cin>>e;
        cout<<DFA.isOwn(e)<<endl;
    }
}
//---------------------------------------------------------------------------
void Test1()
{
    TbDFA DFA;
    DFA.LoadFromFile("test.txt");
    char e[100];
    while(1)
    {
        cout<<"e=";
        cin>>e;
        cout<<DFA.isOwn(e)<<endl;
    }
}
//---------------------------------------------------------------------------
void TestMyLaba()
{
    TbUFA l1,l2,l3,l4,l5,l6,l7,a,b;
    l1.CreateNew("10");
    l2.CreateNew("01");
    l3.CreateNew("111");
    l4.CreateNew("0");
    l5.CreateNew("1");
    l6.CreateNew("0");
    l7.CreateNew("1");

    a=l1.Alternative(l2);
    a=a.Alternative(l3);
    a=a.Iteration();
    a=a.Concatenation(l4);

    b=l6.Iteration();
    b=l5.Concatenation(b);
    b=b.Concatenation(l7);
    b=b.Iteration();
    a=a.Concatenation(b);

    //a.Print();cout<<endl;

    TbDFA DFA;
    //DFA.CreateFull(a);
    DFA.CreateFrom(a);
    //DFA.Print();
    //DFA.RemoveUnreachableStates();
    //cout<<"DFA.RemoveUnreachableStates()\n";
    //DFA.Print(); cout<<endl;
    /*char e[100];
    while(1)
    {
        cout<<"e=";
        cin>>e;
        cout<<DFA.isOwn(e)<<endl;
    }*/
}
//---------------------------------------------------------------------------
void TestUFACreate()
{
    char e[100];
    TbUFA UFA;
    TbDFA DFA;
    //while(1)
    {
        //cout<<"e=";
        //cin>>e;
        UFA.Create("(10|01|111)*0(10*1)*");
        UFA.Print();cout<<endl;
        DFA.CreateFrom(UFA);
        DFA.Print();cout<<endl;
        DFA.DoFullyDefined();
        DFA.Print();cout<<endl;
        DFA.Minimize();
        DFA.Minimize();
        DFA.Print();cout<<endl;
        /*while(1)
        {
            int q1,q2,w[100],l;
            cout<<"q1=";cin>>q1;
            cout<<"q2=";cin>>q2;
            l=DFA.DistinguishStates(q1,q2,w);
            if(l==0)
            {
                cout<<"e\n";
            }
            else
            {
                for(int i=l-1;i>=0;i--)
                {
                    cout<<(char)w[i];
                }
                cout<<endl;
            }
        }*/
    }
    //DFA.LoadFromFile("1.txt");
    //DFA.DoFullyDefined();
    //DFA.Print();cout<<endl;
    while(1)
    {
        cout<<"e=";
        cin>>e;
        cout<<DFA.isOwn(e)<<endl;
    }
}
//---------------------------------------------------------------------------
void Test2()
{
    char e[100];
    TbUFA UFA;
    TbDFA DFA;
    //cout<<"e=";cin>>e;
    //UFA.Create(e);
    //UFA.Create("(x|z)(xy)*x|(yx)*");
    UFA.Create("(+|-|e)(0|1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)*(e|.(0|1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)*)");
    //UFA.Create("(+|-)(0|1|2)(0|1|2)*");
    //UFA.Create("-(0|1)*");
    UFA.Print();cout<<endl;
    DFA.CreateFrom(UFA);
    
    DFA.Print();cout<<endl;
    DFA.DoFullyDefined();
    DFA.Minimize();
    DFA.Print();cout<<endl;
    cout<<DFA.isOwn("")<<endl;
    while(1)
    {
        cout<<"e=";cin>>e;
        cout<<DFA.isOwn(e)<<endl;
    }
}
//---------------------------------------------------------------------------
void f()
{
    ifstream ifs("Expression.txt");
    char Expression[1024];
    ifs>>Expression;          
    ifs.close();
    TbUFA UFA;
    UFA.Create(Expression);
    cout<<"Expression: "<<Expression<<endl;
    cout<<"UFA:\n";
    UFA.Print();cout<<endl;
    TbDFA DFA;
    DFA.CreateFrom(UFA);
    cout<<"DFA:\n";
    DFA.Print();cout<<endl;
    DFA.DoFullyDefined();
    DFA.Minimize();
    cout<<"Minimize full DFA:\n";
    DFA.Print();cout<<"\n\nchainlet=e\n";
    if(DFA.isOwn(Expression))
    {
        cout<<"    belongs"<<endl;
    }
    else
    {
        cout<<"    does not belong"<<endl;
    }
    while(1)
    {
        cout<<"chainlet=";cin>>Expression;
        if(DFA.isOwn(Expression))
        {
            cout<<"    belongs"<<endl;
        }
        else
        {
            cout<<"    does not belong"<<endl;
        }
    }
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    f();
    cout<<"good.";
    getch();
    return 0;
}
//---------------------------------------------------------------------------

