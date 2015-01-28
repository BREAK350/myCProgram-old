//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include "T_List2.h"
//---------------------------------------------------------------------------
template <class Type,class _Add>
class T_List2Add
{
    public:
        T_List2 <Type> List;
        _Add Add;
        T_List2Add():Add(0),List() {}
        T_List2Add(const _Add &add):Add(add),List() {}
        bool operator == (const T_List2Add &List2Add)
        {
            return Add==List2Add.Add;
        }
        bool operator != (const T_List2Add &List2Add)
        {
            return Add!=List2Add.Add;
        }
        bool operator <= (const T_List2Add &List2Add)
        {
            return Add<=List2Add.Add;
        }
        bool operator >= (const T_List2Add &List2Add)
        {
            return Add>=List2Add.Add;
        }
        bool operator < (const T_List2Add &List2Add)
        {
            return Add<List2Add.Add;
        }
        bool operator > (const T_List2Add &List2Add)
        {
            return Add>List2Add.Add;
        }
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 