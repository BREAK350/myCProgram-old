//---------------------------------------------------------------------------
#ifndef T_WordsH
#define T_WordsH
#include <stdio.h>
#include <iostream.h>
//---------------------------------------------------------------------------
class T_Words
{
    protected:
        FILE *File;
        char *fName;
        int N;
    public:
        T_Words();
        T_Words(const T_Words &);
        ~T_Words();
        void Open(const char *);
        void Close();
        void New(const char *);
        int Add(const char *);
        void Add(const char *,const int);
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
#endif
 