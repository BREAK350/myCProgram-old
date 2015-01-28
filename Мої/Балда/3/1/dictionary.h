//---------------------------------------------------------------------------
#ifndef dictionaryH
#define dictionaryH
#include "used.h"
#include <iostream.h>
#include <fstream.h>
//---------------------------------------------------------------------------
class T_Dictionary
{
    private:
        int N;
        char **W;
        T_Used Used;
    public:
        T_Dictionary();
        T_Dictionary(const T_Dictionary &d);
        ~T_Dictionary();
        T_Dictionary(const char *fname);
        const char* operator [] (const int &n)const;
        const char* GetRandomWord();
        int GetN()const { return N; }
        int Add(const char *word);
        int LoadFromFile(const char *fname);
        int SearchWord(const char *word);
        void Delete();
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
