//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Object.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
T_Object obj;
float angle=0;
T_Point Where={100,100};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    /*int n=3;
    int *pn;
    T_Point **p;
    TColor *cl;
    float Scale=5;
    T_Point Where;
    float angle=0*M_PI/180;
    p=new T_Point*[n];
    pn=new int[n];
    pn[0]=4;
    pn[1]=6;
    pn[2]=4;
    p[0]=new T_Point[pn[0]];
    p[1]=new T_Point[pn[1]];
    p[2]=new T_Point[pn[2]];
    cl=new TColor[n];
    cl[0]=clBlue;
    cl[1]=clGray;
    cl[2]=clBlack;
    init(p[0][0],3,4);
    init(p[0][1],3,-4);
    init(p[0][2],-3,-4);
    init(p[0][3],-3,4);
    init(p[1][0],1,2);
    init(p[1][1],2,1);
    init(p[1][2],2,-2);
    init(p[1][3],-2,-2);
    init(p[1][4],-2,1);
    init(p[1][5],-1,2);
    init(p[2][0],-0.5,2);
    init(p[2][1],-0.5,5);
    init(p[2][2],0.5,5);
    init(p[2][3],0.5,2);
    init(Where,100,100);
    obj.Init(n,pn,p,cl,Scale,Where,angle);*/
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    obj.LoadFromFile("Tank001");
    obj.Draw(Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    obj.SetAngleGradus(angle);
    obj.SetWhere(Where);
    obj.Draw(Canvas);
    angle+=10;
    Where.x+=30;
    Where.y+=20;
}
//---------------------------------------------------------------------------
