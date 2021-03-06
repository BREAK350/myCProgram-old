//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void trasa::Create(int _n,int _m)
{
    int i;
    n=_n;
    m=_m;
    mas=(elem**)malloc(n*sizeof(elem*));
    for(i=0;i<n;i++)
    {
        mas[i]=(elem*)malloc(m*sizeof(elem));
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void trasa::RandomColor()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            mas[i][j].cl=RGB(0,10*i,10*j);
        }
    }
}
//---------------------------------------------------------------------------
void trasa::Draw(float X,float Y,float S,Graphics::TBitmap *bmp)
{
    int i,j,_n,_m,x,y;
    if(S<=0)
    {
        return;
    }
    _m=bmp->Width/S+3;
    _n=bmp->Height/S+3;
    if(_n>n || _m>m)
    {
        return;
    }
    X=(X>=0)?((X<m)?(X):(X-m*((int)X/m))):(m+X-m*((int)X/m));
    Y=(Y>=0)?((Y<n)?(Y):(Y-n*((int)Y/n))):(n+Y-n*((int)Y/n));
    x=X;
    y=Y;
    bmp->Canvas->Brush->Color=clWhite;
    bmp->Canvas->Rectangle(0,0,bmp->Width,bmp->Height);
    bmp->Canvas->Brush->Color=clBlue;
    for(i=0;i<_n;i++)
    {
        for(j=0;j<_m;j++)
        {
            //bmp->Canvas->Pen->Color=mas[(i+y>=0)?((i+y<n)?(i+y):(n-i-y)):(n+i+y)][(j+x>=0)?((j+x<m)?(j+x):(m-j-x)):(m+j+x)].cl;
            //bmp->Canvas->Brush->Color=mas[(i+y>=0)?((i+y<n)?(i+y):(n-i-y)):(n+i+y)][(j+x>=0)?((j+x<m)?(j+x):(m-j-x)):(m+j+x)].cl;
            bmp->Canvas->Brush->Color=mas[(i+y<n)?(i+y):(i+y-n)][(j+x<m)?(j+x):(j+x-m)].cl;
            bmp->Canvas->Rectangle((j-1+x-X)*S,(i-1+y-Y)*S,(j+x-X)*S,(i+y-Y)*S);
        }
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
