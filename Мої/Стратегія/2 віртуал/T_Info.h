//---------------------------------------------------------------------------
#ifndef T_InfoH
#define T_InfoH
#include <stdio.h>
//---------------------------------------------------------------------------
struct T_Info
{
    int N;
    char **Text;
    T_Info(){N=0;Text=NULL;}
    ~T_Info();
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 