//---------------------------------------------------------------------------
#ifndef TlistHH
#define TlistHH
#include <iostream.h>
//---------------------------------------------------------------------------
class mTList;
//---------------------------------------------------------------------------
class mTListItem2
{
    private:
        int a;   // value
        mTListItem2 *next,*prev;
    public:
        mTListItem2();
        void AddItemNext(mTListItem2 *&);
        void AddItemPrev(mTListItem2 *&);
        int GetA(){return a;}
        void SetA(int _a){a=_a;}
        int isNext(){return (next)?(1):(0);}
        int isPrev(){return (prev)?(1):(0);}
        mTListItem2* GetNext(){return next;}
        mTListItem2* GetPrev(){return prev;}
};
//---------------------------------------------------------------------------
class mTList
{
    private:
        mTListItem2 *first,*last;
        mTListItem2* Search(mTListItem2 *);
    public:
        mTList();
        void AddItem(mTListItem2 *&);
        void CreateNewItem(int);
        void ShowConsol();
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#endif
 