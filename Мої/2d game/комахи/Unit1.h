//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TTimer *Timer1;
        TButton *Button2;
        TButton *Button3;
        TLabel *Label1;
        TButton *Button4;
        TButton *Button5;
        TPanel *Panel1;
        TButton *Button6;
        TLabel *Label2;
        TLabel *Label3;
        TSaveDialog *SaveDialog1;
        TOpenDialog *OpenDialog1;
        TPanel *Panel2;
        TUpDown *UpDown1;
        TEdit *Edit1;
        TUpDown *UpDown2;
        TUpDown *UpDown3;
        TEdit *Edit2;
        TEdit *Edit3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TPanel *Panel3;
        TUpDown *UpDown4;
        TEdit *Edit4;
        TLabel *Label7;
        TButton *Button11;
        TUpDown *UpDown5;
        TEdit *Edit5;
        TLabel *Label8;
        TButton *Button7;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall FormClick(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
        void __fastcall UpDown2Click(TObject *Sender, TUDBtnType Button);
        void __fastcall UpDown3Click(TObject *Sender, TUDBtnType Button);
        void __fastcall UpDown4Click(TObject *Sender, TUDBtnType Button);
        void __fastcall UpDown5Click(TObject *Sender, TUDBtnType Button);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
