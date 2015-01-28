//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Polyhedron.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void T_Polyhedron::LoadFromFile(ifstream &ifs)
{
    int i,_i,n;
    Const.LoadFromFile(ifs);
    Buf=Const;
    ifs>>n;
    Border.SetN(n);
    T_Border B;
    for(i=0;i<n;i++)
    {
        B.LoadFromFile(ifs);
        Border.SetElement(i,B);
    }
}
//---------------------------------------------------------------------------
void T_Polyhedron::Draw(TCanvas *Canvas,const T_Point3 &Norm)
{
    int i,n;
    n=Border.GetN();
    for(i=0;i<n;i++)
    {
        Border[i].Draw(Canvas,Buf,Norm);
    }
}
//---------------------------------------------------------------------------
void T_Polyhedron::Draw(TCanvas *Canvas,const T_Point3 &Norm,const int &cx,const int &cy)
{
    int i,n;
    n=Border.GetN();
    for(i=0;i<n;i++)
    {
        Border[i].Draw(Canvas,Buf,Norm,cx,cy);
    }
}
//---------------------------------------------------------------------------
void T_Polyhedron::DoMatrix(const T_Matrix4 &M)
{
    oT_Point3s oBuf=Const.GetoT_Point3s();
    oBuf=oBuf*M;
    Buf=oBuf.GetT_Point3s();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

