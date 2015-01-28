//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	currPanel = NULL;
	currBitBtn = NULL;
	matrixChanged = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonCreateClick(TObject *Sender)
{
	int rows = EditRows->Text.ToInt();
	int cols = EditCols->Text.ToInt();
	int fxCols = StringGridMatrix->FixedCols;
	int fxRows = StringGridMatrix->FixedRows;
	if(rows > 0 && cols > 0)
	{
		createMatrix(rows + fxRows, cols + fxCols);
		if(CheckBoxCreateWithDelete->Checked)
		{
			for(int i = 0; i < StringGridMatrix->RowCount - fxRows; i++)
			{
				for(int j = 0; j < StringGridMatrix->ColCount - fxCols; j++)
				{
					StringGridMatrix->Cells[j + fxCols][i + fxRows] = "0";
				}
			}
        }
    }
}
//---------------------------------------------------------------------------
void TMainForm::createMatrix(const int &rows, const int &cols)
{
	StringGridMatrix->RowCount = rows;
	StringGridMatrix->ColCount = cols;
}
//---------------------------------------------------------------------------
void TMainForm::showMatrix(MethRect<IntFraction> &methRect)
{
	int fxCols = StringGridMatrix->FixedCols;
	int fxRows = StringGridMatrix->FixedRows;
	for(int i = 0; i < StringGridMatrix->RowCount - fxRows; i++)
	{
		for(int j = 0; j < StringGridMatrix->ColCount - fxCols; j++)
		{
			StringGridMatrix->Cells[j + fxCols][i + fxRows] = methRect[i][j];
		}
	}
}
//---------------------------------------------------------------------------
void TMainForm::selectMenuItem(TBitBtn *item)
{
	if(currBitBtn)
	{
		currBitBtn->Enabled = true;
	}
	currBitBtn = item;
    if(currBitBtn)
	{
		currBitBtn->Enabled = false;
	}
}
//---------------------------------------------------------------------------
void TMainForm::makeVisible(TPanel *panel)
{
	if(currPanel)
	{
		currPanel->Visible = false;
	}
	currPanel = panel;
	if(currPanel)
	{
		currPanel->Visible = true;
	}
}
//---------------------------------------------------------------------------
void TMainForm::fillMatrix(MethRect<IntFraction> &methRect){
	int fxCols = StringGridMatrix->FixedCols;
	int fxRows = StringGridMatrix->FixedRows;
	for(int i = 0; i < StringGridMatrix->RowCount - fxRows; i++)
	{
		for(int j = 0; j < StringGridMatrix->ColCount - fxCols; j++)
		{
			methRect[i][j] = convertFrom(StringGridMatrix->Cells[j + fxCols][i + fxRows]);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonChooseClick(TObject *Sender)
{
	int fxCols = StringGridMatrix->FixedCols;
	int fxRows = StringGridMatrix->FixedRows;
	MethRect<IntFraction> methRect(StringGridMatrix->RowCount - fxRows,
		StringGridMatrix->ColCount - fxCols);
	fillMatrix(methRect);
	int irow = StringGridMatrix->Selection.TopLeft.Y;
	int icol = StringGridMatrix->Selection.TopLeft.X;
	methRect.chooseItem(irow - fxRows, icol - fxCols);
	showMatrix(methRect);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TreeView1Changing(TObject *Sender, TTreeNode *Node, bool &AllowChange)
{
	selectMenu.onSelect(Node);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::StringGridMatrixGetEditText(TObject *Sender, int ACol, int ARow,
          UnicodeString &Value)
{
	matrixChanged = true;
	MemoDescription->Text = "changed: " + Value;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BitBtn1Click(TObject *Sender)
{
	selectMenuItem((TBitBtn*)(Sender));
	makeVisible(MainForm->Panel1);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BitBtn2Click(TObject *Sender)
{
	selectMenuItem((TBitBtn*)(Sender));
	makeVisible(MainForm->Panel2);
}
//---------------------------------------------------------------------------
TPoint TMainForm::getCenterOfCell(TStringGrid *StringGridMatrix,
		const int &row, const int &col)
{
	TRect rect = StringGridMatrix->CellRect(col, row);
	return TPoint(rect.Left + rect.Width() / 2, rect.Top + rect.Height() / 2);
}
//---------------------------------------------------------------------------
void TMainForm::drawCycle(TStringGrid *StringGridMatrix,
	const TPoint *cells, const int &size)
{
	TPoint *points = new TPoint[size + 1];
	int i;
	for(i = 0; i < size; i++)
	{
		points[i] = getCenterOfCell(StringGridMatrix, cells[i].y, cells[i].x);
	}
    points[i] = points[0];
	StringGridMatrix->Canvas->Polyline(points, size);
	for(i = 0; i < size; i++)
	{
		StringGridMatrix->Canvas->TextOutA(points[i].x, points[i].y,
			(i % 2)?("-"):("+"));
    }
	delete[] points;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BitBtn3Click(TObject *Sender)
{
	selectMenuItem((TBitBtn*)(Sender));
    StringGridMatrix->Canvas->Pen->Color = clRed;
	TPoint cells[] = {TPoint(0,0), TPoint(2,0),TPoint(2,1),TPoint(1,1),TPoint(1,2),TPoint(0,2)};
	drawCycle(StringGridMatrix, cells, 6);
}
//---------------------------------------------------------------------------

