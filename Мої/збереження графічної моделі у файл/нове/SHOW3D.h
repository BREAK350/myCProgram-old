//---------------------------------------------------------------------------
#ifndef SHOW3DH
#define SHOW3DH
#include "Unit1.h"
#include <math.h>
#include <alloc.h>
#include <stdio.h>
#define OX vector v.Init(1,0,0)
//---------------------------------------------------------------------------
class vector
{
    public:
        float x,y,z;
        vector();
        vector Init(float,float,float);
        vector Init(float,float);
        operator=(vector);
        vector operator+(vector);
        vector operator-(vector);
        vector operator+(float);
        vector operator*(float);
        operator+=(vector);
        float fi();
        float theta();
        float d();
        vector Change(vector,float,vector,float);
        void Draw3DMoveTo(Graphics::TBitmap*);
        void Draw3DLineTo(TColor,Graphics::TBitmap*);
};
class matrix33
{
    public:
        float v[3][3];
        vector operator*(vector);
        void Rx(float);
        void Ry(float);
        void Rz(float);
        void Rr(vector,float);
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
class TModel
{
    public:
        int           n_point;
        float         S;
        vector        *point,*chp,loc;
        graf          *grf;
        void LoadFromFile(char*);
        void CreateGraf();
        void Draw3DModel(vector,vector,Graphics::TBitmap*);
};
//---------------------------------------------------------------------------
void Draw3DPointInBmp(vector,TColor,Graphics::TBitmap*);
void Draw3DLineInBmp(vector,vector,TColor,Graphics::TBitmap*);
//---------------------------------------------------------------------------
#endif
