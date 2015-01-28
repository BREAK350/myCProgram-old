//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include "TbString.h"
#include <vcl.h>
#include "TbList2.h"
//---------------------------------------------------------------------------
const BLOCSIZE = 4096;
const char FILECONFIGURATION[]="Configuration";
const char FNAME[] = "Dictionary.txt";
//---------------------------------------------------------------------------
struct TbWord
{
    TbBaseString Eng,Ukr;
    int SizeByte()const { return Eng.SizeByte()+Ukr.SizeByte(); }
    bool operator == (const TbWord &Word) { return Eng==Word.Eng && Ukr==Word.Ukr; }
    void LoadFromFile(FILE *File) { Eng.LoadFromFile(File); Ukr.LoadFromFile(File); }
    void SaveToFile(FILE *File)const { Eng.SaveToFile(File); Ukr.SaveToFile(File); }
    void Show(TMemo *English,TMemo *Ukranian);
};
//---------------------------------------------------------------------------
class TbBloc
{
    private:
        int Size,FileNumber,LastFileNumber;
        TbList2 <TbWord> Words;
        void LoadFromFile(FILE *File);
        void SaveToFile(FILE *File);
        bool Modified;
        int LoadFromFile(const int &FileNumber);
        void SearchEngFileNumber(const TbBaseString &Eng);
        void SearchUkrFileNumber(const TbBaseString &Ukr);
        void SaveToFile();
        TbList2 <TbWord>* SearchEng(const TbBaseString &Eng);
    public:
        TbBloc();
};
//---------------------------------------------------------------------------
#define sENG(eng) ()
enum
{
    NEXT,
    SEARCH_NEXT
};
//---------------------------------------------------------------------------
enum
{
    ALL,  // все слово
    HALF, // через букву
    EMPTY // нема слова
};
//---------------------------------------------------------------------------
class TbDictionary
{
    private:
        TbList2 <TbWord> Words;
        void LoadFromFile(FILE *File);
        void SaveToFile(FILE *File);
    public:
        TbDictionary();
        void SearchEng(const TbBaseString &Eng,const bool &Again);
        void SearchUkr(const TbBaseString &Ukr,const bool &Again);
        void Add(const TbWord &Word);
        void LoadFromFile(const char *fname);
        void SaveToFile(const char *fname);
        bool GetCurr(TbWord &Word)const;
        bool DeleteCurr();
        bool EditCurr(const TbWord &Word);
        int GetCount()const { return Words.GetCount(); }
        int Next(TbWord &Word,const int &Why);
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
 