//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <iostream.h>
#include <vcl.h>
#include "T_List.h"
const char cLeft = '(';
const char cRight = ')';
const char cTranslation = '=';
//---------------------------------------------------------------------------
class T_Word
{
    private:
        int Amount;
        char **Word;
    public:
        void Delete();
        int AmountWord(const char *)const;
        void SearchWord(int &,int &,const char *)const;
        T_Word();
        T_Word(const T_Word &);
        ~T_Word();
        T_Word& operator = (const T_Word &);
        void Create(const char *);
        char* operator [] (const int &);
        char* CreateForSave();
        char* GetAllWord() { return CreateForSave(); }
};
//---------------------------------------------------------------------------
class T_Word_Translation
{
    private:
        T_Word Eng,Ukr;
    public:
        T_Word_Translation();
        T_Word_Translation(const T_Word_Translation &);
        ~T_Word_Translation() {}
        T_Word_Translation& operator = (const T_Word_Translation &);
        void Create(char *);
        char* CreateForSave();
        T_Word& GetEng() { return Eng; }
        T_Word& GetUkr() { return Ukr; }
        void SaveToFile(FILE *);
        int LoadFromFile(FILE *);
};
//---------------------------------------------------------------------------
class T_Words
{
    private:
        gT_List <T_Word_Translation> List;
        AnsiString fName;
        friend bool Compare(const void *,const void *);
    public:
        T_Words();
        void SetFileName(const char *fname) { fName=fname; }
        void LoadFromFile();
        int GetAmount() { return List.GetAmount(); }
        T_Word_Translation* operator [] (const int &k)
            { return List.GetItem(k); }
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
 