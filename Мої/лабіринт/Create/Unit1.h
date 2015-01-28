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
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *N3;
    TMenuItem *N4;
    TMenuItem *N5;
    TMenuItem *N6;
    TMenuItem *N7;
    TMenuItem *N10;
    TMenuItem *N11;
    TMenuItem *N12;
    TSaveDialog *SaveDialog1;
    TOpenDialog *OpenDialog1;
    TMenuItem *N9;
    TMenuItem *N18;
    TMenuItem *N19;
    TMenuItem *N20;
    TMenuItem *N13;
    TMenuItem *N7750501;
    TMenuItem *N10x1035x351;
    TMenuItem *N21x2125x251;
    TMenuItem *N49x4910x101;
    TMenuItem *N14;
    TMenuItem *N15;
    TPanel *Panel1;
    TRadioButton *RadioButton1;
    TRadioButton *RadioButton2;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TEdit *Edit1;
    TEdit *Edit2;
    TEdit *Edit3;
    TBitBtn *BitBtn1;
    TMenuItem *N16;
    TMenuItem *N17;
    TMenuItem *N21;
    TMenuItem *N22;
    TMenuItem *N23;
    void __fastcall N4Click(TObject *Sender);
    void __fastcall N5Click(TObject *Sender);
    void __fastcall N6Click(TObject *Sender);
    void __fastcall N7Click(TObject *Sender);
    void __fastcall N9Click(TObject *Sender);
    void __fastcall N12Click(TObject *Sender);
    void __fastcall N11Click(TObject *Sender);
    void __fastcall N10Click(TObject *Sender);
    void __fastcall N18Click(TObject *Sender);
    void __fastcall N19Click(TObject *Sender);
    void __fastcall N20Click(TObject *Sender);
    void __fastcall N13Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormCanResize(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize);
    void __fastcall N7750501Click(TObject *Sender);
    void __fastcall N10x1035x351Click(TObject *Sender);
    void __fastcall N21x2125x251Click(TObject *Sender);
    void __fastcall N49x4910x101Click(TObject *Sender);
    void __fastcall N14Click(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall N15Click(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall N16Click(TObject *Sender);
    void __fastcall N17Click(TObject *Sender);
    void __fastcall N22Click(TObject *Sender);
    void __fastcall N23Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
