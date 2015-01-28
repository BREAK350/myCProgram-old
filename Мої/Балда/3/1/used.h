//---------------------------------------------------------------------------
#ifndef usedH
#define usedH
#include <stdio.h>
//---------------------------------------------------------------------------
class T_Used
{
    private:
        struct T_ListItem
        {
            int Data;
            T_ListItem *Next;
            T_ListItem() { Data=0; Next=NULL; }
            T_ListItem(const T_ListItem &li) { Data=li.Data; Next=NULL; }
            T_ListItem(const int &d) { Data=d; Next=NULL; }
        } *First;
    protected:
        void Delete(T_ListItem *&Item);
    public:
        T_Used() { First=NULL; }
        T_Used(const T_Used &u);
        ~T_Used() { Delete(First); }
        int Add(const int &data);
        int Search(const int &data)const;
        void Delete() { Delete(First); }
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
