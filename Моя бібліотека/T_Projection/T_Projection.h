//---------------------------------------------------------------------------
#ifndef T_ProjectionH
#define T_ProjectionH
#include "T_Geometry.h"
//---------------------------------------------------------------------------
struct T_Point2D
{
    double x,y;
    T_Point2D() {}
    T_Point2D(const double &_x,const double &_y) { x=_x; y=_y; }
};
//---------------------------------------------------------------------------
struct T_Point3D
{
    double x,y,z;
    T_Point3D() {}
    T_Point3D(const double &_x,const double &_y,const double &_z) { x=_x; y=_y; z=_z; }
    void Init(const double &_x,const double &_y,const double &_z) { x=_x; y=_y; z=_z; }
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*
    Афінні перетворення на площині
*/
class T_2D
{
    public:
        double C[3];
    public:
        /*Конструктори та деструктори*/
        T_2D() { C[0]=C[1]=C[2]=0; }
        T_2D(const T_2D &p);
        ~T_2D() {}
        T_2D(const TPoint &p);
        T_2D(const T_Point &p);
        T_2D(const T_Point2D &p);
        T_2D(const double &x,const double &y);
        /*********Оператори***********/
        T_2D& operator = (const T_2D &p);
        operator T_Point();
        /***********Функції***********/
        T_2D& Dilation(const double &s) { return Dilation(s,s); }
        T_2D& Dilation(const double &a,const double &b); // розтяг (стиск) відносно початку
        T_2D& Dilation(const double &a,const double &b,const double &m,const double &n); // розтяг (стиск) відносно вектора (m,n)
        T_2D& Reflection(); // дзеркальне відображення відносно осі x
        T_2D& Rotation(const double &fi);   // поворот відносно початку координат
        T_2D& Rotation(const T_Vector &v,const double &fi) { return Rotation(v.X,v.Y,fi); }
        T_2D& Rotation(const double &m,const double &n,const double &fi);//поворот відносно вектора (m,n)
        T_2D& Translation(const T_Vector &v) { return Translation(v.X,v.Y); }
        T_2D& Translation(const double &m,const double &n); // перенесення точки на вектор
        // Скорочені функції
        T_2D& D(const double &a,const double &b) { return Dilation(a,b); }
        T_2D& R(const double &fi) { return Rotation(fi); }
        T_2D& T(const double &m,const double &n) { return Translation(m,n); }
        T_2D& Ref() { return Reflection(); }
        /************друзі************/
};
//---------------------------------------------------------------------------
class T_3D
{
    public:
        double C[4];
    public:
        /*Конструктори та деструктори*/
        T_3D(const T_Point3D &p);
        T_3D(const double &x,const double &y,const double &z);
        ~T_3D() {}
        /*********Оператори***********/
        T_3D& operator = (const T_3D &p);
        operator T_Point3D();
        /***********Функції***********/
        T_3D& A(const double &psi,const double &fi); // аксонометричне проектування
        T_3D& D(const double &s) { return D(s,s,s); }
        T_3D& D(const T_Point3D &p) { return D(p.x,p.y,p.z); }
        T_3D& D(const double &a,const double &b,const double &c); // масштабування
        T_3D& Kz(const T_Point3D &p) { return Kz(p.x,p.y,p.z); }
        T_3D& Kz(const double &px,const double &py,const double &pz); // косокутне проектування вздовж вектора
        T_3D& Mxy(); // дзеркальне відображення відносно xy
        T_3D& Myz(); // дзеркальне відображення відносно yz
        T_3D& Mxz(); // дзеркальне відображення відносно xz
        T_3D& Mv(const double &fi,const double &teta,const double &ro);// видове перетворення
        T_3D& M1(const double &f,const double &n,const double &c);// перспективне проектування (ст. 256) 0<n<f
        T_3D& Pab(const double &a,const double &b);
        T_3D& Px(); // ортогональне проектування вздовж осі x
        T_3D& Py(); // ортогональне проектування вздовж осі y
        T_3D& Pz(); // ортогональне проектування вздовж осі z
        T_3D& P1(const double &c); // одноточкова перспектива
        T_3D& Rz(const double &x); // поворот простору відносно z
        T_3D& Rx(const double &fi); // поворот простору відносно x
        T_3D& Ry(const double &psi); // поворот простору відносно y
        T_3D& R(const T_Point3D &v,const double &fi) { return R(v.x,v.y,v.z,fi); }
        T_3D& R(double a,double b,double c,const double &fi); // поворот навколо одиничного вектора (a,b,c) на кут fi
        T_3D& R(const T_Point3D &p,const T_Point3D &v,const double &fi)
              { return R(p.x,p.y,p.z,v.x,v.y,v.z,fi); }
        T_3D& R(const double &x0,const double &y0,const double &z0,
                const double &a,const double &b,const double &c,const double &fi);
        T_3D& T(const T_Point3D &v) { return T(v.x,v.y,v.z); }
        T_3D& T(const double &l,const double &m,const double &n); // перенесення точки на вектор

        /************друзі************/
};
//---------------------------------------------------------------------------
struct T_Link
{
    int First,Second;
    void Init(const int &f,const int &s) { First=f; Second=s; }
};
//---------------------------------------------------------------------------
struct T_Points
{
    int NPoint;
    T_Point3D *Point;
};
//---------------------------------------------------------------------------
struct pT_Link
{
    int NLink;
    T_Link *Link;
};
//---------------------------------------------------------------------------
class T_3D_Obj
{
    public:
        T_Points Const,Buf;
        pT_Link Link;
    public:
        /*Конструктори та деструктори*/
        /*********Оператори***********/
        /***********Функції***********/
        void doCopy();
        void Draw(TCanvas *Canvas,const TPoint &v,const double &s,const TPoint &o);
        void Mv(const double &fi,const double &teta,const double &ro);
        void M1(const double &f,const double &n,const double &c);
        void Pab(const double &a,const double &b);
        void P1(const double &c);
        /************друзі************/
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
