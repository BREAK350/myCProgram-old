//---------------------------------------------------------------------------
#ifndef T_Any_StackH
#define T_Any_StackH
#include <stdio.h>
//---------------------------------------------------------------------------
template < class Type >
class T_Any_Stack
{
    protected:
        int Size,Top;
        Type *Stack;
    public:
        T_Any_Stack();
        T_Any_Stack(const int &size);
        T_Any_Stack(const T_Any_Stack &as);
        ~T_Any_Stack();
        T_Any_Stack& operator = (const T_Any_Stack &as);
        int Write(const Type &t);
        int Read(Type &t);
};
//---------------------------------------------------------------------------
typedef T_Any_Stack < int > T_int_Stack;
typedef T_Any_Stack < char > T_char_Stack;
typedef T_Any_Stack < float > T_float_Stack;
typedef T_Any_Stack < double > T_double_Stack;
//---------------------------------------------------------------------------
template < class Type >
T_Any_Stack < Type >::T_Any_Stack():Stack(0)
{
    Size=0;
    Top=0;
}
//---------------------------------------------------------------------------
template < class Type >
T_Any_Stack < Type >::T_Any_Stack(const int &size)
{
    Size=(size>0)?(size):(0);
    if(Size>0)
    {
        Stack=new Type[Size];
    }
    Top=0;
}
//---------------------------------------------------------------------------
template < class Type >
T_Any_Stack < Type >::T_Any_Stack(const T_Any_Stack &as)
{
    Size=as.Size;
    Top=as.Top;
    if(Size>0)
    {
        int i;
        Stack=new Type[Size];
        for(i=0;i<Top;i++)
        {
            Stack[i]=as.Stack[i];
        }
    }
    else
    {
        Stack=NULL;
    }
}
//---------------------------------------------------------------------------
template < class Type >
T_Any_Stack < Type >::~T_Any_Stack()
{
    delete[] Stack;
    Stack=NULL;
    Size=Top=0;
}
//---------------------------------------------------------------------------
template < class Type >
T_Any_Stack < Type >& T_Any_Stack < Type >::operator = (const T_Any_Stack &as)
{
    if(this!=&as)
    {
        delete[] Stack;
        Size=as.Size;
        Top=as.Top;
        if(Size>0)
        {
            int i;
            Stack=new Type[Size];
            for(i=0;i<Top;i++)
            {
                Stack[i]=as.Stack[i];
            }
        }
        else
        {
            Stack=NULL;
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
template < class Type >
int T_Any_Stack < Type >::Write(const Type &t)
{
    int q=0;
    if(Top<Size)
    {
        Stack[Top]=t;
        Top++;
        q=1;
    }
    return q;
}
//---------------------------------------------------------------------------
template < class Type >
int T_Any_Stack < Type >::Read(Type &t)
{
    int q=0;
    if(Top>0)
    {
        Top--;
        t=Stack[Top];
        q=1;
    }
    return q;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif

