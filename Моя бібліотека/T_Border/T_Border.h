//---------------------------------------------------------------------------
#ifndef T_BorderH
#define T_BorderH
#include "T_Array.h"
#include "T_Point3s.h"
#include <vcl.h>
//---------------------------------------------------------------------------
class T_Border
{
    public:
        T_Array <int> Index;
        T_Point3 GetNotmal(const T_Point3s &Point3s);
        T_Border() {}
        T_Border(const T_Array <int> _Index):Index(_Index) {}
        T_Border(const T_Border &Border):Index(Border.Index) {}
        ~T_Border() {}
        void Draw(TCanvas *Canvas,const T_Point3s &Point3s,const T_Point3 &Norm);
        void Draw(TCanvas *Canvas,const T_Point3s &Point3s,const T_Point3 &Norm,const int &cx,const int &cy);
        void SaveToFile(ofstream &ofs);
        void LoadFromFile(ifstream &ifs);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
