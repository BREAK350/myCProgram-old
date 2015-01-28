//---------------------------------------------------------------------------
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
struct TColorObj {
 int k1,k2,k3;
              };
struct TPoint {
 int x,y;
              };
struct TElementObject {
 int kpoint;
 TPoint *point;
 int angle;
 int height;
 TColorObj line,brush;
               };
struct TObject {
 int kelement;
 int angle;
 int height;
 TElementObject *element;
               };
struct TTrack {
 char name[10];
 TColorObj brush;
 int kobject;
 TObject *object;
              };
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

