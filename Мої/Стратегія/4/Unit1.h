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
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TPanel *PanelInfo;
    TLabel *Label1;
    TLabel *LabelName;
    TLabel *Label3;
    TLabel *LabelXY;
    TLabel *Label5;
    TLabel *LabelLife;
    TLabel *Label7;
    TPanel *Panel2;
    TLabel *Label8;
    TLabel *LabelFire;
    TLabel *Label10;
    TLabel *LabelWater;
    TLabel *Label12;
    TLabel *LabelEarth;
    TLabel *Label14;
    TLabel *LabelAir;
    TButton *ButtonAttack;
    TLabel *Label16;
    TButton *ButtonProtection;
    TLabel *Label17;
    TLabel *LabelAttackRadius;
    TButton *Button7;
    TLabel *Label19;
    TLabel *LabelWalkingRadius;
    TButton *ButtonClose;
    TLabel *Label21;
    TButton *Button9;
    TMainMenu *MainMenu1;
    TMenuItem *N1;
    TMenuItem *N2;
    TOpenDialog *OpenDialog1;
    void __fastcall N2Click(TObject *Sender);
    void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall FormClick(TObject *Sender);
    void __fastcall Button9Click(TObject *Sender);
    void __fastcall ButtonCloseClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    void Clear();
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 