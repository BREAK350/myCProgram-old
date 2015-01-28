//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <vcl.h>
#include "T_Matrix.h"
//---------------------------------------------------------------------------
struct T_Element
{
    T_Matrix Matrix;
    int i,j,x,y,Paste;
    T_Element(const int &n,const int &m,const int &e):Matrix(n,m,e) { i=j=0; }
    T_Element() {}
    void Draw(TCanvas *Canvas,const int &x,const int &y,const int &s);
};
//---------------------------------------------------------------------------
void Draw(const T_Matrix &M,TCanvas *Canvas,const int &x,const int &y,const int &s);
void DrawElement(const T_Matrix &M,TCanvas *Canvas,const int &x,const int &y,const int &s);
void CreateRandomArea(T_Matrix &Matrix,const int &AmountArea);
int isGood(const T_Matrix &Matrix);
int isUp(const T_Element &Element,const int &s,const int &x,const int &y,TRect &Rect);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 