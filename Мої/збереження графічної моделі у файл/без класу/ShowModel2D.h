//---------------------------------------------------------------------------
#ifndef ShowModel2DH
#define ShowModel2DH
#include "TModel.h"
#define clFon clBlack
#define clLine clYellow
//---------------------------------------------------------------------------
void          Show_(TModel,Point3D,Graphics::TBitmap*);
void          FormXY(Point3D);
int           is_Line(graf*,int,int);
void          ShowCHP(location);
void          ChangeCHP(TModel&);
Point3D       _3DTo2D(Point3D);
Point3D       Move(Point3D,Point3D);
void          Move_(Point3D);
void          TurnOX(Point3D);
void          TurnOY(Point3D);
void          TurnOZ(Point3D);
void          TurnOXOYOZ(Point3D&,Point3D);
void          BMPClear(Graphics::TBitmap*);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 