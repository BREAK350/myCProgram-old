//---------------------------------------------------------------------------
#pragma hdrstop
#include "frame.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void TbBufferValue::Assign(const TbValue &value)
{
    if(value.Name!="")
    {
        Value.CurrSetFirst();
        while(Value.CurrCorrect() && Value.GetCurr().Name!=value.Name)
        {
            Value.CurrSetNext();
        }
        if(Value.CurrCorrect())
        {
            Value.GetCurr().Value=value.Value;
        }
        else
        {
            Value.AddLast(value);
        }
    }
}
//---------------------------------------------------------------------------
int TbBufferValue::GetValue(TbValue &value)
{
    int q=0;
    Value.CurrSetFirst();
    while(Value.CurrCorrect() && Value.GetCurr().Name!=value.Name)
    {
        Value.CurrSetNext();
    }
    if(Value.CurrCorrect())
    {
        value.Value=Value.GetCurr().Value;
        q=1;
    }
    return q;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int Tb_if_else::DoOperation(const int &Value)
{
    if(Condition->DoOperation(Value))
    {
        if(True)
        {
            True->DoOperation(Value);
        }
    }
    else
    {
        if(False)
        {
            False->DoOperation(Value);
        }
    }
    return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


