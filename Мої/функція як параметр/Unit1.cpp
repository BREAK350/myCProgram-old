//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include <iostream.h>
//---------------------------------------------------------------------------
typedef float(*func)(float);
//---------------------------------------------------------------------------
void call_func(float(*f)(float))
{
    cout<<f(4)<<endl;
}
//---------------------------------------------------------------------------
float* Graph(func f,float A,float B,int n)
{
    if(B<A)
    {
        return NULL;
    }
    float *y=new float[n];
    int i;
    for(i=0;i<n;i++)
    {
        y[i]=f((B-A)/n*(i+1)+A);
    }
    return y;
}
//---------------------------------------------------------------------------
void pervisna(func f)
{
    cout<<f(3)<<endl;
}
//---------------------------------------------------------------------------
float f1(float x)
{
    return x*x;
}
//---------------------------------------------------------------------------
float f2(float x)
{
    return x;
}
//---------------------------------------------------------------------------
func max(func f1,func f2)
{
    if(f1(4)>f2(4))
    {
        return f1;
    }
    return f2;
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    call_func(max(f1,f2));
    system("Pause");
    return 0;
}
//---------------------------------------------------------------------------
