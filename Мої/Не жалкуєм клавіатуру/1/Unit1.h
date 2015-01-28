//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "Unit2.h"
//---------------------------------------------------------------------------
struct T_Player
{
    int Key,
        Level;
    TColor Color;
    bool KeyDown;
};
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TTimer *Timer1;
    void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
    T_Player Player1,
             Player2;
    TRect Rect;
    int P1,GameType;
    bool Game;
    void NewGame();
    void GameType_1_KeyDown(WORD &Key);
    void GameType_1_KeyUp(WORD &Key);
    void DrawRect(const int &P1); // P1=[0..100]%
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

