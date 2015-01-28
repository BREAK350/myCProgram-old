//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "methrect.h"
#include "menu.h"
#include <ComCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonCreate;
	TLabel *LabelRows;
	TLabel *LabelCols;
	TEdit *EditRows;
	TEdit *EditCols;
	TPanel *PanelMatrix;
	TButton *ButtonChoose;
	TCheckBox *CheckBoxCreateWithDelete;
	TMemo *MemoDescription;
	TLabel *LabelMenu;
	TLabel *LabelDescription;
	TStringGrid *StringGridMatrix;
	TLabel *LabelMatrix;
	TPanel *PanelMenu;
	TPanel *PanelDescription;
	TPanel *Panel1;
	TPanel *PanelTools;
	TPanel *Panel2;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TScrollBox *ScrollBoxMenu;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TBitBtn *BitBtn3;
	void __fastcall ButtonCreateClick(TObject *Sender);
	void __fastcall ButtonChooseClick(TObject *Sender);
	void __fastcall TreeView1Changing(TObject *Sender, TTreeNode *Node, bool &AllowChange);
	void __fastcall StringGridMatrixGetEditText(TObject *Sender, int ACol, int ARow,
          UnicodeString &Value);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall BitBtn3Click(TObject *Sender);

private:	// User declarations
	TSelectMenu selectMenu;
	TPanel *currPanel;
	TBitBtn *currBitBtn;
	bool matrixChanged;
	void createMatrix(const int &rows, const int &cols);
	void showMatrix(MethRect<IntFraction> &methRect);
	void fillMatrix(MethRect<IntFraction> &methRect);
public:		// User declarations
	void makeVisible(TPanel *panel);
	void selectMenuItem(TBitBtn *item);
	// x - סעמגבוצü, y - נÿהמך
	void drawCycle(TStringGrid *StringGridMatrix,
		const TPoint *cells, const int &size);
	TPoint getCenterOfCell(TStringGrid *StringGridMatrix,
		const int &row, const int &col);
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
