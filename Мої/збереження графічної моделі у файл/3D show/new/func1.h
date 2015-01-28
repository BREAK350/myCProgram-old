//---------------------------------------------------------------------------
#ifndef func1H
#define func1H
//---------------------------------------------------------------------------
#include <math.h>
#include <alloc.h>
#include <stdio.h>
#include <vcl.h>
#include "Unit1.h"
#include "MatrixKey2.h"
typedef char graf;
//---------------------------------------------------------------------------
class Point3D
{
    public:
        float x,y,z;
        void Move(Point3D);
        void TurnOX(Point3D);
        void TurnOY(Point3D);
        void TurnOZ(Point3D);
        void TurnOXOYOZ(Point3D);
        TMatrix ToMatrix();
        void MatrixToPoint3D(TMatrix);
};
//---------------------------------------------------------------------------
struct bits
{
    graf b0:1,b1:1,b2:1,b3:1,b4:1,b5:1,b6:1,b7:1;
};
//---------------------------------------------------------------------------
class location
{
    public:
        Point3D p3d,
                alpha;
        location();
};
//---------------------------------------------------------------------------
union grafbit
{
    graf d;
    bits bit;
};
//---------------------------------------------------------------------------
class TModelDetail
{
    public:
        int           n_point;
        Point3D       *point,
                      *chp;
        location      loc;
        graf          *grf;
        float         scale;
};
//---------------------------------------------------------------------------
class LoadSave:TModelDetail
{
    public:
        void          SaveToFile(char*);
        void          LoadToFile(char*);
        void          CreateGraf();
};
//---------------------------------------------------------------------------
class CreateModel:TModelDetail
{
    public:
        void          CreateGraf();
        void          CreateLine(int,int);
        void          DeleteLine(int,int);
        int           isLine(int,int);
};
//---------------------------------------------------------------------------
class Change:TModelDetail
{
    public:
        Point3D       Move(Point3D);
        Point3D       TurnOX(Point3D);
        Point3D       TurnOY(Point3D);
        Point3D       TurnOZ(Point3D);
        void          CreateCHP();
        void          ChangeCHP();
};
//---------------------------------------------------------------------------
class ShowForm:TModelDetail
{
    public:
        void          Show(Point3D);
        void          ShowCHP(location);
        int           isLine(int,int);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class TModel
{
    public:
        TModelDetail  detail;
        LoadSave      ls;
        CreateModel   build;
        Change        change;
        ShowForm          show;
};
//---------------------------------------------------------------------------
int     _is_Line(graf*,int,int);
int     is_Line(graf*,int,int);
graf*   _CreateGraf(int);
int     _CreateLine(graf*&,int,int);
int     _DeleteLine(graf*&,int,int);
void    FormXY(Point3D);
Point3D _3DTo2D(Point3D);
void    ShowPoint(Point3D);
TMatrix CreateOX(float);
//---------------------------------------------------------------------------
#endif
