//---------------------------------------------------------------------------
#ifndef Draw3DH
#define Draw3DH
#include "Unit1.h"
#include <math.h>
#include <stdio.h>
//---------------------------------------------------------------------------
class vector3
{
    public:
        float x,y,z;
        vector3 Init(float,float,float);
        vector3 Init(float,float);
        operator=(vector3);
        vector3 operator+(vector3);
        vector3 operator-(vector3);
        vector3 operator+(float);
        vector3 operator*(float);
        operator+=(vector3);
        float fi();
        float theta();
        float d();
        vector3 Change(vector3,vector3,float);
        void Draw3DMoveTo(Graphics::TBitmap*);
        void Draw3DLineTo(TColor,Graphics::TBitmap*);
};
//---------------------------------------------------------------------------
class matrix33
{
    public:
        float v[3][3];
        vector3 operator*(vector3);
        void Rr(vector3,float);
};
//---------------------------------------------------------------------------
class Line
{
    public:
        unsigned short int l;
};
//---------------------------------------------------------------------------
class TModel
{
    public:
        int       N_point,
                  N_line,
                  N_triagle;
        float     S;     
        vector3   *point;
        Line      *line;
        TColor    *col;
        void      LoadFromFile(char*);
        void      Draw3DModel(vector3,vector3,Graphics::TBitmap*);
};
//---------------------------------------------------------------------------
#endif
