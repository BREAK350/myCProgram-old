//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include "Unit1.h"
#include <math.h>
//---------------------------------------------------------------------------
class TDf {
 private:
    float value;
 public:
    TDf operator=(float);
    float operator+(float);
    TDf operator-(float);
    TDf operator*(float);
    TDf operator/(float);
           };
//---------------------------------------------------------------------------
class Alpha {
 private:
    float alpha;
 public:
    Alpha operator=(float);
    Alpha operator+=(float);
    Alpha operator-(float);
    void CheckAlpha();
    float degree();
            };
//---------------------------------------------------------------------------
class V {
 private:
    float v;
 public:
    V operator=(float);
    V operator+(float);
    V operator-(float);
    float value();
            };
//---------------------------------------------------------------------------
class CBoal {  
 private:
    float x,y;
    int r;
 public:
    CBoal();
    ~CBoal();
    Alpha   alpha;
    V       v;
    void DrawBoal(int,int,TForm*);
    void ClearBoal(int,int,TForm*);
    void Radius(int);
    void Move();
            };
//---------------------------------------------------------------------------
#endif
