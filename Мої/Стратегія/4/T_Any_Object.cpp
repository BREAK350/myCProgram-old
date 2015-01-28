//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Any_Object.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Any_Object::T_Any_Object():XY(0,0)
{
    Name[0]=0;
    Picture=NULL;
    isDraw=no;
    Active=MAX_ACTIVE;
}
//---------------------------------------------------------------------------
void T_Any_Object::Draw(TCanvas *Canvas,T_Point Centre,float s,float angle)
{
    if(Picture)
    {
        Picture->Draw(Canvas,T_Point((XY.GetX()-Centre.GetX())*s,(XY.GetY()-Centre.GetY())*s),s,angle);
        isDraw=yes;
        //Canvas->TextOutA(XY.GetX(),XY.GetY()+s,Name);
    }
}
//---------------------------------------------------------------------------
bool T_Any_Object::isHere(T_Point w)
{
    return w==XY;
}
//---------------------------------------------------------------------------
T_Attack T_Attack::Accident(int k)
{
    int p;
    T_Attack A;
    randomize();
    p=random(2*k+1);
    A.Fire.Power=Fire.Power*(100-k+p)/100;
    A.Fire.Radius=Fire.Radius;
    p=random(2*k+1);
    A.Water.Power=Water.Power*(100-k+p)/100;
    A.Water.Radius=Water.Radius;
    p=random(2*k+1);
    A.Earth.Power=Earth.Power*(100-k+p)/100;
    A.Earth.Radius=Earth.Radius;
    p=random(2*k+1);
    A.Air.Power=Air.Power*(100-k+p)/100;
    A.Air.Radius=Air.Radius;
    return A;
}
//---------------------------------------------------------------------------
T_Any_Object::T_Any_Object(char *name,T_Poligon *p,TPoint xy)
{
    strncpy(Name,name,10);
    Picture=p;
    XY=xy;
    isDraw=no;
    Active=MAX_ACTIVE;
}
//---------------------------------------------------------------------------
T_Any_Object::T_Any_Object(const T_Any_Object &ao)
{
    Picture=ao.Picture;
    XY=ao.XY;
    isDraw=ao.isDraw;
    Active=ao.Active;
}
//---------------------------------------------------------------------------
T_Any_Object::~T_Any_Object()
{
    Picture=NULL;
    isDraw=no;
    Active=0;
}
//---------------------------------------------------------------------------
T_Any_Object& T_Any_Object::operator = (const T_Any_Object &ao)
{
    if(this==&ao)
    {
        return *this;
    }
    Picture=ao.Picture;
    XY=ao.XY;
    isDraw=ao.isDraw;
    Active=ao.Active;
    return *this;
}
//---------------------------------------------------------------------------
int T_Any_Object::nSaveToFile(FILE *f)
{
    int n=nT_Any_Object;
    fwrite(&n,sizeof(int),1,f);
    return n;
}
//---------------------------------------------------------------------------
void T_Any_Object::SaveToFile(FILE *f)
{
    fwrite(Name,sizeof(char),10,f);
    fwrite(&XY,sizeof(T_Point),1,f);
}
//---------------------------------------------------------------------------
void T_Any_Object::LoadFromFile(FILE *f)
{
    fread(Name,sizeof(char),10,f);
    fread(&XY,sizeof(T_Point),1,f);
}
//---------------------------------------------------------------------------
char* T_Any_Object::GetInfo(int Info)
{
    char Text[100];
    switch(Info)
    {
        case InfoName:
            return strdup(Name);
        case InfoXY:
            sprintf(Text,"[%1.2f;%1.2f]",XY.GetX(),XY.GetY());
            return strdup(Text);
    }
    return NULL;
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

