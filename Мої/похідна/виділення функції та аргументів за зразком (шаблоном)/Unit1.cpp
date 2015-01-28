//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma argsused
#include <stdio.h>
#include <conio.h>
#include "SFWPHF.h"
#include <string.h>
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    int i,n;
    AnsiString a,
               p;
    a="sin(x)-(3+sin(tg(3)))*(6-5)+6";
    p+=ARG;
    p+=MA;
    char *_func=NULL,**_arg=NULL,*next;
    printf("a=        %s\npattern= %s\n",a.c_str(),p.c_str());
    printf("\nResult:\n\n");

    next=SFWP(a.c_str(),p.c_str(),_func,_arg,n);

    printf("func=     %s\n",_func);
    for(i=0;i<n;i++)
    {
        printf("arg[%d]=   %s\n",i,_arg[i]);
    }
    printf("next=     %s\n",next);
    getch();
    return 0;
}
//---------------------------------------------------------------------------


