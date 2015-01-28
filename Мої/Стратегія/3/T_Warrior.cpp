//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Warrior.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Warrior& T_Warrior::operator = (const T_Any_Warrior &w)
{
    if(this==&w)
    {
        return *this;
    }
    T_Any_Warrior::operator = (w);
    return *this;
}
//---------------------------------------------------------------------------
T_Warrior::~T_Warrior()
{
    delete Name;
    Name=NULL;
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
void T_Warrior::Attack(T_Any_Warrior *Warrior,T_Character Bonus)
{
    float a,p;
    if(isAttack(Warrior))
    {
        a=GetAttack(ACCIDENT)*(Bonus.Attack+1);
        p=Warrior->GetProtcion(ACCIDENT);
        Warrior->Character.Life-=(a-p>0)?(a-p):(0);
        Active=false;
    }
}
//---------------------------------------------------------------------------
bool T_Warrior::isAttack(T_Any_Warrior *w)
{
    if(Active && this!=w && sqrt((XY.x-w->XY.x)*(XY.x-w->XY.x)+(XY.y-w->XY.y)*(XY.y-w->XY.y))<=Character.Radius)
    {
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------
T_Doctor& T_Doctor::operator = (const T_Any_Warrior &w)
{
    if(this==&w)
    {
        return *this;
    }
    T_Any_Warrior::operator = (w);
    return *this;
}
//---------------------------------------------------------------------------
bool T_Doctor::isMove(TPoint move)
{
    if(Active && sqrt((move.x-XY.x)*(move.x-XY.x)+(move.y-XY.y)*(move.y-XY.y))<=Character.Speed)
    {
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------
void T_Doctor::Move(TPoint move)
{
    if(isMove(move))
    {
        XY=move;
        Active=false;
    }
}
//---------------------------------------------------------------------------
void T_Doctor::Attack(T_Any_Warrior *Warrior,T_Character Bonus)
{
    if(isAttack(Warrior))
    {
        Warrior->Character.Life+=GetAttack(20);
        Active=false;
    }
}
//---------------------------------------------------------------------------
bool T_Doctor::isAttack(T_Any_Warrior *w)
{
    if(Active && this!=w && sqrt((XY.x-w->XY.x)*(XY.x-w->XY.x)+(XY.y-w->XY.y)*(XY.y-w->XY.y))<=Character.Radius)
    {
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------
float T_Warrior::GetAttack(int p)
{
    randomize();
    return Character.Attack*(float)(random(2*p+1)+100-p)/100.0;
}
//---------------------------------------------------------------------------
float T_Warrior::GetProtcion(int p)
{
    randomize();
    return Character.Protection*(float)(random(2*p+1)+100-p)/100.0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
