//---------------------------------------------------------------------------
#ifndef T_MatrixH
#define T_MatrixH
#include <stdio.h>
//---------------------------------------------------------------------------
class T_Matrix
{
    private:
        int N,M,**E;
    public:
        T_Matrix();
        T_Matrix(const T_Matrix &Matrix);
        T_Matrix(const int &n,const int &m);
        T_Matrix(const int &n,const int &m,const int &e);
        ~T_Matrix();
        T_Matrix& operator = (const T_Matrix &Matrix);
        int GetE(const int &i,const int &j,int &e)const;
        int SetE(const int &i,const int &j,const int &e);
        int GetN()const { return N; }
        int GetM()const { return M; }
        void Nullify();
        void Copy(const T_Matrix &Matrix,const int &pi,const int &pj,const int &Insert);
            // ��������� � ������� Matrix
        void Paste(const T_Matrix &Matrix,const int &pi,const int &pj);
            // ������� ������� Matrix
        void PasteAdd(const T_Matrix &Matrix,const int &pi,const int &pj);
            // ������� ������� Matrix (�������� ���������)
        void Sub(const T_Matrix &Matrix,const int &pi,const int &pj);
            // �������� ������� Matrix (�������� ����������)
        void Cut(T_Matrix &Matrix,const int &pi,const int &pj,const int &Insert);
            // �������� � ������� Matrix
        void MirroringRow();
        void MirroringCol();
        void Rotation90();
        void Rotation180();
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
