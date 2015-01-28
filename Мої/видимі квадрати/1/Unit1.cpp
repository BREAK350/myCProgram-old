//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
dT_Matrix Track,cTrack;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    cTrack.Elem[3][5]=50;
    cTrack.Elem[2][6]=50;
    cTrack.Elem[2][5]=50;
    cTrack.Elem[1][5]=50;
    cTrack.Elem[0][5]=50;
    cTrack.Elem[2][7]=50;
    cTrack.Elem[2][8]=50;
    cTrack.Elem[1][6]=50;
    cTrack.Elem[0][6]=50;
    cTrack.Elem[5][3]=50;
    cTrack.Elem[5][2]=50;
    cTrack.Elem[6][2]=50;
    cTrack.Elem[7][2]=50;
    cTrack.Elem[7][3]=50;
    cTrack.Elem[7][4]=50;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    dT_Matrix Dark;
    //int **A=cTrack.Elem;
    //Copy((int **)cTrack.Elem,11,11,(int **)Track.Elem,11,11,5,5,50);
    Track.Draw(Canvas,TPoint(10,10),30);
    CreateDark(Track,Dark);
    Track.Draw(Canvas,TPoint(400,10),30,Dark);
    Canvas->Brush->Color=clRed;
    Canvas->Ellipse(5*30+400,5*30+10,6*30+400,6*30+10);
}
//---------------------------------------------------------------------------
 