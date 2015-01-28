//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "VectorPerformance.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
T_Gravity g(T_Point(200,200),10,170,-10);
T_Gravity g2(T_Point(450,200),30,300,-2);
T_AnyVector vector(100,100,102,100);
float p=1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    int i,j;
    T_AnyVector v;
    Canvas->Rectangle(0,0,1000,1000);
    g.SetPower(p);
    for(i=0;i<50;i++)
    {
        for(j=0;j<50;j++)
        {
            v=T_AnyVector(8*i,8*j,8*i,8*j+7);
            g.Interaction(v);
            v.Draw(Canvas,clBlack);
            v=T_AnyVector(8*i,8*j,8*i,8*j-7);
            g.Interaction(v);
            v.Draw(Canvas,clBlack);
            v=T_AnyVector(8*i,8*j,8*i+7,8*j);
            g.Interaction(v);
            v.Draw(Canvas,clBlack);
            v=T_AnyVector(8*i,8*j,8*i-7,8*j);
            g.Interaction(v);
            v.Draw(Canvas,clBlack);
        }
    }
    p+=p;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
    g.Interaction(vector);
    g2.Interaction(vector);
    vector.Move();
    vector.Draw(Canvas,clBlack);
    g.Draw(Canvas,clRed);
    g2.Draw(Canvas,clGreen);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int i,j;
    T_AnyVector v;
    Canvas->Rectangle(0,0,1000,1000);
    for(i=0;i<50;i++)
    {
        for(j=0;j<50;j++)
        {
            v=T_AnyVector(8*i,8*j,8*i,8*j);
            g.Interaction(v);
            g.Draw(Canvas,clBlue);
            v.Draw(Canvas,clBlack);
        }
    }
}
//---------------------------------------------------------------------------

