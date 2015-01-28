//---------------------------------------------------------------------------
#ifndef LibH
#define LibH
#include <iostream.h>
typedef unsigned int UI;
const UI BUF=16;
//---------------------------------------------------------------------------
class T_Lib_Word
{
    private:
        char *Word;
        char Size;
    public:
        T_Lib_Word() { Word=strdup(""); Size=0; }
        T_Lib_Word(const char *);
        T_Lib_Word(const T_Lib_Word &);
        ~T_Lib_Word();
        T_Lib_Word& operator = (const T_Lib_Word &);
        int operator == (const T_Lib_Word &)const;
        int operator == (const char *word)const { return T_Lib_Word(word)==*this; }
        int operator != (const T_Lib_Word &lw)const { return !(*this==lw); }
        int operator != (const char *word)const { return !(*this==word); }
        void SaveToFile(FILE *);
        void LoadFromFile(FILE *);
        char* GetWord() { return strdup(Word); }
        int GetSize() { return Size; }
};
//---------------------------------------------------------------------------
class T_Lib_Words
{
    private:
        UI AmountWord;
        T_Lib_Word *Words;
    protected:
        void SaveToFile(FILE *)const;
        void LoadFromFile(FILE *);
        UI SearchFreeWord()const;
    public:
        T_Lib_Words();
        ~T_Lib_Words();
        int AddWord(const char *);
        T_Lib_Words& operator = (const T_Lib_Words &);
        char* operator [] (const UI &);
        void SaveToFile(const char *)const;
        void LoadFromFile(const char *);
        void ChangeWord(const UI &,const char *);
        UI SearchWord(const char *)const;
        UI GetAmountWord()const { return AmountWord; }
        void DeleteWord(const UI &);
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
