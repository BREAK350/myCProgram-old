//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "T_Projection.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
T_3D_Obj a;
double fi=0,teta=-70,ro=400;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    a.Const.NPoint=8;
    a.Buf.NPoint=a.Const.NPoint;
    a.Const.Point=new T_Point3D[a.Const.NPoint];
    a.Buf.Point=new T_Point3D[a.Const.NPoint];
    a.Link.NLink=12;
    a.Link.Link=new T_Link[a.Link.NLink];

    a.Const.Point[0].x=-100;
    a.Const.Point[0].y=-100;
    a.Const.Point[0].z=-100;
    a.Const.Point[1].x=-100;
    a.Const.Point[1].y=100;
    a.Const.Point[1].z=-100;
    a.Const.Point[2].x=100;
    a.Const.Point[2].y=100;
    a.Const.Point[2].z=-100;
    a.Const.Point[3].x=100;
    a.Const.Point[3].y=-100;
    a.Const.Point[3].z=-100;
    a.Const.Point[4].x=-100;
    a.Const.Point[4].y=-100;
    a.Const.Point[4].z=100;
    a.Const.Point[5].x=-100;
    a.Const.Point[5].y=100;
    a.Const.Point[5].z=100;
    a.Const.Point[6].x=100;
    a.Const.Point[6].y=100;
    a.Const.Point[6].z=100;
    a.Const.Point[7].x=100;
    a.Const.Point[7].y=-100;
    a.Const.Point[7].z=100;

    a.Link.Link[0].First=0;
    a.Link.Link[0].Second=1;
    a.Link.Link[1].First=1;
    a.Link.Link[1].Second=2;
    a.Link.Link[2].First=2;
    a.Link.Link[2].Second=3;
    a.Link.Link[3].First=3;
    a.Link.Link[3].Second=0;
    a.Link.Link[4].First=4;
    a.Link.Link[4].Second=5;
    a.Link.Link[5].First=5;
    a.Link.Link[5].Second=6;
    a.Link.Link[6].First=6;
    a.Link.Link[6].Second=7;
    a.Link.Link[7].First=0;
    a.Link.Link[7].Second=4;
    a.Link.Link[8].First=1;
    a.Link.Link[8].Second=5;
    a.Link.Link[9].First=2;
    a.Link.Link[9].Second=6;
    a.Link.Link[10].First=3;
    a.Link.Link[10].Second=7;
    a.Link.Link[11].First=7;
    a.Link.Link[11].Second=4;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    a.doCopy();
    Canvas->Rectangle(-1,-1,ClientWidth+1,ClientHeight+1);
    a.Mv(M_PI*fi/180,M_PI*teta/180,ro);
    //a.Pab(1000,1000);
    a.P1(1000);
    fi+=1;
    //teta+=1;
    //ro+=5;
    a.Draw(Canvas,TPoint(ClientWidth/2.0,ClientHeight/2.0),0.7,TPoint(1,-1));
}
//---------------------------------------------------------------------------

