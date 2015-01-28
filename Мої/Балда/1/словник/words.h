//---------------------------------------------------------------------------
#ifndef wordsH
#define wordsH
#include <iostream.h>
#include <conio.h>
//---------------------------------------------------------------------------
struct TSymbol
{
    char S;
    char N;
    TSymbol *next;
};
//---------------------------------------------------------------------------
class TWords
{
    private:
        char N;
        TSymbol *words;
        void Delete(TSymbol &);
        void AddSymbol(char *,TSymbol &);
        int PrintSymbols(TSymbol,int);
        void SaveToFile(FILE *,TSymbol);
        void LoadFromFile(FILE *,TSymbol &);
        bool SearchWord(char *,TSymbol);
    public:
        TWords();
        ~TWords();
        void AddWord(char *);
        void PrintAll();
        void SaveToFile(char *);
        void LoadFromFile(char *);
        void Free();
        bool SearchWord(char *);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 