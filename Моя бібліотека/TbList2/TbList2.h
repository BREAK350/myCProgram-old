//---------------------------------------------------------------------------
#ifndef TbList2H
#define TbList2H
#include <stdio.h>
//---------------------------------------------------------------------------
template <class Type>
class TbList2Iterator;
//---------------------------------------------------------------------------
template <class Type>
class TbList2
{
    friend class TbList2Iterator <Type>;
    private:
        struct TbList2Item
        {
            Type Data;
            TbList2Item *Next,*Prev;
            TbList2Item(const Type &_Data)
            {
                this->Data=_Data;
                Next=NULL;
                Prev=NULL;
            }
        }*First,*Last,*Curr;
        int Count;
    //-----------------------------------------------------------------------
    public:
        TbList2()
        {
            First=NULL;
            Last=NULL;
            Curr=NULL;
            Count=0;
        }
        TbList2(const TbList2 &bList2)
        {
            First=Last=NULL;
            Count=0;
            TbList2Item *p=bList2.First;
            while(p)
            {
                Add(p->Data);
                p=p->Next;
            }
            Curr=First;
        }
        TbList2(const Type *Array,const int &Count)
        {
            this->Count=Count;
            First=Last=NULL;
            for(int i=0;i<Count;i++)
            {
                AddEnd(Array[i]);
            }
            Curr=First;
        }
        ~TbList2()
        {
            DeleteAll();
        }
        //-------------------------------------------------------------------
        void AddLast(const Type &Data)
        {
            if(Last)
            {
                Last->Next=new TbList2Item(Data);
                Last->Next->Prev=Last;
                Last=Last->Next;
            }
            else
            {
                First=new TbList2Item(Data);
                Last=First;
            }
            Count++;
        }
        void AddFirst(const Type &Data)
        {
            if(First)
            {
                First->Prev=new TbList2Item(Data);
                First->Prev->Next=First;
                First=First->Prev;
            }
            else
            {
                First=new TbList2Item(Data);
                Last=First;
            }
            Count++;
        }
        void Add(const Type &Data)
        {
            AddLast(Data);
        }
    private:
        bool AddNext(const Type &Data,TbList2Item *Item)
        {
            bool q=false;
            if(Item)
            {
                q=true;
                if(Item->Next)
                {
                    TbList2Item *Next=Item->Next;
                    Item->Next=new TbList2Item(Data);
                    Item->Next->Prev=Item;
                    Item->Next->Next=Next;
                    Next->Prev=Item->Next;
                }
                else
                {
                    AddLast(Data);
                }
            }
            return q;
        }
        //-------------------------------------------------------------------
        bool AddPrev(const Type &Data,TbList2Item *Item)
        {
            bool q=false;
            if(Item)
            {
                q=true;
                if(Item->Prev)
                {
                    TbList2Item *Prev=Item->Prev;
                    Item->Prev=new TbList2Item(Data);
                    Item->Prev->Next=Item;
                    Item->Prev->Prev=Prev;
                    Prev->Next=Item->Prev;
                }
                else
                {
                    AddFirst(Data);
                }
            }
            return q;
        }
        //-------------------------------------------------------------------
        bool DeleteItem(TbList2Item *&Item)
        {
            bool q=Correct(Item);
            if(q)
            {
                if(Item->Prev)
                {
                    Item->Prev->Next=Item->Next;
                }
                if(Item->Next)
                {
                    Item->Next->Prev=Item->Prev;
                }
                delete Item;
                Item=NULL;
                Count--;
            }
            return q;
        }
        bool Correct(const TbList2Item *Item)const
        {
            return Item!=NULL;
        }
    public:
        bool AddCurrNext(const Type &Data)
        {
            return AddNext(Data,Curr);
        }
        bool AddCurrPrev(const Type &Data)
        {
            return AddPrev(Data,Curr);
        }
        bool DeleteLast()
        {
            bool q=false;
            if(Last)
            {
                TbList2Item *Prev=Last->Prev;
                q=DeleteItem(Last);
                Last=Prev;
                if(Last==NULL)
                {
                    First=NULL;
                }
            }
            return q;
        }
        bool DeleteFirst()
        {
            bool q=false;
            if(First)
            {
                TbList2Item *Next=First->Next;
                q=DeleteItem(First);
                First=Next;
                if(First==NULL)
                {
                    Last=NULL;
                }
            }
            return q;
        }
        void DeleteAll()
        {
            while(DeleteLast());
            First=NULL;
        }
        //-------------------------------------------------------------------
        Type* ToArray()
        {
            Type *Array=new Type [Count];
            int i=0;
            TbList2Item *p=First;
            while(p)
            {
                Array[i]=p->Data;
                p=p->Next;
                i++;
            }
            return Array;
        }
        //-------------------------------------------------------------------
        bool CurrSetFirst()
        {
            Curr=First;
            return Correct(Curr);
        }
        bool CurrSetLast()
        {
            Curr=Last;
            return Correct(Curr);
        }
        bool CurrSetNext()
        {
            if(CurrCorrect())
            {
                Curr=Curr->Next;
            }
            return CurrCorrect();
        }
        bool CurrSetPrev()
        {
            if(CurrCorrect())
            {
                Curr=Curr->Prev;
            }
            return CurrCorrect();
        }
        bool DeleteCurr()
        {
            bool q=false;
            if(Curr)
            {
                q=true;
                if(Curr==First)
                {
                    DeleteFirst();
                    Curr=First;
                }
                else
                {
                    if(Curr==Last)
                    {
                        DeleteLast();
                        Curr=Last;
                    }
                    else
                    {
                        TbList2Item *Next=Curr->Next;
                        DeleteItem(Curr);
                        Curr=Next;
                    }
                }

            }
            return q;
        }
        Type& GetCurr()const
        {
            return Curr->Data;
        }
        bool CurrCorrect()const
        {
            return Correct(Curr);
        }
        bool CurrIsFirst()const
        {
            return Correct(Curr) && Curr==First;
        }
        bool CurrIsLast()const
        {
            return Correct(Curr) && Curr==Last;
        }
        bool CurrIsNext()const
        {
            return Correct(Curr) && Curr->Next;
        }
        bool CurrIsPrev()const
        {
            return Correct(Curr) && Curr->Prev;
        }
        //-------------------------------------------------------------------
        int GetCount()const
        {
            return Count;
        }
};
//---------------------------------------------------------------------------
typedef int (*TbCompare)(const void *arg1,const void *arg2);
//---------------------------------------------------------------------------
template <class Type>
class TbSortList2:protected TbList2 <Type>
{
    protected:
        TbCompare Compare;
    public:
        TbSortList2(TbCompare Compare):TbList2 <Type> ()
        {
            this->Compare=Compare;
        }
        void Add(const Type &Data)
        {
            CurrSetFirst();
            if(CurrCorrect())
            {
                while(CurrCorrect() && Compare(&Data,&(GetCurr()))>0)
                {
                    CurrSetNext();
                }
                if(CurrCorrect())
                {
                    AddCurrPrev(Data);
                }
                else
                {
                    AddLast(Data);
                }
            }
            else
            {
                AddFirst(Data);
            }
        }
        //-------------------------------------------------------------------
        bool CurrCorrect()
        {
            return TbList2 < Type >::CurrCorrect();
        }
        bool CurrSetFirst()
        {
            return TbList2 < Type >::CurrSetFirst();
        }
        bool CurrSetLast()
        {
            return TbList2 < Type >::CurrSetLast();
        }
        bool CurrSetNext()
        {
            return TbList2 < Type >::CurrSetNext();
        }
        bool CurrSetPrev()
        {
            return TbList2 < Type >::CurrSetPrev();
        }
        void DeleteAll()
        {
            TbList2 < Type >::DeleteAll();
        }
        bool DeleteCurr()
        {
            return TbList2 < Type >::DeleteCurr();
        }
        bool DeleteFirst()
        {
            return TbList2 < Type >::DeleteFirst();
        }
        bool DeleteLast()
        {
            return TbList2 < Type >::DeleteLast();
        }
        int GetCount()
        {
            return TbList2 < Type >::GetCount();
        }
        Type& GetCurr()
        {
            return TbList2 < Type >::GetCurr();
        }
        Type* ToArray()
        {
            return TbList2 < Type >::ToArray();
        }
        //-------------------------------------------------------------------
        
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
template <class Type>
class TbList2Iterator
{
    private:
        const TbList2 <Type> *List;
        TbList2 <Type>::TbList2Item *Curr;
    public:
        TbList2Iterator(const TbList2 <Type> &List)
        {
            this->List=&List;
            Curr=List.First;
        }
        ~TbList2Iterator()
        {
            List=NULL;
            Curr=NULL;
        }
        bool SetFirst()
        {
            Curr=List->First;
            return List->Correct(Curr);
        }
        bool SetLast()
        {
            Curr=List->Last;
            return List->Correct(Curr);
        }
        bool SetNext()
        {
            if(Correct())
            {
                Curr=Curr->Next;
            }
            return Correct();
        }
        bool SetPrev()
        {
            if(Correct())
            {
                Curr=Curr->Prev;
            }
            return Correct();
        }
        bool Delete()
        {
            bool q=false;
            if(Curr)
            {
                q=true;
                if(Curr==List->First)
                {
                    List->DeleteFirst();
                    Curr=List->First;
                }
                else
                {
                    if(Curr==List->Last)
                    {
                        List->DeleteLast();
                        Curr=List->Last;
                    }
                    else
                    {
                        TbList2 <Type>::TbList2Item *Next=Curr->Next;
                        List->DeleteItem(Curr);
                        Curr=Next;
                    }
                }

            }
            return q;
        }
        Type& Get()const
        {
            return Curr->Data;
        }
        bool Correct()const
        {
            return List->Correct(Curr);
        }
        bool IsFirst()const
        {
            return Correct() && Curr==List->First;
        }
        bool IsLast()const
        {
            return Correct() && Curr==List->Last;
        }
        bool IsNext()const
        {
            return Correct() && Curr->Next;
        }
        bool IsPrev()const
        {
            return Correct() && Curr->Prev;
        }
};
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
