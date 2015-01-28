//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int pi=0,pj=0;
int f=0,N=5;
T_Matrix_Odd Track(N,N,f),cTrack(N,N,f),Dark(N,N,f);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    cTrack.SetE(3,5,150);
    cTrack.SetE(2,6,150);
    cTrack.SetE(2,5,150);
    cTrack.SetE(1,5,150);
    cTrack.SetE(0,5,150);
    cTrack.SetE(2,7,150);
    cTrack.SetE(2,8,150);
    cTrack.SetE(1,6,150);
    cTrack.SetE(0,6,150);
    //cTrack.SetE(5,3,150);
    cTrack.SetE(5,2,150);
    cTrack.SetE(6,2,150);
    cTrack.SetE(7,2,150);
    cTrack.SetE(7,3,150);
    cTrack.SetE(7,4,150);
    cTrack.SetE(6,6,150);
    cTrack.SetE(6,5,150);
    cTrack.SetE(6,4,150);
    cTrack.SetE(5,6,150);
    //cTrack.SetE(4,6,150);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    switch(Key)
    {
        case 37:
            pi--; break;
        case 38:
            pj--; break;
        case 39:
            pi++; break;
        case 40:
            pj++; break;
    }
    Track.Copy(cTrack,pi,pj,150);
    //Draw(Track,Canvas,TPoint(10,10),30);
    CreateDark(Track,Dark);
    Draw(Track,Canvas,TPoint(400,10),30,Dark);
    Canvas->Brush->Color=clRed;
    Canvas->Ellipse(N*30+400,N*30+10,(N+1)*30+400,(N+1)*30+10);
    Canvas->Ellipse(N*30+10,N*30+10,(N+1)*30+10,(N+1)*30+10);
}
//---------------------------------------------------------------------------

