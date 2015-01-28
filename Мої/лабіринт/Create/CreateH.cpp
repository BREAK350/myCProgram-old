//---------------------------------------------------------------------------
#pragma hdrstop
#include "CreateH.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TCreate::TCreate():TLabirynt()
{
    pP=pX=pY=0;
}
//---------------------------------------------------------------------------
TCreate::~TCreate()
{
}
//---------------------------------------------------------------------------
bool TCreate::Move(int Where)
{
    switch(Where)
    {
        case RIGHT:
            if(pX<mM-1)
            {
                pX++;
                return true;
            }
            break;
        case DOWN:
            if(pY<mN-1)
            {
                pY++;
                return true;
            }
            break;
        case LEFT:
            if(pX>0)
            {
                pX--;
                return true;
            }
            break;
        case UP:
            if(pY>0)
            {
                pY--;
                return true;
            }
            break;
        case UPFLOOR:
            if(pP<mP-1)
            {
                pP++;
                return true;
            }
            break;
        case DOWNFLOOR:
            if(pP>0)
            {
                pP--;
                return true;
            }
            break;
    }
    return false;
}
//---------------------------------------------------------------------------
void TCreate::Draw(int x,int y,TCanvas *Canvas)
{
    MapClear();
    CreatePicture(pP,pX,pY);
    DrawElement(PLAYER,dM*Scale,dN*Scale,(dM+1)*Scale,(dN+1)*Scale);
    TLabirynt::Draw(x,y,Canvas);
}
//---------------------------------------------------------------------------
void TCreate::BeginCreate(int p,int n,int m)
{
    int i,j,k;
    TMatrix::Create((p>0)?(p):(1),(n>1)?(n):(1),(m>0)?(m):(1));
    for(i=0;i<p;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                L[i][j][k]=1;
            }
        }
    }
}
//---------------------------------------------------------------------------
void TCreate::AddElement(int Type)
{
    L[pP][pY][pX]=Type;
}
//---------------------------------------------------------------------------
void TCreate::Add(int What,int Type)
{
    int p,n,m;
    TMatrix M;
    M=(*this);
    p=mP;
    n=mN;
    m=mM;
    switch(What)
    {
        case RIGHT:
            Create(p,n,m+1,Type);
            Insert(0,0,0,M);
            break;
        case DOWN:
            Create(p,n+1,m,Type);
            Insert(0,0,0,M);
            break;
        case LEFT:
            Create(p,n,m+1,Type);
            Insert(0,0,1,M);
            break;
        case UP:
            Create(p,n+1,m,Type);
            Insert(0,1,0,M);
            break;
    }
}
//---------------------------------------------------------------------------
void TCreate::ResizePositive(int newP,int newN,int newM,int Type)
{
    if(newP<1 || newN<1 || newM<1)
    {
        return;
    }
    TMatrix M;
    M=(*this);
    Create(newP,newN,newM,Type);
    Insert(0,0,0,M);
}
//---------------------------------------------------------------------------
void TCreate::ResizeNegative(int newP,int newN,int newM,int Type)
{
    if(newP<1 || newN<1 || newM<1)
    {
        return;
    }
    int p,n,m;
    TMatrix M;
    M=(*this);
    p=mP;
    n=mN;
    m=mM;
    Create(newP,newN,newM,Type);
    Insert(mP-p,mN-n,mM-m,M);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
