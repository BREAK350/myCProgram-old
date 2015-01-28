//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Element=NULL;
    nElement=0;
    CurrElement=-1;
    x=50;
    y=50;
    s=30;
    //////////////////
    T_Matrix A(4,4,0);
    T_Element B(2,2,1),C(2,2,1),D(3,1,1),E(4,2,1);
    B.Matrix.SetE(0,0,0);
    C.Matrix.SetE(1,1,0);
    E.Matrix.SetE(0,0,0);
    B.i=0;
    B.j=0;
    C.i=0;
    C.j=0;
    D.i=D.j=0;
    E.i=E.j=0;
    Matrix=A;
    nElement=4;
    Element=new T_Element[nElement];
    Element[0]=B;
    Element[1]=C;
    Element[2]=D;
    Element[3]=E;
    Element[0].Paste=0;
    Element[1].Paste=0;
    Element[2].Paste=0;
    Element[3].Paste=0;
    Element[0].x=200;
    Element[0].y=50;
    Element[1].x=300;
    Element[1].y=50;
    Element[2].x=450;
    Element[2].y=50;
    Element[3].x=600;
    Element[3].y=50;
    Show();
    Matrix.Nullify();
    Draw(Matrix,Canvas,x,y,s);
    Draw(Element[0].Matrix,Canvas,Element[0].x,Element[0].y,s);
    Draw(Element[1].Matrix,Canvas,Element[1].x,Element[1].y,s);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    int i;
    TRect Rect;
    cx=X;
    cy=Y;
    i=0;
    while(i<nElement)
    {
        if(isUp(Element[i],s,cx,cy,Rect))
        {
            Curr=i;
            Canvas->Brush->Style=bsClear;
            Canvas->Pen->Color=clBlue;
            Canvas->Rectangle(Rect);
            Canvas->Brush->Style=bsSolid;
        }
        else
        {
            Draw(Element[i].Matrix,Canvas,Element[i].x,Element[i].y,s);
        }
        i++;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    int i;
    switch(Key)
    {
        case 37:
            if(Element[CurrElement].j>0)
            {
                Element[CurrElement].j--;
            }
            break;
        case 38:
            if(Element[CurrElement].i>0)
            {
                Element[CurrElement].i--;
            }
            break;
        case 39:
            if(Element[CurrElement].j+Element[CurrElement].Matrix.GetM()<Matrix.GetM())
            {
                Element[CurrElement].j++;
            }
            break;
        case 40:
            if(Element[CurrElement].i+Element[CurrElement].Matrix.GetN()<Matrix.GetN())
            {
                Element[CurrElement].i++;
            }
            break;
    }
    Matrix.Nullify();
    for(i=0;i<nElement;i++)
    {
        if(Element[i].Paste)
        {
            Matrix.PasteAdd(Element[i].Matrix,Element[i].i,Element[i].j);
        }
    }
    Draw(Matrix,Canvas,x,y,s);
    if(CurrElement>=0 && CurrElement<nElement)
    {
        Element[CurrElement].Draw(Canvas,x,y,s);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
    TRect Rect;
    if(isUp(Element[Curr],s,cx,cy,Rect))
    {
        CurrElement=Curr;
        Element[CurrElement].Paste=1;
    }
}
//---------------------------------------------------------------------------

