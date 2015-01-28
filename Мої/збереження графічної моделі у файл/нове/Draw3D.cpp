//---------------------------------------------------------------------------
#pragma hdrstop
#include "Draw3D.h"
//---------------------------------------------------------------------------
int X,Y,K=100;
//---------------------------------------------------------------------------
vector3::operator=(vector3 v)
{
    x=v.x;
    y=v.y;
    z=v.z;
}
//---------------------------------------------------------------------------
vector3 vector3::operator+(vector3 v)
{
    vector3 p;
    p.x=x+v.x;
    p.y=y+v.y;
    p.z=z+v.z;
    return p;
}
//---------------------------------------------------------------------------
vector3 vector3::operator+(float f)
{
    vector3 p;
    p.x=x+f;
    p.y=y+f;
    p.z=z+f;
    return p;
}
//---------------------------------------------------------------------------
vector3 vector3::operator*(float f)
{
    vector3 p;
    p.x=x*f;
    p.y=y*f;
    p.z=z*f;
    return p;
}
//---------------------------------------------------------------------------
vector3 vector3::operator-(vector3 v)
{
    vector3 p;
    p.x=x-v.x;
    p.y=y-v.y;
    p.z=z-v.z;
    return p;
}
//---------------------------------------------------------------------------
vector3::operator+=(vector3 v)
{
    x+=v.x;
    y+=v.y;
    z+=v.z;
}
//---------------------------------------------------------------------------
vector3 matrix33::operator*(vector3 vc)
{
    vector3 p;
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
float vector3::fi()
{
    return acos(z/d())*180/M_PI;
}
//---------------------------------------------------------------------------
float vector3::d()
{
    return sqrt(x*x+y*y+z*z);
}
//---------------------------------------------------------------------------
float vector3::theta()
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
void matrix33::Rr(vector3 vc,float alpha)
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
void Draw3DPointInBmp(vector3 t,TColor col,Graphics::TBitmap*bmp)
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
void Draw3DLineInBmp(vector3 t1,vector3 t2,TColor col,Graphics::TBitmap*bmp)
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
vector3 vector3::Init(float _x,float _y,float _z)
{
    vector3 v;
    v.x=x=_x;
    v.y=y=_y;
    v.z=z=_z;
    return v;
}
//---------------------------------------------------------------------------
vector3 vector3::Init(float fi,float theta)
{
    vector3 v;
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
    point=(vector3*)malloc(n_point*sizeof(vector3));
    fread(point,n_point,sizeof(vector3),f);
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
void TModel::Draw3DModel(vector3 see,float alpha,vector3 loc,Graphics::TBitmap*bmp)
{
    int i,j;
    X=bmp->Width/2;
    Y=bmp->Height/2;
    for(i=1;i<=n_point;i++)
    {
        for(j=1;j<i;j++)
        {
            point[i-1].Change(see,alpha,loc,S).Draw3DMoveTo(bmp);
            if(is_Line(grf,i,j)==1)
            {
                point[j-1].Change(see,alpha,loc,S).Draw3DLineTo(clBlack,bmp);
            }
        }
    }
}
//---------------------------------------------------------------------------
vector3 vector3::Change(vector3 see,float alpha,vector3 loc,float S)
{
    vector3 v;
    matrix33 R;
    v.Init(x,y,z);
    R.Rr(see,alpha);
    return (R*v*S-loc);
}
//---------------------------------------------------------------------------
vector2 vector3::Change(vector3 see,vector3 loc,float S)
//see{x=fi,y=theta,z=alpha}
{
    vector3 v;
    vector2 v2;
    matrix33 R;
    v.Init(see.x,see.y);
    R.Rr(v,see.z);
    v.Init(x,y,z);
    v=(R*v*S-loc);
    if(v.z>K)
    {
        v2.x=K*v.x/v.z;
        v2.y=K*v.y/v.z;
    }
    return v2;
}
//---------------------------------------------------------------------------
void vector3::Draw3DMoveTo(Graphics::TBitmap*bmp)
{
    if(z>K)
    {
        bmp->Canvas->MoveTo(K*x/z+X,Y-K*y/z);
    }
}
//---------------------------------------------------------------------------
void vector3::Draw3DLineTo(TColor col,Graphics::TBitmap*bmp)
{
    int X=bmp->Width/2,
        Y=bmp->Height/2;
    if(z>K)
    {
        bmp->Canvas->Pen->Color=col;
        bmp->Canvas->LineTo(K*x/z+X,Y-K*y/z);
    }
}
//---------------------------------------------------------------------------
int _is_Line(graf *grf,int point1,int point2)
{
    int k,i;
    grafbit r;
    if(point1==point2 || point1<=0 || point2<=0)
    {
        return 0;
    }
    if(point1<point2)
    {
        point1=point1+point2;
        point2=point1-point2;
        point1=point1-point2;
    }
    k=0;
    point1--;
    for(i=0;i<point1;i++)
    {
        k+=i;
    }
    k=k+point2-1;
    r.d=grf[k/8];
    k=k-8*(k/8);
    switch(k)
    {
        case 0:return r.bit.b7;
        case 1:return r.bit.b6;
        case 2:return r.bit.b5;
        case 3:return r.bit.b4;
        case 4:return r.bit.b3;
        case 5:return r.bit.b2;
        case 6:return r.bit.b1;
        case 7:return r.bit.b0;
    }
}
//---------------------------------------------------------------------------
int is_Line(graf *grf,int point1,int point2)
{
    if(_is_Line(grf,point1,point2)==-1)
    {
        return 1;
    }
    return 0;
}
//---------------------------------------------------------------------------
bool isPointIsTriangle(float x4,float y4,float x1,float y1,float x2,float y2,float x3,float y3)
{
    float a,b,c;
    if(y1!=y2)
    {
        a=x1+(x2-x1)*(y4-y1)/(y2-y1);
    }
    else
    {
        a=(x1+x2)/2;
    }
    if(y1!=y3)
    {
        b=x3+(x1-x3)*(y4-y3)/(y1-y3);
    }
    else
    {
        b=(x1+x3)/2;
    }
    if(y2!=y3)
    {
        c=x2+(x3-x2)*(y4-y2)/(y3-y2);
    }
    else
    {
        c=(x2+x3)/2;
    }
    if(y4>=min(y1,y2) && y4<=max(y1,y2))
    {
        if(y4>=min(y1,y3) && y4<=max(y1,y3))
        {
            if(x4<min(a,b) || x4>max(a,b))
            {
                return false;
            }
        }
        else
        {
            if(x4<min(a,c) || x4>max(a,c))
            {
                return false;
            }
        }
    }
    else
    {
        if(x4<min(b,c) || x4>max(b,c))
        {
            return false;
        }
    }
    //*****************
    if(x1!=x2)
    {
        a=y1+(y2-y1)*(x4-x1)/(x2-x1);
    }
    else
    {
        a=(y1+y2)/2;
    }
    if(x1!=x3)
    {
        b=y3+(y1-y3)*(x4-x3)/(x1-x3);
    }
    else
    {
        b=(y1+y3)/2;
    }
    if(x2!=x3)
    {
        c=y2+(y3-y2)*(x4-x2)/(x3-x2);
    }
    else
    {
        c=(y2+y3)/2;
    }
    if(x4>=min(x1,x2) && x4<=max(x1,x2))
    {
        if(x4>=min(x1,x3) && x4<=max(x1,x3))
        {
            if(y4<min(a,b) || y4>max(a,b))
            {
                return false;
            }
        }
        else
        {
            if(y4<min(a,c) || y4>max(a,c))
            {
                return false;
            }
        }
    }
    else
    {
        if(y4<min(b,c) || y4>max(b,c))
        {
            return false;
        }
    }
    return true;
}
//---------------------------------------------------------------------------
float min(float a,float b)
{
    if(a>b)
    {
        return b;
    }
    return a;
}
//---------------------------------------------------------------------------
float max(float a,float b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}
//---------------------------------------------------------------------------
float min(float a,float b,float c)
{
    if(a>b)
    {
        if(b>c)
        {
            return c;
        }
        return b;
    }
    else
    {
        if(a>c)
        {
            return c;
        }
        return a;
    }
}
//---------------------------------------------------------------------------
float max(float a,float b,float c)
{
    if(a>b)
    {
        if(a>c)
        {
            return a;
        }
        return c;
    }
    else
    {
        if(b>c)
        {
            return b;
        }
        return c;
    }
}
//---------------------------------------------------------------------------
void Triagle::Draw3DTriagle(vector3 see,float alpha,vector3 loc,Graphics::TBitmap*bmp)
{
    vector3 d;
   // for(i=1;i<=n;i++)
    {
       // for(j=1;j<i;j++)
        {
           // point[i-1].Change(see,alpha,loc,S).Draw3DMoveTo(bmp);
          //  if(is_Line(grf,i,j)==1)
            {
          //      point[j-1].Change(see,alpha,loc,S).Draw3DLineTo(clBlack,bmp);
            }
        }
    }
}
//---------------------------------------------------------------------------
void vector2::Draw3DMoveTo(Graphics::TBitmap*bmp)
{
    bmp->Canvas->MoveTo(x,y);
}
//---------------------------------------------------------------------------
void vector2::Draw3DLineTo(TColor col,Graphics::TBitmap*bmp)
{
    bmp->Canvas->Pen->Color=col;
    bmp->Canvas->LineTo(x,y);
}
//---------------------------------------------------------------------------
void vector2::Draw3DPixel(TColor col,Graphics::TBitmap*bmp)
{
    bmp->Canvas->Pixels[x][y]=col;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
