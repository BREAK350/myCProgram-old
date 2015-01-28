//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma argsused
#include "Unit2.h"
int main(int argc, char* argv[])
{
    TList L;
    int i;
    TListItem Li,f[4];
    L.Input();
    /*for(i=0;i<4;i++)
    {
        f[i].Input();
    }
    L.Init(3,f,&f[1],&f[2]); */
    L.print();
    system("Pause");
    return 0;
}
//---------------------------------------------------------------------------
