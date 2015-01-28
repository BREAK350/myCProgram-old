//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Warrior.h"
#pragma package(smart_init)
#include <math.h>
//---------------------------------------------------------------------------
T_Character::T_Character(float l,float a,float p,float r,float s)
{
    Life=l;
    Attack=a;
    Protection=p;
    Radius=r;
    Speed=s;
}
//---------------------------------------------------------------------------
T_Character::T_Character()
{
    Life=0;
    Attack=0;
    Protection=0;
    Radius=0;
    Speed=0;
}
//---------------------------------------------------------------------------
bool T_Warrior::isMove(TPoint move)
{
    if(Active && sqrt((move.x-XY.x)*(move.x-XY.x)+(move.y-XY.y)*(move.y-XY.y))<=Character.Speed)
    {
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------
void T_Warrior::Move(TPoint move)
{
    if(isMove(move))
    {
        XY=move;
        Active=false;
    }
}
//---------------------------------------------------------------------------
void T_Warrior::Attack(T_Warrior *Warrior)
{
    if(isAttack(Warrior))
    {
        Warrior->Character.Life-=(Character.Attack-Warrior->Character.Protection>0)?(Character.Attack-Warrior->Character.Protection):(0);
        Active=false;
    }
}
//---------------------------------------------------------------------------
bool T_Warrior::isAttack(T_Warrior *w)
{
    if(Active && this!=w && LinkCommander->Nation!=w->LinkCommander->Nation && sqrt((XY.x-w->XY.x)*(XY.x-w->XY.x)+(XY.y-w->XY.y)*(XY.y-w->XY.y))<=Character.Radius)
    {
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------
T_Warrior::T_Warrior():XY(0,0),Character()
{
    Name=NULL;
    Active=true;
}
//---------------------------------------------------------------------------
T_Warrior::T_Warrior(const T_Warrior &w)
{
    Name=strdup(w.Name);
    XY=w.XY;
    Active=w.Active;
}
//---------------------------------------------------------------------------
T_Warrior::T_Warrior(char *name,TPoint p,T_Character c)
{
    Name=strdup(name);
    XY=p;
    Character=c;
}
//---------------------------------------------------------------------------
T_Warrior& T_Warrior::operator = (const T_Warrior &w)
{
    if(this==&w)
    {
        return *this;
    }
    delete Name;
    Name=strdup(w.Name);
    XY=w.XY;
    Active=w.Active;
    return *this;
}
//---------------------------------------------------------------------------
T_Warrior::~T_Warrior()
{
    delete Name;
    Name=NULL;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
