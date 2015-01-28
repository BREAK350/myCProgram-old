//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include <iostream.h>
#include <conio.h>
#include <math.h>
//---------------------------------------------------------------------------
/*Білет №33*/
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    int M[5][5];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>M[i][j];
        }
    }

    int imin=0,jmin=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(M[i][j]<M[imin][jmin])
            {
                imin=i;
                jmin=j;
            }
        }
    }

    cout<<"("<<imin<<";"<<jmin<<")"<<endl;
    getch();
    return 0;
}
//---------------------------------------------------------------------------
