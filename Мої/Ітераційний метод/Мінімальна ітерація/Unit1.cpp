//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "T_Geometry.h"
#include <conio.h>
int N;//��������� �������
T_Matrix A,b,x,*p=NULL; //������� �, ������ ��,��������� �,�-����� �������
double *a;//����� ����� �
char fname[]="laba1.txt"; // ����� ����� � ������
//---------------------------------------------------------------------------
double Alpha(const int &i) // ����������� ����� ����� �� ��������
{
    T_Matrix Ap=A*p[i];
    gT_Vector a=Ap.GetCol(0),b=p[i].GetCol(0); // ����� 0-� �������� � �������
    return a.Scalar(b)/b.Scalar(b); // ������� �������
}
//---------------------------------------------------------------------------
void LoadFromFile() // �������� ����� � �����
{
    int i,j;
    int n;
    double el;
    FILE *f=fopen(fname,"r");
    fscanf(f,"%d",&n);
    N=n;
    A.SetSize(n,n);
    b.SetSize(n,1);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(f,"%lf",&el);
            A.SetElement(i,j,el);
        }
    }
    for(i=0;i<n;i++)
    {
        fscanf(f,"%lf",&el);
        b.SetElement(i,0,el);
    }
    p=new T_Matrix[n];
    p[0].SetSize(n,1);
    p[0].SetElement(0,0,1);
    for(i=1;i<n;i++)
    {
        p[0].SetElement(i,0,0);
    }
    p[1]=A*p[0]-p[0]*Alpha(0);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
double Betta(const int &i) // ����������� ����� ����� �� ��������
{
    gT_Vector v0=p[i-1].GetCol(0),v1=p[i].GetCol(0);
    return v1.Scalar(v1)/v0.Scalar(v0);
}
//---------------------------------------------------------------------------
void Search_p()// �������� ������ ������� �
{
    int i;
    for(i=1;i<N-1;i++)
    {
        p[i+1]=A*p[i]-p[i]*Alpha(i)-p[i-1]*Betta(i);// �� ������:)
    }
}
//---------------------------------------------------------------------------
double S(const int &i)//����� ������� ������������� �������
{
    gT_Vector a=b.GetCol(0),        //
    b=p[i].GetCol(0);               // �� ������
    return a.Scalar(b)/b.Scalar(b); //
}
//---------------------------------------------------------------------------
void Search_a()
{
    int i,j;
    T_Matrix ma;      // �������� ������� ( ���� ���� ����������������)
    ma.SetSize(N,N+1);
    for(i=0;i<N;i++)   // ����������� �������
    {
        ma.SetElement(i,i,Alpha(i));
        if(i+1<N)
        {
            ma.SetElement(i,i+1,Betta(i+1));
        }
        ma.SetElement(i+1,i,1);
        ma.SetElement(i,N,S(i));
        for(j=0;j<i-1;j++)
        {
            ma.SetElement(i,j,0);
        }
        for(j=i+2;j<N;j++)
        {
            ma.SetElement(i,j,0);
        }
    }
    a=new double[N];
    for(i=0;i<N-1;i++)   // ������� ����� ������ ������� �� ��������
    {
        for(j=i;j<N+1;j++)
        {
            ma.SetElement(i+1,j,ma.GetElement(i+1,j)-ma.GetElement(i,j)/ma.GetElement(i,i));
        }
    }
    for(i=N-1;i>=0;i--) // ��������� ����'���� �������
    {
        a[i]=ma.GetElement(i,N);
        for(j=i+1;j<N;j++)
        {
            a[i]-=ma.GetElement(i,j)*a[j];
        }
        a[i]=a[i]/ma.GetElement(i,i);
    }
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    int i;
    LoadFromFile(); // �������� ...
    Search_p();     // ����� � ...
    Search_a();     // ����� � ...
    x.SetSize(N,1); // ����������� � ...
    for(i=0;i<N;i++)
    {
        x=x+p[i]*a[i]; // ����������� � �� ������ 4.40
    }
    x.printf("x:");
    cout<<"end";
    getch();
    return 0;
}
//---------------------------------------------------------------------------
