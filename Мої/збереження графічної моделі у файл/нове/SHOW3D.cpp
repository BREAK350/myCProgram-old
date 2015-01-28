//---------------------------------------------------------------------------
#pragma hdrstop
#include "SHOW3D.h"
//---------------------------------------------------------------------------
vector::vector()
{
    x=y=z=0;
}
//---------------------------------------------------------------------------
vector::operator=(vector v)
{
    x=v.x;
    y=v.y;
    z=v.z;
}
//---------------------------------------------------------------------------
vector vector::operator+(vector v)
{
    vector p;
    p.x=x+v.x;
    p.y=y+v.y;
    p.z=z+v.z;
    return p;
}
//---------------------------------------------------------------------------
vector vector::operator+(float f)
{
    vector p;
    p.x=x+f;
    p.y=y+f;
    p.z=z+f;
    return p;
}
//---------------------------------------------------------------------------
vector vector::operator*(float f)
{
    vector p;
    p.x=x*f;
    p.y=y*f;
    p.z=z*f;
    return p;
}
//---------------------------------------------------------------------------
vector vector::operator-(vector v)
{
    vector p;
    p.x=x-v.x;
    p.y=y-v.y;
    p.z=z-v.z;
    return p;
}
//---------------------------------------------------------------------------
vector::operator+=(vector v)
{
    x+=v.x;
    y+=v.y;
    z+=v.z;
}
//---------------------------------------------------------------------------
vector matrix33::operator*(vector vc)
{
    vector p;
    p.x=v[0][0]*vc.x+v[0][1]*vc.y+v[0][2]*vc.z;
    p.y=v[1][0]*vc.x+v[1][1]*vc.y+v[1][2]*vc.z;
    p.z=v[2][0]*vc.x+v[2][1]*vc.y+v[2][2]*vc.z;
    return p;
}
//---------------------------------------------------------------------------
void matrix33::Rx(float alpha)
{
    alpha*=M_PI/180;
    v[0][0]=1;
    v[0][1]=v[0][2]=v[1][0]=v[2][0]=0;
    v[1][1]=v[2][2]=cos(alpha);
    v[2][1]=sin(alpha);
    v[1][2]=-v[2][1];
}
//---------------------------------------------------------------------------
void matrix33::Ry(float alpha)
{
    alpha*=M_PI/180;
    v[1][1]=1;
    v[0][1]=v[1][0]=v[1][2]=v[2][1]=0;
    v[0][0]=v[2][2]=cos(alpha);
    v[0][2]=sin(alpha);
    v[2][0]=-v[0][2];
}
//---------------------------------------------------------------------------
void matrix33::Rz(float alpha)
{
    alpha*=M_PI/180;
    v[2][2]=1;
    v[0][2]=v[1][2]=v[2][0]=v[2][1]=0;
    v[0][0]=v[1][1]=cos(alpha);
    v[1][0]=sin(alpha);
    v[0][1]=-v[1][0];
}
//---------------------------------------------------------------------------
float vector::fi()
{
    return acos(z/d())*180/M_PI;
}
//---------------------------------------------------------------------------
float vector::d()
{
    return sqrt(x*x+y*y+z*z);
}
//---------------------------------------------------------------------------
float vector::theta()
{
    if(x>0)
    {
        return atan(x/y)*180/M_PI;
    }
    else
    {
        if(x==0)
        {
            if(y>=0)
            {
                return 90;
            }
            else
            {
                return 270;
            }
        }
        else
        {
            return (M_PI+atan(x/y))*180/M_PI;
        }
    }
}
//---------------------------------------------------------------------------
void matrix33::Rr(vector vc,float alpha)
{
    alpha*=M_PI/180;
    v[0][0]=cos(alpha)+vc.x*vc.x*(1-cos(alpha));
    v[0][1]=vc.x*vc.y*(1-cos(alpha))-vc.z*sin(alpha);
    v[0][2]=vc.x*vc.z*(1-cos(alpha))+vc.y*sin(alpha);
    v[1][0]=vc.y*vc.x*(1-cos(alpha))+vc.z*sin(alpha);
    v[1][1]=cos(alpha)+vc.y*vc.y*(1-cos(alpha));
    v[1][2]=vc.y*vc.z*(1-cos(alpha))-vc.x*sin(alpha);
    v[2][0]=vc.z*vc.x*(1-cos(alpha))-vc.y*sin(alpha);
    v[2][1]=vc.z*vc.y*(1-cos(alpha))+vc.x*sin(alpha);
    v[2][2]=cos(alpha)+vc.z*vc.z*(1-cos(alpha));
}
//---------------------------------------------------------------------------
void Draw3DPointInBmp(vector t,TColor col,Graphics::TBitmap*bmp)
{
    int X=bmp->Width/2,
        Y=bmp->Height/2;
    if(t.z!=0)
    {
        t.x*=1/t.z;
        t.y*=1/t.z;
    }
    bmp->Canvas->Pixels[t.x+X][Y-t.y]=col;
}
//---------------------------------------------------------------------------
void Draw3DLineInBmp(vector t1,vector t2,TColor col,Graphics::TBitmap*bmp)
{
    int X=bmp->Width/2,
        Y=bmp->Height/2;
    t1.z;
    /*if(t1.z!=0)
    {
        t1.x*=1/t1.z;
        t1.y*=1/t1.z;
    }*/
    bmp->Canvas->MoveTo(t1.x+X,Y-t1.y);
    /*if(t2.z!=0)
    {
        t2.x*=1/t2.z;
        t2.y*=1/t2.z;
    }*/
    t2.z;
    bmp->Canvas->Pen->Color=col;
    bmp->Canvas->LineTo(t2.x+X,Y-t2.y);
}
//---------------------------------------------------------------------------
vector vector::Init(float _x,float _y,float _z)
{
    vector v;
    v.x=x=_x;
    v.y=y=_y;
    v.z=z=_z;
    return v;
}
//---------------------------------------------------------------------------
vector vector::Init(float fi,float theta)
{
    vector v;
    v.z=z=cos(fi*M_PI/180);
    v.x=x=sin(fi*M_PI/180)*cos(theta*M_PI/180);
    v.y=y=sin(fi*M_PI/180)*sin(theta*M_PI/180);
    return v;
}
//---------------------------------------------------------------------------
void TModel::LoadFromFile(char*fname)
{
    int i,k;
    FILE *f;
    f=fopen(fname,"rb");
    fread(&n_point,1,sizeof(int),f);
    free(point);
    point=(vector*)malloc(n_point*sizeof(vector));
    fread(point,n_point,sizeof(vector),f);
    CreateGraf();
    for(i=0,k=0;i<n_point;i++)
    {
        k+=i;
    }
    k=k/8+1;
    fread(grf,k,sizeof(graf),f);
    fclose(f);
}
//---------------------------------------------------------------------------
void TModel::CreateGraf()
{
    int i,k;
    for(i=0,k=0;i<n_point;i++)
    {
        k+=i;
    }
    k=k/8+1;
    grf=(graf*)calloc(k,sizeof(graf));
}
//---------------------------------------------------------------------------
void TModel::Draw3DModel(vector see,vector loc,Graphics::TBitmap*bmp)
{
    int X=bmp->Width/2,
        Y=bmp->Height/2;
    int i,j;
    for(i=1;i<=n_point;i++)
    {
        for(j=1;j<i;j++)
        {

        }
    }
}
//---------------------------------------------------------------------------
vector vector::Change(vector see,float alpha,vector loc,float S)
{
    vector v;
    matrix33 R;
    v.Init(x,y,z);
    R.Rr(see,alpha);
    return R*(v*S-loc);
}
//---------------------------------------------------------------------------
void vector::Draw3DMoveTo(Graphics::TBitmap*bmp)
{
    int X=bmp->Width/2,
        Y=bmp->Height/2;
    bmp->Canvas->MoveTo(x+X,Y-y);
}
//---------------------------------------------------------------------------
void vector::Draw3DLineTo(TColor col,Graphics::TBitmap*bmp)
{
    int X=bmp->Width/2,
        Y=bmp->Height/2;
    bmp->Canvas->LineTo(x+X,Y-y);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
