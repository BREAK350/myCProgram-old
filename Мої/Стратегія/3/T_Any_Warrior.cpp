//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Any_Warrior.h"
#pragma package(smart_init)
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
T_Any_Warrior::T_Any_Warrior():XY(0,0),Character(),Picture()
{
    Name=NULL;
    Active=true;
}
//---------------------------------------------------------------------------
T_Any_Warrior::T_Any_Warrior(const T_Any_Warrior &w)
{
    Name=strdup(w.Name);
    XY=w.XY;
    Character=w.Character;
    Active=w.Active;
    Picture=w.Picture;
}
//---------------------------------------------------------------------------
T_Any_Warrior::T_Any_Warrior(char *name,TPoint p,T_Character c,T_Poligon &picture)
{
    Name=strdup(name);
    XY=p;
    Character=c;
    Picture=picture;
    Active=true;
}
//---------------------------------------------------------------------------
T_Any_Warrior& T_Any_Warrior::operator = (const T_Any_Warrior &w)
{
    if(this==&w)
    {
        return *this;
    }
    delete Name;
    Name=strdup(w.Name);
    XY=w.XY;
    Active=w.Active;
    Picture=w.Picture;
    return *this;
}
//---------------------------------------------------------------------------
T_Any_Warrior::~T_Any_Warrior()
{
    delete Name;
    Name=NULL;
}
//---------------------------------------------------------------------------
void T_Any_Warrior::Draw(TCanvas *Canvas,TPoint p,float s)
{
    TColor cl;
    if(isLive())
    {
        TPoint d(XY.x*s+p.x,XY.y*s+p.y);
        cl=Picture.clBrush;
        if(!Active)
        {
            Picture.clBrush=clGray;
        }
        Picture.Draw(Canvas,d,s,0);
        Picture.clBrush=cl;
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
