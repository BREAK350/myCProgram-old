//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Warrior.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Warrior::T_Warrior()
{
    Attack;
}
//---------------------------------------------------------------------------
void T_Warrior::MoveTo(T_Point xy)
{
    if(Active>0 && XY.Distance(xy)<=WalkingRadius)
    {
        XY=xy;
        Active-=1;
    }
}
//---------------------------------------------------------------------------
T_Bang T_Warrior::CreateBang(T_Point p)
{
    if(Active>1 && XY.Distance(p)<=AttackRadius)
    {
        Active-=2;
        return T_Bang(Attack.Accident(ACCIDENT),p);
    }
    return T_Bang();
}
//---------------------------------------------------------------------------
T_Warrior::T_Warrior(char *name,T_Poligon *p,TPoint xy,T_Life l,T_Protection tp,T_Attack a,float wr,float ar)
    :T_StationaryObject(name,p,xy,l,tp)
{
    Attack=a;
    WalkingRadius=wr;
    AttackRadius=ar;
}
//---------------------------------------------------------------------------
T_Warrior::T_Warrior(const T_Warrior &w):T_StationaryObject(w)
{
    Attack=w.Attack;
    WalkingRadius=w.WalkingRadius;
    AttackRadius=w.AttackRadius;
}
//---------------------------------------------------------------------------
T_Warrior& T_Warrior::operator = (const T_Warrior &w)
{
    if(this==&w)
    {
        return *this;
    }
    T_StationaryObject::operator = (w);
    Attack=w.Attack;
    WalkingRadius=w.WalkingRadius;
    AttackRadius=w.AttackRadius;
    return *this;
}
//---------------------------------------------------------------------------
int T_Warrior::nSaveToFile(FILE *f)
{
    int n=nT_Warrior;
    fwrite(&n,sizeof(int),1,f);
    return n;
}
//---------------------------------------------------------------------------
void T_Warrior::SaveToFile(FILE *f)
{
    T_StationaryObject::SaveToFile(f);
    fwrite(&Attack,sizeof(T_Attack),1,f);
    fwrite(&WalkingRadius,sizeof(float),1,f);
    fwrite(&AttackRadius,sizeof(float),1,f);
}
//---------------------------------------------------------------------------
void T_Warrior::LoadFromFile(FILE *f)
{
    T_StationaryObject::LoadFromFile(f);
    fread(&Attack,sizeof(T_Attack),1,f);
    fread(&WalkingRadius,sizeof(float),1,f);
    fread(&AttackRadius,sizeof(float),1,f);
}
//---------------------------------------------------------------------------
char* T_Warrior::GetInfo(int Info)
{
    char Text[300];
    switch(Info)
    {
        case InfoAttack:
            sprintf(Text,"AttackRadius=%1.2f.\n[Fire:%1.2f/%1.2f][Water:%1.2f/%1.2f][Earth:%1.2f/%1.2f][Air:%1.2f/%1.2f]",
            AttackRadius,Attack.Fire.Power,Attack.Fire.Radius,Attack.Water.Power,Attack.Water.Radius,
            Attack.Earth.Power,Attack.Earth.Radius,Attack.Air.Power,Attack.Air.Radius);
            return strdup(Text);
        case InfoAttackFire:
            sprintf(Text,"P: %1.2f. R: %1.2f.",Attack.Fire.Power,Attack.Fire.Radius);
            return strdup(Text);
        case InfoAttackWater:
            sprintf(Text,"P: %1.2f. R: %1.2f.",Attack.Water.Power,Attack.Water.Radius);
            return strdup(Text);
        case InfoAttackEarth:
            sprintf(Text,"P: %1.2f. R: %1.2f.",Attack.Earth.Power,Attack.Earth.Radius);
            return strdup(Text);
        case InfoAttackAir:
            sprintf(Text,"P: %1.2f. R: %1.2f.",Attack.Air.Power,Attack.Air.Radius);
            return strdup(Text);
        case InfoAttackRadius:
            sprintf(Text,"%1.2f",AttackRadius);
            return strdup(Text);
        case InfoWalkingRadius:
            sprintf(Text,"%1.2f",WalkingRadius);
            return strdup(Text);
    }
    return T_StationaryObject::GetInfo(Info);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
