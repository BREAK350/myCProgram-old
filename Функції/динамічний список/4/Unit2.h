//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <iostream.h>
//---------------------------------------------------------------------------
class TList;
//---------------------------------------------------------------------------
class TListItem
{
    private:
        int value;
        TListItem *next;
        TListItem* Init(int);
        TListItem* Add(int);
        friend void Delete(TListItem *&);
    public:
        TListItem();
        friend int GetN(TList);
        friend int SetN(TList &,int);
        friend TList Input(TList &);
        friend void DeleteList(TList &);
        friend void PrintList(TList);
        friend TList operator + (TList,TList);
        friend TList operator - (TList,TList);
        friend TList operator * (TList,TList);
        friend bool operator == (TList,TList);
        friend TList Copy(TList);
        friend int ValueAtThePoint(TList,int);
        friend TList ValueAtXPlusA(TList,int);
        friend TList operator * (TList,int);
};
//---------------------------------------------------------------------------
class TList
{
    private:
        TListItem *first;
    public:
        TList();
        ~TList();
        friend int GetN(TList);
        friend int SetN(TList &,int);
        friend TList Input(TList &);
        friend void DeleteList(TList &);
        friend void PrintList(TList);
        friend TList operator + (TList,TList);
        friend TList operator - (TList,TList);
        friend TList operator * (TList,TList);
        friend bool operator == (TList,TList);
        friend TList Copy(TList);
        friend int ValueAtThePoint(TList,int);
        friend TList ValueAtXPlusA(TList,int);
        friend TList operator * (TList,int);
        //void operator = (TList);
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
 