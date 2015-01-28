//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include <iostream.h>
#include <conio.h>
#include <math.h>
//---------------------------------------------------------------------------
/*Білет №12*/
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    int n,bal,summ=0;
    cout<<"n=";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"student "<<i+1<<", bal=";
        cin>>bal;
        summ+=bal;
    }
    cout<<"seredniy bal="<<(float)summ/n<<endl;
    getch();
    return 0;
}
//---------------------------------------------------------------------------
