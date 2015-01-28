//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormRegularExpression.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRegularExpression *FormRegularExpression;
//---------------------------------------------------------------------------
UnicodeString Label[2][11]=
{
	{"Regular expression","Undetermined","Determined","Minimized","Create","Check","?","Expression","Wait...","Belongs.","Not belongs."},
	{"Регулярний вираз","Недетермінований","Детермінований","Мінімізований","Створити","Перевірка","?","Ланцюжок","Почекайте","Належить","Неналежить",}
};
//---------------------------------------------------------------------------
__fastcall TFormRegularExpression::TFormRegularExpression(TComponent* Owner)
    : TForm(Owner)
{
	RegChanges=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormRegularExpression::RegularExpChange(TObject *Sender)
{
    RegChanges=true;    
}
//---------------------------------------------------------------------------
void TFormRegularExpression::ShowUFA()
{
    if(!UFA.isEmpty())
    {
        Table->RowCount=UFA.GetCountQ()+1;
        Table->ColCount=UFA.GetCountS()+1;
        int i,j,k;
        TbSeti buf;
        for(i=0;i<UFA.GetCountS();i++)
        {
            Table->Cells[i+1][0]=(char)UFA.GetSymbols().GetElements()[i];
        }
        for(i=0;i<UFA.GetCountQ();i++)
        {
            if(UFA.isEndQ(i))
            {
                Table->Cells[0][i+1]=AnsiString("(")+i+")";
            }
            else
            {
                Table->Cells[0][i+1]=i;
            }
            for(j=0;j<UFA.GetCountS();j++)
            {
                buf=UFA.GetElementIndex(i,j);
                if(buf.GetCount()==0)
                {
                    Table->Cells[j+1][i+1]="-1";
                }
                else
                {
                    Table->Cells[j+1][i+1]="";
                    for(k=0;k<buf.GetCount()-1;k++)
                    {
                        Table->Cells[j+1][i+1]=Table->Cells[j+1][i+1]+
                            IntToStr(buf.GetElements()[k])+",";
                    }
                    Table->Cells[j+1][i+1]=Table->Cells[j+1][i+1]+
                        IntToStr(buf.GetElements()[k]);
                }
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormRegularExpression::RadioButtonUndeterminedClick(TObject *Sender)
{
    ShowUFA();
}
//---------------------------------------------------------------------------
void TFormRegularExpression::ShowDFA(const TbDFA &DFA)
{
    if(!DFA.isEmpty())
    {
        Table->RowCount=DFA.GetCountQ()+1;
        Table->ColCount=DFA.GetCountS()+1;
        int i,j,k;
        for(i=0;i<DFA.GetCountS();i++)
        {
            Table->Cells[i+1][0]=(char)DFA.GetSymbol(i);
        }
        for(i=0;i<DFA.GetCountQ();i++)
        {
            if(DFA.isEndQ(i))
            {
                Table->Cells[0][i+1]=AnsiString("(")+i+")";
            }
            else
            {
                Table->Cells[0][i+1]=i;
            }
            for(j=0;j<DFA.GetCountS();j++)
            {
                Table->Cells[j+1][i+1]=DFA.GetElement(i,j);

            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormRegularExpression::RadioButtonDeterminedClick(
      TObject *Sender)
{
    ShowDFA(DFA);    
}
//---------------------------------------------------------------------------
void __fastcall TFormRegularExpression::RadioButtonMinimizedClick(TObject *Sender)
{
    ShowDFA(MDFA);    
}
//---------------------------------------------------------------------------
void __fastcall TFormRegularExpression::BitBtnHelpClick(TObject *Sender)
{
	ShellExecute(Handle,NULL,"http://e-learning.chnu.edu.ua/course/view.php?id=286",NULL,NULL,SW_RESTORE);
}
//---------------------------------------------------------------------------
void TFormRegularExpression::ShowMDFA()
{
    RadioButtonMinimized->Checked=true;
    ShowDFA(MDFA);
}
//---------------------------------------------------------------------------
void __fastcall TFormRegularExpression::BitBtnCreateClick(TObject *Sender)
{
    // check regular expression
    if(RegChanges && RegularExp->Text.Length()>0)
    {
		UFA.Create(RegularExp->Text.t_str());
        DFA.CreateFrom(UFA);
        MDFA=DFA;
        MDFA.Minimize();
        if(RadioButtonUndetermined->Checked)
        {
            ShowUFA();
        }
        else
        if(RadioButtonDetermined->Checked)
        {
            ShowDFA(DFA);
        }
        else
        {
            ShowDFA(MDFA);
        }
        RegChanges=false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormRegularExpression::BitBtnCheckClick(TObject *Sender)
{
	FormCheck->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFormRegularExpression::cmbLanguageChange(TObject *Sender)
{
	Label1->Caption=Label[cmbLanguage->ItemIndex][0];
	RadioButtonUndetermined->Caption=Label[cmbLanguage->ItemIndex][1];
	RadioButtonDetermined->Caption=Label[cmbLanguage->ItemIndex][2];
	RadioButtonMinimized->Caption=Label[cmbLanguage->ItemIndex][3];
	BitBtnCreate->Caption=Label[cmbLanguage->ItemIndex][4];
	BitBtnCheck->Caption=Label[cmbLanguage->ItemIndex][5];
	BitBtnHelp->Caption=Label[cmbLanguage->ItemIndex][6];
	FormCheck->Label1->Caption=Label[cmbLanguage->ItemIndex][7];
	FormCheck->BitBtnCheck->Caption=Label[cmbLanguage->ItemIndex][5];
	FormCheck->Result->Caption=Label[cmbLanguage->ItemIndex][8];
}
//---------------------------------------------------------------------------

