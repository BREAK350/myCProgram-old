//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <iostream.h>
#include <vcl.h>
#include "Unit3.h"
#include <math.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
struct bT_Data
{
    struct T_Data
    {
        char S,Use;
        TPoint C;
        T_Data():C(0,0) { S=0; Use=0; }
        T_Data(const char &s,const TPoint &c) { S=s; C=c; Use=0; }
    } Data;
    bT_Data *Next;
    bT_Data(const T_Data &D):Data(D) { Next=NULL; }
};
//---------------------------------------------------------------------------
class T_Balda
{
    protected:
        bT_Data *First,*Last;
        
    protected:
        char* toChar()const;
        int Search(const TPoint &c)const;
        TPoint SearchMin()const;
        bT_Data* pSearch(const TPoint &c)const;
        bT_Data* SearchWord(const char *w,T_Balda &Border);
        bT_Data::T_Data SearchMaxWordFB(T_Dictionary &D,T_Balda &Border,int &i);
        bT_Data::T_Data SearchMaxWordLB(T_Dictionary &D,T_Balda &Border,int &i);
        void Add(const bT_Data::T_Data &data);
        void CreateBorder(T_Balda &Border)const;
        void CreateFirstWord(const T_Dictionary &D);
        void Delete(bT_Data *&);
        void SearchWord(const char *w,const int &i,const TPoint &c,int &q);
    public:
        T_Balda():First(0),Last(0) { }
        T_Balda(const char *w);
        T_Balda(const T_Dictionary &D);
        ~T_Balda() { Delete(); }
        bT_Data::T_Data SearchMaxWord(T_Dictionary &D,int &i);
        void Add(const bT_Data::T_Data &data,const int &i,T_Dictionary &D);
        void Again(const T_Dictionary &D);
        void Draw(TCanvas *Canvas,const TPoint &c,const int &s)const;
        void Delete() { Delete(First); First=Last=NULL; }
        void CreateFirstWord(const char *w);
};
//---------------------------------------------------------------------------
int operator == (const TPoint &a,const TPoint &b);
int isNear(const TPoint &a,const TPoint &b);
int isNear(const bT_Data *a,const bT_Data *b);
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
 