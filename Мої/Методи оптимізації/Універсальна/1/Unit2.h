//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <OleCtrls.hpp>
#include <SHDocVw.hpp>
#include <Menus.hpp>
#include "mo.h";
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TWebBrowser *WebBrowser1;
	TMemo *Memo1;
	TMainMenu *MainMenu1;
	TMenuItem *N2;
	TPanel *Panel1;
	TButton *Button1;
	void __fastcall N2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Panel1Resize(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
	TbTagHTML *html;
	TbContainerHTML *ol_c;
	TbAbstractProblem *problem;
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
	void showHTML();
	void setProblem(TbAbstractProblem *problem);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
