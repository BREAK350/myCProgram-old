//---------------------------------------------------------------------------
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <vcl.h>
#ifndef DrawFunctionH
#define DrawFunctionH
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
struct TColorObj {
 int k1,k2,k3;
                 };
struct TColorObjEl {
int cl;
                   };
struct TColorObjChar {
unsigned char k1,k2,k3;
                     };
struct TPoint2d {
 int x,y;
              };
struct TElementObject {
 int kpoint;
 TPoint2d *point,PlacePaint;
 int angle;
 int height;
 TColorObj line,brush;
               };
struct TObject2d {
 TPoint2d place;
 int kelement;
 int angle;
 int height;
 TElementObject *element;
               };
struct TTrack {
 char name[10];
 TColorObj brush;
 int kobject;
 TObject2d *object;
              };
struct TPicture2d {
 int width;
 int height;
 TColorObjChar **points;
               };
//---------------------------------------------------------------------------
void Draw2D(TTrack);
void Draw2DElementObject(TElementObject);
TColor ColorRGB(TColorObj);
TColor ColorRGB(TColorObjChar);
//---------------------------------------------------------------------------
void Draw2DPicture(int,int,TPicture2d);
//---------------------------------------------------------------------------

