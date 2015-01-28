//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbString.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbBaseString::TbBaseString(const char *row)
{
    if(row)
    {
        this->row=strdup(row);
        length=strlen(this->row);
    }
    else
    {
        row=NULL;
        length=0;
    }
}
//---------------------------------------------------------------------------
TbBaseString::TbBaseString(const TbBaseString &BaseString)
{
    length=BaseString.length;
    if(length)
    {
        row=strdup(BaseString.row);
    }
    else
    {
        row=NULL;
    }
}
//---------------------------------------------------------------------------
TbBaseString::~TbBaseString()
{
    if(length)
    {
        delete[] row;
        row=NULL;
        length=0;
    }
}
//---------------------------------------------------------------------------
TbBaseString& TbBaseString::operator = (const TbBaseString &BaseString)
{
    if(this!=&BaseString)
    {
        if(length)
        {
            delete[] row;
        }
        length=BaseString.length;
        if(length)
        {
            row=strdup(BaseString.row);
        }
        else
        {
            row=NULL;
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
bool TbBaseString::operator == (const TbBaseString &BaseString)const
{
    bool q=false;
    if(row && BaseString.row)
    {
        if(strcmp(row,BaseString.row)==0)
        {
            q=true;
        }
    }
    return q;
}
//---------------------------------------------------------------------------
bool TbBaseString::operator < (const TbBaseString &BaseString)const
{
    bool q=false;
    if(row && BaseString.row)
    {
        if(strcmp(row,BaseString.row)<0)
        {
            q=true;
        }
    }
    return q;
}
//---------------------------------------------------------------------------
bool TbBaseString::operator > (const TbBaseString &BaseString)const
{
    bool q=false;
    if(row && BaseString.row)
    {
        if(strcmp(row,BaseString.row)>0)
        {
            q=true;
        }
    }
    return q;
}
//---------------------------------------------------------------------------
void TbBaseString::SaveToFile(FILE *File)const
{
    fwrite(&length,sizeof(int),1,File);
    if(length)
    {
        fwrite(row,sizeof(char),length,File);
    }
}
//---------------------------------------------------------------------------
void TbBaseString::LoadFromFile(FILE *File)
{
    if(length)
    {
        delete[] row;
    }
    fread(&length,sizeof(int),1,File);
    if(length)
    {
        row=new char [length+1];
        fread(row,sizeof(char),length,File);
        row[length]=0;
    }
    else
    {
        row=NULL;
    }
}
//---------------------------------------------------------------------------
bool TbBaseString::Search(const TbBaseString &BaseString)const
{
    return Search(BaseString.row);
}
//---------------------------------------------------------------------------
char* TbBaseString::SearchPlace(const char *row)const
{
    return strstr(this->row,row);
}
//---------------------------------------------------------------------------
bool TbBaseString::Search(const char *row)const
{
    bool q=false;
    if(SearchPlace(row))
    {
        q=true;
    }
    return q;
}
//---------------------------------------------------------------------------
void TbBaseString::Union(const TbBaseString &BaseString)
{
    if(BaseString.length)
    {
        int unionlength=length+BaseString.length;
        if(length)
        {
            char *buf=new char [unionlength];
            strcpy(buf,row);
            strcpy(&buf[length],BaseString.row);
            delete[] row;
            row=buf;
        }
        else
        {
            row=strdup(BaseString.row);
        }
        length=unionlength;
    }
}
//---------------------------------------------------------------------------
void TbBaseString::Union(const char *row)
{
    Union(TbBaseString(row));
}
//---------------------------------------------------------------------------
TbBaseString TbBaseString::SeparateBegin(const TbBaseString &Separator)
{
    TbBaseString r;
    //char *sp=SearchPlace(Separator.row);
    
    return r;
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

