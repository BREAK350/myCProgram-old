//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "T_List.h"
//---------------------------------------------------------------------------
bool f(const void *a,const void *b)
{
    return *(int *)a==*(int *)b;
}
//---------------------------------------------------------------------------
void z()
{
    int *b=NULL;
    gT_List <int> List(f);
    List.Add(4);
    b=List.GetItem(0);
    *b=2;
    b=0;
    b=List.GetItem(0);
}
//---------------------------------------------------------------------------
struct tt
{
    float x,y;
};
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    gT_List < gT_List <int> > List(f);
    while(1) z();
    void *a;
    tt *b;
    b=(tt *)a;
    b->x;
    a=b;
    return 0;
}
//---------------------------------------------------------------------------
