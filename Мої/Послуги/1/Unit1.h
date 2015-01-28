//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Unit2.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormMainMenu : public TForm
{
__published:	// IDE-managed Components
    TButton *ButtonNaturalGas;
    TButton *ButtonWaterWaste;
    void __fastcall ButtonNaturalGasClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormMainMenu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMainMenu *FormMainMenu;
//---------------------------------------------------------------------------
#endif

