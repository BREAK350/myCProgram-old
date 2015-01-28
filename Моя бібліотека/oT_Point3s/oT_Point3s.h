//---------------------------------------------------------------------------
#ifndef oT_Point3sH
#define oT_Point3sH
#include "oT_Point3.h"
class T_Point3s;
//---------------------------------------------------------------------------
class oT_Point3s
{
    private:
        oT_Point3 *oPoint;
        int N;
    public:
        oT_Point3s();
        oT_Point3s(const int &n);
        oT_Point3s(const oT_Point3s &oPoint3s);
        ~oT_Point3s();
        oT_Point3s& operator = (const oT_Point3s &oPoint3s);
        int SetoPoint(const int &i,const oT_Point3 &op);
        T_Point3s GetT_Point3s();
        oT_Point3s operator * (const T_Matrix4 &M);
        int GetN()const { return N; }
        void SetN(const int &n);
};
/*
    масив однорідних координат
*/
#include "T_Point3s.h"
//---------------------------------------------------------------------------
#endif
 