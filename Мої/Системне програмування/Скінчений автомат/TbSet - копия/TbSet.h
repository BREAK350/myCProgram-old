//---------------------------------------------------------------------------
#ifndef TbSetH
#define TbSetH
#include <iostream.h>
//---------------------------------------------------------------------------
class TbSet // множина значень (станів), відсортована множина
{
    private:
        int *Elements,Count;
    public:
        TbSet();
        TbSet(const TbSet &Set);
        ~TbSet();
        TbSet& operator = (const TbSet &Set);
        TbSet operator + (const int &Element)const;
        TbSet operator + (const TbSet &Set)const;
        bool operator == (const TbSet &Set)const;
        bool operator != (const TbSet &Set)const;
        void Add(const int &Element);
        void Add(const TbSet &Set);
        const int* GetElements()const;
        int GetCount()const;
        int GetIndex(const int &Element)const;
        bool Search(const int &Element)const;
        bool isEmpty()const;
        int GetCommon(const TbSet &Set)const;
        void Clear();
        void Shift(const int &ShiftTo);
        void Print()const;
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
