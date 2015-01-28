//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Word_2K_SRVR"
#pragma resource "*.dfm"
TForm1 *Form1;
char Symbols[]="0123456789qwrtyuiopasdfghjklzxcvbnm";
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    randomize();
}
//---------------------------------------------------------------------------
void TForm1::FillDFAs()
{
    if(DFAs)
    {
        delete[] DFAs;
    }
    if(Count>0)
    {
        int i=0,q,fs;
        char *Expression;
        TbUFA UFA;
        DFAs=new fDFA[Count];
        while(i<Count)
        {
            Expression=CreateRandom(MaxLength);
            ChangeSymbol(Expression,Symbols);

            UFA.Create(Expression);
            DFAs[i].DFA.CreateFrom(UFA);
            DFAs[i].DFA.Minimize();
            DFAs[i].DFA.DoNotFullyDefined();
            q=DFAs[i].DFA.GetCountQ();
            fs=DFAs[i].DFA.GetCountFinaleState();
            if(q>=5 && q<7 && fs>1 && fs<4 && isGood(Expression))
            {
                DFAs[i].Expression=Expression;
                i++;
            }
        }
    }
    else
    {
        DFAs=NULL;
    }
}
fDFA::~fDFA()
{
    delete Expression;
}
//---------------------------------------------------------------------------
void TForm1::FillFields()
{
    Count=EditCount->Text.ToInt();
    MaxLength=EditMaxLength->Text.ToInt();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonSaveHTMLClick(TObject *Sender)
{
    if(SaveDialog->Execute())
    {
        FileName=SaveDialog->FileName;
        FillFields();
        FillDFAs();
        if(DFAs)
        {
            ofstream ofs((FileName+".html").c_str());
            HeadHTML(ofs);
            int i=0;
            while(i<Count)
            {
                WriteInHTML(ofs,DFAs[i].Expression,DFAs[i].DFA,i);
                i++;
            }
            EndHTML(ofs);
            ofs.close();
        }
    }
}
//---------------------------------------------------------------------------
void SetPaddingForTable(Variant &vTable)
{
    vTable.OlePropertySet("TopPadding",10);
    vTable.OlePropertySet("BottomPadding",10);
    vTable.OlePropertySet("LeftPadding",10);
    vTable.OlePropertySet("RightPadding",10);
}
//---------------------------------------------------------------------------
void FillTable(Variant &vTable,const TbDFA &DFA)
{
    Variant vCell;
    int q=DFA.GetCountQ(),s=DFA.GetCountS();
    for(int j=0;j<s;j++)
    {
        vCell=vTable.OleFunction("Cell",1,j+2);
        String text=String("'")+(char)DFA.GetSymbol(j)+"'";
        vCell.OlePropertyGet("Range").
            OlePropertySet("Text",text.c_str());
    }
    for(int i=0;i<q;i++)
    {
        String text;
        if(DFA.isEndQ(i))
        {
            text=String("(")+IntToStr(i)+")";
        }
        else
        {
            text=IntToStr(i);
        }
        vCell=vTable.OleFunction("Cell",i+2,1);
        vCell.OlePropertyGet("Range").
            OlePropertySet("Text",text.c_str());
        for(int j=0;j<s;j++)
        {
            text=IntToStr(DFA.GetElement(i,j));
            vCell=vTable.OleFunction("Cell",i+2,j+2);
            vCell.OlePropertyGet("Range").
                OlePropertySet("Text",text.c_str());
        }
    }
}
//---------------------------------------------------------------------------
void TForm1::CreateTableTitle(Variant &vRange,const int &iDFA)
{
    String text=String("Варіант №")+IntToStr(iDFA+1)+"\n"+DFAs[iDFA].Expression;
    vRange.OlePropertySet("Text",text.c_str());
}
//---------------------------------------------------------------------------
void TForm1::CreateTable(Variant &vCell,const int &iDFA)
{
    int q=DFAs[iDFA].DFA.GetCountQ();
    int s=DFAs[iDFA].DFA.GetCountS();
    Variant vTables,vTable;
    vTables=vCell.OlePropertyGet("Tables");

    vTables.OleProcedure("Add", vCell.OlePropertyGet("Range"), q+1, s+1,
        wdWord9TableBehavior, /*wdAutoFitFixed*/wdAutoFitContent);

    vTable=vTables.OleFunction("Item",1);
    FillTable(vTable,DFAs[iDFA].DFA);
}
//---------------------------------------------------------------------------
void TForm1::CreateAllTable(Variant &vRange)
{
    Variant vTables,vTable,vCell,vTitleRange,vTableRange;
    vTables=vRange.OlePropertyGet("Tables");

    vTables.OleProcedure("Add", vRange, Count, 2,
        wdWord9TableBehavior, /*wdAutoFitContent*/wdAutoFitFixed);

    vTable=vTables.OleFunction("Item",1);
    for(int i=0;i<Count;i++)
    {
        vCell=vTable.OleFunction("Cell",i+1,1);
        vTitleRange=vCell.OlePropertyGet("Range");
        CreateTableTitle(vTitleRange,i);

        vCell=vTable.OleFunction("Cell",i+1,2);
        vTableRange=vCell.OlePropertyGet("Range");
        CreateTable(vCell,i);
    }
    /**/
        vTable.OlePropertyGet("Rows").
            OlePropertySet("Alignment",1);
        SetPaddingForTable(vTable);
    /**/
}
//---------------------------------------------------------------------------
void TForm1::CreateDocument(const char *FileName)
{
    Variant vApp,vDocs,vDoc,vParagraphs,vParagraph,vRange,vFont;

    vApp=CreateOleObject("Word.Application");
    vDocs=vApp.OlePropertyGet("Documents");
    vDocs.OleProcedure("Add");
    vDoc=vDocs.OleFunction("Item",(int)vDocs.OlePropertyGet("Count"));

    vParagraphs=vDoc.OlePropertyGet("Paragraphs");
    vParagraphs.OleProcedure("Add");

    vParagraph=vParagraphs.OleFunction("Item",(int)vParagraphs.OlePropertyGet("Count"));
    vParagraph.OlePropertyGet("Range").
        OlePropertySet("Text","Побудова регулярного виразу по скінченному автомату");

    /**/
        vParagraph.OlePropertySet("Alignment",1);
        vFont=vParagraph.OlePropertyGet("Range").
                OlePropertyGet("Font");
        vFont.OlePropertySet("Size",18);
        vFont.OlePropertySet("Name","Times New Roman");
        vFont.OlePropertySet("Bold",true);
    /**/
    vParagraphs.OleProcedure("Add");

    vParagraph=vParagraphs.OleFunction("Item",(int)vParagraphs.OlePropertyGet("Count"));
    vRange=vParagraph.OlePropertyGet("Range");
    CreateAllTable(vRange);

    vDoc.OleProcedure("SaveAs",FileName);

    vApp.OleProcedure("Quit");
}
//---------------------------------------------------------------------------
void TForm1::Write(Variant &vTables,Variant &vParagraphs,
    int &iParagraphs,const int &iDFA)
{
    int q=DFAs[iDFA].DFA.GetCountQ();
    int s=DFAs[iDFA].DFA.GetCountS();
    Variant vParagraph,vTable,vRange;

    vParagraph=vParagraphs.OleFunction("Item",iParagraphs);
    vRange=vParagraph.OlePropertyGet("Range");

    CreateTableTitle(vRange,iDFA);

    vParagraphs.OleProcedure("Add");
    iParagraphs++;
    vParagraph=vParagraphs.OleFunction("Item",iParagraphs);
    vParagraph.OlePropertySet("Alignment",1);
    vRange = vParagraph.OlePropertyGet("Range");

    vTables.OleProcedure("Add", vRange, q+1, s+1,
        wdWord9TableBehavior, wdAutoFitFixed);

    vParagraph=vParagraphs.OleFunction("Item",iParagraphs);
    vRange = vParagraph.OlePropertyGet("Range");
    vTables=vRange.OlePropertyGet("Tables");

    vTable=vTables.OleFunction("Item",1);
    vTable.OlePropertyGet("Rows").
          OlePropertySet("Alignment",1);

    FillTable(vTable,DFAs[iDFA].DFA);
    iParagraphs+=(q+1)*(s+2);

    vParagraphs.OleProcedure("Add");
    iParagraphs++;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonSaveWordClick(TObject *Sender)
{
    /*int iParagraphs=2;
    Variant vApp,vDocs,vDoc,vParagraphs,vParagraph,vFont,vRange,
        vTable,vCell,vTables;

    //FillFields();
    //FillDFAs();

    vApp=CreateOleObject("Word.Application");
    vDocs=vApp.OlePropertyGet("Documents");
    vDocs.OleProcedure("Add");
    vDoc=vDocs.OleFunction("Item",1);
    vParagraphs=vDoc.OlePropertyGet("Paragraphs");
    vTables=vDoc.OlePropertyGet("Tables");
    vParagraphs.OleProcedure("Add");
    vParagraph=vParagraphs.OleFunction("Item",1);
    vParagraph.OlePropertyGet("Range").
              OlePropertySet("Text","Побудова регулярного виразу по скінченному автомату");
    vParagraph.OlePropertySet("Alignment",1);
    vFont=vParagraph.OlePropertyGet("Range").
                OlePropertyGet("Font");
    vFont.OlePropertySet("Size",18);
    vFont.OlePropertySet("Name","Times New Roman");
    vFont.OlePropertySet("Bold",true);

    vParagraphs.OleProcedure("Add");
    for(int i=0;i<Count;i++)
    {
        vParagraph=vParagraphs.OleFunction("Item",iParagraphs);
        vParagraph.OlePropertySet("Alignment",1);
        vFont=vParagraph.OlePropertyGet("Range").
                OlePropertyGet("Font");
        vFont.OlePropertySet("Size",18);
        vFont.OlePropertySet("Name","Times New Roman");
        vFont.OlePropertySet("Bold",true);
        Write(vTables,vParagraphs,iParagraphs,i);
    }

    vDoc=vDocs.OleFunction("Item",1); */
    if(SaveDialog->Execute())
    {
        if(DFAs==0)
        {
            FillFields();
            FillDFAs();
        }
        if(DFAs)
        {
            CreateDocument((SaveDialog->FileName+".doc").c_str());
        }
    }
    //vDoc.OleProcedure("SaveAs",(SaveDialog->FileName+".doc").c_str());

    //vApp.OleProcedure("Quit");
}
//---------------------------------------------------------------------------

