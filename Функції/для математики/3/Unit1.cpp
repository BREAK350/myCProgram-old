//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "Operation.h"
#include <conio.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void p2()
{
    TOperand op;
    //TOperation d;
    op.Operation=new TOperation;
    op.Operation->Operands=new TOperand[2];
}
//---------------------------------------------------------------------------
void p1()
{
    char *s=NULL;
    float a;
    TOperand op;
    op.Operation=new TOperation;
    op.Operation->Name=strdup("add");
    op.Operation->N=2;
    op.Operation->Operands=new TOperand[2];
    op.Operation->Operands[0].Value=3;
    op.Operation->Operands[1].Value=6;
    op.Operation->Func=_add_;
    op.Return(s,a);
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    char **v=NULL,*s;
    float x[]={3,6},a;
    while(1)
    {
        p1();
        getch();
    }
    func f;
    f=_add_;
    //f(v,x,s,a);
    return 0;
}
//---------------------------------------------------------------------------
