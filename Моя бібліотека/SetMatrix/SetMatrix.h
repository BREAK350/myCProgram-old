//---------------------------------------------------------------------------
#ifndef SetMatrixH
#define SetMatrixH
#include "oT_Point3.h"
#include <math.h>
#include "T_Matrix4.h"
//---------------------------------------------------------------------------
struct SetMatrix
{
    T_Matrix4 Axonometric(const float &psi,const float &fi);
    T_Matrix4 Oblique(const float &alpha,const float &betta); //косокутна проекція
    T_Matrix4 Isometric();
    T_Matrix4 RotationX(const float &fi);
    T_Matrix4 RotationY(const float &fi);
    T_Matrix4 RotationZ(const float &fi);
    T_Matrix4 Pab(const float &a,const float &b);
    T_Matrix4 Pabc(const float &a,const float &b,const float &c);
    T_Matrix4 T(const float &x,const float &y,const float &z);
    T_Matrix4 D(const float &x,const float &y,const float &z);
    T_Matrix4 Pc(const float &c);
    T_Matrix4 Cavalier(const float &alpha) { return GetOblique(alpha,45*M_PI/180); }
    T_Matrix4 Cabinet();
    T_Matrix4 Px();
    T_Matrix4 Py();
    T_Matrix4 Pz();
    T_Matrix4 Dymetriya();
};
/*
    клас для створення різних матриць-перетворень
*/
//---------------------------------------------------------------------------
#endif
