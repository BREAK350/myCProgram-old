//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "T_Geometry.h"
#include <conio.h>
int N;//розмірність матриці
T_Matrix A,b,x,*p=NULL; //матриця А, вектор бе,результат х,р-масив векторів
double *a;//масив чисел а
char fname[]="laba1.txt"; // назва файла з даними
//---------------------------------------------------------------------------
double Alpha(const int &i) // знаходження числа альфа за формулою
{
    T_Matrix Ap=A*p[i];
    gT_Vector a=Ap.GetCol(0),b=p[i].GetCol(0); // берем 0-й стовпчик з матриць
    return a.Scalar(b)/b.Scalar(b); // скалярні добутки
}
//---------------------------------------------------------------------------
void LoadFromFile() // загрузка даних з файла
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
double Betta(const int &i) // знаходження числа бетта за формулою
{
    gT_Vector v0=p[i-1].GetCol(0),v1=p[i].GetCol(0);
    return v1.Scalar(v1)/v0.Scalar(v0);
}
//---------------------------------------------------------------------------
void Search_p()// побудова масиву векторів р
{
    int i;
    for(i=1;i<N-1;i++)
    {
        p[i+1]=A*p[i]-p[i]*Alpha(i)-p[i-1]*Betta(i);// по формулі:)
    }
}
//---------------------------------------------------------------------------
double S(const int &i)//права частина тригодіанальної матриці
{
    gT_Vector a=b.GetCol(0),        //
    b=p[i].GetCol(0);               // по формулі
    return a.Scalar(b)/b.Scalar(b); //
}
//---------------------------------------------------------------------------
void Search_a()
{
    int i,j;
    T_Matrix ma;      // допоміжна матриця ( вона буде тригодіагональною)
    ma.SetSize(N,N+1);
    for(i=0;i<N;i++)   // ініціалізація матриці
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
    for(i=0;i<N-1;i++)   // методом гауса зводим матрицю до трикутної
    {
        for(j=i;j<N+1;j++)
        {
            ma.SetElement(i+1,j,ma.GetElement(i+1,j)-ma.GetElement(i,j)/ma.GetElement(i,i));
        }
    }
    for(i=N-1;i>=0;i--) // вираховуєм розв'язок системи
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
    LoadFromFile(); // загружаєм ...
    Search_p();     // шукаєм р ...
    Search_a();     // шукаєм а ...
    x.SetSize(N,1); // ініціалізація х ...
    for(i=0;i<N;i++)
    {
        x=x+p[i]*a[i]; // знаходження х по формулі 4.40
    }
    x.printf("x:");
    cout<<"end";
    getch();
    return 0;
}
//---------------------------------------------------------------------------
