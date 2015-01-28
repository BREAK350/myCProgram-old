//---------------------------------------------------------------------------
#ifndef T_PolyhedronH
#define T_PolyhedronH
#include "T_Array.h"
#include "T_Border.h"
//---------------------------------------------------------------------------
class T_Polyhedron
{
    private:
        T_Array <T_Border> Border;
        T_Point3s Const,Buf;
    public:
        void LoadFromFile(ifstream &ifs);
        void Draw(TCanvas *Canvas,const T_Point3 &Norm);
        void Draw(TCanvas *Canvas,const T_Point3 &Norm,const int &cx,const int &cy);
        void DoMatrix(const T_Matrix4 &M);
};
//---------------------------------------------------------------------------
#endif
