//---------------------------------------------------------------------------
#pragma hdrstop
#include "LabiryntH.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TLabirynt::TLabirynt():TMatrix()
{
    dN=dM=3;
    Scale=50; // pixels
    Map=new Graphics::TBitmap;
    Map->Height=dN*Scale;
    Map->Width=dM*Scale;
}
//---------------------------------------------------------------------------
TLabirynt::~TLabirynt()
{
    delete Map;
}
//---------------------------------------------------------------------------
void TLabirynt::MapClear()
{
    TColor cl;
    cl=Map->Canvas->Brush->Color;
    Map->Canvas->Brush->Color=clWhite;
    Map->Canvas->Rectangle(-1,-1,dM*Scale+1,dN*Scale+1);
    Map->Canvas->Brush->Color=cl;
}
//---------------------------------------------------------------------------
void TLabirynt::Draw(int x,int y,TCanvas *Canvas)
{
    Canvas->Draw(x,y,Map);
}
//---------------------------------------------------------------------------
void TLabirynt::CreatePicture(int x,int y,int p)
{
    int i,j;
    if(x<0 || y<0 || p<0 || x>=mM || y>=mN || p>=mP )
    {
        return;
    }
    for(i=y-dN;i<2*dN+1;i++)
    {
        for(j=x-dM;j<2*dM+1;j++)
        {
            if(i>=0 && i<mN && j>=0 && j<mM)
            {
                DrawElement(L[p][i][j],(j-x+dM)*Scale,(i-y+dN)*Scale,(j-x+dM+1)*Scale,(i-y+dN+1)*Scale);
            }
            else
            {
                DrawElement(-1,(j-x+dM)*Scale,(i-y+dN)*Scale,(j-x+dM+1)*Scale,(i-y+dN+1)*Scale);
            }
        }
    }
}
//---------------------------------------------------------------------------
void TLabirynt::DrawElement(int Type,int x1,int y1,int x2,int y2)
{
    switch(Type)
    {
        case 1:
            Map->Canvas->Rectangle(x1,y1,x2,y2);
            break;
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 