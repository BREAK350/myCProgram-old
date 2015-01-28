//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "Unit2.h"
#include "words.h"
#include "players.h"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *N1;
    TMenuItem *N2;
    TEdit *Edit2;
    TMenuItem *N4;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TMemo *Memo1;
    TMenuItem *N3;
    TMenuItem *N5;
    TMenuItem *N6;
    TSaveDialog *SaveDialog1;
    TOpenDialog *OpenDialog1;
    void __fastcall N4Click(TObject *Sender);
    void __fastcall Edit2KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormClick(TObject *Sender);
    void __fastcall N3Click(TObject *Sender);
    void __fastcall N5Click(TObject *Sender);
    void __fastcall N6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
    TPoint Centre;
    int S;
    T_Balda Balda;
    T_Words Words;
    T_Players Players;
    void Draw(T_SWBA &SWBA);
    T_Player *Curr;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
