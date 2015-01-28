//---------------------------------------------------------------------------
#ifndef T_Point3sH
#define T_Point3sH
#include "T_Point3.h"
class oT_Point3s;
//---------------------------------------------------------------------------
class T_Point3s
{
    private:
        T_Point3 *Point;
        int N;
    public:
        T_Point3s();
        T_Point3s(const int &n);
        T_Point3s(const T_Point3s &Point3s);
        ~T_Point3s();
        T_Point3s& operator = (const T_Point3s &Point3s);
        int SetPoint(const int &i,const T_Point3 &p);
        int GetPoint(const int &i,T_Point3 &p)const;
        oT_Point3s GetoT_Point3s();
        int GetN()const { return N; }
        void SetN(const int &n);
        void SaveToFile(ofstream &ofs);
        void LoadFromFile(ifstream &ifs);
};
#include "oT_Point3s.h"
//---------------------------------------------------------------------------
#endif
