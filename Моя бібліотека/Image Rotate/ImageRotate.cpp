//---------------------------------------------------------------------------
#pragma hdrstop
#include "ImageRotate.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
double GetMinX(const TbVector2d *p,const int &n)
{
	double MinX=p[0].X;
	for(int i=1;i<n;i++)
	{
		if(MinX>p[i].X)
		{
			MinX=p[i].X;
		}
	}
	return MinX;
}
//---------------------------------------------------------------------------
double GetMinY(const TbVector2d *p,const int &n)
{
	double MinY=p[0].Y;
	for(int i=1;i<n;i++)
	{
		if(MinY>p[i].Y)
		{
			MinY=p[i].Y;
		}
	}
	return MinY;
}
//---------------------------------------------------------------------------
double GetMaxX(const TbVector2d *p,const int &n)
{
	double MaxX=p[0].X;
	for(int i=1;i<n;i++)
	{
		if(MaxX<p[i].X)
		{
			MaxX=p[i].X;
		}
	}
	return MaxX;
}
//---------------------------------------------------------------------------
double GetMaxY(const TbVector2d *p,const int &n)
{
	double MaxY=p[0].Y;
	for(int i=1;i<n;i++)
	{
		if(MaxY<p[i].Y)
		{
			MaxY=p[i].Y;
		}
	}
	return MaxY;
}
//---------------------------------------------------------------------------
void BitmapRotate(Graphics::TBitmap *pFromBitmap,
	Graphics::TBitmap *pToBitmap,const double &Radians)
{
	double vCosinus=cos(Radians);
	double vSinus=sin(Radians);
	TbVector2d p[4];
	p[0]=TbVector2d(0,0);
	p[1]=TbVector2d(pFromBitmap->Width,0);
	p[2]=TbVector2d(0,pFromBitmap->Height);
	p[3]=TbVector2d(pFromBitmap->Width,pFromBitmap->Height);
	for(int i=0;i<4;i++)
	{
		p[i].Rotate(Radians);
	}
	TbVector2d TopLeft(GetMinX(p,4),GetMinY(p,4)),
			   BottomRight(GetMaxX(p,4),GetMaxY(p,4));

	pToBitmap->Height=ceil(BottomRight.Y-TopLeft.Y);
	pToBitmap->Width=ceil(BottomRight.X-TopLeft.X);
	SetGraphicsMode(pToBitmap->Canvas->Handle,GM_ADVANCED);
	XFORM xform;
	xform.eM11=vCosinus;
	xform.eM12=vSinus;
	xform.eM21=-vSinus;
	xform.eM22=vCosinus;
	xform.eDx=-TopLeft.X;
	xform.eDy=-TopLeft.Y;
	SetWorldTransform(pToBitmap->Canvas->Handle,&xform);
	BitBlt(pToBitmap->Canvas->Handle,0,0,
		pFromBitmap->Width,
		pFromBitmap->Height,
		pFromBitmap->Canvas->Handle,
		0,
		0,
		SRCCOPY);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
