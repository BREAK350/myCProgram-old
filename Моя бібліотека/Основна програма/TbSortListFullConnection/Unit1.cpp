//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbSortListFullConnection.h"
#pragma argsused
int Compare(const void *arg1,const void *arg2)
{
    return 1;
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    TbSLFC <int,float> Test1;
    Test1.List;
    TbSortList2 <int> sl(Compare);
    sl.Add(3);
    return 0;
}
//---------------------------------------------------------------------------
 