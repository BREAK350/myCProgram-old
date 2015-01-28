//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <math.h>
#include <ExtCtrls.hpp>
const int Size=32;
const float sm=0.2;
const float e=0.0001;
const float loss=0.9;
const float max=0.5;
//---------------------------------------------------------------------------
struct tdata
{
    float h,dh;
};
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
    __published:	// IDE-managed Components
    TTimer *Timer1;
    void __fastcall Timer1Timer(TObject *Sender);
    private:	// User declarations
        tdata Wave[Size];
    public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        void Draw(TPoint c,float s);
        void Smoothing();
        void Smoothing(int i);
        void Smoothing2();
        void Smoothing2(int i);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 