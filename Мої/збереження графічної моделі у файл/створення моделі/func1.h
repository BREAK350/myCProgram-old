//---------------------------------------------------------------------------
#ifndef func1H
#define func1H
//---------------------------------------------------------------------------
#include <math.h>
#include <alloc.h>
#include <stdio.h>
#include <vcl.h>
#include "Unit1.h"
typedef char graf;
//---------------------------------------------------------------------------
struct Point2D
{
    float x,y;
};
struct bits
{
    graf b0:1,b1:1,b2:1,b3:1,b4:1,b5:1,b6:1,b7:1;
};
union grafbit
{
    graf d;
    bits bit;
};
class TModel
{
    public:
        int n_point;
        Point2D *point;
        graf *grf;
        void CreateGraf();
        void CreateLine(int,int);
        int isLine(int,int);
        void SaveToFile(char*);
        void LoadToFile(char*);
        void Show(Point2D);
};
//---------------------------------------------------------------------------
struct listitem
{
    Point2D point;
    int i;
    listitem*next,*prev;
};
//---------------------------------------------------------------------------
int     _is_Line(graf*,int,int);
int     is_Line(graf*,int,int);
graf*   _CreateGraf(int);
int     _CreateLine(graf*&,int,int);
//---------------------------------------------------------------------------
#endif
