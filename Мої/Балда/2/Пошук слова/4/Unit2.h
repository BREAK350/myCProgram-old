//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <iostream.h>
#include <vcl.h>
#include "Unit3.h"
#include <math.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
struct bT_ListItem
{
    struct T_Data
    {
        char S,Use;
        TPoint C;
        T_Data():C(0,0) { S=0; Use=0; }
        T_Data(const char &s,const TPoint &c) { S=s; C=c; Use=0; }
    } Data;
    bT_ListItem *Next;
    bT_ListItem(const T_Data &D):Data(D) { Next=NULL; }
};
//---------------------------------------------------------------------------
class bT_List
{
    protected:
        bT_ListItem *First,*Last;
    protected:
        char* toChar()const;
        int Search(const TPoint &c)const;
        TPoint SearchMin()const;
        bT_ListItem* pSearch(const TPoint &c)const;
        bT_ListItem* SearchWord(const char *w,bT_List &Border,bT_Stack &bs);
        bT_ListItem::T_Data SearchMaxWordFB(T_Dictionary &D,bT_List &Border,int &i,bT_Stack &bs);
        bT_ListItem::T_Data SearchMaxWordLB(T_Dictionary &D,bT_List &Border,int &i,bT_Stack &bs);
        void Add(const bT_ListItem::T_Data &data);
        void CreateBorder(bT_List &Border)const;
        void CreateFirstWord(const T_Dictionary &D);
        void Delete(bT_ListItem *&);
        void SearchWord(const char *w,const int &i,const TPoint &c,int &q,bT_Stack &bs);
    public:
        bT_List():First(0),Last(0) { }
        bT_List(const char *w);
        bT_List(const T_Dictionary &D);
        ~bT_List() { Delete(); }
        bT_ListItem::T_Data SearchMaxWord(T_Dictionary &D,int &i,bT_Stack &bs);
        char GetChar(const TPoint &p)const;
        void Add(const bT_ListItem::T_Data &data,const int &i,T_Dictionary &D);
        void Again(const T_Dictionary &D);
        void Draw(TCanvas *Canvas,const TPoint &c,const int &s)const;
        void Delete() { Delete(First); First=Last=NULL; }
        void CreateFirstWord(const char *w);
        void ShowLink(TCanvas *Canvas,const TPoint &c,const int &s)const;
};
//---------------------------------------------------------------------------
int operator == (const TPoint &a,const TPoint &b);
int isNear(const TPoint &a,const TPoint &b);
int isNear(const bT_ListItem *a,const bT_ListItem *b);
char* DoBack(char *w);
//---------------------------------------------------------------------------
class T_Balda
{
    protected:
        bT_List List;
        T_Dictionary Dictionary;
    public:
        T_Balda(const char *fname);
        void LoadDictionary(const char *fname);
};
//---------------------------------------------------------------------------
struct bT_Player
{
    public:
        T_Dictionary *D; // вказівник, не масив
        bT_List *List;   // вказівник, не масив
        int Type; // 0 - комп або 1 - людина
        string Name;
        bT_Player():Name("PC") { D=NULL; List=NULL; Type=0; }
        int GetWord(bT_Stack &bs);                                 
        int SearchWord(const char &c,bT_Stack &bs);
        int SearchWord(const char *w);
        int AddWord(const char *w);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
