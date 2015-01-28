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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Test;
    TMemo *Memo1;
    TButton *Button1;
    TButton *Button2;
    TButton *Button3;
    TMainMenu *MainMenu1;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *N3;
    TMemo *Memo2;
    TPanel *Answer;
    TMemo *Memo3;
    TRadioButton *RadioButton1;
    TRadioButton *RadioButton2;
    TButton *Button4;
    TTimer *AnswerTimer;
    void __fastcall AnswerTimerTimer(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
    bool AnswerVisible;
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 