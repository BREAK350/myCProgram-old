//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <HTTPApp.hpp>
#include <HTTPProd.hpp>
//---------------------------------------------------------------------------
class TFormWeb : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
private:	// User declarations
public:		// User declarations
    __fastcall TFormWeb(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormWeb *FormWeb;
//---------------------------------------------------------------------------
#endif
