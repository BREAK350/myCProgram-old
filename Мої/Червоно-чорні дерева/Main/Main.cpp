//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "RBTree.h"
#include <iostream.h>
//---------------------------------------------------------------------------
struct TPoint
{
    int x,y;
    TPoint(int x,int y)
    {
        this->x=x;
        this->y=y;
    }

    int compareTo(const TPoint &Point)
    {
        int q=0;
        if(x+y>Point.x+Point.y)
        {
            q=1;
        }
        else
        if(x+y<Point.x+Point.y)
        {
            q=-1;
        }
        return q;
    }
};
//---------------------------------------------------------------------------
class TbHero
{
    public:
        int Health,Attack,Protection;
        TPoint Location;
    public:
        TbHero(const int &Health,const int &Attack,const int &Protection,
            const TPoint &Location):Location(Location)
        {
            this->Health=Health;
            this->Attack=Attack;
            this->Protection=Protection;
        }
        void print()
        {
            printf("%d %d %d (%d;%d)\n",Health,Attack,Protection,Location.x,Location.y);    
        }
};
//---------------------------------------------------------------------------
typedef TbHero* pTbHero;
struct TbTreeItemHealth:public TbTreeItemBasis <pTbHero>
{
    TbTreeItemHealth(const pTbHero &Hero)
        :TbTreeItemBasis<pTbHero>(Hero){}
    int compareTo(const pTbHero &Hero)
    {
        int q=0;
        if(Data->Health>Hero->Health)
        {
            q=1;
        }
        else
        if(Data->Health<Hero->Health)
        {
            q=-1;
        }
        return q;
    }
    void print(){ Data->print(); }
};
//---------------------------------------------------------------------------
class TbHeroCompareHealth:public TbRBTree <pTbHero,TbTreeItemHealth>{};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    TbHeroCompareHealth HCH;
    TbHero Hero1(100,30,20,TPoint(10,25));

    HCH.Add(&Hero1);
    HCH.Add(&Hero1);
    HCH.Add(&Hero1);
    HCH.print();
    getch();
    return 0;
}
//---------------------------------------------------------------------------
 