//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "T_Vector2d.h"
//---------------------------------------------------------------------------
const int MAXSTACK = 128;
//---------------------------------------------------------------------------
class T_Stack
{
    private:
        T_Vector2d Array[MAXSTACK];
        int Top;
    public:
        T_Stack() { Top=0; }
        int Read(T_Vector2d &Vector)
        {
            int q=0;
            if(Top>0)
            {
                q=1;
                Top--;
                Vector=Array[Top];
            }
            return q;
        }
        int Write(const T_Vector2d &Vector)
        {
            int q=0;
            if(Top<MAXSTACK)
            {
                q=1;
                Array[Top]=Vector;
                Top++;
            }
            return q;
        }
};
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TLabel *LabelCursor;
    void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall FormClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    TPoint Cursor;
    T_Stack Stack;
    double Scale;
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 