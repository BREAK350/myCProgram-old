//---------------------------------------------------------------------------
#ifndef T_TrajectoryH
#define T_TrajectoryH
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vcl.h>
#include "T_Vector2d.h"
//---------------------------------------------------------------------------
struct T_Curve:public TObject
{
    virtual int Value(const double &t,T_Vector2d &p){ return 0; }
    virtual void LoadFromFile(FILE *File){}
    virtual void SaveToFile(FILE *File)const{}

    void SaveToFileID(FILE *File)const;
};
//---------------------------------------------------------------------------
typedef T_Curve* pT_Curve;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class T_Trajectory
{
    protected:
        double Epsilon,Length,Last_t;

        int Amount;

        pT_Curve *Curve;
    protected:
        char* LoadFromFileID(FILE *File);

        double Distance(const T_Vector2d &p1,const T_Vector2d &p2);
        double Normalization(const double &t);

        int Value(const double &t,T_Vector2d &p); // if(Amount>0)

        pT_Curve GetIDType(const char *ID)const;

        void Delete();
        void Nullify();
        void LoadFromFile(FILE *File);
        void NextPointLR(int &k,const T_Vector2d &p0,T_Vector2d &p,double &l,double &r,const int &kmax);
        void SaveToFile(FILE *File)const;
    public:
        T_Trajectory();
        T_Trajectory(const int &_Amount);
        T_Trajectory(const T_Trajectory &Trajectory); // ?
        ~T_Trajectory() { Delete(); }
        T_Trajectory& operator = (const T_Trajectory &Trajectory);

        double Get_t()const { return Last_t; }

        int NextPoint_Right(const double &t0,T_Vector2d &p);
        int NextPoint_Left(const double &t0,T_Vector2d &p);
        int GetPoint(const double &t,T_Vector2d &p);
        int GetAmount()const { return Amount; }
        int GetCount()const { return Amount; }
        pT_Curve& operator [] (const int &i);

        void SetAmount(const int &Amount);
        void SetCount(const int &Count) { SetAmount(Count); }
        void SetEpsilon(const double &_Epsilon);
        void SetLength(const double &_Length);
        void SaveToFile(const char *fname)const;
        void LoadFromFile(const char *fname);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/***************************************************************************/
/*******************************Curve***************************************/
/***************************************************************************/
struct T_Segment:public T_Curve
{
    T_Vector2d p0,p1;
    T_Segment() {}
    T_Segment(const double &x0,const double &y0,const double &x1,const double &y1)
        :p0(x0,y0),p1(x1,y1) {}
    T_Segment(const T_Vector2d &_p0,const T_Vector2d &_p1)
        :p0(_p0),p1(_p1) {}
    virtual int Value(const double &t,T_Vector2d &p);
    virtual void LoadFromFile(FILE *File);
    virtual void SaveToFile(FILE *File)const;
};
//---------------------------------------------------------------------------
struct T_Arc:public T_Curve
{
    T_Vector2d c;
    double r,fi0,fi1;
    char counterclockwise; //1-проти годинникової стрілки
    T_Arc() {}
    T_Arc(const double &_xc,const double &_yc,const double &_r,
          const double &_fi0,const double &_fi1,const char &ccw); // radian
    virtual int Value(const double &t,T_Vector2d &p);
    virtual void LoadFromFile(FILE *File);
    virtual void SaveToFile(FILE *File)const;
};
//---------------------------------------------------------------------------
struct T_HermiteCurve:public T_Curve
{
    T_Vector2d p0,p1,q0,q1;
    T_HermiteCurve() {}
    T_HermiteCurve(const T_Vector2d &_p0,const T_Vector2d &_p1,
                   const T_Vector2d &_q0,const T_Vector2d &_q1)
                   :p0(_p0),p1(_p1),q0(_q0),q1(_q1) {}
    virtual int Value(const double &t,T_Vector2d &p);
    virtual void LoadFromFile(FILE *File);
    virtual void SaveToFile(FILE *File)const;
};
//---------------------------------------------------------------------------
struct T_BezierCurve:public T_Curve
{
    T_Vector2d p0,p1,p2,p3;
    T_BezierCurve() {}
    T_BezierCurve(const T_Vector2d &_p0,const T_Vector2d &_p1,
                  const T_Vector2d &_p2,const T_Vector2d &_p3)
                  :p0(_p0),p1(_p1),p2(_p2),p3(_p3) {}
    virtual int Value(const double &t,T_Vector2d &p);
    virtual void LoadFromFile(FILE *File);
    virtual void SaveToFile(FILE *File)const;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
