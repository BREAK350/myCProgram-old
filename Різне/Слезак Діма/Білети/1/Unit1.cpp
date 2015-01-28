//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include <iostream.h>
#include <conio.h>
//---------------------------------------------------------------------------
/*Білет №1*/
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    float M[3][3];

    cout<<"input matrix:\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>M[i][j];
        }
    }

    int imax=0,jmax=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(M[i][j]>M[imax][jmax])
            {
                imax=i;
                jmax=j;
            }
        }
    }
    cout<<"max: ("<<imax<<';'<<jmax<<")\n";
    getch();
    return 0;
}
//---------------------------------------------------------------------------
 