//---------------------------------------------------------------------------
#ifndef InsectH
#define InsectH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
#define UI unsigned int
//---------------------------------------------------------------------------
struct TInsect {
 char password[20];
 char typeInsect[20];
 char nameInsect[20];
 char nameOwner[20];
 UI life,
    gn,sl,vl,mz,re,shv;
 char superWeapon[20];
 UI slSW;
          };
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TPanel *Panel1;
        TButton *Button1;
        TPanel *Panel2;
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 