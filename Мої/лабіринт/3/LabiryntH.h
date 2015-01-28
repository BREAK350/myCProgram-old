//---------------------------------------------------------------------------
#ifndef LabiryntHH
#define LabiryntHH
#include "MatrixH.h"
#include <vcl.h>
#define RIGHT     1
#define DOWN      2
#define LEFT      3
#define UP        4
#define UPFLOOR   5
#define DOWNFLOOR 6
//---------------------------------------------------------------------------
class TLabirynt:public TMatrix
{
    protected:
        int Scale;  // розмір одного квадрата
        int dN,dM;  // розмірність ігрового вікна (у квадратах)
        Graphics::TBitmap *Map;
        Graphics::TBitmap *Style;
        int NumberOfType(int);
    public:
        TLabirynt();
        ~TLabirynt();
        void MapClear();
        void Draw(int,int,TCanvas *);
        void CreatePicture(int,int,int);
        void DrawElement(int,int,int,int,int);
        bool CanGo(int,int,int);
        void GetSizePicture(int &,int &);
        void SetScale(int S){Scale=(S>1)?(S):(Scale);}
        void SetQuadrat(int Dn,int Dm){dN=(Dn>0)?(Dn):(dN);dM=(Dm>0)?(Dm):(dM);}
        int GetElement(int i,int j,int k){return L[i][j][k];}
        void SearchRandomBEGIN(int &,int &,int &);
        void GetSize(int &p,int &n,int &m){p=mP;m=mM;n=mN;}
        void LoadStyle(char *);
        void DeleteStyle();
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
