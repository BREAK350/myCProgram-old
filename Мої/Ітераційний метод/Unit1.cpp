//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Geometry.h"
#pragma argsused
#include <conio.h>
T_Matrix A,b,x;
const double E=0.001;
char fname[]="laba1.txt"; // назва файла з даними
//---------------------------------------------------------------------------
void LoadFromFile() // загрузка даних з файла
{
    int i,j;
    int n;
    double el;
    FILE *f=fopen(fname,"r");
    fscanf(f,"%d",&n);
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
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
double Teta(const T_Matrix &x) // коефіцієнт тета
{
    T_Matrix bAxk=b-A*x;
    T_Matrix AbAxk=A*bAxk;
    gT_Vector v1=bAxk.GetCol(0),
              v2=AbAxk.GetCol(0);
    return v2.Scalar(v1)/v2.Scalar(v2);
}
//---------------------------------------------------------------------------
int Solve()
{
    int i=0;
    T_Matrix x0,x1,r;
    x1=b;
    do
    {
        x0=x1;
        r=b-A*x0;
        x1=x0+r*Teta(x0);
        i++;
    }
    while(x0.Approximation(x1)>=E);
    x=x1;
    return i;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    int k;
    LoadFromFile();
    A.printf("--A--");
    b.printf("--b--");
    k=Solve();
    x.printf("--x--");
    (b-A*x).printf("--r--");
    cout<<"kilkist iteraciy "<<k<<endl;
    getch();
    return 0;
}
//---------------------------------------------------------------------------
