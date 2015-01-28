//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include <iostream.h>
#include <conio.h>
#include <fstream.h>
//---------------------------------------------------------------------------
/*Білет №10*/
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    int k=0;
    ofstream ofs("digit.txt");
    float num;
    for(int i=0;i<10;i++)
    {
        cin>>num;
        if(num==0)
        {
            k++;
        }
        ofs<<num<<' ';
    }
    ofs.close();
    cout<<k<<endl;
    getch();
    return 0;
}
//---------------------------------------------------------------------------
