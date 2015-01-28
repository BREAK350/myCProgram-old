//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <vcl.h>
#include "stack.h"
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
class T_Balda
{
    private:
        int N,M;
        T_Element **Element;
    //protected:
    public:
        /*пошук слова по буквам*/
        void SearchWord(const char *w,const T_C &c,T_Stack &stack,int &q);
        /*пошук першої букви слова*/
        void SearchWord(const char *w,T_Stack &stack,int &q);
        /*створює різні комбінації зі слова*/
        int SearchWord(const char *w,T_Stack &stack,T_C &add,int &index);
        int isHere(const T_C &c) { return this->operator [](c).Symbol; }
        void InsertWord(const char *w,const T_C &c);
        void DoUsed(const T_C &c);
        void DoNotUsed(const T_C &c);
        void SetSymbol(const T_C &c,const char &s);
    public:
        T_Balda();
        T_Balda(const T_Balda &balda);
        T_Balda(const int &n,const int &m);
        T_Balda(const char *w);
        T_Balda(const int &n,const int &m,const char *w);
        T_Element operator [] (const T_C &c);
        void Draw(TCanvas *Canvas,const TPoint &c,const int &s);
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
 