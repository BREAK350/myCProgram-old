//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <MPlayer.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
struct T_Player
{
    TRect Rect;
    TColor Color;
    float Angle,vAngle;
    int HP,sv;
    TPoint Snaryad;
    float SnaryadAngle;
    bool Shot;
    int Move; // = [-5..5] (random)
    void Draw(TCanvas *Canvas);
    void DoShot();
    void NextStep(const TRect &Region,T_Player &Enemy);
};
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TTimer *Timer1;
    TMediaPlayer *MediaPlayer1;
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    T_Player Player1,Player2;
    bool Game;
    int MaxHP;
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 