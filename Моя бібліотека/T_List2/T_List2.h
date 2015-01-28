//---------------------------------------------------------------------------
#ifndef T_List2H
#define T_List2H
#include <iostream.h>
//---------------------------------------------------------------------------
template <class Type>
class T_List2
{
    private:
        struct T_List2Item
        {
            Type Data;
            T_List2Item *Prev,*Next;
            T_List2Item();
            T_List2Item(const Type &data);
        }*First,*Last;
        Type Data;
        int N;
        bool Sort,Repeat;
        void Copy(const T_List2 &List2);
    protected:
        int WriteSort(const Type &data);
        void GetIndexSort(const Type &data,int &first,int &last)const;
        void GetIndexNotSort(const Type &data,int &first,int &last)const;
        void Delete();
    public:
        T_List2();
        T_List2(const Type &data);
        T_List2(const bool &sort,const bool &repeat);
        T_List2(const Type &data,const bool &sort,const bool &repeat);
        T_List2(const T_List2 &List2);
        ~T_List2();
        int Write(const Type &data);
        void print()const;
        void DoSort();
        Type& operator [] (const int &i)const;
        int GetIndex(const Type &data)const;
        int GetN()const { return N; }
        void GetIndex(const Type &data,int &first,int &last)const;
        T_List2& operator = (const T_List2 &List2);
        bool operator == (const T_List2 &List2)const
        {
            return Data==List2.Data;
        }
        bool operator != (const T_List2 &List2)const
        {
            return Data!=List2.Data;
        }
        bool operator <= (const T_List2 &List2)const
        {
            return Data<=List2.Data;
        }
        bool operator >= (const T_List2 &List2)const
        {
            return Data>=List2.Data;
        }
        bool operator < (const T_List2 &List2)const
        {
            return Data<List2.Data;
        }
        bool operator > (const T_List2 &List2)const
        {
            return Data>List2.Data;
        }
        friend ostream& operator << (ostream &out,const T_List2 &List2)
        {
            out<<List2.Data;
            return out;
        }
        friend istream& operator >> (istream &in,T_List2 &List2)
        {
            in>>List2.Data;
            return in;
        }
};
//---------------------------------------------------------------------------
template <class Type>
T_List2 <Type> ::T_List2Item::T_List2Item(const Type &data)
{
    Data=data;
    Prev=NULL;
    Next=NULL;
}
//---------------------------------------------------------------------------
template <class Type>
T_List2 <Type> ::T_List2Item::T_List2Item()
{
    Prev=NULL;
    Next=NULL;
}
//---------------------------------------------------------------------------
template <class Type>
T_List2 <Type> ::T_List2()
{
    N=0;
    Sort=false;
    Repeat=false;
    First=NULL;
    Last=NULL;
}
//---------------------------------------------------------------------------
template <class Type>
T_List2 <Type> ::T_List2(const Type &data):Data(data)
{
    N=0;
    Sort=false;
    Repeat=false;
    First=NULL;
    Last=NULL;
}
//---------------------------------------------------------------------------
template <class Type>
T_List2 <Type> ::T_List2(const bool &sort,const bool &repeat)
{
    N=0;
    Sort=sort;
    Repeat=repeat;
    First=NULL;
    Last=NULL;
}
//---------------------------------------------------------------------------
template <class Type>
T_List2 <Type> ::T_List2(const Type &data,const bool &sort,const bool &repeat)
    :Data(data)
{
    N=0;
    Sort=sort;
    Repeat=repeat;
    First=NULL;
    Last=NULL;
}
//---------------------------------------------------------------------------
template <class Type>
T_List2 <Type> ::T_List2(const T_List2 &List2)
{
    if(List2.First)
    {
        T_List2Item *p=List2.First;
        N=List2.N;
        Data=List2.Data;
        Sort=List2.Sort;
        Repeat=List2.Repeat;
        First=new T_List2Item(p->Data);
        Last=First;
        p=p->Next;
        while(p)
        {
            Write(p->Data);
            p=p->Next;
        }
    }
    else
    {
        N=0;
        Sort=false;
        Repeat=false;
        First=NULL;
        Last=NULL;
    }
}
//---------------------------------------------------------------------------
template <class Type>
void T_List2 <Type> ::Copy(const T_List2 &List2)
{
    T_List2Item *p=List2.First;
    N=List2.N;
    Data=List2.Data;
    Sort=List2.Sort;
    Repeat=List2.Repeat;
    First=new T_List2Item(p->Data);
    Last=First;
    p=p->Next;
    while(p)
    {
        Write(p->Data);
        p=p->Next;
    }
}
//---------------------------------------------------------------------------
template <class Type>
T_List2 <Type> ::~T_List2()
{
    Delete();
}
//---------------------------------------------------------------------------
template <class Type>
void T_List2 <Type> ::Delete()
{
    if(First)
    {
        while(Last->Prev)
        {
            Last=Last->Prev;
            delete[] Last->Next;
            Last->Next=NULL;
        }
        delete[] First;
        First=NULL;
        N=0;
        Sort=false;
        Repeat=false;
    }
}
//---------------------------------------------------------------------------
template <class Type>
int T_List2 <Type> ::Write(const Type &data)
{
    int i=-1;
    if(First)
    {
        if(Sort)
        {
            i=WriteSort(data);
        }
        else
        {
            if(Repeat || GetIndex(data)==-1)
            {
                Last->Next=new T_List2Item(data);
                Last->Next->Prev=Last;
                Last=Last->Next;
                i=N;
                N++;
            }
        }
    }
    else
    {
        First=new T_List2Item(data);
        Last=First;
        i=N;
        N++;
    }
    return i;
}
//---------------------------------------------------------------------------
template <class Type>
void T_List2 <Type> ::print()const
{
    T_List2Item *p=First;
    while(p)
    {
        cout<<p->Data<<' ';
        p=p->Next;
    }
}
//---------------------------------------------------------------------------
template <class Type>
Type& T_List2 <Type> ::operator [] (const int &i)const
{
    T_List2Item *p=NULL;
    if(i>=0 && i<N)
    {
        int j=0;
        p=First;
        while(j!=i)
        {
            p=p->Next;
            j++;
        }
    }
    return p->Data;
}
//---------------------------------------------------------------------------
template <class Type>
int T_List2 <Type> ::GetIndex(const Type &data)const
{
    int i=0;
    T_List2Item *p=First;
    if(Sort)
    {
        while(p && data>p->Data)
        {
            p=p->Next;
            i++;
        }
    }
    else
    {
        while(p && data!=p->Data)
        {
            p=p->Next;
            i++;
        }
    }
    if(!p || data!=p->Data)
    {
        i=-1;
    }
    return i;
}
//---------------------------------------------------------------------------
template <class Type>
int T_List2 <Type> ::WriteSort(const Type &data)
{
    int i=0;
    T_List2Item *p=First;
    while(p && data>(p->Data))
    {
        p=p->Next;
        i++;
    }
    if(p)
    {
        if(Repeat || data!=p->Data)
        {
            T_List2Item *insert=new T_List2Item(data);
            if(p->Prev)
            {
                insert->Prev=p->Prev;
                insert->Next=p;
                insert->Prev->Next=insert;
                insert->Next->Prev=insert;
            }
            else
            {
                insert->Next=First;
                First->Prev=insert;
                First=insert;
            }
            N++;
        }
        else
        {
            i=-1;
        }
    }
    else
    {
        Last->Next=new T_List2Item(data);
        Last->Next->Prev=Last;
        Last=Last->Next;
        i=N;
        N++;
    }
    return i;
}
//---------------------------------------------------------------------------
template <class Type>
void T_List2 <Type> ::GetIndex(const Type &data,int &first,int &last)const
{
    if(Sort)
    {
        GetIndexSort(data,first,last);
    }
    else
    {
        GetIndexNotSort(data,first,last);
    }
}
//---------------------------------------------------------------------------
template <class Type>
void T_List2 <Type> ::GetIndexSort(const Type &data,int &first,int &last)const
{
    T_List2Item *p=First;
    first=0;
    while(p && data>p->Data)
    {
        p=p->Next;
        first++;
    }
    if(!p || data!=p->Data)
    {
        first=-1;
        last=-1;
    }
    else
    {
        last=first;
        while(p && data==p->Data)
        {
            p=p->Next;
            last++;
        }
    }
}
//---------------------------------------------------------------------------
template <class Type>
void T_List2 <Type> ::GetIndexNotSort(const Type &data,int &first,int &last)const
{
    first=0;
    T_List2Item *p=First;
    while(p && data!=p->Data)
    {
        p=p->Next;
        first++;
    }
    if(!p || data!=p->Data)
    {
        first=-1;
        last=-1;
    }
    else
    {
        if(Repeat)
        {
            last=N;
            p=Last;
            while(p && data!=p->Data)
            {
                p=p->Prev;
                last--;
            }
        }
        else
        {
            last=first+1;
        }
    }
}
//---------------------------------------------------------------------------
template <class Type>
T_List2 < Type >& T_List2 <Type> ::operator = (const T_List2 <Type> &List2)
{
    if(this!=&List2)
    {
        Delete();
        if(List2.First)
        {
            T_List2Item *p=List2.First;
            N=List2.N;
            Data=List2.Data;
            Sort=List2.Sort;
            Repeat=List2.Repeat;
            First=new T_List2Item(p->Data);
            Last=First;
            p=p->Next;
            while(p)
            {
                Write(p->Data);
                p=p->Next;
            }
        }
    }
    return *this;
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
#endif

