//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "T_Warrior.h"
#include "Unit1.h"
#include "T_List.h"
#include "T_Minery.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
T_Poligon *p,*m;
float s=80;
float angle=0*M_PI/180;
T_List World;
T_Any_Object *Object=NULL;
TPoint Centre(0,0),Cur(0,0);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    /*p=new T_Poligon;
    p->LoadFromFile("2");
    w=new T_Warrior("W1",p,TPoint(2,2),T_Life(1),T_Protection(),T_Attack(),600,10);
    List.Add(w);
    w=new T_Warrior("W2",p,TPoint(1,2),T_Life(1),T_Protection(),T_Attack(),600,10);
    List.Add(w);
    w=new T_Warrior("W3",p,TPoint(2,1),T_Life(1),T_Protection(),T_Attack(),600,10);
    List.Add(w);
    m=new T_Poligon;
    m->LoadFromFile("Øàõòà");
    ao=new T_Minery("Sh",m,T_Point(5,5),T_Life(100),T_Protection(),T_Resource());
    List.Add(ao);
    List.Check();*/
    Centre.x=-ClientWidth/(2*s);
    Centre.y=-ClientHeight/(2*s);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
    OpenDialog1->Execute();
    World.LoadFromFile(OpenDialog1->FileName.c_str());
    Clear();
    World.Draw(Canvas,Centre,s,angle);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    Cur.x=floor(X/s+0.5)+Centre.x;
    Cur.y=floor(Y/s+0.5)+Centre.y;
    Canvas->TextOutA(500,10,"  "+IntToStr(Cur.x)+';'+IntToStr(Cur.y)+"  ");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
    Object=World.GetObjectA(Cur);
    if(Object)
    {
        Button9->Visible=true;
    }
    Clear();
    World.Draw(Canvas,Centre,s,angle);
}
//---------------------------------------------------------------------------
void TForm1::Clear()
{
    Canvas->Brush->Color=clWhite;
    Canvas->Rectangle(-1,-1,Width,Height);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
    Button9->Visible=false;
    PanelInfo->Visible=true;
    if(Object)
    {
        LabelName->Caption=Object->GetInfo(InfoName);
        LabelXY->Caption=Object->GetInfo(InfoXY);
        LabelLife->Caption=Object->GetInfo(InfoLife);
        LabelAttackRadius->Caption=Object->GetInfo(InfoAttackRadius);
        LabelWalkingRadius->Caption=Object->GetInfo(InfoWalkingRadius);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonCloseClick(TObject *Sender)
{
    PanelInfo->Visible=false;
}
//---------------------------------------------------------------------------

