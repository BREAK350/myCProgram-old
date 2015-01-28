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
    mod.ls.LoadToFile("model1.model");
    mod.change.CreateCHP();
    mod.show.ShowCHP(loc);
    mod.detail.scale=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    TMatrix r,OX;
    int i;
    Canvas->Pen->Color=clWhite;
    mod.show.ShowCHP(loc);
    Canvas->Pen->Color=clBlack;
    mod.detail.loc.alpha.x++;
    for(i=0;i<mod.detail.n_point;i++)
    {
        mod.detail.chp[i].x=mod.detail.scale*mod.detail.point[i].x+mod.detail.loc.p3d.x;
        mod.detail.chp[i].y=mod.detail.scale*mod.detail.point[i].y+mod.detail.loc.p3d.y;
        mod.detail.chp[i].z=mod.detail.scale*mod.detail.point[i].z+mod.detail.loc.p3d.z;
        r=mod.detail.chp[i].ToMatrix();
        OX=CreateOX(mod.detail.loc.alpha.x);
        r=DobytokMatrix(r,OX);
        mod.detail.chp[i].MatrixToPoint3D(r);
    }
    mod.show.ShowCHP(loc);
}
//---------------------------------------------------------------------------
