//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_StationaryObject.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_StationaryObject::T_StationaryObject():T_Any_Object()
{
}
//---------------------------------------------------------------------------
void T_StationaryObject::AfterBang(T_Bang Bang)
{
    float P,A=0;
    float Distance;
    Distance=XY.Distance(Bang.XY);
    if(Distance<Bang.Attack.Fire.Radius)
    {
        P=Bang.Attack.Fire.Power*(Bang.Attack.Fire.Radius-Distance)/Bang.Attack.Fire.Radius;
        if(P>0)
        {
            A+=(P>Protection.Fire.Power)?(P-Protection.Fire.Power):(0);
        }
        else
        {
            A+=P;
        }
    }
    if(Distance<Bang.Attack.Water.Radius)
    {
        P=Bang.Attack.Water.Power*(Bang.Attack.Water.Radius-Distance)/Bang.Attack.Water.Radius;
        if(P>0)
        {
            A+=(P>Protection.Water.Power)?(P-Protection.Water.Power):(0);
        }
        else
        {
            A+=P;
        }
    }
    if(Distance<Bang.Attack.Earth.Radius)
    {
        P=Bang.Attack.Earth.Power*(Bang.Attack.Earth.Radius-Distance)/Bang.Attack.Earth.Radius;
        if(P>0)
        {
            A+=(P>Protection.Earth.Power)?(P-Protection.Earth.Power):(0);
        }
        else
        {
            A+=P;
        }
    }
    if(Distance<Bang.Attack.Air.Radius)
    {
        P=Bang.Attack.Air.Power*(Bang.Attack.Air.Radius-Distance)/Bang.Attack.Air.Radius;
        if(P>0)
        {
            A+=(P>Protection.Air.Power)?(P-Protection.Air.Power):(0);
        }
        else
        {
            A+=P;
        }
    }
    Life.Health-=A;
    if(Life.Health>Life.MaxHealth)
    {
        Life.Health=Life.MaxHealth;
    }
}
//---------------------------------------------------------------------------
T_StationaryObject::T_StationaryObject(char *name,T_Poligon *p,TPoint xy,T_Life l,T_Protection tp):T_Any_Object(name,p,xy)
{
    Life=l;
    Protection=tp;
}
//---------------------------------------------------------------------------
T_StationaryObject::T_StationaryObject(const T_StationaryObject &so):T_Any_Object(so)
{
    Life=so.Life;
    Protection=so.Protection;
}
//---------------------------------------------------------------------------
T_StationaryObject::~T_StationaryObject()
{
}
//---------------------------------------------------------------------------
T_StationaryObject& T_StationaryObject::operator = (const T_StationaryObject &so)
{
    if(this==&so)
    {
        return *this;
    }
    T_Any_Object::operator = (so);
    Life=so.Life;
    Protection=so.Protection;
    return *this;
}
//---------------------------------------------------------------------------
int T_StationaryObject::nSaveToFile(FILE *f)
{
    int n=nT_StationaryObject;
    fwrite(&n,sizeof(int),1,f);
    return n;
}
//---------------------------------------------------------------------------
void T_StationaryObject::SaveToFile(FILE *f)
{
    T_Any_Object::SaveToFile(f);
    fwrite(&Life,sizeof(T_Life),1,f);
    fwrite(&Protection,sizeof(T_Protection),1,f);
}
//---------------------------------------------------------------------------
void T_StationaryObject::LoadFromFile(FILE *f)
{
    T_Any_Object::LoadFromFile(f);
    fread(&Life,sizeof(T_Life),1,f);
    fread(&Protection,sizeof(T_Protection),1,f);
}
//---------------------------------------------------------------------------
char* T_StationaryObject::GetInfo(int Info)
{
    char Text[300];
    switch(Info)
    {
        case InfoLife:
            sprintf(Text,"%1.2f/%1.2f",Life.Health,Life.MaxHealth);
            return strdup(Text);
        case InfoProtection:
            sprintf(Text,"[Fire:%1.2f/%1.2f][Water:%1.2f/%1.2f][Earth:%1.2f/%1.2f][Air:%1.2f/%1.2f]",
            Protection.Fire.Power,Protection.Fire.Radius,Protection.Water.Power,Protection.Water.Radius,
            Protection.Earth.Power,Protection.Earth.Radius,Protection.Air.Power,Protection.Air.Radius);
            return strdup(Text);
        case InfoProtectionFire:
            sprintf(Text,"P: %1.2f. R: %1.2f.",Protection.Fire.Power,Protection.Fire.Radius);
            return strdup(Text);
        case InfoProtectionWater:
            sprintf(Text,"P: %1.2f. R: %1.2f.",Protection.Water.Power,Protection.Water.Radius);
            return strdup(Text);
        case InfoProtectionEarth:
            sprintf(Text,"P: %1.2f. R: %1.2f.",Protection.Earth.Power,Protection.Earth.Radius);
            return strdup(Text);
        case InfoProtectionAir:
            sprintf(Text,"P: %1.2f. R: %1.2f.",Protection.Air.Power,Protection.Air.Radius);
            return strdup(Text);
    }
    return T_Any_Object::GetInfo(Info);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
