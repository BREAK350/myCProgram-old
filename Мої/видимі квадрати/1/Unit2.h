//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <vcl.h>
//---------------------------------------------------------------------------
struct TOrientation
{
    int i,j; // ���������� �������
    int si,sj; // ����� ( 1, -1)
    void Init(const int &_i,const int &_j,const int &_si,const int &_sj);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void CreateDark(const int **Track,int **Dark);
void CreateDark(const int **Track,int **Dark,const int &ci,const int &cj);
int Min(const int &A,const int &B);
void CreateDark(const int **Track,int **Dark,const TOrientation &or);
void Index(const int &V,int &i,int &j);
int Away(const int &i,const int &di);
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
 