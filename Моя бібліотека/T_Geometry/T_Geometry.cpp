//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Geometry.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
/*******************************T_Point*************************************/
//---------------------------------------------------------------------------
double T_Point::Distance(const T_Point &p)const
{
    return sqrt((X-p.X)*(X-p.X)+(Y-p.Y)*(Y-p.Y));
}
//---------------------------------------------------------------------------
T_Point::T_Point(const double &x,const double &y)
{
    X=x;
    Y=y;
}
//---------------------------------------------------------------------------
T_Point::T_Point(const TPoint &p)
{
    X=p.x;
    Y=p.y;
}
//---------------------------------------------------------------------------
T_Point::T_Point(const T_Point &p)
{
    X=p.X;
    Y=p.Y;
}
//---------------------------------------------------------------------------
T_Point::operator TPoint()const
{
    return TPoint(X,Y);
}
//---------------------------------------------------------------------------
T_Point& T_Point::operator = (const T_Point &p)
{
    X=p.X;
    Y=p.Y;
    return *this;
}
//---------------------------------------------------------------------------
int T_Point::operator == (const T_Point &p)const
{
    return (X==p.X && Y==p.Y);
}
//---------------------------------------------------------------------------
bool T_Point::operator != (const T_Point &p)const
{
    return !(*this==p);
}
//---------------------------------------------------------------------------
void T_Point::Init(const double &x,const double &y)
{
    X=x;
    Y=y;
}
//---------------------------------------------------------------------------
T_Point::T_Point()
{
    X=Y=0;
}
//---------------------------------------------------------------------------
char* T_Point::toChar()const
{
    char buf[32];
    sprintf(buf,"(%f;%f)",X,Y);
    return strdup(buf);
}
//---------------------------------------------------------------------------
void T_Point::Draw(TCanvas *Canvas,const TColor &cl)const
{
    Canvas->Pixels[X][Y]=cl;
}
//---------------------------------------------------------------------------
int T_Point::Comparison(const T_Point &p)const
{
    int w=1;
    if(X>=p.X)
    {
        if(Y<p.Y)
        {
            w=4;
        }
    }
    else
    {
        if(Y>=p.Y)
        {
            w=2;
        }
        else
        {
            w=3;
        }
    }
    return w;
}
//---------------------------------------------------------------------------
double T_Point::Distance(const T_StraightLine &sl)const
{
    double d=sl.isCorrectLine();
    if(d)
    {
        d=fabs(sl.A*X+sl.B*Y+sl.C)/sqrt(d);
    }
    return d;
}
//---------------------------------------------------------------------------
/*******************************T_Vector************************************/
//---------------------------------------------------------------------------
T_Vector::T_Vector(const T_Vector &v):T_Point(v)
{
}
//---------------------------------------------------------------------------
T_Vector::T_Vector(const double &_x,const double &_y):T_Point(_x,_y)
{
}
//---------------------------------------------------------------------------
T_Vector T_Vector::operator + (const T_Vector &v)const
{
    return T_Vector(X+v.X,Y+v.Y);
}
//---------------------------------------------------------------------------
T_Vector T_Vector::operator - (const T_Vector &v)const
{
    return T_Vector(X-v.X,Y-v.Y);
}
//---------------------------------------------------------------------------
T_Vector T_Vector::operator * (const double &f)const
{
    return T_Vector(f*X,f*Y);
}
//---------------------------------------------------------------------------
double T_Vector::Length()const
{
    return sqrt(X*X+Y*Y);
}
//---------------------------------------------------------------------------
T_Vector T_Vector::Rotate(const double &angle)
{
    T_Vector p;
    p.X=X*cos(angle)-Y*sin(angle);
    p.Y=X*sin(angle)+Y*cos(angle);
    return *this=p;
}
//---------------------------------------------------------------------------
double T_Vector::GetAngleRadian()const
{
    double angle=M_PI/2;
    if(X==0)
    {
        if(Y<0)
        {
            angle=3*M_PI/2;
        }
    }
    else
    {
        if(X>0)
        {
            angle=atan(Y/X);
        }
        else
        {
            angle=M_PI+atan(Y/X);
        }
    }
    if(angle<0)
    {
        angle+=M_PI+M_PI;
    }
    return angle;
}
//---------------------------------------------------------------------------
T_Vector T_Vector::Normalization()
{
    SetLength(1);
    return *this;
}
//---------------------------------------------------------------------------
void T_Vector::Draw(TCanvas *Canvas,const TColor &cl)const
{
    TColor pen=Canvas->Pen->Color;
    Canvas->Pen->Color=cl;
    Canvas->MoveTo(0,0);
    Canvas->LineTo(X,Y);
    Canvas->Pen->Color=pen;
}
//---------------------------------------------------------------------------
double T_Vector::AngleBetween(const T_Vector &v)const
{
    T_Vector vector=*this;
    vector.Rotate(-v.GetAngleRadian());
    return vector.GetAngleRadian();
}
//---------------------------------------------------------------------------
double T_Vector::Scalar(const T_Vector &v)const
{
    return X*v.X+Y*v.Y;
}
//---------------------------------------------------------------------------
void T_Vector::SetLength(const double &l)
{
    double L=Length();
    if(L)
    {
        Y=l*Y/L;
        X=l*X/L;
    }
}
//---------------------------------------------------------------------------
T_Vector::T_Vector(const T_Vector &From,const T_Vector &To):
    T_Point(To-From)
{
}
//---------------------------------------------------------------------------
/****************************T_AnyVector************************************/
//---------------------------------------------------------------------------
T_AnyVector::T_AnyVector(const T_AnyVector &av):T_Vector(av)
{
    Begin=av.Begin;
}
//---------------------------------------------------------------------------
void T_AnyVector::SetEnd(const T_Point &end)
{
    this->T_Vector::operator=(T_Vector(end)-Begin);
}
//---------------------------------------------------------------------------
T_AnyVector& T_AnyVector::operator = (const T_AnyVector &av)
{
    if(this!=&av)
    {
        T_Vector::operator = (av);
        Begin=av.Begin;
    }
    return *this;
}
//---------------------------------------------------------------------------
T_AnyVector T_AnyVector::operator + (const T_AnyVector &av)const
{
    T_AnyVector r;
    r=T_Vector::operator + (av);
    r.Begin=Begin;
    return r;
}
//---------------------------------------------------------------------------
char* T_AnyVector::toChar(const int &n)const
{
    char buf[128];
    char *b,*e;
    b=Begin.toChar();
    e=GetEnd().toChar();
    sprintf(buf,"[%s;%s]",b,e);
    delete b;
    delete e;
    return strdup(buf);
}
//---------------------------------------------------------------------------
T_AnyVector::T_AnyVector(const T_Vector &b,const T_Vector &e):T_Vector(e.operator -(b))
{
    Begin=b;
}
//---------------------------------------------------------------------------
void T_AnyVector::Draw(TCanvas *Canvas,const TColor &cl)const
{
    TColor pen=Canvas->Pen->Color;
    Canvas->Pen->Color=cl;
    Canvas->MoveTo(Begin.X,Begin.Y);
    Canvas->LineTo(GetEnd().X,GetEnd().Y);
    Canvas->Pen->Color=pen;
}
//---------------------------------------------------------------------------
T_AnyVector T_AnyVector::Rotate(const T_Point &p,const double &angle)
{
    T_Vector v1(Begin-T_Vector(p));
    T_Vector v2(GetEnd()-T_Vector(p));
    v1.Rotate(angle);
    v2.Rotate(angle);
    SetBegin(v1+p);
    SetEnd(v2+p);
    return *this;
}
//---------------------------------------------------------------------------
void T_AnyVector::Move()
{
    Begin=Begin+(T_Vector)(*this);
}
//---------------------------------------------------------------------------
/**************************T_StraightLine***********************************/
//---------------------------------------------------------------------------
void T_StraightLine::Init(const double &a,const double &b,const double &c)
{
    A=a;
    B=b;
    C=c;
}
//---------------------------------------------------------------------------
T_StraightLine::T_StraightLine(const double &a,const double &b,const double &c)
{
    Init(a,b,c);
}
//---------------------------------------------------------------------------
T_StraightLine::T_StraightLine(const T_StraightLine &sl)
{
    Init(sl.A,sl.B,sl.C);
}
//---------------------------------------------------------------------------
T_StraightLine::T_StraightLine(const double &k,const double &b)
{
    Init(k,-1,b);
}
//---------------------------------------------------------------------------
T_StraightLine& T_StraightLine::operator = (const T_StraightLine &sl)
{
    Init(sl.A,sl.B,sl.C);
    return *this;
}
//---------------------------------------------------------------------------
T_StraightLine::T_StraightLine(const T_Point &p1,const T_Point &p2)
{
    Init(p2.Y-p1.Y,p1.X-p2.X,p1.Y*(p2.X-p1.X)-p1.X*(p2.Y-p1.Y));
}
//---------------------------------------------------------------------------
int T_StraightLine::isParallel(const T_StraightLine &sl)const
{
    return GetAngleRadian()==sl.GetAngleRadian();
}
//---------------------------------------------------------------------------
double T_StraightLine::GetAngleRadian()const
{
    double Angle=0;
    if(A!=0)
    {
        if(B==0)
        {
            Angle=M_PI/2;
        }
        else
        {
            Angle=atan(-A/B);    
        }
    }
    return Angle;
}
//---------------------------------------------------------------------------
T_StraightLine::T_StraightLine(const T_Vector &v)
{
    if(v.Length())
    {
        Init(v.Y,-v.X,0);
    }
    else
    {
        Init(0,0,0);
    }
}
//---------------------------------------------------------------------------
double T_StraightLine::isCorrectLine()const
{
    return A*A+B*B;
}
//---------------------------------------------------------------------------
/******************************gT_Vector*************************************/
//---------------------------------------------------------------------------
gT_Vector::gT_Vector()
{
    N=1;
    C=new double[N];
    C[0]=0;
}
//---------------------------------------------------------------------------
gT_Vector::gT_Vector(const int &n)
{
    int i;
    N=n;
    if(N<=0)
    {
        N=1;
    }
    C=new double[N];
    for(i=0;i<N;i++)
    {
        C[i]=0;
    }
}
//---------------------------------------------------------------------------
gT_Vector::gT_Vector(const gT_Vector &gp)
{
    int i;
    N=gp.N;
    C=new double[N];
    for(i=0;i<N;i++)
    {
        C[i]=gp.C[i];
    }
}
//---------------------------------------------------------------------------
gT_Vector::~gT_Vector()
{
    delete[] C;
    C=NULL;
    N=0;
}
//---------------------------------------------------------------------------
gT_Vector::gT_Vector(const T_Vector &p)
{
    N=2;
    C=new double[N];
    C[0]=p.X;
    C[1]=p.Y;
}
//---------------------------------------------------------------------------
gT_Vector& gT_Vector::operator = (const gT_Vector &gp)
{
    int i;
    if(this!=&gp)
    {
        delete[] C;
        N=gp.N;
        C=new double[N];
        for(i=0;i<N;i++)
        {
            C[i]=gp.C[i];
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
gT_Vector::operator T_Vector()const
{
    return T_Vector(GetCoordinate(0),GetCoordinate(1));
}
//---------------------------------------------------------------------------
int gT_Vector::operator == (const gT_Vector &gp)const
{
    int i=0,max=(N>gp.N)?(N):(gp.N);
    while(i<max && GetCoordinate(i)==gp.GetCoordinate(i))
    {
        i++;
    }
    return i==max;
}
//---------------------------------------------------------------------------
gT_Vector gT_Vector::operator + (const gT_Vector &gp)const
{
    int i;
    gT_Vector r((N>gp.N)?(N):(gp.N));
    for(i=0;i<r.N;i++)
    {
        r.C[i]=GetCoordinate(i)+gp.GetCoordinate(i);
    }
    return r;
}
//---------------------------------------------------------------------------
double gT_Vector::Distance(const gT_Vector &gp)const
{
    double d=0;
    int i,max=(N>gp.N)?(N):(gp.N);
    for(i=0;i<max;i++)
    {
        d+=(GetCoordinate(i)-gp.GetCoordinate(i))*(GetCoordinate(i)-gp.GetCoordinate(i));
    }
    return sqrt(d);
}
//---------------------------------------------------------------------------
gT_Vector gT_Vector::operator - (const gT_Vector &gp)const
{
    int i;
    gT_Vector r((N>gp.N)?(N):(gp.N));
    for(i=0;i<r.N;i++)
    {
        r.C[i]=GetCoordinate(i)-gp.GetCoordinate(i);
    }
    return r;
}
//---------------------------------------------------------------------------
gT_Vector gT_Vector::operator * (const double &f)const
{
    int i;
    gT_Vector r(N);
    for(i=0;i<N;i++)
    {
        r.C[i]=C[i]*f;
    }
    return r;
}
//---------------------------------------------------------------------------
double gT_Vector::Length()const
{
    double d=0;
    int i;
    for(i=0;i<N;i++)
    {
        d+=C[i]*C[i];
    }
    return sqrt(d);
}
//---------------------------------------------------------------------------
void gT_Vector::SetCoordinate(const int &n,const double &c)
{
    if(n>=0)
    {
        if(n<N)
        {
            C[n]=c;
        }
        else
        {
            int i;
            gT_Vector r(*this);
            delete[] C;
            C=new double[N=n+1];
            for(i=0;i<r.N;i++)
            {
                C[i]=r.C[i];
            }
            for(;i<n;i++)
            {
                C[i]=0;
            }
            C[n]=c;
        }
    }
}
//---------------------------------------------------------------------------
double gT_Vector::SetLength(const double &l)
{
    int i;
    double L=Length();
    if(L)
    {
        for(i=0;i<N;i++)
        {
            C[i]=l*C[i]/L;
        }
    }
    return L;
}
//---------------------------------------------------------------------------
double gT_Vector::Scalar(const gT_Vector &gv)const
{
    double f=0;
    int i;
    for(i=0;i<N;i++)
    {
        f+=C[i]*gv.GetCoordinate(i);
    }
    return f;
}
//---------------------------------------------------------------------------
void gT_Vector::Rotate(const int &c1,const int &c2,const double &angle)
{
    double x,y;
    x=GetCoordinate(c1)*cos(angle)-GetCoordinate(c2)*sin(angle);
    y=GetCoordinate(c1)*sin(angle)+GetCoordinate(c2)*cos(angle);
    SetCoordinate(c1,x);
    SetCoordinate(c2,y);
}
//---------------------------------------------------------------------------
double gT_Vector::GetCoordinate(const int &n)const
{
    double c=0;
    if(n>=0 && n<N)
    {
        c=C[n];
    }
    return c;
}
//---------------------------------------------------------------------------
void gT_Vector::SetDimension(const int &n)
{
    if(n>0 && n!=N)
    {
        int i,k;
        double *c=new double[N];
        for(i=0;i<N;i++)
        {
            c[i]=C[i];
        }
        delete[] C;
        C=new double[n];
        k=(N>n)?(n):(N);
        for(i=0;i<k;i++)
        {
            C[i]=c[i];
        }
        N=n;
        for(;i<N;i++)
        {
            C[i]=0;
        }
        delete[] c;
        c=NULL;
    }
}
//---------------------------------------------------------------------------
int MaxDimension(const gT_Vector &gv1,const gT_Vector &gv2)
{
    return (gv1.N>gv2.N)?(gv1.N):(gv2.N);
}
//---------------------------------------------------------------------------
int MinDimension(const gT_Vector &gv1,const gT_Vector &gv2)
{
    return (gv1.N<gv2.N)?(gv1.N):(gv2.N);
}
//---------------------------------------------------------------------------
double gT_Vector::Approximation(const gT_Vector &gv)const
{
    double e=0,p;
    int maxN=(N>gv.N)?(N):(gv.N),i;
    for(i=0;i<maxN;i++)
    {
        p=fabs(this->GetCoordinate(i)-gv.GetCoordinate(i));
        if(p>e)
        {
            e=p;
        }
    }
    return e;
}
//---------------------------------------------------------------------------
void gT_Vector::printf()const
{
    int i;
    cout<<N<<":\n";
    for(i=0;i<N;i++)
    {
        cout<<C[i]<<' ';
    }
}
//---------------------------------------------------------------------------
gT_Vector::gT_Vector(const int &n,const double *c)
{
    int i;
    N=(n>1)?(n):(1);
    C=new double[N];
    if(c)
    {
        for(i=0;i<N;i++)
        {
            C[i]=c[i];
        }
    }
    else
    {
        for(i=0;i<N;i++)
        {
            C[i]=0;
        }
    }
}
//---------------------------------------------------------------------------
gT_Vector::gT_Vector(const double &x,const double &y)
{
    N=2;
    C=new double[N];
    C[0]=x;
    C[1]=y;
}
//---------------------------------------------------------------------------
gT_Vector::gT_Vector(const double &x,const double &y,const double &z)
{
    N=3;
    C=new double[N];
    C[0]=x;
    C[1]=y;
    C[2]=z;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/**************************gT_StraightLine**********************************/
//---------------------------------------------------------------------------
gT_StraightLine::gT_StraightLine():DVector(),Point()
{
}
//---------------------------------------------------------------------------
gT_StraightLine::gT_StraightLine(const gT_Vector &dv,const gT_Vector &p)
    :DVector(dv),Point(p)
{
    DVector.SetDimension(MaxDimension(DVector,Point));
    Point.SetDimension(DVector.GetDimension());
    Normalization();
}
//---------------------------------------------------------------------------
gT_Vector gT_StraightLine::GetPointT(const double &t)const
{
    int i;
    gT_Vector r(GetDimension());
    for(i=0;i<GetDimension();i++)
    {
        r.SetCoordinate(i,GetCoordinateT(i,t));
    }
    return r;
}
//---------------------------------------------------------------------------
int gT_StraightLine::isParallel(const gT_StraightLine &gsl)const
{
    return DVector==gsl.DVector;
}
//---------------------------------------------------------------------------
double gT_StraightLine::GetCoordinateT(const int &n,const double &t)const
{
    return DVector.GetCoordinate(n)*t+Point.GetCoordinate(n);
}
//---------------------------------------------------------------------------
int gT_StraightLine::CrossPoint(const gT_StraightLine &gsl,gT_Vector &gv)const
{
    int i=1,max=MaxDimension(GetDimension(),gsl.GetDimension());
    while(i<max && gsl.DVector.GetC(0)*DVector.GetC(i)-
                   DVector.GetC(0)*gsl.DVector.GetC(i)==0 )
    {
        i++;
    }
    if(i<max)
    {
        double t=(gsl.DVector.GetC(0)*(gsl.Point.GetC(i)-Point.GetC(i))-
                  gsl.DVector.GetC(i)*(gsl.Point.GetC(0)-Point.GetC(0)))/
                  (gsl.DVector.GetC(0)*DVector.GetC(i)-
                   DVector.GetC(0)*gsl.DVector.GetC(i));
        i++;
        while(i<max && GetCoordinateT(i,t)==gsl.GetCoordinateT(i,t))
        {
            i++;
        }
        if(i>=max)
        {
            gv=GetPointT(t);
            i=1;
        }
        else
        {
            i=0;
        }
    }
    else
    {
        i=0;
    }
    return i;
}
//---------------------------------------------------------------------------
void gT_StraightLine::Normalization()
{
    int i;
    double a=0,b=0;
    DVector.Normalization();
    for(i=0;i<GetDimension();i++)
    {
        a+=DVector.GetCoordinate(i)*DVector.GetCoordinate(i);
        b+=2*DVector.GetCoordinate(i)*Point.GetCoordinate(i);
    }
    if(a>0)
    {
        Point=GetPointT(-b/(2*a));
    }
}
//---------------------------------------------------------------------------
gT_StraightLine::gT_StraightLine(const double &a,const double &b,const double &c)
{
    T_Vector p1,p2;
    if(a)
    {
        p1.Y=0;
        p1.X=(-c-b*p1.Y)/a;
        p2.Y=1;
        p2.X=(-c-b*p2.Y)/a;
    }
    else
    {
        if(b)
        {
            p1.X=0;
            p1.Y=(-c-a*p1.Y)/b;
            p2.X=1;
            p2.Y=(-c-a*p2.Y)/b;
        }
    }
    DVector=p2-p1;
    Point=p1;
    Normalization();
}
//---------------------------------------------------------------------------
gT_StraightLine::gT_StraightLine(const double &k,const double &b)
{
    T_Vector p1,p2;
    p1.X=0;
    p1.Y=k*p1.X+b;
    p2.X=1;
    p2.Y=k*p2.X+b;
    DVector=p2-p1;
    Point=p1;
    Normalization();
}
//---------------------------------------------------------------------------
void gT_StraightLine::SetDVector(const gT_Vector &dv)
{
    DVector=dv;
    if(dv.GetDimension()>Point.GetDimension())
    {
        Point.SetDimension(dv.GetDimension());
    }
    else
    {
        DVector.SetDimension(Point.GetDimension());
    }
}
//---------------------------------------------------------------------------
void gT_StraightLine::SetPoint(const gT_Vector &p)
{
    Point=p;
    if(p.GetDimension()>DVector.GetDimension())
    {
        DVector.SetDimension(p.GetDimension());
    }
    else
    {
        Point.SetDimension(DVector.GetDimension());
    }
}
//---------------------------------------------------------------------------
void gT_StraightLine::SetDimension(const int &n)
{
    DVector.SetDimension(n);
    Point.SetDimension(n);
}
//---------------------------------------------------------------------------
int gT_StraightLine::hasPoint(const gT_Vector &p,double &t)const
{
    int i=0;
    while(i<GetDimension() && DVector.GetC(i)==0)
    {
        i++;
    }
    if(i<GetDimension())
    {
        t=(p.GetC(i)-Point.GetC(i))/DVector.GetC(i);
        if(p==GetPointT(t))
        {
            i=1;
        }
        else
        {
            i=0;
        }
    }
    else
    {
        i=0;
    }
    return i;
}
//---------------------------------------------------------------------------
double gT_StraightLine::Distance(const gT_Vector &p)const
{
    gT_StraightLine Line(DVector,Point-p);
    return Line.GetPointT(0).Length();
}
//---------------------------------------------------------------------------
double gT_StraightLine::Distance(const gT_StraightLine &gsl)const
{
    gT_StraightLine Line(DVector-gsl.DVector,Point-gsl.Point);
    return Line.GetPointT(0).Length();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/****************************T_Designator***********************************/
//---------------------------------------------------------------------------
T_Designator::T_Designator()
{
    N=0;
    E=NULL;
}
//---------------------------------------------------------------------------
T_Designator::T_Designator(const int &n)
{
    N=(n>0)?(n):(0);
    if(N)
    {
        int i,j;
        E=new double*[N];
        for(i=0;i<N;i++)
        {
            E[i]=new double[N];
            for(j=0;j<N;j++)
            {
                E[i][j]=0;
            }
        }
    }
    else
    {
        E=NULL;
    }
}
//---------------------------------------------------------------------------
T_Designator::T_Designator(const T_Designator &d)
{
    N=d.N;
    if(N)
    {
        int i,j;
        E=new double*[N];
        for(i=0;i<N;i++)
        {
            E[i]=new double[N];
            for(j=0;j<N;j++)
            {
                E[i][j]=d.E[i][j];
            }
        }
    }
    else
    {
        E=NULL;
    }
}
//---------------------------------------------------------------------------
T_Designator::~T_Designator()
{
    int i;
    for(i=0;i<N;i++)
    {
        delete[] E[i];
        E[i]=NULL;
    }
    delete[] E;
    E=NULL;
    N=0;
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
/*************************T_CoordinateSystem********************************/
//---------------------------------------------------------------------------
T_Point T_CoordinateSystem::GetPoint(const T_Point &p)const
{
    T_Vector v(p);
    v.Rotate(Ox.GetAngleRadian());
    v.Init(v.X*Ox.Length(),v.Y*Oy.Length());
    v=v+O;
    return v;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/******************************T_Matrix*************************************/
//---------------------------------------------------------------------------
T_Matrix::T_Matrix()
{
    N=M=0;
    E=NULL;
}
//---------------------------------------------------------------------------
T_Matrix::T_Matrix(const T_Matrix &m)
{
    int i,j;
    N=m.N;
    M=m.M;
    E=new double*[N];
    for(i=0;i<N;i++)
    {
        E[i]=new double[M];
        for(j=0;j<M;j++)
        {
            E[i][j]=m.E[i][j];
        }
    }
}
//---------------------------------------------------------------------------
T_Matrix::T_Matrix(const int &n,const int &m,const double **mass)
{
    if(m>0 && n>0)
    {
        int i,j;
        N=n;
        M=m;
        E=new double*[N];
        for(i=0;i<N;i++)
        {
            E[i]=new double[M];
            for(j=0;j<M;j++)
            {
                E[i][j]=mass[i][j];
            }
        }
    }
    else
    {
        M=N=0;
        E=NULL;
    }
}
//---------------------------------------------------------------------------
T_Matrix::~T_Matrix()
{
    Delete();
}
//---------------------------------------------------------------------------
T_Matrix& T_Matrix::operator = (const T_Matrix &m)
{
    if(this!=&m)
    {
        int i,j;
        if(N==m.N)
        {
            if(M!=m.M)
            {
                for(i=0;i<N;i++)
                {
                    delete[] E[i];
                    E[i]=new double[M=m.M];
                }
            }
        }
        else
        {
            for(i=0;i<N;i++)
            {
                delete[] E[i];
            }
            delete[] E;
            E=new double*[N=m.N];
            M=m.M;
            for(i=0;i<N;i++)
            {
                E[i]=new double[M];
            }
        }
        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                E[i][j]=m.E[i][j];
            }
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
T_Matrix T_Matrix::operator + (const T_Matrix &m)const
{
    T_Matrix r;
    int i,j;
    if(N==m.N && M==m.M)
    {
        r=*this;
        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                r.E[i][j]+=m.E[i][j];
            }
        }
    }
    return r;
}
//---------------------------------------------------------------------------
T_Matrix T_Matrix::operator - (const T_Matrix &m)const
{
    T_Matrix r;
    int i,j;
    if(N==m.N && M==m.M)
    {
        r=*this;
        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                r.E[i][j]-=m.E[i][j];
            }
        }
    }
    return r;
}
//---------------------------------------------------------------------------
T_Matrix T_Matrix::operator * (const T_Matrix &m)const
{
    T_Matrix r;
    int i,j,k;
    if(M==m.N)
    {
        r.N=N;
        r.M=m.M;
        r.E=new double*[r.N];
        for(i=0;i<r.N;i++)
        {
            r.E[i]=new double[r.M];
            for(j=0;j<r.M;j++)
            {
                r.E[i][j]=0;
                for(k=0;k<M;k++)
                {
                    r.E[i][j]+=E[i][k]*m.E[k][j];
                }
            }
        }
    }
    return r;
}
//---------------------------------------------------------------------------
T_Matrix::T_Matrix(const int &n,const int &m,double f,...)
{
    if(m>0 && n>0)
    {
        int i,j;
        double *p=&f;
        N=n;
        M=m;
        E=new double*[N];
        for(i=0;i<N;i++)
        {
            E[i]=new double[M];
            for(j=0;j<M;j++)
            {
                E[i][j]=*p;
                p++;
            }
        }
    }
    else
    {
        M=N=0;
        E=NULL;
    }
}
//---------------------------------------------------------------------------
void T_Matrix::SetSize(const int &n,const int &m)
{
    if(m>0 && n>0)
    {
        int i,j;
        N=n;
        M=m;
        E=new double*[N];
        for(i=0;i<N;i++)
        {
            E[i]=new double[M];
        }
    }
}
//---------------------------------------------------------------------------
void T_Matrix::Delete()
{
    int i;
    for(i=0;i<N;i++)
    {
        delete[] E[i];
    }
    delete[] E;
    E=NULL;
    N=M=0;
}
//---------------------------------------------------------------------------
T_Matrix::T_Matrix(const T_Matrix &m,int _i,int _j,int i_,int j_)
{
    int i,j;
    N=m.N;
    M=m.M;
    if(M==0 || N==0)
    {
        E=NULL;
    }                            
    else
    {
        if(_i>i_)
        {
            _i=_i+i_;
            i_=_i-i_;
            _i= _i-_i;
        }
        if(_j>j_)
        {
            _j=_j+j_;
            j_=_j-j_;
            _j= _j-_j;
        }
        if(_i>=N || _j>=M || i_<0 || j_<0 || _i==i_ || _j==j_)
        {
            N=M=0;
            E=NULL;
        }
        else
        {
            N=i_-_i;
            M=j_-_j;
            E=new double*[N];
            for(i=0;i<N;i++)
            {
                E[i]=new double[M];
                for(j=0;j<M;j++)
                {
                    E[i][j]=m.E[i+_i][j+_j];
                }
            }
        }
    }
}
//---------------------------------------------------------------------------
T_Matrix T_Matrix::Copy(const int &a,const int &b,const int &c,const int &d)
{
    return T_Matrix(*this,a,b,c,d);
}
//---------------------------------------------------------------------------
void T_Matrix::Paste(const T_Matrix &m,const int &_i,const int &_j)
{
    int i,j;
    if(N!=0 && M!=0 && m.N!=0 && m.M!=0)
    {
        for(i=(_i>0)?(_i):(0);i<(_i+m.N<N)?(_i+m.N):(N);i++)
        {
            for(j=(_j>0)?(_j):(0);j<(_j+m.M<M)?(_j+m.M):(M);j++)
            {
                E[i][j]=m.E[i+_i][j+_j];
            }
        }
    }
}
//---------------------------------------------------------------------------
void T_Matrix::printf()const
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            cout<<E[i][j]<<' ';
        }
        cout<<endl;
    }
}
//---------------------------------------------------------------------------
void T_Matrix::printf(const char *begin)const
{
    cout<<begin<<endl;
    this->printf();
}
//---------------------------------------------------------------------------
T_Matrix::T_Matrix(const T_Vector &v)
{
    N=1;
    M=2;
    E=new double*[N];
    E[0]=new double[M];
    E[0][0]=v.X;
    E[0][1]=v.Y;
}
//---------------------------------------------------------------------------
T_Matrix::T_Matrix(const gT_Vector &gv)
{
    int i;
    N=1;
    M=gv.GetDimension();
    E=new double*[N];
    E[0]=new double[M];
    for(i=0;i<M;i++)
    {
        E[0][i]=gv.GetCoordinate(i);
    }
}
//---------------------------------------------------------------------------
void T_Matrix::Turn()
{
    int i,j;
    T_Matrix m=*this;
    if(N!=M)
    {
        Delete();
        N=m.M;
        M=m.N;
        E=new double*[N];
        for(i=0;i<N;i++)
        {
            E[i]=new double[M];
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            E[i][j]=m.E[j][i];
        }
    }
}
//---------------------------------------------------------------------------
gT_Vector T_Matrix::GetRow(const int &r)const
{
    gT_Vector row;
    if(r>=0 && r<N)
    {
        int i;
        row.SetDimension(M);
        for(i=0;i<M;i++)
        {
            row.SetCoordinate(i,E[r][i]);
        }
    }
    return row;
}
//---------------------------------------------------------------------------
gT_Vector T_Matrix::GetCol(const int &c)const
{
    gT_Vector col;
    if(c>=0 && c<M)
    {
        int i;
        col.SetDimension(N);
        for(i=0;i<N;i++)
        {
            col.SetCoordinate(i,E[i][c]);
        }
    }
    return col;
}
//---------------------------------------------------------------------------
double T_Matrix::Approximation(const T_Matrix &m)const
{
    double e=-1,p;
    int i,j;
    if(N==m.N && M==m.M)
    {
        e=0;
        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                p=fabs(E[i][j]-m.E[i][j]);
                if(p>e)
                {
                    e=p;
                }
            }
        }
    }
    return e;
}
//---------------------------------------------------------------------------
void T_Matrix::SetElement(const int &i,const int &j,const double &e)
{
    if(i>=0 && i<N && j>=0 && j<M)
    {
        E[i][j]=e;
    }
}
//---------------------------------------------------------------------------
T_Matrix::T_Matrix(const gT_Vector &gv,const int &)
{
    int i;
    N=gv.GetDimension();
    M=1;
    E=new double*[N];
    for(i=0;i<N;i++)
    {
        E[i]=new double[M];
        E[i][0]=gv.GetCoordinate(i);
    }
}
//---------------------------------------------------------------------------
T_Matrix T_Matrix::operator * (const double &c)const
{
    int i,j;
    T_Matrix r=*this;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            r.E[i][j]*=c;
        }
    }
    return r;
}
//---------------------------------------------------------------------------
double T_Matrix::GetElement(const int &i,const int &j)const
{
    double e=0;
    if(i>=0 && i<N && j>=0 && j<M)
    {
        e=E[i][j];
    }
    return e;
}
//---------------------------------------------------------------------------
void T_Matrix::MultAndAdd_Row(const int &k,const double &f,const int &n)
{
    if(f && k!=n && k>=0 && k<N && n>=0 && n<N)
    {
        int i;
        for(i=0;i<M;i++)
        {
            E[n][i]+=E[k][i]*f;
        }
    }
}
//---------------------------------------------------------------------------
void T_Matrix::MultAndAdd_Col(const int &k,const double &f,const int &n)
{
    if(f && k!=n && k>=0 && k<M && n>=0 && n<M)
    {
        int i;
        for(i=0;i<N;i++)
        {
            E[i][n]+=E[i][k]*f;
        }
    }
}
//---------------------------------------------------------------------------
void T_Matrix::doTriangleForm()
{
    if(N>1 && M>1)
    {
        int i=0,j=0;
        while(i<N-1)
        {
            if(E[i][i])
            {
                j=i+1;
                while(j<N)
                {
                    while(j<N && E[j][i]==0)
                    {
                        j++;
                    }
                    if(j<N)
                    {
                        MultAndAdd_Row(i,-E[j][i]/E[i][i],j);
                    }
                    j++;
                }
                i++;
            }
            else
            {
                j=i+1;
                while(j<N && E[j][i]==0)
                {
                    j++;
                }
                if(j<N)
                {
                    MultAndAdd_Row(j,1,i);
                }
                else
                {
                    i++;
                }
            }
        }
    }
}
//---------------------------------------------------------------------------
T_Matrix T_Matrix::Gauss()
{
    T_Matrix r;
    if(N>0 && M>1)
    {
        doTriangleForm();
        if(M<N+2)
        {
            int i,j;
            r.SetSize(N,1);
            for(i=N-1;i>=0;i--)
            {
                r.E[i][0]=E[i][M-1];
                for(j=i+1;j<N;j++)
                {
                    r.E[i][0]-=E[i][j]*r.E[j][0];
                }
                if(E[i][i])
                {
                    r.E[i][0]=r.E[i][0]/E[i][i];
                }
                else
                {
                    i=-1;
                    r.Delete();
                }
            }
        }
    }
    return r;
}
//---------------------------------------------------------------------------
T_Matrix T_Matrix::GetE(const int &n)const
{
    T_Matrix e(n,n);
    int i;
    for(i=0;i<n;i++)
    {
        e.E[i][i]=1;
    }
    return e;
}
//---------------------------------------------------------------------------
T_Matrix::T_Matrix(const int &n,const int &m)
{
    N=n;
    M=m;
    if(N>0 && M>0)
    {
        int i,j;
        E=new double*[N];
        for(i=0;i<N;i++)
        {
            E[i]=new double[M];
            for(j=0;j<M;j++)
            {
                E[i][j]=0;
            }
        }
    }
    else
    {
        N=M=0;
        E=NULL;
    }
}
//---------------------------------------------------------------------------
void T_Matrix::SetRow(const int &k,const gT_Vector &gv)
{
    if(k>=0 && k<N)
    {
        int j;
        for(j=0;j<M;j++)
        {
            E[k][j]=gv.GetCoordinate(j);
        }
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*****************************gT_Segment************************************/
//---------------------------------------------------------------------------
gT_Segment::gT_Segment():gT_StraightLine()
{
    Left=Right=0;
}
//---------------------------------------------------------------------------
gT_Segment::gT_Segment(const gT_Vector &p1,const gT_Vector &p2)
    :gT_StraightLine(p1,p2)
{
    gT_StraightLine::hasPoint(p1,Left);
    gT_StraightLine::hasPoint(p2,Right);
    if(Right<Left)
    {
        Left=Left+Right;
        Right=Left-Right;
        Left=Left-Right;
    }
}
//---------------------------------------------------------------------------
int gT_Segment::CrossPoint(const gT_Segment &gs,gT_Vector &gv)const
{
    int q=gT_StraightLine::CrossPoint(gs,gv);
    double t;
    if(hasPoint(gv,t) && gs.hasPoint(gv,t))
    {
        q=1;
    }
    else
    {
        q=0;
    }
    return q;
}
//---------------------------------------------------------------------------
int gT_Segment::hasPoint(const gT_Vector &p,double &t)const
{
    int q=gT_StraightLine::hasPoint(p,t);
    if(q && t>=Left && t<=Right)
    {
    }
    else
    {
        q=0;
    }
    return q;
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
/******************************Функції**************************************/
//---------------------------------------------------------------------------
int LineCrossPoint(const T_Vector &a,const T_Vector &b,const T_Vector &c,
    const T_Vector &d,T_Vector &r)
{
    int q=0;
    double x1,x2;
    if(b.Y-a.Y)
    {
        if(d.Y-c.Y)
        {
            x1=(b.X-a.X)/(b.Y-a.Y)-(d.X-c.X)/(d.Y-c.Y);
            x2=c.X-a.X+(b.X-a.X)/(b.Y-a.Y)*a.Y-(d.X-c.X)/(d.Y-c.Y)*c.Y;
            if(x1)
            {
                r.Y=x2/x1;
                r.X=(b.X-a.X)*(r.Y-a.Y)/(b.Y-a.Y)+a.X;
                q=1;
            }
        }
        else
        {
            r.Y=c.Y;
            r.X=(b.X-a.X)*(r.Y-a.Y)/(b.Y-a.Y)+a.X;
            q=1;
        }
    }
    else
    {
        if(d.Y-c.Y)
        {
            r.Y=a.Y;
            r.X=(d.X-c.X)*(r.Y-c.Y)/(d.Y-c.Y)+c.X;
            q=1;
        }
    }
    return q;
}
//---------------------------------------------------------------------------
int SegmentCrossPoint(const T_Vector &a,const T_Vector &b,const T_Vector &c,
    const T_Vector &d,T_Vector &r)
{
    int q=LineCrossPoint(a,b,c,d,r);
    const double e=0.00001;
    if(q)
    {
        if(fabs(fabs(a.X-b.X)-(fabs(a.X-r.X)+fabs(b.X-r.X)))<e &&
           fabs(fabs(a.Y-b.Y)-(fabs(a.Y-r.Y)+fabs(b.Y-r.Y)))<e &&
           fabs(fabs(c.X-d.X)-(fabs(c.X-r.X)+fabs(d.X-r.X)))<e &&
           fabs(fabs(c.Y-d.Y)-(fabs(c.Y-r.Y)+fabs(d.Y-r.Y)))<e)
        {
        }
        else
        {
            q=0;
        }
    }
    return q;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/******************************T_Matrix*************************************/
//---------------------------------------------------------------------------
T_Poligon::T_Poligon()
{
    N=0;
    Top=NULL;
}
//---------------------------------------------------------------------------
T_Poligon::T_Poligon(const T_Poligon &p)
{
    N=p.N;
    if(N)
    {
        int i;
        Top=new T_Vector[N];
        for(i=0;i<N;i++)
        {
            Top[i]=p.Top[i];
        }
    }
    else
    {
        Top=NULL;
    }
}
//---------------------------------------------------------------------------
T_Poligon::~T_Poligon()
{
    delete[] Top;
    Top=NULL;
    N=0;
}
//---------------------------------------------------------------------------
T_Poligon::T_Poligon(const int &n,const T_Vector *v)
{
    N=(n>0)?(n):(0);
    if(N)
    {
        int i;
        Top=new T_Vector[N];
        for(i=0;i<N;i++)
        {
            Top[i]=v[i];
        }
    }
    else
    {
        Top=NULL;
    }
}
//---------------------------------------------------------------------------
T_Poligon& T_Poligon::operator = (const T_Poligon &p)
{
    if(this!=&p)
    {
        delete[] Top;
        N=p.N;
        if(N)
        {
            int i;
            Top=new T_Vector[N];
            for(i=0;i<N;i++)
            {
                Top[i]=p.Top[i];
            }
        }
        else
        {
            Top=NULL;
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
T_Poligon::T_Poligon(const int &n)
{
    N=(n>0)?(n):(0);
    if(N)
    {
        Top=new T_Vector[N];
    }
    else
    {
        Top=NULL;
    }
}
//---------------------------------------------------------------------------
T_Vector& T_Poligon::operator[] (const int &i)
{
    return Top[i];
}
//---------------------------------------------------------------------------
int T_Poligon::hasPoint(const T_Vector &p)const
{
    int q=0;
    if(N>2)
    {
        int i;
        T_Vector r,l(SearchMinX()-10,0);
        for(i=0;i<N-1;i++)
        {
            q+=SegmentCrossPoint(Top[i],Top[i+1],p,l,r);
            if(r==Top[i])
            {
                q++;
            }
        }
        q+=SegmentCrossPoint(Top[0],Top[i],p,l,r);
        if(r==Top[i])
        {
            q++;
        }
        q=q%2;
    }
    return q;
}
//---------------------------------------------------------------------------
double T_Poligon::SearchMinX()const
{
    int i;
    double minX=0;
    if(N)
    {
        minX=Top[0].X;
        for(i=1;i<N;i++)
        {
            if(Top[i].X<minX)
            {
                minX=Top[i].X;
            }
        }
    }
    return minX;
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
/***************************Далі буде***************************************/

