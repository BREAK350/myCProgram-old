//---------------------------------------------------------------------------
#ifndef funcH
#define funcH
#include <string.h>
#include "Unit6.h"
//---------------------------------------------------------------------------
class TbGame             
{
    private:
        char Step[100][6],Set[100][11],Digit[10];
        int nStep,nSet,nDigit;
    protected:
        void SetSub(const int &i,const int &j,const int &r); // [r]=[i]-[j] i,j,r>=0
        bool SetEquals(const int &i,const int &j)const;
        int SetGetCommon(const int &i,const int &j)const;
        int SetGetCount(const int &i)const;
    public:
        TbGame();
};
//---------------------------------------------------------------------------
bool Add(TbCPlural_char *Set,int &n,const TbCPlural_char &pl);
void Delete(TbCPlural_char *Set,int &n,const TbCPlural_char &pl);
void Equals(TbCPlural_char *Set,int &n);
int GetFound(const TbPlural_char &Set,const TbPlural_char &Search);
TbPlural_char CreateNumber(TbCPlural_char *Set,int &n,TbPlural_char &NotUsed);
int GetUndefined(const TbCPlural_char *Set,const int &n);
int GetDefined(const TbCPlural_char *Set,const int &n);
void CheckDefined(TbCPlural_char *Set,int &n);
void CheckSet(TbCPlural_char *Set,int &n);
void AddAgain(TbCPlural_char *Set,int &n);
bool GetCowBull(const TbPlural_char &Set,const TbPlural_char &Search,int &Cow,int &Bull);
//---------------------------------------------------------------------------
struct TbPosition
{
    char Pos[10][4]; // 0 - не може, 1 - невизначено 2 - можливо
    TbPosition()
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<4;j++)
            {
                Pos[i][j]='1';
            }
        }
    }
};
//---------------------------------------------------------------------------
void WritePos(TbPosition &Pos,const TbBCPlural_char &num);
void CreateCorrPos(TbPosition &Pos,TbPlural_char &num);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void CreatePermutation(const int &n,const char *Element);
void CreatePermutation(const int &n,char *Element,char *res,const int &i);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 