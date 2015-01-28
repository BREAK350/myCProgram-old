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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TPanel *PanelCityInf;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TPanel *PanelArmy;
    TLabel *Label5;
    TEdit *Edit1;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label8;
    TLabel *Label9;
    TEdit *Edit2;
    TEdit *Edit3;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label4;
    TButton *Button1;
    TButton *Button2;
    void __fastcall FormMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
    void __fastcall FormMouseWheelUp(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
    void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall FormClick(TObject *Sender);
    void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    T_Game Game;
    TbOrientation Or;
    TPoint Curr,pMouseDown;
    bool bMouseDown;
    int CityAttack;
    void GameDraw();
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
