//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormNaturalGas *FormNaturalGas;
//---------------------------------------------------------------------------
__fastcall TFormNaturalGas::TFormNaturalGas(TComponent* Owner)
    : TForm(Owner)
{
    time_t t=time(NULL);
    tm* aTm=localtime(&t);
    EditMonth->Text=Months[aTm->tm_mon];
    EditYear->Text=aTm->tm_year+1900;
    delete aTm;

    bData=NULL;
    size=0;
    LoadFromFile("GasData.gd",size,bData);
    if(size==0)
    {
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormNaturalGas::ButtonOKClick(TObject *Sender)
{
    bool q=true;
    TbData Data;
    try
    {
        Data.end=StrToFloat(EditTerminal->Text);
    }
    catch(...)
    {
        ShowMessage("Неправильно введено кінцевий показник");
        q=false;
    }
    if(q)
    {
        try
        {
            Data.begin=StrToFloat(EditInitial->Text);
        }
        catch(...)
        {
            ShowMessage("Неправильно введено початковий показник");
            q=false;
        }
    }
    if(q)
    {
        try
        {
            Data.price=StrToFloat(EditPrice->Text);
        }
        catch(...)
        {
            ShowMessage("Неправильно введено ціну за куб");
            q=false;
        }
    }
    if(q)
    {
        EditDifference->Text=FloatToStr(Data.Different());
        EditSum->Text=FloatToStr(Data.Summ());
    }
}
//---------------------------------------------------------------------------

