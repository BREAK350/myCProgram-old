//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include "Unit1.h"
#include <stdio.h>
//---------------------------------------------------------------------------
class TWord
{
    private:
        char *word;
        int n;
    public:
        TWord();
        ~TWord();
        char* CreateFirstWord(char*);
        char* GetWord();
};
//---------------------------------------------------------------------------
class TSentence
{
    private:
        TWord *words;
        int Nword;
        char *sentence;
    public:
        TSentence();
        ~TSentence();
        char* CreateFirstSentence(char*);
        char* GetSentence();
        char* GetWord(int);
};
//---------------------------------------------------------------------------
class TText
{
    private:
        TSentence *sentences;
        int N;
    public:
        TText();
        ~TText();
        void CreateTextWithFile(char*);
        char* GetSentences(int);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#endif
 