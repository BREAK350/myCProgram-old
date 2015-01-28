//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "func1.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Point3D XY;
TModel mod;
location loc;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    XY.x=Form1->ClientWidth/2;
    XY.y=Form1->ClientHeight/2;
    XY.z=0;
    Canvas->Pen->Width=1;
    Canvas->Brush->Style=bsClear;
    Form1->Show();
    FormXY(XY);
    Canvas->Pen->Color=clBlack;
    mod.LoadToFile("model1.model");
    mod.CreateCHP();
    mod.ShowCHP(loc);
    mod.scale=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    TMatrix r,OX;
    int i;
    Canvas->Pen->Color=clWhite;
    mod.ShowCHP(loc);
    Canvas->Pen->Color=clBlack;
    mod.loc.alpha.x++;
    for(i=0;i<mod.n_point;i++)
    {
        mod.chp[i].x=mod.scale*mod.point[i].x+mod.loc.p3d.x;
        mod.chp[i].y=mod.scale*mod.point[i].y+mod.loc.p3d.y;
        mod.chp[i].z=mod.scale*mod.point[i].z+mod.loc.p3d.z;
        r=mod.chp[i].ToMatrix();
        OX=CreateOX(mod.loc.alpha.x);
        r=DobytokMatrix(r,OX);
        mod.chp[i].MatrixToPoint3D(r);
    }
    mod.ShowCHP(loc);
}
//---------------------------------------------------------------------------
