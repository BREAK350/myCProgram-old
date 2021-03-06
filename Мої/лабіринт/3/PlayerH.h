//---------------------------------------------------------------------------
#ifndef PlayerHH
#define PlayerHH
#include "LabiryntH.h"
//---------------------------------------------------------------------------
class TPlayer:private TLabirynt
{
    protected:
        int pP,pX,pY;
        AnsiString fName;
    public:
        TPlayer();
        ~TPlayer();
        int Move(int);
        void Draw(int,int,TCanvas *);
        void RandomMatrix(int);
        void GetSize(int &,int &);
        void LoadFromFile(char *);
        void LoadFromFileAgain();
        void LoadStyle(char *fname){TLabirynt::LoadStyle(fname);}
        void DeleteStyle(){TLabirynt::DeleteStyle();}
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
