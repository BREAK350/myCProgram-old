//---------------------------------------------------------------------------

#pragma hdrstop
#include "main.h"
#include "DrawFunction.h"
#include "SaveLoad.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void Draw2D(TTrack Track)
{
 Form1->Canvas->Brush ->Color=(TColor) RGB(255,255,255);
 Form1->Canvas->Pen->Color=(TColor) RGB(255,255,255);
 Form1-> Canvas->Rectangle(0,0,1000,1000);
 Form1-> Canvas->FloodFill(400,200,Form1->Color, fsBorder);
 Form1->Canvas->Pen->Color=(TColor) RGB(0,0,0);
 Form1->Canvas->Pen->Width=1;
 Form1->Canvas->MoveTo(200,200);
 Form1->Canvas->LineTo(600,200);
 Form1->Canvas->MoveTo(400,0);
 Form1->Canvas->LineTo(400,400);
}

void Draw2DElementObject(TElementObject ElementObject)
{
 int i;
 //-------------
 ElementObject.kpoint=3;
 ElementObject.point=(TPoint2d*)malloc(3*sizeof(TPoint2d));
 ElementObject.point[0].x=100;
 ElementObject.point[0].y=100;
 ElementObject.point[1].x=200;
 ElementObject.point[1].y=300;
 ElementObject.point[2].x=400;
 ElementObject.point[2].y=100;
 ElementObject.PlacePaint.x=120;
 ElementObject.PlacePaint.y=120;
 ElementObject.line.k1=0;
 ElementObject.line.k2=0;
 ElementObject.line.k3=0;
 ElementObject.brush.k1=0;
 ElementObject.brush.k2=0;
 ElementObject.brush.k3=255;
 //-------------
 Form1->Canvas->Brush->Color=(TColor)RGB(ElementObject.brush.k1,ElementObject.brush.k2,ElementObject.brush.k3);
 Form1->Canvas->Pen->Color=(TColor)RGB(ElementObject.line.k1,ElementObject.line.k2,ElementObject.line.k3);
 Form1->Canvas->Pen->Width=1;
 Form1->Canvas->MoveTo(ElementObject.point[0].x,ElementObject.point[0].y);
 for(i=1;i<ElementObject.kpoint;i++)
  Form1->Canvas->LineTo(ElementObject.point[i].x,ElementObject.point[i].y);
 Form1->Canvas->LineTo(ElementObject.point[0].x,ElementObject.point[0].y);
// Form1->Canvas->FloodFill(ElementObject.PlacePaint.x,ElementObject.PlacePaint.y,(TColor)RGB(ElementObject.line.k1,ElementObject.line.k2,ElementObject.line.k3),fsSurface);
 Form1->Canvas->FloodFill(ElementObject.PlacePaint.x,ElementObject.PlacePaint.y,(TColor)RGB(ElementObject.line.k1,ElementObject.line.k2,ElementObject.line.k3),fsBorder);
}
//---------------------------------------------------------------------------
void Draw2DPicture(int x,int y,TPicture2d Picture)
{
 int i,j;
 for(i=0;i<Picture.width;i++)
  for(j=0;j<Picture.height;j++)
   if((Picture.points[i][j].k1>0)&&(Picture.points[i][j].k2>0)&&(Picture.points[i][j].k3>0))
    Form1->Canvas->Pixels[x+i][y+j]=ColorRGB(Picture.points[i][j]);
}
//---------------------------------------------------------------------------
TColor ColorRGB(TColorObj cl)
{
 return (TColor)RGB(cl.k1,cl.k2,cl.k3);
}
TColor ColorRGB(TColorObjChar cl)
{
 return (TColor)RGB(cl.k1,cl.k2,cl.k3);
}
//---------------------------------------------------------------------------
