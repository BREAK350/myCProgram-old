//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <vcl.h>
#include <stdio.h>
#define ROAD  1
#define WALL  0
#define BEGIN 2
#define END   3
typedef char TElem;
//---------------------------------------------------------------------------
class TMatrix
{
    protected:
        int N,M;
        TElem **E;
        void SaveToFile(FILE *);
        void LoadFromFile(FILE *);
    public:
        TMatrix();
        ~TMatrix();
        void SaveToFile(char *);
        void LoadFromFile(char *);
        void Create(int,int,int);
        void Delete();
        void Insert(TMatrix &,int,int);
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
#endif
 