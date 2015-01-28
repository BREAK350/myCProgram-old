//---------------------------------------------------------------------------
#ifndef TbList3H
#define TbList3H
#include <stdio.h>
#include <vcl.h>
#include <iostream.h>
#include "T_Vector2d.h"
//---------------------------------------------------------------------------
int Pow2(int a)
{
    int p=0;
    while(a>1)
    {
        a/=2;
        p++;
    }
    return p;
}
//---------------------------------------------------------------------------
struct TData
{
    int Value;
};
//template <class TData>
class TbList3
{
    private:
    public:
        struct TbRect
        {
            int Value;
            TPoint Min;
            bool Belong(const TPoint &Point)
            {
                return Point.x>=Min.x && Point.x<Min.x+Value &&
                       Point.y>=Min.y && Point.y<Min.y+Value;
            }
            void Create(const TPoint &Point,const int &Value)
            {
                this->Value=Value;
                if(Point.x<0)
                {
                    Min.x=Value*((Point.x+1)/Value-1);
                }
                else
                {
                    Min.x=Value*(Point.x/Value);
                }
                if(Point.y<0)
                {
                    Min.y=Value*((Point.y+1)/Value-1);
                }
                else
                {
                    Min.y=Value*(Point.y/Value);
                }
            }
        };
        struct TbListItem
        {
            TData *Data;
            TbRect Rect;
            TbListItem *Next,*NextLevel;
            TbListItem()
            {
                Data=NULL;
                Next=NextLevel=NULL;
            }
        }*First;
        TbListItem* SearchNext(TbListItem *Level,const TPoint &Point)const
        {
            TbListItem *p=Level;
            while(p && p->Rect.Belong(Point)==0)
            {
                p=p->Next;
            }
            return p;
        }
        void AddNextLevel(TbListItem *&p,int &Value,const TPoint &Point,TData *Data)
        {
            AddNextLevel(p,Value,0,Point,Data);
        }
        void AddNextLevel(TbListItem *&p,int &Value,const int &MinValue,const TPoint &Point,TData *Data)
        {
            while(Value>MinValue)
            {
                p->NextLevel=new TbListItem;
                p->NextLevel->Rect.Create(Point,Value);
                Value/=2;
                p=p->NextLevel;
            }
            if(MinValue==0)
            {
                p->Data=Data;
            }
        }
        void GetValue(int &Value,const TPoint &Point)
        {
            while(Point.x/Value || Point.y/Value)
            {
                Value*=2;
            }
        }
    public:
        TbList3()
        {
            First=NULL;
        }
        void Add(const TPoint &Point,TData *Data)
        {
            int Value=1;
            GetValue(Value,Point);
            if(First)
            {
                if(Value>First->Rect.Value) // добудовуєм зверху
                {
                    TbListItem *NewFirst=new TbListItem;
                    TbListItem *pFirst=First,*pNewFirst=NewFirst;
                    while(pFirst)
                    {
                        int pValue=Value;
                        pNewFirst->Rect.Create(pFirst->Rect.Min,pValue);
                        pValue/=2;
                        AddNextLevel(pNewFirst,pValue,pFirst->Rect.Value,pFirst->Rect.Min,Data);
                        pNewFirst->NextLevel=pFirst;
                        pFirst=pFirst->Next;
                        if(pFirst)
                        {
                            pNewFirst->Next=new TbListItem;
                            pNewFirst=pNewFirst->Next;
                        }
                    }
                    First=NewFirst;
                }
                TbListItem *p=SearchNext(First,Point);
                if(p==NULL) // якщо нема на першому рівні до доповнюєм
                {
                    p=First;
                    while(p->Next)
                    {
                        p=p->Next;
                    }
                    p->Next=new TbListItem;
                    p->Next->Rect.Create(Point,First->Rect.Value);
                    p=p->Next;
                }   // p вказує на ту гілку, де знаходиться доданий елемент
                TbListItem *t=p->NextLevel;
                while(t)
                {
                    t=SearchNext(t,Point);
                    if(t)
                    {
                        p=t;
                        t=t->NextLevel;
                    }
                }
                if(p->NextLevel)
                {
                    p=p->NextLevel;
                    while(p->Next)
                    {
                        p=p->Next;
                    }
                    p->Next=new TbListItem;
                    p->Next->Rect.Create(Point,p->Rect.Value);
                    p=p->Next;
                }
                Value=p->Rect.Value/2;
                if(Value)
                {
                    AddNextLevel(p,Value,Point,Data);
                }
            }
            else
            {
                First=new TbListItem;
                First->Rect.Create(Point,Value);
                Value/=2;
                TbListItem *p=First;
                AddNextLevel(p,Value,Point,Data);
            }
        }
        TbListItem* Delete(const TPoint &Point)
        {
            TbListItem *r=NULL;
            if(First)
            {
                int n=Pow2(First->Rect.Value),i=0;
                TbListItem **List=new TbListItem* [n+1];
                TbListItem *p=First;
                while(p)
                {
                    p=SearchNext(p,Point);
                    List[i]=p;
                    i++;
                    if(p)
                    {
                        p=p->NextLevel;
                    }
                }
                i--;
                if(List[i])
                {
                    if(List[i]->Rect.Value==1)
                    {
                        while(i>0)
                        {
                            i--;
                        }
                    }
                }
            }
            return r;
        }
        //------------------------------------------------------------------
        TbListItem* SearchNexLevel(const TPoint &Point)const
        {
            TbListItem *p=First;
            while(p && (p=SearchNext(p,Point)) && p->Rect.Value!=1)
            {
                p=p->NextLevel;
            }
            return p;
        }
        void Print(TbListItem *Item)
        {
            if(Item)
            {
                TbListItem *p=Item;
                while(p)
                {
                    cout<<'('<<p->Rect.Min.x<<';'<<p->Rect.Min.y<<';'<<p->Rect.Value<<')'<<endl;
                    if(p->Rect.Value==1)
                    {
                        cout<<"Data="<<p->Data<<endl;
                    }
                    Print(p->NextLevel);
                    p=p->Next;
                    cout<<endl;
                }
            }
        }
        void Print() { Print(First); }
        void Draw(const TbOrientation &Or)
        {
            Draw(Or,First);    
        }
        void Draw(const TbOrientation &Or,TbListItem *Item)
        {
            if(Item)
            {
                TbListItem *p=Item;
                while(p)
                {
                    Or.Canvas->Brush->Color=RGB(0,0,50*Pow2(p->Rect.Value));
                    Or.Rectangle(p->Rect.Min.x,p->Rect.Min.y,p->Rect.Min.x+p->Rect.Value,p->Rect.Min.y+p->Rect.Value);
                    Draw(Or,p->NextLevel);
                    p=p->Next;
                }
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
