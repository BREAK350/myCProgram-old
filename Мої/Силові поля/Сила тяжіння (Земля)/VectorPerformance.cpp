//---------------------------------------------------------------------------
#pragma hdrstop
#include "VectorPerformance.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Gravity::T_Gravity():Centre(0,0)
{
    minRadius=0;
    maxRadius=0;
    Power=0;
}
//---------------------------------------------------------------------------
T_Gravity::T_Gravity(const T_Vector &c,const float &min,const float &max,
    const float &p):Centre(c)
{
    SetRadius(min,max);
    Power=p;
    Angle=0;
}
//---------------------------------------------------------------------------
T_Gravity::T_Gravity(const T_Gravity &g):Centre(g.Centre)
{
    minRadius=g.minRadius;
    maxRadius=g.maxRadius;
    Power=g.Power;
}
//---------------------------------------------------------------------------
void T_Gravity::Interaction(T_AnyVector &av)const
{
    av=av+GetPowerVector(av.GetBegin());
}
//---------------------------------------------------------------------------
T_Vector T_Gravity::GetPowerVector(const T_Vector &v)const
{
    T_Vector rv(v-Centre);
    float l=rv.Length();
    if(l>=minRadius)
    {
        if(l<maxRadius)
        {
            rv.SetLength(Power*(maxRadius-l)/(maxRadius-minRadius));
        }
        else
        {
            rv.SetLength(0);
        }
    }
    else
    {
        rv.SetLength(Power*(l/minRadius));
    }
    rv.Rotate(Angle);
    return rv;
}
//---------------------------------------------------------------------------
void T_Gravity::SetRadius(const float &r1,const float &r2)
{
    if(r1>=0 && r2>0)
    {
        if(r1>r2)
        {
            maxRadius=r1;
            minRadius=r2;
        }
        else
        {
            maxRadius=r2;
            minRadius=r1;
        }
    }
}
//---------------------------------------------------------------------------
void T_Gravity::Draw(TCanvas *Canvas,const TColor &cl)const
{
    TBrushStyle bs=Canvas->Brush->Style;
    TColor c=Canvas->Pen->Color;
    Canvas->Brush->Style=bsClear;
    Canvas->Pen->Color=cl;
    Canvas->Ellipse(Centre.X-minRadius,Centre.Y-minRadius,
        Centre.X+minRadius,Centre.Y+minRadius);
    Canvas->Ellipse(Centre.X-maxRadius,Centre.Y-maxRadius,
        Centre.X+maxRadius,Centre.Y+maxRadius);
    Canvas->Brush->Style=bs;
    Canvas->Pen->Color=c;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
float LawOfGravity(const float &m1, // маса першого т≥ла
                   const float &m2, // маса другого т≥ла
                   const float &R,  // в≥дстань м≥ж т≥лами
                   const float &G   // грав≥тац≥йна стала
                   )
{
    float F=-1;
    if(R>0 && m1>=0 && m2>=0)
    {
        F=G*m1*m2/(R*R);
    }
    return F;
}
//---------------------------------------------------------------------------
T_Vector DoVectorAttraction(const T_Vector &From,// повертаЇ вектор прит€ганн€
                            const T_Vector &To,  // в≥д точки From до точки
                            const float &F      // To з силою F
                            )
{
    T_Vector Vector(To-From);
    Vector.SetLength(F);
    return Vector;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
