//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Minery.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Minery::T_Minery():T_StationaryObject(),Resource()
{
}
//---------------------------------------------------------------------------
T_Minery::T_Minery(const T_Minery &m):T_StationaryObject(m)
{
    Resource=m.Resource;
}
//---------------------------------------------------------------------------
T_Minery::T_Minery(char *name,T_Poligon *p,TPoint xy,T_Life l,T_Protection pr,T_Resource r)
    :T_StationaryObject(name,p,xy,l,pr)
{
    Resource=r;
}
//---------------------------------------------------------------------------
T_Minery& T_Minery::operator = (const T_Minery &m)
{
    if(this==&m)
    {
        return *this;
    }
    T_StationaryObject::operator = (m);
    Resource=m.Resource;
    return *this;
}
//---------------------------------------------------------------------------
T_Resource T_Minery::GetResource()
{
    if(Active>0)
    {
        Active=0;
        return Resource;
    }
    return T_Resource();
}
//---------------------------------------------------------------------------
int T_Minery::nSaveToFile(FILE *f)
{
    int n=nT_Minery;
    fwrite(&n,sizeof(int),1,f);
    return n;
}
//---------------------------------------------------------------------------
void T_Minery::SaveToFile(FILE *f)
{
    T_StationaryObject::SaveToFile(f);
    fwrite(&Resource,sizeof(T_Resource),1,f);
}
//---------------------------------------------------------------------------
void T_Minery::LoadFromFile(FILE *f)
{
    T_StationaryObject::LoadFromFile(f);
    fread(&Resource,sizeof(T_Resource),1,f);
}
//---------------------------------------------------------------------------
char* T_Minery::GetInfo(int Info)
{
    char Text[300];
    switch(Info)
    {
        case InfoResource:
            sprintf(Text,"");
    }
    return T_StationaryObject::GetInfo(Info);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
