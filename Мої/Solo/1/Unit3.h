//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "Unit1.h"
//---------------------------------------------------------------------------
class TKeyBoard : public TForm
{
__published:	// IDE-managed Components
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    Graphics::TBitmap *bmp,*bmpKey,*bmpSpace;
    void WriteSymbols(const char Symbols[2][33]);
    __fastcall TKeyBoard(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TKeyBoard *KeyBoard;
//---------------------------------------------------------------------------
#endif
