//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include "Unit1.h"
#include <math.h>
//---------------------------------------------------------------------------
class mTPoint {
 public:
    float x,y;
             };
//---------------------------------------------------------------------------
class TVector {
 public:
    float x,y,alpha,v;
    TVector();
    void Interaction(TVector);
    void Check();
    float degree();
    void Draw(int,int,TForm*);
    void Move();
    float DegreeLine(TVector);
    float Degree0(float,float,float);
    void CreateVector_xyxy(float,float,float,float);
    void CreateVector_xyalphav(float,float,float,float);
    mTPoint CrossVector(TVector);
    int Collision(TVector,float);
    float Distance(float,float);
    float NoDirection();
    void CornerOfReflection(TVector);
    float OppositeCorner();
              };
//---------------------------------------------------------------------------
class TBoal {
 public:
    TVector vector,
            projection;
    float r;
    TBoal();
    void Draw(int,int,TForm*,TColor);
   

            };
//---------------------------------------------------------------------------
int PointIsLine(float,float,float,float,float,float,float);
mTPoint CrossPoint(float,float,TVector);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#endif
