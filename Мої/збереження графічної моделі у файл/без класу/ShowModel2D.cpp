//---------------------------------------------------------------------------
#pragma hdrstop
#include "ShowModel2D.h"
Point3D P;
//extern Point3D XY;
extern int K;
//---------------------------------------------------------------------------
int isLine(int point1,int point2,TModel mod)
{
    return is_Line(mod.grf,point1,point2);
}
//---------------------------------------------------------------------------
void Show_(TModel mod,Point3D XY,Graphics::TBitmap* bmp)
{
    int i,j;
    int x=bmp->Width/2;
    int y=bmp->Height/2;
    for(i=1;i<=mod.n_point;i++)
    {
        for(j=1;j<i;j++)
        {
            P=mod.point[i-1];
            P.x*=mod.scale;
            P.y*=mod.scale;
            P.z*=mod.scale;
            P.x+=mod.loc.p3d.x;
            P.y+=mod.loc.p3d.y;
            P.z+=mod.loc.p3d.z;
            P.x-=XY.x;
            P.y-=XY.y;
            P.z-=XY.z;
            if(P.z>0)
            {
                P=_3DTo2D(P);
                bmp->Canvas->MoveTo(P.x+x,y-P.y);
                if(isLine(i,j,mod)==1)
                {
                    P=mod.point[j-1];
                    P.x*=mod.scale;
                    P.y*=mod.scale;
                    P.z*=mod.scale;
                    P.x+=mod.loc.p3d.x;
                    P.y+=mod.loc.p3d.y;
                    P.z+=mod.loc.p3d.z;
                    P.x-=XY.x;
                    P.y-=XY.y;
                    P.z-=XY.z;
                    if(P.z>0)
                    {
                        P=_3DTo2D(P);
                        bmp->Canvas->Pen->Color=clWhite;
                        bmp->Canvas->LineTo(P.x+x,y-P.y);
                    }
                }
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
          //  Form1->Canvas->MoveTo(P.x+XY.x,XY.y-P.y);
            if(isLine(i,j,mod)==1)
            {
                P=mod.chp[j-1];
                //P.Move(l.p3d);
                //P.TurnOXOYOZ(l.alpha);
                P=_3DTo2D(P);
              //  Form1->Canvas->LineTo(P.x+XY.x,XY.y-P.y);
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
Point3D _3DTo2D(Point3D P)
{
    float d;
    Point3D t;
    t=P;
    d=(float)P.z;
    //d=sqrt(P.x*P.x+P.y*P.y+P.z*P.z);
    if(d>0)
    {
        t.x*=300/d;
        t.y*=300/d;
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
void BMPClear(Graphics::TBitmap* bmp)
{
    bmp->Canvas->Pen->Color=clFon;
    bmp->Canvas->Brush->Color=clFon;
    bmp->Canvas->Brush->Style=bsSolid;
    bmp->Canvas->Rectangle(0,0,bmp->Width,bmp->Height);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
