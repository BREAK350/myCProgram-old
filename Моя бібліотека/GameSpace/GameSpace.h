//---------------------------------------------------------------------------
#ifndef GameSpaceH
#define GameSpaceH
#include "TbListFunc.h"
//---------------------------------------------------------------------------
template <class TData,class TCoordinate> // TCoordinate = int || Double
class TbGameSpace
{
    private:
        struct TbCoordinateListItem;
        struct TbObjListItem
        {
            TData Data; // Data.X && Data.Y
            TbObjListItem *Next,*Prev;
            TbCoordinateListItem *X,*Y;
            TbObjListItem(const TData &Data)
            {
                this->Data=Data;
                Next=Prev=NULL;
            }
        };
        struct TbObjList
        {
            TbObjListItem *First,*Last;
            TbObjList() { First=Last=NULL; }
            TbObjListItem* Add(const TData &Data)
            {
                if(First)
                {
                    AddLast2(Last,Data);
                }
                else
                {
                    First=new TbObjListItem(Data);
                    Last=First;
                }
                return Last;
            }
        }Obj;
        //-------------------------------------------------------------------
        struct TbCoordinateListItem
        {
            TCoordinate Data;
            TbCoordinateListItem *Next,*Prev;
            TbObjListItem *Obj;
            TbCoordinateListItem(const TCoordinate &Data)
            {
                this->Data=Data;
                Next=Prev=NULL;
            }
        };
        struct TbCoordinateList
        {
            TbCoordinateListItem *First,*Last;
            TbCoordinateList() { First=Last=NULL; }
            TbCoordinateListItem* Add(const TCoordinate &Data) // X || Y - numbers
            {
                TbCoordinateListItem *r=NULL;
                if(First)
                {
                    if(Data<First->Data)
                    {
                        AddFirst2(First,Data);
                        r=First;
                    }
                    else
                    {
                        TbCoordinateListItem *p=First;
                        while(p->Next && Data>p->Data)
                        {
                            p=p->Next;
                        }
                        if(p->Next)
                        {
                            AddNext2(p,Data);
                            r=p->Next;
                        }
                        else
                        {
                            AddLast2(Last,Data);
                            r=Last;
                        }
                    }
                }
                else
                {
                    First=new TbCoordinateListItem(Data);
                    Last=First;
                    r=Last;
                }
                return r;
            }
        }X,Y;
    public:
        void Add(const TData &Data)
        {
            TbObjListItem *obj=Obj.Add(Data);
            TbCoordinateListItem *x=X.Add(Data.X);
            TbCoordinateListItem *y=Y.Add(Data.Y);
            obj->X=x;
            obj->Y=y;
            x->Obj=y->Obj=obj;
        }
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
