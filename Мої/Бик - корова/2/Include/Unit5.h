//---------------------------------------------------------------------------
#ifndef Unit5H
#define Unit5H
#include "Unit6.h"
#define MAXpr 64
#define MAXcom 16
//---------------------------------------------------------------------------
class TbBullCow
{
    private:
        TbBCPlural_char Progress[MAXpr];
        int CountPr;
        TbCPlural_char Component[MAXcom];
        int CountCom;
        int Found;
    protected:
        bool SearchProgress(const TbBCPlural_char &BCPl);
    public:
        TbBullCow() { Found=CountPr=CountCom=0; }
        TbBullCow(const char *Component,const int &Found);
    public:
        TbPlural_char GetNext();
        void SetNext(const TbPlural_char &CPl,const int &Cow,const int &Bull);
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
 