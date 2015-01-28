//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TbDFA.h"
#include <Dialogs.hpp>
#include "Unit2.h"
#include "DFA_HTML.h"
#include "Word_2K_SRVR.h"
#include <OleServer.hpp>
#include <ComObj.hpp>
//---------------------------------------------------------------------------
struct fDFA
{
    TbDFA DFA;
    char *Expression;

    ~fDFA();
};
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TEdit *EditCount;
    TLabel *Label3;
    TLabel *Label4;
    TEdit *EditMaxLength;
    TButton *ButtonSaveHTML;
    TButton *ButtonSaveWord;
    TSaveDialog *SaveDialog;
    void __fastcall ButtonSaveHTMLClick(TObject *Sender);
    void __fastcall ButtonSaveWordClick(TObject *Sender);
private:	// User declarations
    fDFA *DFAs;
    int Count,MaxLength;
    String FileName;
    void FillDFAs();
    void FillFields();
    void CreateTable(Variant &vRange,const int &iDFA);
    void CreateTableTitle(Variant &vCell,const int &iDFA);
    void CreateAllTable(Variant &vRange);
    void CreateDocument(const char *FileName);
    
    void Write(Variant &vTables,Variant &vParagraphs,
    int &iParagraphs,const int &iDFA);
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
