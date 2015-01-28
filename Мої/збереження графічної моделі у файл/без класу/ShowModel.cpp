//---------------------------------------------------------------------------
#pragma hdrstop
#include "ShowModel.h"
Point3D P;
extern Point3D XY;
//---------------------------------------------------------------------------
int isLine(int point1,int point2,TModel mod)
{
    return is_Line(mod.grf,point1,point2);
}
//---------------------------------------------------------------------------
void Show_(TModel mod,Point3D XY)
{
    int i,j;
    for(i=1;i<=mod.n_point;i++)
    {
        for(j=1;j<i;j++)
        {
            P=mod.point[i-1];
            P=_3DTo2D(P);
            Form1->Canvas->MoveTo(P.x+XY.x,XY.y-P.y);
            if(isLine(i,j,mod)==1)
            {
                P=mod.point[j-1];
                P=_3DTo2D(P);
                Form1->Canvas->LineTo(P.x+XY.x,XY.y-P.y);
            }
        }
    }
}
//---------------------------------------------------------------------------
void FormXY(Point3D XY)
{
    Form1->Canvas->Pen->Color=clYellow;
    Form1->Canvas->MoveTo(XY.x,0);
    Form1->Canvas->LineTo(XY.x,2*XY.y);
    Form1->Canvas->MoveTo(0,XY.y);
    Form1->Canvas->LineTo(2*XY.x,XY.y);
}
//---------------------------------------------------------------------------
void ShowCHP(location l,TModel mod)
{
    int i,j;
    for(i=1;i<=mod.n_point;i++)
    {
        for(j=1;j<i;j++)
        {
            P=mod.chp[i-1];
            //P.Move(l.p3d);
            //P.TurnOXOYOZ(l.alpha);
            P=_3DTo2D(P);
            Form1->Canvas->MoveTo(P.x+XY.x,XY.y-P.y);
            if(isLine(i,j,mod)==1)
            {
                P=mod.chp[j-1];
                //P.Move(l.p3d);
                //P.TurnOXOYOZ(l.alpha);
                P=_3DTo2D(P);
                Form1->Canvas->LineTo(P.x+XY.x,XY.y-P.y);
            }
        }
    }
}
//---------------------------------------------------------------------------
void ChangeCHP(TModel &mod)
{
    int i;
    for(i=0;i<mod.n_point;i++)
    {

    }
}
//---------------------------------------------------------------------------
Point3D _3DTo2D(Point3D p)
{
    float d;
    Point3D t;
    t=p;
    if(p.z-XY.z>=10)
    {
        d=10/(float)p.z;
        t.x=t.x*d;
        t.y=t.y*d;
    }
    else
    {
        t.z=-1;
    }
    return t;
}
//---------------------------------------------------------------------------
void Move(Point3D &t,Point3D p)
{
    t.x+=p.x;
    t.y+=p.y;
    t.z+=p.z;
}
//---------------------------------------------------------------------------
void TurnOX(Point3D &t,Point3D alpha)
{
    t.y=t.y*cos(alpha.x)-t.z*sin(alpha.x);
    t.z=t.y*sin(alpha.x)+t.z*sin(alpha.x);
}
//---------------------------------------------------------------------------
void TurnOY(Point3D &t,Point3D alpha)
{
    t.z=t.z*cos(alpha.y)-t.x*sin(alpha.y);
    t.x=t.z*sin(alpha.y)+t.x*sin(alpha.y);
}
//---------------------------------------------------------------------------
void TurnOZ(Point3D &t,Point3D alpha)
{
    t.x=t.x*cos(alpha.z)-t.y*sin(alpha.z);
    t.y=t.x*sin(alpha.z)+t.y*sin(alpha.z);
}
//---------------------------------------------------------------------------
void TurnOXOYOZ(Point3D &t,Point3D alpha)
{
    TurnOX(t,alpha);
    TurnOY(t,alpha);
    TurnOZ(t,alpha);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
