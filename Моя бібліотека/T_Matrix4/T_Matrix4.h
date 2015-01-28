//---------------------------------------------------------------------------
#ifndef T_Matrix4H
#define T_Matrix4H
//---------------------------------------------------------------------------
struct T_Matrix4
{
    float e[4][4];
    T_Matrix4();
    T_Matrix4(const float &e00,const float &e01,const float &e02,const float &e03,
              const float &e10,const float &e11,const float &e12,const float &e13,
              const float &e20,const float &e21,const float &e22,const float &e23,
              const float &e30,const float &e31,const float &e32,const float &e33);
    T_Matrix4 operator * (const T_Matrix4 &M);
};
//---------------------------------------------------------------------------
#endif
