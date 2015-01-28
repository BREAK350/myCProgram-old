//---------------------------------------------------------------------------
#pragma hdrstop
#include "Draw3D.h"
//---------------------------------------------------------------------------
int X,Y,i,j,er;
unsigned short int n1,n2;
float Front=100;
//---------------------------------------------------------------------------
void TModel::LoadFromFile(char*fname)
{
    FILE *f;
    f=fopen(fname,"rb");
    if(!f)
    {
        N_point=N_line=N_triagle=0;
        point=NULL;
        line=NULL;
        col=NULL;
        return;
    }
    fread(&N_point,sizeof(int),1,f);
    if(N_point>256)
    {
        return;
    }
    fread(&N_line,sizeof(int),1,f);
    fread(&N_triagle,sizeof(int),1,f);
    point=new vector3[N_point];
    line=new Line[N_line];
    col=new TColor[N_line+N_triagle];
    fread(point,sizeof(vector3),N_point,f);
    fread(line,sizeof(Line),N_line,f);
    fread(col,sizeof(TColor),N_line+N_triagle,f);
    fclose(f);
}
//---------------------------------------------------------------------------
void TModel::Draw3DModel(vector3 see,vector3 loc,Graphics::TBitmap*bmp)
{
    int k=0;
    if(N_point==0 || N_point>256)
    {
        return;
    }
    X=bmp->Width/2;
    Y=bmp->Height/2;
    for(i=0;i<N_line;i++)
    {
        n1=line[i].l>>8;
        n2=line[i].l-(n1<<8);
        if(n1!=n2)
        {
            point[n1].Change(see,loc,S).Draw3DMoveTo(bmp);
            point[n2].Change(see,loc,S).Draw3DLineTo(col[k],bmp);
            k++;
        }
    }
}
//---------------------------------------------------------------------------
float vector3::d()
{
    return sqrt(x*x+y*y+z*z);
}
//---------------------------------------------------------------------------
vector3 vector3::Change(vector3 see,vector3 loc,float S)
//see{x=fi,y=theta,z=alpha}
{
    vector3 v;
    matrix33 R;
    v.Init(see.x,see.y);
    R.Rr(v,see.z);
    v.Init(x,y,z);
    v=(R*v*S-loc);
    if(v.z>Front)
    {
        v.x=Front*v.x/v.z;
        v.y=Front*v.y/v.z;
        er=1;
    }
    else
    {
        er=0;
    }
    return v;
}
//---------------------------------------------------------------------------
void vector3::Draw3DMoveTo(Graphics::TBitmap*bmp)
{
    if(z>Front)
    {
        bmp->Canvas->MoveTo(x+X,Y-y);
    }
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
vector3 vector3::Init(float _x,float _y,float _z)
{
    vector3 v;
    v.x=x=_x;
    v.y=y=_y;
    v.z=z=_z;
    return v;
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
vector3::operator=(vector3 v)
{
    x=v.x;
    y=v.y;
    z=v.z;
}
//---------------------------------------------------------------------------
void vector3::Draw3DLineTo(TColor col,Graphics::TBitmap*bmp)
{
    if(z>Front)
    {
        bmp->Canvas->Pen->Color=col;
        bmp->Canvas->LineTo(x+X,Y-y);
    }
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
#pragma package(smart_init)
