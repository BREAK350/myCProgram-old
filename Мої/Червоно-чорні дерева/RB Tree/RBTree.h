//---------------------------------------------------------------------------
#ifndef RBTreeH
#define RBTreeH
#include <stdio.h>
#include <conio.h>
//---------------------------------------------------------------------------
typedef COLORS TbTreeColor;
//---------------------------------------------------------------------------
template <class TbTreeData>
struct TbTreeItemBasis
{
    TbTreeData Data;
    TbTreeItemBasis *Left,*Right,*Parent;
    TbTreeColor Color;

    virtual int compareTo(const TbTreeData &Data){};
    virtual void print(){ cout<<"TbTreeItemBasis"<<endl; }

    TbTreeItemBasis(const TbTreeData &Data)
        :Data(Data)
    {
        this->Left=NULL;
        this->Right=NULL;
        this->Parent=NULL;
        this->Color=RED;
    }
    TbTreeItemBasis(const TbTreeData &Data,TbTreeItemBasis *Left,TbTreeItemBasis *Right,
    TbTreeItemBasis *Parent,const TbTreeColor &Color)
    {
        this->Data=Data;
        this->Left=Left;
        this->Right=Right;
        this->Parent=Parent;
        this->Color=Color;
    }
};
//---------------------------------------------------------------------------
template <class TbTreeData,class TbTreeItem>
class TbRBTree
{
    private:
        TbTreeItemBasis <TbTreeData> *Root;
    public:
        TbRBTree()
        {
            Root=NULL;
        }

        void Add(const TbTreeData &Data)
        {
            if(Root)
            {
                TbTreeItemBasis <TbTreeData> *t=Root;
                while(t->Right)
                {
                    t=t->Right;
                }
                if(t->compareTo(Data)==0)
                {
                    t->Right=new TbTreeItem(Data);
                }
            }
            else
            {
                Root=new TbTreeItem(Data);
            }
        }

        void print()
        {
            TbTreeItemBasis <TbTreeData> *t=Root;
            while(t)
            {
                t->print();
                t=t->Right;
            }
        }
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 