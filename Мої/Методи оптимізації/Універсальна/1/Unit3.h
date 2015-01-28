//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TStringGrid *StringGridF;
	TLabel *Label2;
	TEdit *EditN;
	TButton *Button1;
	TPanel *Panel1;
	TPanel *Panel2;
	TLabel *Label3;
	TComboBox *ComboBoxFRight;
	TEdit *EditVariable;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *EditM;
	TStringGrid *StringGridRestrictionLeft;
	TStringGrid *StringGridRestrictionSignedRight;
	TStringGrid *StringGridAdditionalRestriction;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall StringGridsClick(TObject *Sender);
	void __fastcall ButtonsClick(TObject *Sender);
private:	// User declarations
	TStringGrid *lastFocus;
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
