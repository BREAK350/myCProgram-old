//---------------------------------------------------------------------------
#ifndef TbSetH
#define TbSetH
#include <iostream.h>
//typedef int TbElement;
//---------------------------------------------------------------------------
template <class TbElement>
class TbSet // множина значень (станів), відсортована множина
{
    private:
        TbElement *Elements;
        int Count;
    public:
        TbSet()
        {
            Count=0;
            Elements=NULL;
        }
        TbSet(const TbSet &Set)
        {
            Count=Set.Count;
            if(Count>0)
            {
                Elements=new TbElement [Count];
                int i=0;
                while(i<Count)
                {
                    Elements[i]=Set.Elements[i];
                    i++;
                }
            }
            else
            {
                Elements=NULL;
            }
        }
        ~TbSet()
        {
            Clear();
        }
        TbSet& operator = (const TbSet &Set)
        {
            if(this!=&Set)
            {
                if(Count>0)
                {
                    delete Elements;
                }
                Count=Set.Count;
                if(Count>0)
                {
                    Elements=new TbElement [Count];
                    int i=0;
                    while(i<Count)
                    {
                        Elements[i]=Set.Elements[i];
                        i++;
                    }
                }
                else
                {
                    Elements=NULL;
                }
            }
            return *this;
        }
        TbSet operator + (const TbElement &Element)const
        {
            TbSet res;
            if(!Search(Element))
            {
                if(Count>0)
                {
                    res.Count=Count+1;
                    res.Elements=new TbElement [res.Count];
                    int i=0;
                    while(i<res.Count && Element>Elements[i])
                    {
                        res.Elements[i]=Elements[i];
                        i++;
                    }
                    res.Elements[i]=Element;
                    i++;
                    while(i<res.Count)
                    {
                        res.Elements[i]=Elements[i-1];
                        i++;
                    }
                }
                else
                {
                    res.Count=1;
                    res.Elements=new TbElement [Count];
                    res.Elements[0]=Element;
                }
            }
            else
            {
                res=*this;
            }
            return res;
        }
        TbSet operator + (const TbSet &Set)const
        {
            TbSet res=*this;
            res.Add(Set);
            return res;
        }
        bool operator == (const TbSet &Set)const
        {
            bool res=Count==Set.Count;
            if(res)
            {
                int i=0;
                while(i<Count && res)
                {
                    res=Elements[i]==Set.Elements[i];
                    i++;
                }
            }
            return res;
        }
        bool operator != (const TbSet &Set)const
        {
            return !(*this==Set);
        }
        void Add(const TbElement &Element)
        {
            if(!Search(Element))
            {
                if(Count>0)
                {
                    TbSet buf=*this;
                    delete[] Elements;
                    Count++;
                    Elements=new TbElement [Count];
                    int i=0;
                    while(i<buf.Count && Element>buf.Elements[i])
                    {
                        Elements[i]=buf.Elements[i];
                        i++;
                    }
                    Elements[i]=Element;
                    i++;
                    while(i<Count)
                    {
                        Elements[i]=buf.Elements[i-1];
                        i++;
                    }
                }
                else
                {
                    Count=1;
                    Elements=new TbElement [Count];
                    Elements[0]=Element;
                }
            }
        }
        void Add(const TbSet &Set)
        {
            int i=0;
            while(i<Set.Count)
            {
                Add(Set.Elements[i]);
                i++;
            }
        }
        const TbElement* GetElements()const
        {
            return Elements;
        }
        int GetCount()const
        {
            return Count;
        }
        int GetIndex(const TbElement &Element)const
        {
            int i=0;
            while(i<Count && Elements[i]!=Element)
            {
                i++;
            }
            return (i<Count)?(i):(-1);
        }
        bool Search(const TbElement &Element)const
        {
            int i=0;
            while(i<Count && Elements[i]!=Element)
            {
                i++;
            }
            return i<Count;
        }
        bool isEmpty()const
        {
            return Count==0;
        }
        int GetCommon(const TbSet &Set)const
        {
            int i=0,k=0;
            while(i<Count)
            {
                k+=Set.Search(Elements[i]);
                i++;
            }
            return k;
        }
        void Clear()
        {
            if(Count>0)
            {
                delete[] Elements;
                Elements=NULL;
                Count=0;
            }
        }
        void Shift(const int &ShiftTo)
        {
            for(int i=0;i<Count;i++)
            {
                Elements[i]=Elements[i]+ShiftTo;
            }
        }
        void Print()const
        {
            int i=0;
            while(i<Count-1)
            {
                cout<<Elements[i]<<';';
                i++;
            }
            if(i==Count-1)
            {
                cout<<Elements[i];
            }
        }
};
//---------------------------------------------------------------------------
typedef TbSet <int> TbSeti;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
