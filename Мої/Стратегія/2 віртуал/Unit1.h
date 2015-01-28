//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TButton *Button1;
    TTrackBar *TrackBar1;
    TTrackBar *TrackBar2;
    TTrackBar *TrackBar3;
    TEdit *Edit1;
    TEdit *Edit2;
    TEdit *Edit3;
    TPopupMenu *PopupMenu1;
    TMenuItem *GOCITY1;
    TMenuItem *GOCOMMANDER1;
    TMenuItem *MOVETO1;
    void __fastcall TrackBar1Change(TObject *Sender);
    void __fastcall TrackBar2Change(TObject *Sender);
    void __fastcall TrackBar3Change(TObject *Sender);
    void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall FormClick(TObject *Sender);
    void __fastcall GOCITY1Click(TObject *Sender);
    void __fastcall GOCOMMANDER1Click(TObject *Sender);
    void __fastcall MOVETO1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 