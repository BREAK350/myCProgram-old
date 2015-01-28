//---------------------------------------------------------------------------
#ifndef __func__H
#define __func__H
#include <math.h>
#include <string.h>
#include <vcl.h>
#include <iostream.h>
typedef float (*_func_)(float,float);
//---------------------------------------------------------------------------
float _sin_(float,float);
float _cos_(float,float);
float _add_(float,float);
float _sub_(float,float);
float _mult_(float,float);
float _div_(float,float);
float _pow_(float,float);
float _brk_(float,float);
//---------------------------------------------------------------------------
class _FUNC_
{
    private:
        char *Name;
        _func_ func;
    public:
        _FUNC_();
        _FUNC_(char *,_func_);
        char* GetName()   {return Name;}
        _func_ GetFunc()  {return func;}
        ~_FUNC_();
};
//---------------------------------------------------------------------------
class _FUNCS_
{
    private:
        static _FUNC_ F[];
        static int N;
    public:
        static char* GetNameFunc(_func_);
        static _func_ GetFunc(char *,int &,int &);
        static int WhatIsIt(char *,int &,int &,float &,_func_ &);
};
                        int _FUNCS_::N=2;
_FUNC_ _FUNCS_::F[]={
                    _FUNC_("sin",_sin_),
                    _FUNC_("cos",_cos_)
                    };
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
