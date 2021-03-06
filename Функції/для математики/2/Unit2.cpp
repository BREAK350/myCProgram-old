//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TElement::TElement()
{
    x=y=0;
    func=NULL;
    xe=ye=NULL;
}
//---------------------------------------------------------------------------
TElement::~TElement()
{
    delete xe;
    delete ye;
}
//---------------------------------------------------------------------------
void TElement::SetFunc(_func_ f)
{
    func=f;
}
//---------------------------------------------------------------------------
float TElement::Return()
{
    float _x,_y;
    if(xe)
    {
        _x=xe->Return();
    }
    else
    {
        _x=x;
    }
    if(ye)
    {
        _y=ye->Return();
    }
    else
    {
        _y=y;
    }
    return (func)?(func(_x,_y)):(x);
}
//---------------------------------------------------------------------------
void TElement::SetX(float _x)
{
    x=_x;
}
//---------------------------------------------------------------------------
void TElement::SetY(float _y)
{
    y=_y;
}
//---------------------------------------------------------------------------
void TElement::SetXE(TElement *_xe)
{
    xe=_xe;
}
//---------------------------------------------------------------------------
void TElement::SetYE(TElement *_ye)
{
    ye=_ye;
}
//---------------------------------------------------------------------------
void TElement::Create(char *s,int l,int r)
{
    int d;
    d=_SearchLevel_(s,l,r);
    if(d==-1)
    {
        switch(_FUNCS_::WhatIsIt(s,l,r,x,func))
        {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                Create(s,l,r);
                break;
            case 4:
                xe=new TElement;
                xe->Create(s,l,r);
                break;
        }
    }
    else
    {
        if(!isNumber(s,l,d,x))
        {
            xe=new TElement;
            xe->Create(s,l,d);
        }
        if(!isNumber(s,d+1,r,y))
        {
            ye=new TElement;
            ye->Create(s,d+1,r);
        }
        switch(s[d])
        {
            case '+':func=_add_;break;
            case '-':func=_sub_;break;
            case '*':func=_mult_;break;
            case '/':func=_div_;break;
            case '^':func=_pow_;break;
        }
    }
}
//---------------------------------------------------------------------------
void TElement::Create(char *s)
{
    Create(s,0,strlen(s));
}
//---------------------------------------------------------------------------
char* ChooseFunction(_func_ func)
{
    if(func==_sin_)  return "sin";
    if(func==_cos_)  return "cos";
    return "";
}
//---------------------------------------------------------------------------
char* ChooseOperatcia(_func_ func)
{
    if(func==_add_)  return "+";
    if(func==_sub_)  return "-";
    if(func==_mult_) return "*";
    if(func==_div_)  return "/";
    if(func==_pow_)  return "^";
    return "";
}
//---------------------------------------------------------------------------
void TElement::Print()
{
    char *f;
   // f=ChooseFunction(func);
    f=_FUNCS_::GetNameFunc(func);
    cout<<f<<'(';
    if(xe)
    {
        xe->Print();
    }
    else
    {
        cout<<x;

    }
    cout<<')';
    if(!*f)
    {
        f=ChooseOperatcia(func);
        cout<<f;
        cout<<'(';
        if(ye)
        {
            ye->Print();
        }
        else
        {
            cout<<y;
        }
        cout<<')';
    }
}
//---------------------------------------------------------------------------
void TElement::DoNegativeY()
{
    y=-y;
    if(ye)
    {
        ye->DoNegativeY();
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 