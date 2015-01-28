//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void Draw(const T_Matrix &M,TCanvas *Canvas,const int &x,const int &y,const int &s)
{
    int i,j,e,n=M.GetN(),m=M.GetM();
    Canvas->Pen->Color=clSilver;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            M.GetE(i,j,e);
            if(e==0)
            {
                Canvas->Brush->Color=clWhite;
            }
            else
            if(e==1)
            {
                Canvas->Brush->Color=(TColor)RGB(0,255,0);
            }
            else
            if(e>1)
            {
                Canvas->Brush->Color=clGreen;
            }
            else
            {
                Canvas->Brush->Color=clRed;
            }
            Canvas->Rectangle(j*s+x,i*s+y,(j+1)*s+x,(i+1)*s+y);
        }
    }
}
//---------------------------------------------------------------------------
void CreateRandomArea(T_Matrix &Matrix,const int &AmountArea)
{
    int k=1,i,e,j,n=Matrix.GetN(),m=Matrix.GetM();
    int *Amount=new int[AmountArea];
    for(i=0;i<AmountArea;i++)
    {
        Amount[i]=0;
    }
    Matrix.Nullify();
    randomize();
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            e=random(AmountArea)+1;
            Amount[e-1]++;
            Matrix.SetE(i,j,e);
        }
    }
    while(k<=AmountArea)
    {

        k++;
    }
    delete Amount;
}
//---------------------------------------------------------------------------
void DrawElement(const T_Matrix &M,TCanvas *Canvas,const int &x,const int &y,const int &s)
{
    int i,j,e,n=M.GetN(),m=M.GetM();
    Canvas->Pen->Color=clBlue;
    Canvas->Brush->Style=bsClear;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            M.GetE(i,j,e);
            if(e==1)
            {
                Canvas->Rectangle(j*s+x,i*s+y,(j+1)*s+x,(i+1)*s+y);
            }
        }
    }
    Canvas->Brush->Style=bsSolid;
}
//---------------------------------------------------------------------------
void T_Element::Draw(TCanvas *Canvas,const int &x,const int &y,const int &s)
{
    DrawElement(Matrix,Canvas,x+j*s,y+i*s,s);
}
//---------------------------------------------------------------------------
int isGood(const T_Matrix &Matrix)
{
    int i=0,j,q=1,n=Matrix.GetN(),m=Matrix.GetM();
    while(i<n && q==1)
    {
        j=0;
        while(j<m && q==1)
        {
            Matrix.GetE(i,j,q);
            j++;
        }
        i++;
    }
    return q==1;
}
//---------------------------------------------------------------------------
int isUp(const T_Element &Element,const int &s,const int &x,const int &y,TRect &Rect)
{
    int q=0;
    if(x>=Element.x && x<=Element.x+Element.Matrix.GetM()*s &&
       y>=Element.y && y<=Element.y+Element.Matrix.GetN()*s)
    {
        q=1;
        Rect=TRect(Element.x,Element.y,Element.x+Element.Matrix.GetM()*s,Element.y+Element.Matrix.GetN()*s);
    }
    return q;
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
