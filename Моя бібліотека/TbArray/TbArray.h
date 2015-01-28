//---------------------------------------------------------------------------
#ifndef TbArrayH
#define TbArrayH
#include <stdio.h>
//---------------------------------------------------------------------------
template <class TData>
class TbArray
{
    private:
        int Count;
        TData *Data;
    public:
        TbArray()
        {
            Count=0;
            Data=NULL;
        }
        TbArray(const int &Count)
        {
            this->Count=(Count>0)?(Count):(0);
            if(this->Count>0)
            {
                Data=new TData [this->Count];
            }
            else
            {
                Data=NULL;
            }
        }
        TbArray(const int &Count,const TData *Data)
        {
            this->Count=(Count>0)?(Count):(0);
            if(this->Count>0)
            {
                Data=new TData [this->Count];
                for(int i=0;i<this->Count;i++)
                {
                    this->Data[i]=Data[i];
                }
            }
            else
            {
                Data=NULL;
            }
        }
        TbArray(const TbArray &Array)
        {
            Count=Array.Count;
            if(Count>0)
            {
                Data=new TData [Count];
                for(int i=0;i<Count;i++)
                {
                    Data[i]=Array.Data[i];
                }
            }
            else
            {
                Data=NULL;
            }
        }
        ~TbArray()
        {
            if(Count>0)
            {
                delete Data;
                Count=0;
                Data=NULL;
            }
        }
        TbArray& operator = (const TbArray &Array)
        {
            if(this!=&Array)
            {
                if(Count!=Array.Count)
                {
                    if(Count>0)
                    {
                        delete Data;
                    }
                    Count=Array.Count;
                    if(Count>0)
                    {
                        Data=new TData [Count];
                    }
                    else
                    {
                        Data=NULL;
                    }
                }
                for(int i=0;i<Count;i++)
                {
                    Data[i]=Array.Data[i];
                }
            }
            return *this;
        }
        TData& operator [] (const int &i)
        {
            return Data[i];
        }
        operator const TData* ()const
        {
            return Data;
        }

        int GetCount()const
        {
            return Count;
        }
        void SetCount(const int &Count)
        {
            if(Count!=this->Count)
            {
                if(this->Count>0)
                {
                    delete Data;
                }
                this->Count=Count;
                if(this->Count>0)
                {
                    Data=new TData [this->Count];
                }
                else
                {
                    Data=NULL;
                }
            }
        }
        void Delete()
        {
            if(Count>0)
            {
                delete Data;
                Data=NULL;
                Count=0;
            }
        }
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
