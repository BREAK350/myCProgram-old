//---------------------------------------------------------------------------
#pragma hdrstop
#include "Draw2D.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
int X,Y;
//---------------------------------------------------------------------------
point2D point2D::InitXY(float _x,float _y)
{
    point2D t;
    t.x=x=_x;
    t.y=y=_y;
    return t;
}
//---------------------------------------------------------------------------
point2D point2D::Draw2D(TColor col,Graphics::TBitmap*bmp)
{
    point2D t;
    X=bmp->Width/2;
    Y=bmp->Height/2;
    bmp->Canvas->Pixels[x+X][Y-y]=col;
    return t.InitXY(x,y);
}
//---------------------------------------------------------------------------
point2D point2D::MoveTo(Graphics::TBitmap*bmp)
{
    point2D t;
    X=bmp->Width/2;
    Y=bmp->Height/2;
    bmp->Canvas->MoveTo(x+X,Y-y);
    return t.InitXY(x,y);
}
//---------------------------------------------------------------------------
point2D point2D::LineTo(TColor col,Graphics::TBitmap*bmp)
{
    point2D t;
    X=bmp->Width/2;
    Y=bmp->Height/2;
    bmp->Canvas->Pen->Color=col;
    bmp->Canvas->LineTo(x+X,Y-y);
    return t.InitXY(x,y);
}
//---------------------------------------------------------------------------
float point2D::DistanceToPoint(point2D p)
{
    return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
}
//---------------------------------------------------------------------------
point2D point2D::SymmetryToPoint(point2D p)
{
    point2D t;
    return t.InitXY(2*p.x-x,2*p.y-y);
}
//---------------------------------------------------------------------------
float point2D::DistanceToLine(point2D p1,point2D p2)
{
    if(p1==p2)
    {
        return -1;
    }
    return fabs((p2.y-p1.y)*x-(p2.x-p1.x)*y-p1.x*(p2.y-p1.y)+p1.y*(p2.x-p1.x))/sqrt((p2.y-p1.y)*(p2.y-p1.y)+(p2.x-p1.x)*(p2.x-p1.x));
}
//---------------------------------------------------------------------------
bool point2D::operator==(point2D p)
{
    if(x==p.x && y==p.y)
    {
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------
point2D point2D::SymmetryToLine(point2D p1,point2D p2)
{
    float k;
    point2D t;
    if(p1==p2)
    {
        return SymmetryToPoint(p1);
    }
    if(p1.x==p2.x)
    {
        t.y=y;
        t.x=p1.x;
        return SymmetryToPoint(t);
    }
    k=(p2.y-p1.y)/(p2.x-p1.x);
    if(k==0)
    {
        t.x=x;
        t.y=p1.y;
        return SymmetryToPoint(t);
    }
    k=-1/k;
    float A=(p2.y-p1.y),
          B=(-p2.x+p1.y),
          C=(-p1.x*(p2.y-p1.y)+p1.y*(p2.x-p1.x)),
          b=(y-k*x);
    t.x=-(C+B*b)/(A+B*k);
    t.y=k*t.x+b;
    return SymmetryToPoint(t);
}
//---------------------------------------------------------------------------
point2D point2D::InitAlphaD(float alpha,float D)
{
    point2D t;
    alpha=alpha*M_PI/180;
    x=D*cos(alpha);
    y=D*sin(alpha);
    return t.InitXY(x,y);
}
//---------------------------------------------------------------------------
point2D point2D::TurnToPoint(point2D p,float alpha)
{
    point2D t;
    alpha*=M_PI/180;
    t.x=(x-p.x)*cos(alpha)-(y-p.y)*sin(alpha);
    t.y=(x-p.x)*sin(alpha)+(y-p.y)*cos(alpha);
    t=t+p;
    return t;
}
//---------------------------------------------------------------------------
point2D point2D::operator+(point2D p)
{
    point2D t;
    return t.InitXY(x+p.x,y+p.y);
}
//---------------------------------------------------------------------------
point2D point2D::operator*(float f)
{
    point2D t;
    return t.InitXY(x*f,y*f);
}
//---------------------------------------------------------------------------
point2D point2D::operator-(point2D p)
{
    point2D t;
    return t.InitXY(x-p.x,y-p.y);
}
//---------------------------------------------------------------------------
float point2D::Alpha()
{
    float alpha;
    if(y!=0)
    {
        return atan(x/y)*180/M_PI;
    }
    if(x>=0)
    {
        return 0;
    }
    return 180;
}
//---------------------------------------------------------------------------
float point2D::D()
{
    return sqrt(x*x+y*y);
}
//---------------------------------------------------------------------------
detail::detail()
{
    Npoint=Nline=alpha=0;
    S=300;
}
//---------------------------------------------------------------------------
void detail::DrawDetail(Graphics::TBitmap*bmp)
{
    int i,j,n1,n2;
    point2D t;
    if(Npoint<=0 || Npoint>=256)
    {
        return;
    }
    X=bmp->Width/2;
    Y=bmp->Height/2;
    for(i=0;i<Nline;i++)
    {
        n1=line[i]>>8;
        n2=line[i]-(n1<<8);
        if(n1!=n2)
        {
            (point[n1]*S).TurnToPoint(loc,alpha).MoveTo(bmp);
            (point[n2]*S).TurnToPoint(loc,alpha).LineTo(clline[i],bmp);
        }
    }
}
//---------------------------------------------------------------------------
void detail::LoadFromFile(char*fname)
{
    FILE *f;
    if(!strstr(fname,".detail"))
    {
        return;
    }
    f=fopen(fname,"rb");
    if(!f)
    {
        Npoint=Nline=0;
        point=NULL;
        line=NULL;
        clline=NULL;
        return;
    }
    fread(&Npoint,sizeof(int),1,f);
    if(Npoint>256)
    {
        return;
    }
    fread(&Nline,sizeof(int),1,f);
    fread(&S,sizeof(float),1,f);
    point=new point2D[Npoint];
    line=new USI[Nline];
    clline=new TColor[Nline];
    fread(point,sizeof(point2D),Npoint,f);
    fread(line,sizeof(USI),Nline,f);
    fread(clline,sizeof(TColor),Nline,f);
    fclose(f);
}
//---------------------------------------------------------------------------
void detail::operator=(detail dt)
{
    int i;
    Npoint=dt.Npoint;
    Nline=dt.Nline;
    alpha=dt.alpha;
    S=dt.S;
    loc=dt.loc;
    for(i=0;i<Npoint;i++)
    {
        point[i]=dt.point[i];
    }
    for(i=0;i<Nline;i++)
    {
        line[i]=dt.line[i];
        clline[i]=dt.clline[i];
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