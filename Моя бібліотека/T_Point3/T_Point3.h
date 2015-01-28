//---------------------------------------------------------------------------
#ifndef T_Point3H
#define T_Point3H
#include "T_Point2.h"
#include <fstream.h>
//---------------------------------------------------------------------------
struct T_Point3: public T_Point2
{
    float z;
    T_Point3():T_Point2() { z=0; }
    T_Point3(const float &_x,const float &_y,const float &_z)
        :T_Point2(_x,_y) { z=_z; }
    int operator == (const T_Point3 &p) { return z==p.z && this->T_Point2::operator ==(p);}
    void SaveToFile(ofstream &ofs)
    {
        ofs<<x<<' '<<y<<' '<<z;
    }
    void LoadFromFile(ifstream &ifs)
    {
        ifs>>x>>y>>z;
    }
    float Scalar(const T_Point3 &p);
    T_Point3 Vector(const T_Point3 &p);
    T_Point3 operator + (const T_Point3 &p) { return T_Point3(x+p.x,y+p.y,z+p.z); }
    T_Point3 operator - (const T_Point3 &p) { return T_Point3(x-p.x,y-p.y,z-p.z); }
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
