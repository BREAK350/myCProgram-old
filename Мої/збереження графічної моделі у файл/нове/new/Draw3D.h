//---------------------------------------------------------------------------
#ifndef Draw3DH
#define Draw3DH
#include "Unit1.h"
#include <math.h>
#include <alloc.h>
#include <stdio.h>
#define OX vector v.Init(1,0,0)
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
class matrix33
{
    public:
        float v[3][3];
        vector3 operator*(vector3);
        void Rx(float);
        void Ry(float);
        void Rz(float);
        void Rr(vector3,float);
};
//---------------------------------------------------------------------------
typedef char graf;
union grafbit
{
    graf d;
    struct bits
    {
        graf b0:1,b1:1,b2:1,b3:1,b4:1,b5:1,b6:1,b7:1;
    } bit;
};
class Triagle
{
    public:
        vector3 point[3];
        TColor col;
        void Draw3DTriagle(vector3,vector3,Graphics::TBitmap*);
};
class TModel
{
    public:
        int           n_point;
        float         S;
        vector3       *point,loc;
        graf          *grf;
        void LoadFromFile(char*);
        void CreateGraf();
        void Draw3DModel(vector3,vector3,Graphics::TBitmap*);
};
//---------------------------------------------------------------------------
float   min(float,float);
float   max(float,float);
float   min(float,float,float);
float   max(float,float,float);
float   DArea(vector3,vector3,vector3,float,float);
int     is_Line(graf *,int,int);
bool    isPointIsTriangle(float,float,float,float,float,float,float,float);
void    NewDisplay(Graphics::TBitmap*);
void    InitDisplay(Graphics::TBitmap*);
//---------------------------------------------------------------------------
#endif
