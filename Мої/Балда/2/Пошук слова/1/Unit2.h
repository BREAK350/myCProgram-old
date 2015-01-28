//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <iostream.h>
#include <vcl.h>
#include "Unit3.h"
#include <math.h>
//---------------------------------------------------------------------------
struct T_Data
{
    char S,Use;
    TPoint C;
    T_Data(const char &s,const TPoint &c) { S=s; C=c; }
};
//---------------------------------------------------------------------------
struct T_ListItem
{
    T_Data Data;
    T_ListItem *Next;
    T_ListItem(const T_Data &D):Data(D) { Next=NULL; }
};
//---------------------------------------------------------------------------
class T_List
{
    protected:
        T_ListItem *First,*Last;
        void Delete(T_ListItem *&);
        int Search(const TPoint &c)const;
        T_ListItem* pSearch(const TPoint &c)const;
        TPoint SearchMin()const;
    public:
        void CreateBorder(const char &s,T_List &Border)const;
        char* toChar()const;
        T_ListItem* SearchWord(const char *w,T_List &Border)const;
        T_Data SearchMaxWordFB(T_Dictionary &D,T_List &Border,int &i)const;
        T_Data SearchMaxWordLB(T_Dictionary &D,T_List &Border,int &i)const;
        void SearchWord(const char *w,const int &i,const TPoint &c,int &q)const;
    public:
        T_List():First(0),Last(0) { }
        T_List(const char *w);
        ~T_List() { Delete(); }
        void Add(const T_Data &data);
        void Draw(TCanvas *Canvas,const TPoint &c,const int &s)const;
        void Delete() { Delete(First); First=Last=NULL; }
        T_Data SearchMaxWord(T_Dictionary &D,int &i)const;
};
//---------------------------------------------------------------------------
int operator == (const TPoint &a,const TPoint &b);
int isNear(const TPoint &a,const TPoint &b);
int isNear(const T_ListItem *a,const T_ListItem *b);
char* DoBack(char *w);
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
 