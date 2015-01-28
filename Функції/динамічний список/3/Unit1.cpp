//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "Unit2.h"
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    TListItem L,R;
    //L.Init(5);
    L.Add(3,1,2,3);
    L.print();cout<<endl;
    R=L.Copy();
    R.print();cout<<endl;
    L.Del();
    R.Input();
    R.print();
    system("Pause");
    return 0;
}
//---------------------------------------------------------------------------
 