//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Unit2.h"
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TButton *Button1;
    TButton *Button4;
    TButton *Button5;
    TButton *Button6;
    TButton *Button7;
    TButton *Button2;
    TMainMenu *MainMenu1;
    TMenuItem *N1;
    TMenuItem *N2;
    TOpenDialog *OpenDialog1;
    TMemo *Memo1;
    void __fastcall Button7Click(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall Button6Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall N2Click(TObject *Sender);
    void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall FormClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    int S,kword,player,NPlayer;
    TPoint Centre,C;
    bT_List List;
    bT_Stack BS;
    T_Dictionary D[2];
    bT_Player p[2];
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
