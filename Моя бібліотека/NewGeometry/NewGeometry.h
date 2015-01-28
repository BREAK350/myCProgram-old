//---------------------------------------------------------------------------
#ifndef NewGeometryH
#define NewGeometryH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>
//---------------------------------------------------------------------------
class TbMatrix_d
{
    private:
        int RowCount,ColCount;
        double **Element;
    protected:
        void Delete();
        void New(const int &RowCount,const int &ColCount);
        void Fill(const double &f);
        void Fill(double **E);
    public:
        TbMatrix_d();
        TbMatrix_d(const TbMatrix_d &Matrix);
        TbMatrix_d(const int &RowCount,const int &ColCount);
        ~TbMatrix_d();

        TbMatrix_d&  operator = (const TbMatrix_d &Matrix);
        TbMatrix_d   operator + (const TbMatrix_d &Matrix);
        TbMatrix_d   operator - (const TbMatrix_d &Matrix);
        TbMatrix_d&  operator += (const TbMatrix_d &Matrix);
        TbMatrix_d&  operator -= (const TbMatrix_d &Matrix);
        TbMatrix_d   operator * (const TbMatrix_d &Matrix);
        TbMatrix_d&  operator *= (const TbMatrix_d &Matrix);

        double*      operator [] (const int &Row)const { return Element[Row]; }
        int          GetRowCount()const { return RowCount; }
        int          GetColCount()const { return ColCount; }
};
//---------------------------------------------------------------------------
struct TbPoint2d;
class TbMatrix_3d:protected TbMatrix_d
{
    public:
        TbMatrix_3d():TbMatrix_d(3,3) {}
        TbMatrix_3d(const double &e00,const double &e01,const double &e02,
                    const double &e10,const double &e11,const double &e12,
                    const double &e20,const double &e21,const double &e22);
        TbMatrix_3d GetTranslation(const TbPoint2d &Vector)const;
        TbMatrix_3d GetDilation(const TbPoint2d &Vector)const;
        TbMatrix_3d GetRotation(const double &fi)const;
        TbMatrix_3d GetReflectionX()const;
        TbMatrix_3d GetReflectionY()const;
        TbMatrix_3d operator * (const TbMatrix_3d &Matrix);
        TbMatrix_3d& operator = (const TbMatrix_3d &Matrix);
        TbMatrix_d ToTbMatrix_d()const;
};
//---------------------------------------------------------------------------
struct TbPoint2d
{
    double x,y;
    TbPoint2d() { x=0; y=0; }
    TbPoint2d(const double &x,const double &y) { this->x=x; this->y=y; }
    void Init(const double &x,const double &y) { this->x=x; this->y=y; }
    void MoveTo(TCanvas *Canvas) { Canvas->MoveTo(x,y); }
    void LineTo(TCanvas *Canvas) { Canvas->LineTo(x,y); }
    void Pixel(TCanvas *Canvas,const TColor &Color) { Canvas->Pixels[x][y]=Color; }
};
//---------------------------------------------------------------------------
class TbSelfPoint2d:protected TbMatrix_d
{
    public:
        TbSelfPoint2d():TbMatrix_d(1,3) { this->operator [](0)[2]=1; }
        TbSelfPoint2d(const TbPoint2d &Point):TbMatrix_d(1,3)
            { this->operator [](0)[0]=Point.x; this->operator [](0)[1]=Point.y;
              this->operator [](0)[2]=1; }
        TbSelfPoint2d(const double &x,const double &y):TbMatrix_d(1,3)
            { this->operator [](0)[0]=x; this->operator [](0)[1]=y;
              this->operator [](0)[2]=1; }
        operator TbPoint2d()const;
        TbSelfPoint2d& operator = (const TbSelfPoint2d &Point);
        TbSelfPoint2d operator * (const TbMatrix_3d &Matrix);
};
//---------------------------------------------------------------------------
struct TbPoint3d:public TbPoint2d
{
    double z;
    TbPoint3d():TbPoint2d() { z=0; }
    TbPoint3d(const double &x,const double &y,const double &z)
        :TbPoint2d(x,y) { this->z=z; }
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
double Distance(const TbPoint2d &point1,const TbPoint2d &point2);
void Test();
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
