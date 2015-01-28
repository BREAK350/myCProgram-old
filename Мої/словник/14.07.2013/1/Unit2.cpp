//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void TbWord::Show(TMemo *English,TMemo *Ukranian)
{
    English->Lines->Clear();
    English->Lines->Add(Eng.ToChar());
    Ukranian->Lines->Clear();
    Ukranian->Lines->Add(Eng.ToChar());
}
//---------------------------------------------------------------------------
void TbBloc::LoadFromFile(FILE *File)
{
    int Count;
    Words.DeleteAll();
    fread(&Count,sizeof(int),1,File);
    TbWord w;
    for(int i=0;i<Count;i++)
    {
        w.LoadFromFile(File);
        Words.AddLast(w);
    }
    fseek(File,0,SEEK_END);
    Size=ftell(File);
}
//---------------------------------------------------------------------------
void TbBloc::SaveToFile(FILE *File)
{
    int Count=Words.GetCount();
    fwrite(&Count,sizeof(int),1,File);
    Words.CurrSetFirst();
    for(int i=0;i<Count;i++)
    {
        Words.GetCurr().SaveToFile(File);
        Words.CurrSetNext();
    }
}
//---------------------------------------------------------------------------
TbBloc::TbBloc()
{
    Size=0;
    Modified=false;
    FILE *File=fopen(FILECONFIGURATION,"rb");
    if(File)
    {
        fread(&LastFileNumber,sizeof(int),1,File);
        fclose(File);
    }
    else
    {
        LastFileNumber=0;
        File=fopen(FILECONFIGURATION,"wb");
        fwrite(&LastFileNumber,sizeof(int),1,File);
        fclose(File);

    }
    FileNumber=-1;
}
//---------------------------------------------------------------------------
int TbBloc::LoadFromFile(const int &FileNumber)
{
    int q=0;
    if(FileNumber>=0 && FileNumber<LastFileNumber)
    {
        q=1;
        this->FileNumber=FileNumber;
        FILE *File=fopen(IntToStr(this->FileNumber).c_str(),"rb");
        LoadFromFile(File);
        fclose(File);
        Modified=false;
    }
    return q;
}
//---------------------------------------------------------------------------
void TbBloc::SearchEngFileNumber(const TbBaseString &Eng)
{
    if(LastFileNumber>0)
    {
        if(FileNumber<0 || FileNumber>=LastFileNumber)
        {
            LoadFromFile(0);
        }
        int q=1;
        while(q)
        {
            Words.CurrSetFirst();
            if(Words.GetCurr().Eng<Eng)
            {
                q=LoadFromFile(FileNumber-1);
            }
            else
            {
                Words.CurrSetLast();
                if(Words.GetCurr().Eng>Eng)
                {
                    q=LoadFromFile(FileNumber+1);
                }
            }
        }
    }
}
//---------------------------------------------------------------------------
void TbBloc::SearchUkrFileNumber(const TbBaseString &Ukr)
{
    if(LastFileNumber>0)
    {
        if(FileNumber<0 || FileNumber>=LastFileNumber)
        {
            LoadFromFile(0);
        }
        int q=1;
        while(q)
        {
            Words.CurrSetFirst();
            if(Words.GetCurr().Ukr<Ukr)
            {
                q=LoadFromFile(FileNumber-1);
            }
            else
            {
                Words.CurrSetLast();
                if(Words.GetCurr().Ukr>Ukr)
                {
                    q=LoadFromFile(FileNumber+1);
                }
            }
        }
    }
}
//---------------------------------------------------------------------------
void TbBloc::SaveToFile()
{
    if(FileNumber>=0 && FileNumber<LastFileNumber && Modified)
    {
        FILE *File=fopen(IntToStr(FileNumber).c_str(),"wb");
        SaveToFile(File);
        fclose(File);
    }
}
//---------------------------------------------------------------------------
TbList2 <TbWord>* TbBloc::SearchEng(const TbBaseString &Eng)
{
    TbList2 <TbWord> *R=new TbList2 <TbWord> ();
    for(FileNumber=0;FileNumber<LastFileNumber;FileNumber++)
    {
        int i=0,Count=Words.GetCount();
        this->LoadFromFile(FileNumber);
        Words.CurrSetFirst();
        while(i<Count)
        {
            if(Words.GetCurr().Eng.Search(Eng))
            {
                R->AddLast(Words.GetCurr());
            }
            Words.CurrSetNext();
        }
    }
    return R;
}
//---------------------------------------------------------------------------
TbDictionary::TbDictionary()
{
    LoadFromFile(FNAME);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TbDictionary::LoadFromFile(FILE *File)
{
    int Count;
    Words.DeleteAll();
    fread(&Count,sizeof(int),1,File);
    TbWord w;
    for(int i=0;i<Count;i++)
    {
        w.LoadFromFile(File);
        Words.AddLast(w);
    }
}
//---------------------------------------------------------------------------
void TbDictionary::SaveToFile(FILE *File)
{
    int Count=Words.GetCount();
    fwrite(&Count,sizeof(int),1,File);
    Words.CurrSetFirst();
    for(int i=0;i<Count;i++)
    {
        Words.GetCurr().SaveToFile(File);
        Words.CurrSetNext();
    }
}
//---------------------------------------------------------------------------
void TbDictionary::SearchEng(const TbBaseString &Eng,const bool &Again)
{
    if(Again)
    {
        Words.CurrSetFirst();
    }
    else
    {
        Words.CurrSetNext();
    }
    while(Words.CurrCorect() && Words.GetCurr().Eng.Search(Eng)==false)
    {
        Words.CurrSetNext();
    }
}
//---------------------------------------------------------------------------
void TbDictionary::SearchUkr(const TbBaseString &Ukr,const bool &Again)
{
    if(Again)
    {
        Words.CurrSetFirst();
    }
    else
    {
        Words.CurrSetNext();
    }
    while(Words.CurrCorect() && Words.GetCurr().Ukr.Search(Ukr)==false)
    {
        Words.CurrSetNext();
    }
}
//---------------------------------------------------------------------------
void TbDictionary::Add(const TbWord &Word)
{
    Words.AddLast(Word);
}
//---------------------------------------------------------------------------
void TbDictionary::LoadFromFile(const char *fname)
{
    FILE *File=fopen(fname,"rb");
    if(File)
    {
        LoadFromFile(File);
        fclose(File);
    }
}
//---------------------------------------------------------------------------
void TbDictionary::SaveToFile(const char *fname)
{
    FILE *File=fopen(fname,"wb");
    SaveToFile(File);
    fclose(File);
}
//---------------------------------------------------------------------------
bool TbDictionary::GetCurr(TbWord &Word)const
{
    if(Words.CurrCorect())
    {
        Word=Words.GetCurr();
    }
    return Words.CurrCorect();
}
//---------------------------------------------------------------------------
bool TbDictionary::DeleteCurr()
{
    return Words.DeleteCurr();
}
//---------------------------------------------------------------------------
bool TbDictionary::EditCurr(const TbWord &Word)
{
    if(Words.CurrCorect())
    {
        Words.GetCurr()=Word;
    }
    return Words.CurrCorect();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
