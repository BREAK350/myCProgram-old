//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
extern TVector g;
//---------------------------------------------------------------------------
TVector::TVector()
{
 x=y=alpha=v=0;
}
//---------------------------------------------------------------------------
void TVector::Interaction(TVector _vector)
{
 float x1,y1,x2,y2;
 x1=v*cos(degree());
 y1=v*sin(degree());
 x2=_vector.v*cos(_vector.degree());
 y2=_vector.v*sin(_vector.degree());
 x1+=x2;
 y1+=y2;
 v=sqrt(x1*x1+y1*y1);
 alpha=Degree0(x1,y1,v);
 Check();
}
//---------------------------------------------------------------------------
void TVector::Check()
{
 if(alpha>=360)
   alpha=alpha-360;
 else
   if(alpha<0)
     alpha=360+alpha;
}
//---------------------------------------------------------------------------
float TVector::degree()
{
 return alpha*M_PI/180;
}
//---------------------------------------------------------------------------
void TVector::Draw(int X,int Y,TForm *Form)
{
 Form->Canvas->Ellipse(x-2+X,Y-y-2,x+2+X,Y-y+2);
 Form->Canvas->MoveTo(x+X,Y-y);
 Form->Canvas->LineTo(v*cos(degree())+x+X,Y-v*sin(degree())-y);
}
//---------------------------------------------------------------------------
void TVector::Move()
{
 x+=v*cos(degree());
 y+=v*sin(degree());
}
//---------------------------------------------------------------------------
TBoal::TBoal()
{
 r=0;
}
//---------------------------------------------------------------------------
void TBoal::Draw(int X,int Y,TForm *Form,TColor cl)
{
 Form->Canvas->Pen->Color=cl;
 Form->Canvas->Ellipse(vector.x-r+X,Y-vector.y+r,vector.x+r+X,Y-vector.y-r);
}
//---------------------------------------------------------------------------
float TVector::DegreeLine(TVector vector)
{
 float alpha1,alpha2;
 alpha1=alpha;
 alpha2=vector.alpha;
 if(alpha1>180)
   alpha1=alpha1-180;
 if(alpha2>180)
   alpha2=alpha2-180;
 alpha2=fabs(alpha1-alpha2);
// if(alpha2>90)
//   alpha2=180-alpha2;
 return alpha2;
}
//---------------------------------------------------------------------------
float TVector::Degree0(float dx,float dy,float v1)
{
 float alpha1;
 if(v1==0)
   alpha1=0;
 else
  {
   if(dx>=0)
    {
     alpha1=dy/v1;
     alpha1=asin(alpha1)*180/M_PI;
    }
   else
    {
     alpha1=dy/v1;
     alpha1=180-asin(alpha1)*180/M_PI;
    }
  }
 Check(); 
 return alpha1;
}
//---------------------------------------------------------------------------
void TVector::CreateVector_xyxy(float x1,float y1,float x2,float y2)
{
 float dx,dy;
 dx=x2-x1;
 dy=y2-y1;
 v=sqrt(dx*dx+dy*dy);
 x=x1;
 y=y1;
 alpha=Degree0(dx,dy,v);
}
//---------------------------------------------------------------------------
mTPoint TVector::CrossVector(TVector vector)
{
 mTPoint point;
 point.x=point.y=-10000;
 float k1,k2,b1,b2;
 k1=tan(degree());
 k2=tan(vector.degree());
 b1=y-k1*x;
 b2=vector.y-k2*vector.x;
 if(k1-k2==0)
   return point;
 point.x=(b2-b1)/(k1-k2);
 point.y=k1*point.x+b1;
 return point;
}
//---------------------------------------------------------------------------
int TVector::Collision(TVector vec,float R)
{
 float x1,y1,d,a;
 TVector vec2;
 x1=x+v*cos(degree());
 y1=y+v*sin(degree());
 if(PointIsLine(x1,y1,R,vec.x,vec.y,vec.x+vec.v*cos(vec.degree()),vec.y+vec.v*sin(vec.degree()))==0)
   return 0;
 d=vec.Distance(x1,y1);
 if(d>R)
   return 0;
 CornerOfReflection(vec);
 //--------------------
 vec.v=sin(vec.degree())*g.v;
 vec.Check();
 if(vec.alpha<180)
   vec.OppositeCorner();
 Interaction(vec);
 //--------------------
 return 1;
}
//---------------------------------------------------------------------------
int PointIsLine(float x,float y,float R,float x1,float y1,float x2,float y2)
{
 float d;
 if(x1>x2)
  {
   d=x1;
   x1=x2;
   x2=d;
  }
 if(y1>y2)
  {
   d=y1;
   y1=y2;
   y2=d;
  }
 if((x1-R<=x)&&(x<=x2+R)&&(y1-R<=y)&&(y<=y2+R))
   return 1;
 return 0;
}
//---------------------------------------------------------------------------
mTPoint CrossPoint(float x,float y,TVector vec)
{
 mTPoint point;
 point.x=point.y=-10000;
 float k1,k2,b1,b2;
 k2=tan(vec.degree());
 if(k2!=0)
  {
   k1=-1/k2;
   b1=y-k1*x;
   b2=vec.y-k2*vec.x;
   if(k1-k2==0)
     return point;
   point.x=(b2-b1)/(k1-k2);
   point.y=k1*point.x+b1;
  }
 else
  {
   point.x=x;
   point.y=vec.y;
  }
 return point;
}
//---------------------------------------------------------------------------
float TVector::Distance(float x1,float y1)
{
 float k1,b1;
 k1=tan(degree());
 b1=y-k1*x;
 return fabs(k1*x1-y1+b1)/sqrt(k1*k1+1);
}
//---------------------------------------------------------------------------
float TVector::NoDirection()
{
 Check();
 if(alpha>180)
   alpha=alpha-180;
 return alpha;
}
//---------------------------------------------------------------------------
void TVector::CreateVector_xyalphav(float x1,float y1,float alpha1,float v1)
{
 x=x1;
 y=y1;
 alpha=alpha1;
 v=v1;
 Check();
}
//---------------------------------------------------------------------------
void TVector::CornerOfReflection(TVector vec)
{
 float a;
 //a=vec.alpha;
 //vec.alpha=0;
 //alpha=alpha-a;
 //alpha=180-alpha;
 //vec.alpha=a;
 //alpha=alpha+a;
 //OppositeCorner();
 alpha=2*vec.alpha-alpha;
}
//---------------------------------------------------------------------------
float TVector::OppositeCorner()
{
 alpha+=180;
 Check();
 return alpha;
}
//---------------------------------------------------------------------------


