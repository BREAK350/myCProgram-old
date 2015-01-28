//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit5.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbBullCow::TbBullCow(const char *Component,const int &Found)
{
    CountPr=0;
    CountCom=1;
    this->Found=Found;
    this->Component[0]=TbCPlural_char(Component,Found);
}
//---------------------------------------------------------------------------
bool TbBullCow::SearchProgress(const TbBCPlural_char &BCPl)
{
    int i=0;
    while(i<CountPr && Progress[i]!=BCPl)
    {
        i++;
    }
    return i<CountPr;
}
//---------------------------------------------------------------------------
void TbBullCow::SetNext(const TbPlural_char &CPl,const int &Cow,const int &Bull)
{
    if(CountPr<MAXpr && SearchProgress(CPl)==false)
    {
        //Progress[CountPr]=TbBCPlural_char(BCPl.TbPlural_char::GetStr(),Cow+Bull,Bull);
        CountPr++;
    }
}
//---------------------------------------------------------------------------
TbPlural_char TbBullCow::GetNext()
{
    TbPlural_char res;
    if(Component[0].GetCount()>Found)
    {
        int i;
        TbCPlural_char a(Found);
        for(i=0;i<Found;i++)
        {
            a[i]=res[i];
        }
        Component[0]=Component[0]-a;
        Component[CountCom]=a;
        CountCom++;
        res=a;
    }
    return res;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
