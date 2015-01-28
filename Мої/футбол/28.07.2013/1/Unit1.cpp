//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include <iostream.h>
#include <conio.h>
#include <math.h>
//---------------------------------------------------------------------------
double Im(const double &O)
{
    return pow(0.7,O)*100;
}
//---------------------------------------------------------------------------
bool Adding(const double &Im)
{
    bool add=false;
    double im=random(10000)/100;
    if(im<Im)
    {
        add=true;
    }
    return add;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    double O=10,h=0.1;
    randomize();
    int addtrue,strue=0;
    for(int i=0;i<100;i++)
    {
        addtrue=Adding(Im(O));
        strue+=addtrue;
        cout<<addtrue<<endl;
    }
    cout<<"real im="<<Im(O)<<" : practical im="<<strue/30.0*100<<endl;
    getch();
    return 0;
}
//---------------------------------------------------------------------------
 