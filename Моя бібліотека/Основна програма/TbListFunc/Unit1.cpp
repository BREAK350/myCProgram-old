//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "GameSpace.h"
//---------------------------------------------------------------------------
struct TbList
{
    struct TbListItem
    {
        int Data;
        TbListItem *Next,*Prev;
        TbListItem(const int &Data)
        {
            this->Data=Data;
            Next=Prev=NULL;
        }
    }*First,*Last;
    TbList()
    {
        First=Last=NULL;
    }
    void AddLast(const int &Data)
    {
        AddLast1(Last,Data);
    }
};
//---------------------------------------------------------------------------
struct TObj
{
    int X,Y,Life;
    TObj() {}
    TObj(const TObj &Obj) { X=Obj.X; Y=Obj.Y; Life=Obj.Life; }
};
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    TObj Obj;
    Obj.X=3;
    Obj.Y=1;
    TbGameSpace <TObj,int> GameSpace;
    GameSpace.Add(Obj);
    Obj.X=5;
    Obj.Y=-1;
    GameSpace.Add(Obj);
    return 0;
}
//---------------------------------------------------------------------------
 