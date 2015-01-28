//---------------------------------------------------------------------------
#pragma hdrstop
#include "button.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void TbButton::LoadFromFile(ifstream &ifs)
{
    int Count;
    char buf[64];

    ifs>>Count;
    Point.SetCount(Count);
    for(int i=0;i<Count;i++)
    {
        ifs>>Point[i].x>>Point[i].y;
    }

    ifs>>Count;
    AddWord.SetCount(Count);
    for(int i=0;i<Count;i++)
    {
        ifs>>buf;
        AddWord[i]=buf;
    }

    ifs>>Count;
    NeedWord.SetCount(Count);
    for(int i=0;i<Count;i++)
    {
        ifs>>buf;
        NeedWord[i]=buf;
    }

    ifs>>buf;
    Next=buf;
}
//---------------------------------------------------------------------------
int SearchWord(const string &sw,TbList2 < string > &Word)
{
    int q=0;
    Word.CurrSetFirst();
    while(q==0 && Word.CurrCorrect())
    {
        if(Word.GetCurr()==sw)
        {
            q=1;
        }
        else
        {
            Word.CurrSetNext();
        }
    }
    return q;
}
//---------------------------------------------------------------------------
void TbButton::Add(TbList2 < string > &Word)
{
    for(int i=0;i<AddWord.GetCount();i++)
    {
        if(SearchWord(AddWord[i],Word)==0)
        {
            Word.AddLast(AddWord[i]);
        }
    }
}
//---------------------------------------------------------------------------
int TbButton::onClick(const TPoint &p,string &GameAddress,TbList2 < string > &Word)
{
    int q=0;
    if(isBelongPoligon(p))
    {
        q=1;
        for(int i=0;i<NeedWord.GetCount();i++)
        {
            q=q*SearchWord(NeedWord[i],Word);
        }
        if(q==1)
        {
            GameAddress=Next;
            Add(Word);
        }
    }
    return q;
}
//---------------------------------------------------------------------------
int TbButton::isBelongPoligon(const TPoint &p)
{
    int q=0,n=Point.GetCount();
    double Angle=0;
    T_Vector2d v0(Point[0]),v1;
    v0=v0-p;
    for(int i=1;i<n;i++)
    {
        v1=Point[i];
        v1=v1-p;
        Angle+=v0.AngleBetween(v1);
        v0=v1;
    }
    v0=Point[0];
    v0=v0-p;
    Angle+=v0.AngleBetween(v1);
    if(Angle+0.1>=2*M_PI)
    {
        q=1;
    }
    return q;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
