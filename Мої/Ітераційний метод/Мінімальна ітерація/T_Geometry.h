//---------------------------------------------------------------------------
#ifndef T_GeometryH
#define T_GeometryH
#include <vcl.h>
#include <math.h>
#include <stdio.h>
#include <iostream.h>
//---------------------------------------------------------------------------
/*******************************T_Point*************************************/
//---------------------------------------------------------------------------
class T_StraightLine;
//---------------------------------------------------------------------------
class T_Point
{
    public:
        double X,Y;
    public:
        /*������������ �� �����������*/
        T_Point();
        T_Point(const double &,const double &);
        T_Point(const TPoint &);
        T_Point(const T_Point &);
        ~T_Point(){}
        /*********���������***********/
        int operator == (const T_Point &)const;
        bool operator !=(const T_Point &)const;
        operator TPoint()const;
        T_Point& operator = (const T_Point &);
        /***********�������***********/
        T_Point Symetry(const T_Point &);
        char* toChar()const;
        double Distance(const T_Point &)const;
        double Distance(const T_StraightLine &)const;
        int Comparison(const T_Point &p)const; // ������� ������ �� �����������
            // ������, � ��� ����������� ���� ����� ������� p
        void Draw(TCanvas *,const TColor &)const;
        void Init(const double &,const double &);
};
//---------------------------------------------------------------------------
/*******************************T_Vector************************************/
//---------------------------------------------------------------------------
class T_Vector:public T_Point
{
    public:
        /*������������ �� �����������*/
        T_Vector():T_Point(){}
        T_Vector(const T_Point &p):T_Point(p){}
        T_Vector(const T_Vector &);
        T_Vector(const T_Vector &,const T_Vector &); // ������ �� ����� �������
        T_Vector(const double &,const double &);
        ~T_Vector(){}
        /*********���������***********/
        T_Vector operator + (const T_Vector &)const;
        T_Vector operator - (const T_Vector &)const;
        T_Vector operator * (const double &)const;
        /***********�������***********/
        T_Vector Rotate(const double &angle); // ������� ������ �� ��� angle
        T_Vector Normalization(); // ����� ������� �� 1
        double isPerpendicular(const T_Vector &v)const { return Scalar(v); }
        double Scalar(const T_Vector &)const;
        double Length()const;
        double GetAngleRadian()const;
        double AngleBetween(const T_Vector &)const;
        void Draw(TCanvas *,const TColor &)const;
        void SetLength(const double &);
};
//---------------------------------------------------------------------------
/****************************T_AnyVector************************************/
//---------------------------------------------------------------------------
class T_AnyVector:public T_Vector
{
    protected:
        T_Vector Begin;
    public:
        /*������������ �� �����������*/
        T_AnyVector():T_Vector(0,0),Begin(0,0) {}
        T_AnyVector(const T_Vector &v):T_Vector(v),Begin(0,0) {}
        T_AnyVector(const T_AnyVector &);
        T_AnyVector(const T_Vector &,const T_Vector &);
        T_AnyVector(const double &x1,const double &y1,const double &x2,const double &y2)
            :T_Vector(x2-x1,y2-y1),Begin(x1,y1) {}
        ~T_AnyVector() {}
        /*********���������***********/
        T_AnyVector& operator = (const T_AnyVector &);
        T_AnyVector operator + (const T_AnyVector &)const;
        /***********�������***********/
        T_Vector GetBegin()const { return Begin; }
        T_Vector GetEnd()const { return (T_Vector(*this)+Begin); }
        char* toChar(const int &)const;
        void Draw(TCanvas *,const TColor &)const;
        void Move();
        void SetBegin(const T_Point &b) { Begin=b; }
        void SetEnd(const T_Point &);
        T_AnyVector Rotate(const T_Point &,const double &);
};
//---------------------------------------------------------------------------
/**************************T_StraightLine***********************************/
//---------------------------------------------------------------------------
class T_StraightLine // Ax+By+C=0
{
    public:
        double A,B,C;
    public:
        /*������������ �� �����������*/
        T_StraightLine() { A=B=C=0; }
        T_StraightLine(const T_StraightLine &sl);
        T_StraightLine(const double &a,const double &b,const double &c); // ax+by+c=0
        T_StraightLine(const double &k,const double &b); // y=kx+b
        T_StraightLine(const T_Point &p1,const T_Point &p2);
        T_StraightLine(const T_Vector &v);
        ~T_StraightLine() {}
        /*********���������***********/
        T_StraightLine& operator = (const T_StraightLine &sl);
        /***********�������***********/
        double isCorrectLine()const;
        int isParallel(const T_StraightLine &sl)const;
        double GetAngleRadian()const;
        void Init(const double &a,const double &b,const double &c);
};
//---------------------------------------------------------------------------
/******************************gT_Vector************************************/
//---------------------------------------------------------------------------
class gT_Vector // ������ � N-�������� �������
{
    private:
        int N; // N-����
        double *C; // ����������
    public:
        /*������������ �� �����������*/
        gT_Vector();
        gT_Vector(const int &);
        gT_Vector(const gT_Vector &);
        gT_Vector(const T_Vector &);
        ~gT_Vector();
        /*********���������***********/
        int operator == (const gT_Vector &)const;
        gT_Vector& operator = (const gT_Vector &);
        gT_Vector operator + (const gT_Vector &)const;
        gT_Vector operator - (const gT_Vector &)const;
        gT_Vector operator * (const double &)const;
        operator T_Vector()const;
        /***********�������***********/
        double Approximation(const gT_Vector &)const;
        double Distance(const gT_Vector &)const;
        double Length()const;
        double GetCoordinate(const int &)const;
        double GetX()const { return GetCoordinate(0); }
        double GetY()const { return GetCoordinate(1); }
        double GetZ()const { return GetCoordinate(2); }
        double Normalization() { return SetLength(1); }
        double Scalar(const gT_Vector &)const;
        double SetLength(const double &);
        int GetDimension()const { return N; }
        void Rotate(const int &,const int &,const double &);
        void SetCoordinate(const int &,const double &);
        void SetDimension(const int &);
        void SetX(const double &c) { SetCoordinate(0,c); }
        void SetY(const double &c) { SetCoordinate(1,c); }
        void SetZ(const double &c) { SetCoordinate(2,c); }
        /************����************/
        friend int MaxDimension(const gT_Vector &,const gT_Vector &);
        friend int MinDimension(const gT_Vector &,const gT_Vector &);
};
//---------------------------------------------------------------------------
typedef gT_Vector gT_Point;
//---------------------------------------------------------------------------
/**************************gT_StraightLine**********************************/
//---------------------------------------------------------------------------
class gT_StraightLine
{
    protected:
        gT_Vector DirectionalVector, // ����������� ������
                  Point;
    public:
        /*������������ �� �����������*/
        gT_StraightLine();
        gT_StraightLine(const gT_Vector &,const gT_Vector &);
        /*********���������***********/
        /***********�������***********/
        gT_Vector GetVectorT(const double &);
        double GetCoordinateT(const int &,const double &);
        int GetDimension()const { return DirectionalVector.GetDimension(); }
        int isParallel(const gT_StraightLine &);
        /************����************/
};
//---------------------------------------------------------------------------
/****************************T_Designator***********************************/
//---------------------------------------------------------------------------
class T_Designator // ���������
{
    private:
        int N;
        double **E;
    public:
        /*������������ �� �����������*/
        T_Designator();
        T_Designator(const T_Designator &);
        T_Designator(const int &);
        ~T_Designator();
        /*********���������***********/
        /***********�������***********/
        /************����************/
};
//---------------------------------------------------------------------------
/*************************T_CoordinateSystem********************************/
//---------------------------------------------------------------------------
class T_CoordinateSystem
{
    protected:
        T_Vector Ox,Oy,O;
    public:
        /*������������ �� �����������*/
        T_CoordinateSystem():Ox(1,0),Oy(0,1),O(0,0) {}
        /*********���������***********/
        /***********�������***********/
        T_Point GetPoint(const T_Point &)const;
        /************����************/
};
//---------------------------------------------------------------------------
/******************************T_Matrix*************************************/
//---------------------------------------------------------------------------
class T_Matrix
{
    private:
        int N, // �����
            M; // ��������
        double **E; // ��������
    public:
        /*������������ �� �����������*/
        T_Matrix();
        T_Matrix(const T_Matrix &);
        T_Matrix(const T_Vector &);
        T_Matrix(const gT_Vector &);
        T_Matrix(const gT_Vector &,const int &);
        T_Matrix(const int &,const int &,const double **);
        T_Matrix(const int &,const int &,double,...);
        T_Matrix(const T_Matrix &,int,int,int,int);
        ~T_Matrix();
        /*********���������***********/
        T_Matrix& operator = (const T_Matrix &);
        T_Matrix operator + (const T_Matrix &)const;
        T_Matrix operator - (const T_Matrix &)const;
        T_Matrix operator * (const T_Matrix &)const;
        T_Matrix operator * (const double &)const;
        /***********�������***********/
        double Approximation(const T_Matrix &)const;
        double GetElement(const int &,const int &)const;
        int GetSizeRow()const { return N; }
        int GetSizeCol()const { return M; }
        void SetElement(const int &,const int &,const double &);
        void SetSize(const int &,const int &);
        void Delete();
        T_Matrix Copy(const int &,const int &,const int &,const int &);
        void Paste(const T_Matrix &,const int &,const int &);
        void printf()const;
        void printf(const char *)const;
        void Turn();
        gT_Vector GetRow(const int &)const; // �����
        gT_Vector GetCol(const int &)const; // ��������
        /************����************/
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
