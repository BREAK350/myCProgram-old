//---------------------------------------------------------------------------
#ifndef ObjectH
#define ObjectH
#include <math.h>
#include <stdio.h>
#include "T_Poligon.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class T_Object
{
    protected:
        int n;//������� ��������� ��� (�������)
        int *pn;//������� ����� ����� �������� ��
        T_Point **p;//�� ����� ��� ���
        TColor *cl;//��������� ���� ������� �������
        float Scale;//�������
        T_Point Where;//��������� ������������
        float angle;//��� � ��������� ���� �� � �������
        T_Point GC(const T_Point &);//��������� ����� �� ����������� ������
        T_Point Rotate(const T_Point &);//������� ������ � �������� � (0;0) �� ���
        T_Point Move(const T_Point &);//�������� ����� �� ������, ������� ����� � ��������(��������)
        T_Point Zoom(const T_Point &);//�������� �����
        void DrawPoligon(TCanvas *,int);
        void SaveToFile(FILE *);
        void LoadFromFile(FILE *);
    public:
        T_Object();
        T_Object(const T_Object &);
        T_Object(int,int *,T_Point **,TColor *,float,T_Point, float);
        virtual void Init(int,int *,T_Point **,TColor *,float,T_Point, float);
        virtual ~T_Object();
        virtual void Draw(TCanvas *);
        virtual void SaveToFile(const char *);
        virtual void LoadFromFile(const char *);
        void SetAngleGradus(float);
        void SetWhere(T_Point);
        T_Point SearchCenter();
        float GetDiametr();
        float Distance(const T_Object &);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
