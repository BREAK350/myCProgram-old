//---------------------------------------------------------------------------
#ifndef T_TreeH
#define T_TreeH
#include <stdio.h>
//---------------------------------------------------------------------------
typedef int (*Tree_Compare)(const void *,const void *);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
template <class Type, int Amount>
class T_Tree
{
    private:
        Type Data;
        T_Tree *Pointer[Amount];
        static Tree_Compare Compare;
        void Delete();
    public:
        T_Tree(const Type &);
        ~T_Tree();
        void Add(const Type &);
        void SetCompare(const Tree_Compare &c) { Compare=c; }
};
//---------------------------------------------------------------------------
template <class Type, int Amount>
Tree_Compare T_Tree<Type,Amount>::Compare=NULL;
//---------------------------------------------------------------------------
template <class Type, int Amount>
T_Tree<Type,Amount>::T_Tree(const Type &d)
{
    int i;
    for(i=0;i<Amount;i++)
    {
        Pointer[i]=NULL;
    }
    Data=d;
}
//---------------------------------------------------------------------------
template <class Type, int Amount>
void T_Tree<Type,Amount>::Add(const Type &add)
{
    int n=Compare(&add,&Data);
    if(Pointer[n])
    {
        Pointer[n]->Add(add);
    }
    else
    {
        Pointer[n]=new T_Tree<Type,Amount>(add);
    }
}
//---------------------------------------------------------------------------
template <class Type, int Amount>
T_Tree<Type,Amount>::~T_Tree()
{
    int i;
    this->Delete();
}
//---------------------------------------------------------------------------
template <class Type, int Amount>
void T_Tree<Type,Amount>::Delete()
{
    int i;
    for(i=0;i<Amount;i++)
    {
        if(Pointer[i])
        {
            Pointer[i]->Delete();
            delete Pointer[i];
            Pointer[i]=NULL;
        }
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
