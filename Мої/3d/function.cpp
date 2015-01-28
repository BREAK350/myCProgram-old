//---------------------------------------------------------------------------

#pragma hdrstop
#include "space.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
vector3 VectorNaMatrix3(vector3 v,matrix3 m)
{
int i;
vector3 r;
for(i=0;i<3;i++)
  r.v[i]=v.v[0]*m.a[0][i]+v.v[1]*m.a[1][i]+v.v[2]*m.a[2][i];
return r;
}

void PrintVector3(vector3 v)
{
  printf("%1.3f %1.3f %1.3f",v.v[0],v.v[1],v.v[2]);
}

void ScanVector3(vector3 &v)
{
scanf("%f%f%f",&v.v[0],&v.v[1],&v.v[2]);
}

void PrintMatrix3(matrix3 m)
{
 int i,j;
 for(i=0;i<3;i++)
 {
   for(j=0;j<3;j++)
     printf("%1.3f ",m.a[i][j]);
  printf("\n");
 }
}

void ScanMatrix3(matrix3 &m)
{
int i,j;
 for(i=0;i<3;i++)
   for(j=0;j<3;j++)
     scanf("%f",&m.a[i][j]);
}

point2 xyz_xy(point3 p,data3dWorld data)
{
point2 t;
t.x=p.x*data.eyes/p.z;
t.y=p.y*data.eyes/p.z;
return t;
}

point3 AbsoluteXYZ(point3 p,data3dWorld data)
{
point3 d,t;
d.x=p.x+data.Point_of_view.x;
d.y=p.y+data.Point_of_view.y;
d.z=p.z+data.Point_of_view.z;
t.x=data.side+(d.x*cos(data.betta*pi/180)-(d.z*cos(data.alfa*pi/180)-d.y*sin(data.alfa*pi/180))*sin(data.betta*pi/180))*cos(data.gamma*pi/180)-(d.z*sin(data.alfa*pi/180)+d.y*cos(data.alfa*pi/180))*sin(data.gamma*pi/180);
t.y=data.height+(d.x*cos(data.betta*pi/180)-(d.z*cos(data.alfa*pi/180)-d.y*sin(data.alfa*pi/180))*sin(data.betta*pi/180))*sin(data.gamma*pi/180)+(d.z*sin(data.alfa*pi/180)+d.y*cos(data.alfa*pi/180))*cos(data.gamma*pi/180);
t.z=data.distance+d.x*sin(data.betta*pi/180)+(d.z*cos(data.alfa*pi/180)-d.y*sin(data.alfa*pi/180))*cos(data.betta*pi/180);
return t;
}

void InitData3(data3dWorld &data)
{
data.alfa=data.betta=data.gamma=0;
data.distance=data.side=data.height=0;
data.Point_of_view.x=0;
data.Point_of_view.y=0;
data.Point_of_view.z=0;
data.eyes=0;
data.scale=10;
}

void InitData2(data2dWorld &data)
{
data.x0=300;
data.y0=300;
}

int is_point(point3 a)
{
if(a.z>0)
 return 1;
return 0;
}
int Line3D(point3 a,point3 b,data3dWorld data,data2dWorld data2)
{
point3 t;
point2 p;
t=AbsoluteXYZ(a,data);
if(is_point(t)==0)
  return 0;
p=xyz_xy(t,data);
Form1->Canvas->MoveTo(data2.x0+data.scale*p.x,data2.y0-data.scale*p.y);
t=AbsoluteXYZ(b,data);
if(is_point(t)==0)
  return 0;
p=xyz_xy(t,data);
Form1->Canvas->LineTo(data2.x0+data.scale*p.x,data2.y0-data.scale*p.y);
return 1;
}

point3 convert_point3(float x,float y,float z)
{
point3 t;
t.x=x;
t.y=y;
t.z=z;
return t;
}

point2 convert_point2(float x,float y)
{
point2 t;
t.x=x;
t.y=y;
return t;
}
