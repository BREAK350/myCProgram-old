//---------------------------------------------------------------------------
#pragma hdrstop
#include "Training.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_TrainingElement::T_TrainingElement()
{
    SizeName=0;
    Name=NULL;
    AllAmount=MaxAmount=AmountDay=0;
}
//---------------------------------------------------------------------------
T_TrainingElement::T_TrainingElement(const T_TrainingElement &te)
{
    SizeName=te.SizeName;
    Name=strdup(te.Name);
    AllAmount=te.AllAmount;
    MaxAmount=te.MaxAmount;
    AmountDay=te.AmountDay;
}
//---------------------------------------------------------------------------
T_TrainingElement::~T_TrainingElement()
{
    delete Name;
    SizeName=0;
    Name=NULL;
    AllAmount=MaxAmount=AmountDay=0;
}
//---------------------------------------------------------------------------
void T_TrainingElement::SaveToFile(FILE *f)
{
    fwrite(&SizeName,sizeof(int),1,f);
    fwrite(Name,sizeof(char),SizeName,f);
    fwrite(&AllAmount,sizeof(int),1,f);
    fwrite(&MaxAmount,sizeof(int),1,f);
    fwrite(&AmountDay,sizeof(int),1,f);
}
//---------------------------------------------------------------------------
void T_TrainingElement::LoadFromFile(FILE *f)
{
    delete Name;
    fread(&SizeName,sizeof(int),1,f);
    Name=new char[SizeName];
    fread(Name,sizeof(char),SizeName,f);
    fread(&AllAmount,sizeof(int),1,f);
    fread(&MaxAmount,sizeof(int),1,f);
    fread(&AmountDay,sizeof(int),1,f);
}
//---------------------------------------------------------------------------
T_Training::T_Training()
{
    Amount=0;
    Element=NULL;
}
//---------------------------------------------------------------------------
T_Training::T_Training(const T_Training &t)
{
    int i;
    Amount=t.Amount;
    if(Amount==0)
    {
        Element=NULL;
        return;
    }
    Element=new T_TrainingElement[Amount];
    for(i=0;i<Amount;i++)
    {
        Element[i]=t.Element[i];
    }
}
//---------------------------------------------------------------------------
T_TrainingElement& T_TrainingElement::operator = (const T_TrainingElement &te)
{
    if(this!=&te)
    {
        SizeName=te.SizeName;
        Name=strdup(te.Name);
        AllAmount=te.AllAmount;
        MaxAmount=te.MaxAmount;
        AmountDay=te.AmountDay;
    }
    return *this;
}
//---------------------------------------------------------------------------
T_Training::~T_Training()
{
    delete[] Element;
    Element=NULL;
    Amount=0;
}
//---------------------------------------------------------------------------
void T_Training::SaveToFile(FILE *f)
{
    int i;
    fwrite(&Amount,sizeof(int),1,f);
    for(i=0;i<Amount;i++)
    {
        Element[i].SaveToFile(f);
    }
}
//---------------------------------------------------------------------------
void T_Training::LoadFromFile(FILE *f)
{
    int i;
    delete[] Element;
    fread(&Amount,sizeof(int),1,f);
    if(Amount==0)
    {
        Element=NULL;
        return;
    }
    Element=new T_TrainingElement[Amount];
    for(i=0;i<Amount;i++)
    {
        Element[i].LoadFromFile(f);
    }
}
//---------------------------------------------------------------------------
void T_Training::AddElement(char *name)
{
    int i;
    T_TrainingElement *buf=new T_TrainingElement[Amount];
    for(i=0;i<Amount;i++)
    {
        buf[i]=Element[i];
    }
    delete[] Element;
    Element=new T_TrainingElement[Amount+1];
    for(i=0;i<Amount;i++)
    {
        Element[i]=buf[i];
    }
    Element[i].GiveName(name);
    Amount++;
    delete[] buf;
}
//---------------------------------------------------------------------------
void T_Training::DeleteElement(int k)
{
    int i;
    if(k<0 || k>=Amount)
    {
        return;
    }
    T_TrainingElement *buf=new T_TrainingElement[Amount-1];
    for(i=0;i<k;i++)
    {
        buf[i]=Element[i];
    }
    for(;i<Amount-1;i++)
    {
        buf[i]=Element[i+1];
    }
    delete[] Element;
    Amount--;
    Element=new T_TrainingElement[Amount];
    for(i=0;i<Amount;i++)
    {
        Element[i]=buf[i];
    }
    delete[] buf;
}
//---------------------------------------------------------------------------
void T_Training::DeleteElement(char *name)
{
    DeleteElement(SearchNumber(name));
}
//---------------------------------------------------------------------------
void T_Training::DoTraining(int k,int n)
{
    if(k<0 || k>=Amount)
    {
        return;
    }
    Element[k].AllAmount+=n;
    if(n>Element[k].MaxAmount)
    {
        Element[k].MaxAmount=n;
    }
    Element[k].AmountDay++;
}
//---------------------------------------------------------------------------
int T_Training::SearchNumber(char *name)
{
    int i=0;
    while(i<Amount && strcmp(name,Element[i].Name)!=0)
    {
        i++;
    }
    return i;
}
//---------------------------------------------------------------------------
T_TrainingElement T_Training::operator [] (int k)
{
    if(k<0 || k>=Amount)
    {
        return T_TrainingElement();
    }
    return Element[k];
}
//---------------------------------------------------------------------------
ostream& operator << (ostream &os,T_TrainingElement &te)
{
    os<<"Назва:                     "<<te.Name<<endl;
    os<<"Всього зроблено:           "<<te.AllAmount<<endl;
    os<<"Максимальна кількість раз: "<<te.MaxAmount<<endl;
    os<<"Кількість днів:            "<<te.AmountDay<<endl;
    return os;
}
//---------------------------------------------------------------------------
void T_Training::SaveToFile(char *fname)
{
    FILE *f;
    f=fopen(fname,"wb");
    SaveToFile(f);
    fclose(f);
}
//---------------------------------------------------------------------------
bool T_Training::LoadFromFile(char *fname)
{
    FILE *f;
    f=fopen(fname,"rb");
    if(f)
    {
        LoadFromFile(f);
        return true;
    }
    fclose(f);
    return false;
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

