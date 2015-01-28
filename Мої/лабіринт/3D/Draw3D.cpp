//---------------------------------------------------------------------------
#pragma hdrstop
#include "Draw3D.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TDraw3D::Draw3DQuadrat(Graphics::TBitmap *Map,TRect *r,int i,int j)
{
    int l;
    switch(Data[i][j])
    {
        case 0:
            Map->Canvas->MoveTo(r[j].Left,r[j].Top);
            Map->Canvas->LineTo(r[j+1].Left,r[j+1].Top);
            Map->Canvas->MoveTo(r[j].Left,r[j].Bottom);
            Map->Canvas->LineTo(r[j+1].Left,r[j+1].Bottom);
            break;
        case 1:
            if(j>0 && Data[i][j-1]==0)
            {
                Map->Canvas->MoveTo(r[j].Left,r[j].Top);
                Map->Canvas->LineTo(r[j].Left,r[j].Bottom);
            }
            if(j<D-1)
            {
                if(Data[i][j+1]==0)
                {
                    Map->Canvas->MoveTo(r[j+1].Left,r[j+1].Top);
                    Map->Canvas->LineTo(r[j+1].Left,r[j+1].Bottom);
                    l=j;
                    while(l>=0 && Data[i][l]==1)
                    {
                        l--;
                    }
                    l++;
                    Map->Canvas->MoveTo(r[j+1].Left,r[j+1].Top);
                    Map->Canvas->LineTo(r[l].Left,r[j+1].Top);
                    Map->Canvas->MoveTo(r[j+1].Left,r[j+1].Bottom);
                    Map->Canvas->LineTo(r[l].Left,r[j+1].Bottom);
                }
            }
    }
}
//---------------------------------------------------------------------------
void TDraw3D::Draw3DAll(Graphics::TBitmap *Map)
{
    int i,g;
    TRect r[]={
               TRect(0,0,Map->Width,Map->Height),
               TRect(Map->Width*3/14,Map->Height*3/14,Map->Width*11/14,Map->Height*11/14),
               TRect(Map->Width*5/14,Map->Height*5/14,Map->Width*9/14,Map->Height*9/14),
               TRect(Map->Width*6/14,Map->Height*6/14,Map->Width*8/14,Map->Height*8/14)
               };
    for(i=0;i<D;i++)
    {
        Draw3DQuadrat(Map,r,0,i);
    }
    Draw3DEnd(Map,r,0,i);
    for(i=0;i<4;i++)
    {
        g=r[i].Left;
        r[i].Left=r[i].Right;
        r[i].Right=g;
    }
    for(i=0;i<D;i++)
    {
        Draw3DQuadrat(Map,r,1,i);
    }
    Draw3DEnd(Map,r,1,i);
}
//---------------------------------------------------------------------------
void TDraw3D::Draw3DEnd(Graphics::TBitmap *Map,TRect *r,int i,int j)
{
    int l;
    if(Data[i][j-1]==0)
    {
        Map->Canvas->MoveTo(r[j].Left,r[j].Top);
        Map->Canvas->LineTo(r[j].Left,r[j].Bottom);
    }
    if(Data[i][j-1]==1)
    {
        l=j-1;
        while(l>=0 && Data[i][l]==1)
        {
            l--;
        }
        l+=1;
        Map->Canvas->MoveTo(r[j].Left,r[j].Top);
        Map->Canvas->LineTo(r[l].Left,r[j].Top);
        Map->Canvas->MoveTo(r[j].Left,r[j].Bottom);
        Map->Canvas->LineTo(r[l].Left,r[j].Bottom);
    }
    Map->Canvas->MoveTo(r[j].Left,r[j].Top);
    Map->Canvas->LineTo(r[j].Right,r[j].Top);
    Map->Canvas->MoveTo(r[j].Left,r[j].Bottom);
    Map->Canvas->LineTo(r[j].Right,r[j].Bottom);
}
//---------------------------------------------------------------------------
void TDraw3D::CreateVector(char ***L,int p,int n,int m,int p0,int n0,int m0,int Where)
{
    int i;
    i=0;
    D=0;
    switch(Where)
    {
        case RIGHT:
            while(i+m0<m && L[p0][n0][i+m0]==1 && D<3)
            {
                if(n0<=0)
                {
                    Data[0][i]=0;
                }
                else
                {
                    Data[0][i]=L[p0][n0-1][i+m0];
                }
                if(n0<n-1)
                {
                    Data[1][i]=L[p0][n0+1][i+m0];
                }
                else
                {
                    Data[1][i]=0;
                }
                D++;
                i++;
            }
        case DOWN:
            while(i+n0<n && L[p0][i+n0][m0]==1 && D<3)
            {
                if(m0<=0)
                {
                    Data[0][i]=0;
                }
                else
                {
                    Data[0][i]=L[p0][i+n0][m0-1];
                }
                if(m0<m-1)
                {
                    Data[1][i]=L[p0][i+n0][m0+1];
                }
                else
                {
                    Data[1][i]=0;
                }
                D++;
                i++;
            }
        case LEFT:
            while(m0-i>0 && L[p0][n0][m0-i]==1 && D<3)
            {
                if(n0<=0)
                {
                    Data[0][i]=0;
                }
                else
                {
                    Data[0][i]=L[p0][n0-1][m0-i];
                }
                if(n0<n-1)
                {
                    Data[1][i]=L[p0][n0+1][m0-i];
                }
                else
                {
                    Data[1][i]=0;
                }
                D++;
                i++;
            }
        case UP:
            while(n0-i>0 && L[p0][n0-i][m0]==1 && D<3)
            {
                if(m0<=0)
                {
                    Data[0][i]=0;
                }
                else
                {
                    Data[0][i]=L[p0][n0-i][m0-1];
                }
                if(m0<m-1)
                {
                    Data[1][i]=L[p0][n0-i][m0+1];
                }
                else
                {
                    Data[1][i]=0;
                }
                D++;
                i++;
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
 