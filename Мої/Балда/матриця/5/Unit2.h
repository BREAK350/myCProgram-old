//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <vcl.h>
#include "stack.h"
#include <iostream.h>
#include <fstream.h>
#define FOUR 4
#define EIGHT 8
//---------------------------------------------------------------------------
struct T_Element
{
    char Symbol;
    char Used; // 0 - not use, 1 - use
    T_Element() { Symbol=' '; Used=0; }
    T_Element(const char &s) { Symbol=s; Used=0; }
    T_Element(const char &s,const char &u) { Symbol=s; Used=u; }
    operator char() { return Symbol; }
};
//---------------------------------------------------------------------------
struct T_C
{
    int i,j;
    T_C() { i=j=0; }
    T_C(const int &_i,const int &_j) { i=_i; j=_j; }
};
//---------------------------------------------------------------------------
typedef
struct T_SearchWordsWithoutAdding // пошук слова без додавання
{
    string Word;
    T_Stack Stack;
    int Q;
    T_SearchWordsWithoutAdding(const char *w);
} T_SWWA;
//---------------------------------------------------------------------------
typedef
struct T_SearchWordsByAdding // пошук слова з додавання
{
    string Word;
    T_Stack Stack;
    int Q;
    T_C Add;
    int Index;
    T_SearchWordsByAdding(const char *w);
    T_SearchWordsByAdding& operator = (const T_SearchWordsByAdding &SWBA);
} T_SWBA;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class T_Balda
{
    private:
        int N,M;
        T_Element **Element;
    protected:
        /*пошук слова по буквам*/
        void SearchWord_4(const char *w,const T_C &c,T_Stack &stack,int &q);
        /* + пошук по діагоналі*/
        void SearchWord_8(const char *w,const T_C &c,T_Stack &stack,int &q);
        /*пошук першої букви слова*/
        void SearchWord_4(const char *w,T_Stack &stack,int &q);
        void SearchWord_8(const char *w,T_Stack &stack,int &q);
        /*створює різні комбінації зі слова*/
        int SearchWord(const char *w,T_Stack &stack,T_C &add,int &index,const int &type);
        int isHere(const T_C &c) { return this->operator [](c).Symbol; }
        void InsertWord(const char *w,const T_C &c);
        void DoUsed(const T_C &c);
        void DoNotUsed(const T_C &c);
        void SetSymbol(const T_C &c,const char &s);
        void Delete();
    public:
        T_Balda();
        ~T_Balda();
        T_Balda(const T_Balda &balda);
        T_Balda(const int &n,const int &m);
        T_Balda(const char *w);
        T_Balda(const int &n,const int &m,const char *w);
        T_Element operator [] (const T_C &c);
        void Draw(TCanvas *Canvas,const TPoint &c,const int &s);
        void SearchWord(T_SWWA &SWWA,const int &type);
        void SearchWord(T_SWBA &SWBA,const int &type);
        void AddWord(T_SWBA &SWBA,const int &type);
        void Again(const char *w);
        void Again(const int &n,const int &m,const char *w);
        void SaveToFile(ofstream &ofs);
        void LoadFromFile(ifstream &ifs);
        TRect GetRect(const TPoint &c,const int &s)const;
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
#endif
