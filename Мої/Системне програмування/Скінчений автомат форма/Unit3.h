//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TbUFAd.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormAnimation : public TForm
{
__published:	// IDE-managed Components
    TButton *ButtonStart;
    TPanel *Panel1;
    TEdit *EditRegularExpression;
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall ButtonStartClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormAnimation(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAnimation *FormAnimation;
extern Graphics::TBitmap *bmp;
//---------------------------------------------------------------------------
#endif
