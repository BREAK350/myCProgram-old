//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <stdlib.h>
//---------------------------------------------------------------------------
struct TWord {
 char *eng,
      *ukr;
      TWord()
      {
        eng=ukr=NULL;
      }
      TWord(const TWord &Word)
      {
        eng=strdup(Word.eng);
        ukr=strdup(Word.ukr);
      }
      ~TWord()
      {
        delete eng;
        delete ukr;
        eng=ukr=NULL;
      }
      TWord& operator = (const TWord &Word)
      {
        if(this!=&Word)
        {
          delete eng;
          delete ukr;
          eng=strdup(Word.eng);
          ukr=strdup(Word.ukr);
        }
        return *this;
      }
             };
struct data {
 char *fwtxt,
      *fwbak,
      *fstxt,
      *fsbak;
            };
//---------------------------------------------------------------------------
int    LoadWords();
void   ShowRandomWord();
void   ShowWord1();
void   ShowWord2();
void   SortWordEng();
void   SortWordUkr();
void   SearchNextWord();
void   SearchEngWord();
void   SearchUkrWord();
void   CreateStandartWords();
void   StandartData();
void   SaveAll();
void   SaveOne();
void   reLoad();
//---------------------------------------------------------------------------
#endif
