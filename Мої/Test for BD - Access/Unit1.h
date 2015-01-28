// ---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
#include <FMTBcd.hpp>
#include <SqlExpr.hpp>
#include <Keyboard.hpp>
#include <vector>
#include <utility>

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TADOConnection *ADOConnection1;
	TDataSource *DataSource1;
	TADOTable *ADOTable1;
	TDBGrid *DBGrid1;
	TPopupMenu *PopupMenu1;
	TMenuItem *new1;
	TMenuItem *delete1;
	TAutoIncField *ADOTable1id;
	TIntegerField *ADOTable1idEngWord;
	TIntegerField *ADOTable1idUkrWord;
	TADOQuery *ADOQuery1;
	TMemo *Memo1;

private:
	void showResult(TMemo *memo, const String &request, TADOQuery *ADOQuery);

public: // User declarations
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif
