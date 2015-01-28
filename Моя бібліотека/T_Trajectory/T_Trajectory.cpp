//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Trajectory.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Trajectory::T_Trajectory()
{
    Amount=0;
    Curve=NULL;
}
//---------------------------------------------------------------------------
T_Trajectory::T_Trajectory(const T_Trajectory &Trajectory)
{
    /*Amount=Trajectory.Amount;
    if(Amount>0)
    {
        Curve=new pT_Curve [Amount];
        for(int i=0;i<Amount;i++)
        {
            Curve[i]=GetIDType(Trajectory.Curve[i]->GetID());
        }
    }
    else
    {
        Curve=NULL;
    }*/
    Amount=0;
    Trajectory.SaveToFile("~Copy");
    LoadFromFile("~Copy");
}
//---------------------------------------------------------------------------
T_Trajectory& T_Trajectory::operator = (const T_Trajectory &Trajectory)
{
    if(this!=&Trajectory)
    {
        Trajectory.SaveToFile("~Copy");
        LoadFromFile("~Copy");
    }
    return *this;
}
//---------------------------------------------------------------------------
T_Trajectory::T_Trajectory(const int &_Amount)
{
    Amount=(_Amount>0)?(_Amount):(0);
    if(Amount>0)
    {
        Curve=new pT_Curve [Amount];
        Nullify();
    }
    else
    {
        Curve=NULL;
    }
}
//---------------------------------------------------------------------------
void T_Trajectory::Nullify()
{
    int i;
    for(i=0;i<Amount;i++)
    {
        Curve[i]=NULL;
    }
}
//---------------------------------------------------------------------------
pT_Curve& T_Trajectory::operator [] (const int &i)
{
    return Curve[i];
}
//---------------------------------------------------------------------------
int T_Trajectory::Value(const double &t,T_Vector2d &p)
{
    int i,error=1;
    double norm_t=Normalization(t);
    i=norm_t;
    if(Curve && Curve[i])
    {
        error=Curve[i]->Value(norm_t-i,p);
    }
    return error;
}
//---------------------------------------------------------------------------
int T_Trajectory::NextPoint_Right(const double &t0,T_Vector2d &p)
{
    int Error=0;
    if(Amount>0)
    {
        int kmax=1/Epsilon,k=0;
        T_Vector2d p0;
        double norm_t=Normalization(t0);
        double l=norm_t,
               r=l+Amount/4.0,
               len;
        Value(l,p0);
        Value(r,p);
        len=Distance(p0,p);
        if(len<Length)
        {
            r=r+Amount/4.0;
            Value(r,p);
            len=Distance(p0,p);
            if(len<Length)
            {
                Error=1;
            }
        }
        if(Error==0)
        {
            NextPointLR(k,p0,p,l,r,kmax);
        }
    }
    return Error;
}
//---------------------------------------------------------------------------
void T_Trajectory::NextPointLR(int &k,const T_Vector2d &p0,T_Vector2d &p,double &l,double &r,const int &kmax)
{
    double len;
    do
    {
        k++;
        Last_t=(l+r)/2;
        Value(Last_t,p);
        len=Distance(p0,p);
        if(len<Length)
        {
            l=Last_t;
        }
        else
        {
            if(len>Length)
            {
                r=Last_t;
            }
        }
    }
    while(fabs(len-Length)>Epsilon && k<kmax);
}
//---------------------------------------------------------------------------
int T_Trajectory::NextPoint_Left(const double &t0,T_Vector2d &p)
{
    int Error=0;
    if(Amount>0)
    {
        int kmax=1/Epsilon,k=0;
        T_Vector2d p0;
        double norm_t=Normalization(t0);
        double l=norm_t,
               r=l-Amount/4.0,
               len;
        Value(l,p0);
        Value(r,p);
        len=Distance(p0,p);
        if(len<Length)
        {
            r=r-Amount/4.0;
            Value(r,p);
            len=Distance(p0,p);
            if(len<Length)
            {
                Error=1;
            }
        }
        if(Error==0)
        {
            NextPointLR(k,p0,p,l,r,kmax);
        }
    }
    return Error;
}
//---------------------------------------------------------------------------
double T_Trajectory::Distance(const T_Vector2d &p1,const T_Vector2d &p2)
{
    return (p1-p2).Length();
}
//---------------------------------------------------------------------------
void T_Trajectory::SetEpsilon(const double &_Epsilon)
{
    Epsilon=(_Epsilon>0)?(_Epsilon):(0.1);
}
//---------------------------------------------------------------------------
void T_Trajectory::SetLength(const double &_Length)
{
    Length=(_Length>0)?(_Length):(0);
}
//---------------------------------------------------------------------------
int T_Trajectory::GetPoint(const double &t,T_Vector2d &p)
{
    int q=0;
    if(Amount>0)
    {
        q=Value(t,p);
    }
    return q;
}
//---------------------------------------------------------------------------
double T_Trajectory::Normalization(const double &t)
{
    double norm_t=fabs(t);
    int k=norm_t/Amount;
    norm_t=norm_t-k*Amount;
    if(t<0)
    {
        norm_t=Amount-norm_t;
    }
    return norm_t;
}
//---------------------------------------------------------------------------
char* T_Trajectory::LoadFromFileID(FILE *File)
{
    char *ID;
    int n;
    fread(&n,sizeof(int),1,File);
    ID=new char [n+1];
    fread(ID,sizeof(char),n,File);
    ID[n]=0;
    return ID;
}
//---------------------------------------------------------------------------
pT_Curve T_Trajectory::GetIDType(const char *ID)const
{
    T_Curve *IDType=NULL;
    if(strcmp(ID,"T_Segment")==0)
    {
        IDType=new T_Segment;
    }
    else
    if(strcmp(ID,"T_Arc")==0)
    {
        IDType=new T_Arc;
    }
    else
    if(strcmp(ID,"T_HermiteCurve")==0)
    {
        IDType=new T_HermiteCurve;
    }
    else
    if(strcmp(ID,"T_BezierCurve")==0)
    {
        IDType=new T_BezierCurve;
    }
    return IDType;
}
//---------------------------------------------------------------------------
void T_Trajectory::SaveToFile(FILE *File)const
{
    fwrite(&Amount,sizeof(int),1,File);
    fwrite(&Epsilon,sizeof(double),1,File);
    fwrite(&Length,sizeof(double),1,File);
    fwrite(&Last_t,sizeof(double),1,File);
    for(int i=0;i<Amount;i++)
    {
        Curve[i]->SaveToFile(File);
    }
}
//---------------------------------------------------------------------------
void T_Trajectory::LoadFromFile(FILE *File)
{
    Delete();
    fread(&Amount,sizeof(int),1,File);
    fread(&Epsilon,sizeof(double),1,File);
    fread(&Length,sizeof(double),1,File);
    fread(&Last_t,sizeof(double),1,File);
    if(Amount>0)
    {
        Curve=new pT_Curve [Amount];
        if(Curve)
        {
            for(int i=0;i<Amount;i++)
            {
                Curve[i]=GetIDType(LoadFromFileID(File));
                if(Curve[i])
                {
                    Curve[i]->LoadFromFile(File);
                }
            }
        }
        else
        {
            Amount=0;
        }
    }
}
//---------------------------------------------------------------------------
void T_Trajectory::Delete()
{
    if(Amount>0)
    {
        for(int i=0;i<Amount;i++)
        {
            delete Curve[i];
        }
    }
    Amount=0;
    Curve=NULL;
}
//---------------------------------------------------------------------------
void T_Trajectory::SaveToFile(const char *fname)const
{
    FILE *File=fopen(fname,"wb");
    SaveToFile(File);
    fclose(File);
}
//---------------------------------------------------------------------------
void T_Trajectory::LoadFromFile(const char *fname)
{
    FILE *File=fopen(fname,"rb");
    if(File)
    {
        LoadFromFile(File);
        fclose(File);
    }
}
//---------------------------------------------------------------------------
void T_Trajectory::SetAmount(const int &Amount)
{
    if(Amount>=0)
    {
        if(Amount>0)
        {
            int i;
            T_Curve **buf=new T_Curve* [(this->Amount>Amount)?(Amount):(this->Amount)];
            for(i=0;i<((this->Amount>Amount)?(Amount):(this->Amount));i++)
            {
                buf[i]=Curve[i];
            }
            for(i=0;i<this->Amount;i++)
            {
                delete Curve[i];
            }
            delete Curve;
            Curve=new pT_Curve [Amount];
            for(i=0;i<((this->Amount>Amount)?(Amount):(this->Amount));i++)
            {
                Curve[i]=buf[i];
            }
            delete buf;
            for(i=0;i<((this->Amount<Amount)?(Amount):(this->Amount));i++)
            {
                Curve[i]=NULL;
            }
        }
        else
        {
            Delete();
        }
        this->Amount=Amount;
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/***************************************************************************/
/*******************************Curve***************************************/
/***************************************************************************/
//---------------------------------------------------------------------------
void T_Curve::SaveToFileID(FILE *File)const
{
    char *ID=this->ClassName().t_str();
    int n=strlen(ID);
    fwrite(&n,sizeof(int),1,File);
    fwrite(ID,sizeof(char),n,File);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int T_Segment::Value(const double &t,T_Vector2d &p)
{
    p=(p1-p0)*t+p0;
    return 1;
}
//---------------------------------------------------------------------------
void T_Segment::LoadFromFile(FILE *File)
{
    fread(&p0,sizeof(T_Vector2d),1,File);
    fread(&p1,sizeof(T_Vector2d),1,File);
}
//---------------------------------------------------------------------------
void T_Segment::SaveToFile(FILE *File)const
{
    SaveToFileID(File);
    fwrite(&p0,sizeof(T_Vector2d),1,File);
    fwrite(&p1,sizeof(T_Vector2d),1,File);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
T_Arc::T_Arc(const double &_xc,const double &_yc,const double &_r,
          const double &_fi0,const double &_fi1,const char &ccw):c(_xc,_yc)
{
    int k;
    r=_r;
    k=fabs(_fi0)/(2*M_PI);
    fi0=fabs(_fi0)-2*M_PI*k;
    if(_fi0<0)
    {
        fi0=2*M_PI-fi0;
    }
    k=fabs(_fi1)/(2*M_PI);
    fi1=fabs(_fi1)-2*M_PI*k;
    if(_fi1<0)
    {
        fi1=2*M_PI-fi1;
    }
    counterclockwise=ccw;
    if(counterclockwise==1)
    {
        if(fi0>fi1)
        {
            fi1+=2*M_PI;
        }
    }
    else
    {
        if(fi0<fi1)
        {
            fi1-=2*M_PI;
        }
    }
}
//---------------------------------------------------------------------------
int T_Arc::Value(const double &t,T_Vector2d &p)
{
    p.X=r*cos((fi1-fi0)*t+fi0)+c.X;
    p.Y=r*sin((fi1-fi0)*t+fi0)+c.Y;
    return 1;
}
//---------------------------------------------------------------------------
void T_Arc::LoadFromFile(FILE *File)
{
    fread(&c,sizeof(T_Vector2d),1,File);
    fread(&r,sizeof(double),1,File);
    fread(&fi0,sizeof(double),1,File);
    fread(&fi1,sizeof(double),1,File);
    fread(&counterclockwise,sizeof(char),1,File);
}
//---------------------------------------------------------------------------
void T_Arc::SaveToFile(FILE *File)const
{
    SaveToFileID(File);
    fwrite(&c,sizeof(T_Vector2d),1,File);
    fwrite(&r,sizeof(double),1,File);
    fwrite(&fi0,sizeof(double),1,File);
    fwrite(&fi1,sizeof(double),1,File);
    fwrite(&counterclockwise,sizeof(char),1,File);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int T_HermiteCurve::Value(const double &t,T_Vector2d &p)
{
    p=p0*(2*t*t*t-3*t*t+1)+p1*(-2*t*t*t+3*t*t)+q0*(t*t*t-2*t*t+t)+q1*(t*t*t-t*t);
    return 1;
}
//---------------------------------------------------------------------------
void T_HermiteCurve::LoadFromFile(FILE *File)
{
    fread(&p0,sizeof(T_Vector2d),1,File);
    fread(&p1,sizeof(T_Vector2d),1,File);
    fread(&q0,sizeof(T_Vector2d),1,File);
    fread(&q1,sizeof(T_Vector2d),1,File);
}
//---------------------------------------------------------------------------
void T_HermiteCurve::SaveToFile(FILE *File)const
{
    SaveToFileID(File);
    fwrite(&p0,sizeof(T_Vector2d),1,File);
    fwrite(&p1,sizeof(T_Vector2d),1,File);
    fwrite(&q0,sizeof(T_Vector2d),1,File);
    fwrite(&q1,sizeof(T_Vector2d),1,File);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int T_BezierCurve::Value(const double &t,T_Vector2d &p)
{
    p=p0*(1-t)*(1-t)*(1-t)+p1*(3*t*(1-t)*(1-t))+p2*(3*t*t*(1-t))+p3*(t*t*t);
    return 1;
}
//---------------------------------------------------------------------------
void T_BezierCurve::LoadFromFile(FILE *File)
{
    fread(&p0,sizeof(T_Vector2d),1,File);
    fread(&p1,sizeof(T_Vector2d),1,File);
    fread(&p2,sizeof(T_Vector2d),1,File);
    fread(&p3,sizeof(T_Vector2d),1,File);
}
//---------------------------------------------------------------------------
void T_BezierCurve::SaveToFile(FILE *File)const
{
    SaveToFileID(File);
    fwrite(&p0,sizeof(T_Vector2d),1,File);
    fwrite(&p1,sizeof(T_Vector2d),1,File);
    fwrite(&p2,sizeof(T_Vector2d),1,File);
    fwrite(&p3,sizeof(T_Vector2d),1,File);
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

