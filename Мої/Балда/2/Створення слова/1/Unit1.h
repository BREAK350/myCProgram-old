//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include "Unit2.h"
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TEdit *Edit1;
    TLabel *Label1;
    TMainMenu *MainMenu1;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *N3;
    TMenuItem *N5;
    TOpenDialog *OpenDialog1;
    TSaveDialog *SaveDialog1;
    TLabel *Label2;
    TLabel *Label3;
    TMenuItem *N4;
    TLabel *fname;
    TMenuItem *N6;
    TMenuItem *N7;
    TEdit *Edit2;
    void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall N2Click(TObject *Sender);
    void __fastcall N3Click(TObject *Sender);
    void __fastcall N5Click(TObject *Sender);
    void __fastcall N4Click(TObject *Sender);
    void __fastcall N7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    T_Words W;
    int Save,Check;
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
