//---------------------------------------------------------------------------
#pragma hdrstop
#include "Data.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbData::TbData(const time_t &t,const double &end,const double &begin,const double &price)
{
    this->t=t;
    this->end=end;
    this->begin=begin;
    this->price=price;
}
//---------------------------------------------------------------------------
void SaveToFile(FILE *File,const TbData &Data)
{
    fwrite(&Data,sizeof(TbData),1,File);
}
//---------------------------------------------------------------------------
void LoadFromFile(FILE *File,TbData &Data)
{
    fread(&Data,sizeof(TbData),1,File);
}
//---------------------------------------------------------------------------
void SaveToFile(FILE *File,const int &n,const TbData *Data)
{
    fwrite(&n,sizeof(int),1,File);
    for(int i=0;i<n;i++)
    {
        SaveToFile(File,Data[i]);
    }
}
//---------------------------------------------------------------------------
void LoadFromFile(FILE *File,int &n,TbData *&Data)
{
    if(Data==NULL)
    {
        fread(&n,sizeof(int),1,File);
        Data=new TbData [n+ADDER];
        for(int i=0;i<n;i++)
        {
            LoadFromFile(File,Data[i]);
        }
    }
}
//---------------------------------------------------------------------------
void SaveToFile(const char *FileName,const int &n,const TbData *Data)
{
    FILE *F=fopen(FileName,"wb");
    SaveToFile(F,n,Data);
    fclose(F);
}
//---------------------------------------------------------------------------
void LoadFromFile(const char *FileName,int &n,TbData *&Data)
{
    FILE *F=fopen(FileName,"rb");
    if(F)
    {
        LoadFromFile(F,n,Data);
        fclose(F);
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
