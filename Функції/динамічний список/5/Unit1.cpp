//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "Unit2.h"
//---------------------------------------------------------------------------
void p()
{
    TList L,R;
    int l[]={1,1,1},
        r[]={5};
    L.Init(3,l);
    R.Init(1,r);
    R=L.ChangeXToXPlusA(-2);
    R.Display();
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    while(1)
    {
        p();
    }
    return 0;
}
//---------------------------------------------------------------------------
 