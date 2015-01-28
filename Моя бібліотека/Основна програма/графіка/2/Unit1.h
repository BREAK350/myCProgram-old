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
#include "T_Polyhedron.h"
#include "SetMatrix.h"
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
    TMenuItem *N8;
    TMenuItem *N9;
    TMenuItem *N10;
    TMenuItem *N11;
    TMenuItem *N12;
    TMenuItem *N13;
    TMenuItem *N14;
    TMenuItem *N15;
    TMenuItem *N16;
    TMenuItem *N17;
    TMenuItem *N18;
    TMenuItem *N19;
    TImage *Image1;
    TPanel *Panel1;
    TLabel *Label1;
    TLabel *Label2;
    TEdit *Edit1;
    TLabel *Label3;
    TEdit *Edit2;
    TLabel *Label4;
    TEdit *Edit3;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TEdit *Edit4;
    TEdit *Edit5;
    TEdit *Edit6;
    TEdit *Edit7;
    TEdit *Edit8;
    TEdit *Edit9;
    TButton *Button1;
    TPanel *Panel2;
    TLabel *Label8;
    TEdit *Edit10;
    TEdit *Edit11;
    TEdit *Edit12;
    TMemo *Memo1;
    TMenuItem *N20;
    TMenuItem *XoY1;
    TMenuItem *XoZ1;
    TMenuItem *YoZ1;
    void __fastcall N17Click(TObject *Sender);
    void __fastcall N18Click(TObject *Sender);
    void __fastcall N12Click(TObject *Sender);
    void __fastcall N14Click(TObject *Sender);
    void __fastcall N15Click(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall XoY1Click(TObject *Sender);
    void __fastcall XoZ1Click(TObject *Sender);
    void __fastcall YoZ1Click(TObject *Sender);
    void __fastcall N13Click(TObject *Sender);
    void __fastcall N11Click(TObject *Sender);
    void __fastcall N19Click(TObject *Sender);
    void __fastcall N3Click(TObject *Sender);
    void __fastcall N4Click(TObject *Sender);
    void __fastcall N5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    T_Polyhedron Obj;
    T_Matrix4 Projection,Model;
    SetMatrix SM;
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
