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
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TPanel *Panel1;
        TMemo *eng;
        TMemo *ukr;
        TLabel *Label1;
        TLabel *Label2;
        TButton *prev;
        TButton *button;
        TButton *next;
        TMenuItem *N3;
        TMenuItem *N11;
        TMenuItem *N21;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N8;
        TMenuItem *N9;
        TMenuItem *N10;
        TMenuItem *N12;
        TMenuItem *N13;
        TMenuItem *N14;
        TMenuItem *N22;
        TMenuItem *N23;
        TMenuItem *N31;
        TMenuItem *N41;
        TMenuItem *N15;
        TMenuItem *N16;
        TPanel *Panel2;
        TLabel *Label3;
        TEdit *Edit1;
        TButton *Button1;
        TButton *Button2;
        TMenuItem *N17;
        TPanel *Panel3;
        TEdit *Edit2;
        TEdit *Edit3;
        TButton *Button3;
        TButton *Button4;
        TPanel *msg;
        TMemo *Memo1;
        TLabel *Label4;
        TButton *Button5;
        TButton *Button6;
        TButton *Button7;
        TButton *Button8;
        TButton *Button10;
        TButton *Button11;
        TButton *Button9;
        TLabel *Label5;
        TButton *Button12;
        TMenuItem *N18;
        TMenuItem *N19;
        TMenuItem *N20;
        TMenuItem *N24;
        TMenuItem *N25;
        void __fastcall nextClick(TObject *Sender);
        void __fastcall prevClick(TObject *Sender);
        void __fastcall buttonClick(TObject *Sender);
        void __fastcall N11Click(TObject *Sender);
        void __fastcall N21Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall N9Click(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
        void __fastcall N12Click(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall N14Click(TObject *Sender);
        void __fastcall N22Click(TObject *Sender);
        void __fastcall N23Click(TObject *Sender);
        void __fastcall N31Click(TObject *Sender);
        void __fastcall N41Click(TObject *Sender);
        void __fastcall N15Click(TObject *Sender);
        void __fastcall N16Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall N17Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Edit2Change(TObject *Sender);
        void __fastcall Edit3Change(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall msgClick(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall N18Click(TObject *Sender);
        void __fastcall N20Click(TObject *Sender);
        void __fastcall N24Click(TObject *Sender);
        void __fastcall FormCanResize(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize);
        void __fastcall N25Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
