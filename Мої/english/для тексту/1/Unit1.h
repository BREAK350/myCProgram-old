//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TMemo *Memo1;
    TMainMenu *MainMenu1;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *N3;
    TMenuItem *N4;
    TMemo *Memo2;
    TButton *Button1;
    TButton *Button2;
    TMemo *Memo3;
    TMenuItem *N5;
    TMenuItem *N6;
    TMenuItem *N7;
    TMenuItem *N8;
    TMenuItem *N9;
    TMenuItem *N10;
    TMenuItem *N11;
    TButton *Button3;
    TOpenDialog *OpenDialog1;
    TMenuItem *N12;
    TMenuItem *N13;
    TMenuItem *N14;
    void __fastcall Memo1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall Memo2MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall Button1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall Button2MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall Memo3MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall Button3MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall N3Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall N13Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
