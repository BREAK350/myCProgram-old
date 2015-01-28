//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
UnicodeString Eng("`qwertyuiop[]asdfghjkl;'zxcvbnm,./~QWERTYUIOP{}ASDFGHJKL:\"ZXCVBNM<>?");
UnicodeString Ukr("'йцукенгшщзхїфівапролджєячсмитьбю.₴ЙЦУКЕНГШЩЗХЇФІВАПРОЛДЖЄЯЧСМИТЬБЮ,");
UnicodeString Rus("ёйцукенгшщзхъфывапролджэячсмитьбю.ЁЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ,");
//---------------------------------------------------------------------------
int searchChar(const wchar_t &wc,const UnicodeString &where);
void Decoder(const UnicodeString &TextFrom,const UnicodeString &KeyFrom,
			 UnicodeString &TextTo,const UnicodeString &KeyTo);
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TMemo *Memo2;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	void __fastcall Memo1Change(TObject *Sender);
	void __fastcall Memo2Change(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
private:	// User declarations
	UnicodeString* switchKey(TComboBox *ComboBox);
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
