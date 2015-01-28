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
    Map->Height=(2*dN+1)*Scale;
    Map->Width=(2*dM+1)*Scale;
    Style=NULL;
}
//---------------------------------------------------------------------------
TLabirynt::~TLabirynt()
{
    delete Map;
    delete Style;
}
//---------------------------------------------------------------------------
void TLabirynt::MapClear()
{
    TColor cl;
    cl=Map->Canvas->Brush->Color;
    Map->Canvas->Brush->Color=clWhite;
    Map->Canvas->Rectangle(-1,-1,(2*dM+1)*Scale+1,(2*dN+1)*Scale+1);
    Map->Canvas->Brush->Color=cl;
}
//---------------------------------------------------------------------------
void TLabirynt::Draw(int x,int y,TCanvas *Canvas)
{
    Canvas->Draw(x,y,Map);
}
//---------------------------------------------------------------------------
void TLabirynt::CreatePicture(int p,int x,int y)
{
    int i,j;
    Map->Height=(2*dN+1)*Scale;
    Map->Width=(2*dM+1)*Scale;
    if(x<0 || y<0 || p<0 || x>=mM || y>=mN || p>=mP )
    {
        return;
    }
    for(i=y-dN;i<y+dN+1;i++)
    {
        for(j=x-dM;j<x+dM+1;j++)
        {
            if(i>=0 && i<mN && j>=0 && j<mM)
            {
                DrawElement(L[p][i][j],(j-x+dM)*Scale,(i-y+dN)*Scale,(j-x+dM+1)*Scale,(i-y+dN+1)*Scale);
            }
            else
            {
                DrawElement(WALL,(j-x+dM)*Scale,(i-y+dN)*Scale,(j-x+dM+1)*Scale,(i-y+dN+1)*Scale);
            }
        }
    }
}
//---------------------------------------------------------------------------
void TLabirynt::DrawElement(int Type,int x1,int y1,int x2,int y2)
{
    if(Style)
    {
        TRect tRectFrom(Type*50,0,(Type+1)*50,50);
        TRect tRectTo(x1,y1,x2,y2);
        /*Style->Transparent=true;
        Style->TransparentMode=tmFixed;
        Style->TransparentColor=clWhite;*/
        Map->Canvas->CopyMode=cmSrcCopy;
        Map->Canvas->CopyRect(tRectTo,Style->Canvas,tRectFrom);
        return;
    }
    Map->Canvas->Brush->Color=clBlack;
    switch(Type)
    {
        case ROAD:
            //...
            break;
        case WALL:
            Map->Canvas->Brush->Color=clBlack;
            Map->Canvas->Rectangle(x1,y1,x2,y2);
            break;
        case BEGIN:
            Map->Canvas->Brush->Color=clAqua;
            Map->Canvas->Rectangle(x1,y1,x2,y2);
            break;
        case END:
            Map->Canvas->Brush->Color=clGreen;
            Map->Canvas->Rectangle(x1,y1,x2,y2);
            break;
        case PLAYER:
            Map->Canvas->Brush->Color=clBlue;
            Map->Canvas->Ellipse(x1+Scale/5,y1+Scale/5,x2-Scale/5,y2-Scale/5);
            break;
        case HALFWALL:
            Map->Canvas->Brush->Color=clGray;
            Map->Canvas->Rectangle(x1,y1,x2,y2);
            break;
        case GOUP:
            Map->Canvas->Brush->Color=clSkyBlue;
            Map->Canvas->Rectangle(x1,y1,x2,y2);
            break;
        case GODOWN:
            Map->Canvas->Brush->Color=clHotLight;
            Map->Canvas->Rectangle(x1,y1,x2,y2);
            break;
    }
}
//---------------------------------------------------------------------------
bool TLabirynt::CanGo(int i,int j,int k)
{
    if( L[i][j][k]==ROAD ||
        L[i][j][k]==BEGIN ||
        L[i][j][k]==END ||
        L[i][j][k]==HALFWALL ||
        L[i][j][k]==GOUP ||
        L[i][j][k]==GODOWN
      )
    {
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------
void TLabirynt::GetSizePicture(int &Height,int &Width)
{
    Height=(2*dN+1)*Scale;
    Width=(2*dM+1)*Scale;
}
//---------------------------------------------------------------------------
void TLabirynt::SearchRandomBEGIN(int &p,int &x,int &y)
{
    int i,j,k,n,h;
    p=x=y=0;
    n=NumberOfType(BEGIN);
    if(n==0)
    {
        return;
    }
    randomize();
    n=random(n)+1;
    h=0;
    for(i=0;i<mP;i++)
    {
        for(j=0;j<mN;j++)
        {
            for(k=0;k<mM;k++)
            {
                if(L[i][j][k]==BEGIN)
                {
                    h++;
                    if(h==n)
                    {
                        p=i;
                        x=k;
                        y=j;
                        return;
                    }
                }
            }
        }
    }
    return;
}
//---------------------------------------------------------------------------
int TLabirynt::NumberOfType(int Type)
{
    int i,j,k,n=0;
    for(i=0;i<mP;i++)
    {
        for(j=0;j<mN;j++)
        {
            for(k=0;k<mM;k++)
            {
                if(L[i][j][k]==Type)
                {
                    n++;
                }
            }
        }
    }
    return n;
}
//---------------------------------------------------------------------------
void TLabirynt::LoadStyle(char *fname)
{
    Style=new Graphics::TBitmap;
    Style->LoadFromFile(fname);
}
//---------------------------------------------------------------------------
void TLabirynt::DeleteStyle()
{
    delete Style;
    Style=NULL;
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
 