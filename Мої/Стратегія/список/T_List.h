//---------------------------------------------------------------------------
#ifndef T_ListH
#define T_ListH
#include "T_Any_Object.h"
//---------------------------------------------------------------------------
struct T_ListItem;
typedef T_ListItem* pT_ListItem;
//---------------------------------------------------------------------------
struct T_ListItem
{
    T_Any_Object *Object;
    T_ListItem *Next;
};
//---------------------------------------------------------------------------
class T_LIST;
//---------------------------------------------------------------------------
class T_List
{
    protected:
        T_ListItem *First;
        T_Simile Simile;
        void Delete(T_ListItem *&);
        void DeleteItem(T_ListItem *&);
    public:
        T_List();
        T_List(const T_List &);
        void Add(T_Any_Object *);
        void Delete();
        void SetSimile(T_Simile s){Simile=s;}
        void Draw(TCanvas *,float,float);
        friend T_LIST;
};
//---------------------------------------------------------------------------
struct T_List_Item
{
    T_List *List;
    T_List_Item *Next;
    T_List_Item();
};
//---------------------------------------------------------------------------
class T_LIST
{
    protected:
        T_List_Item *First;
        T_Simile SimileX,SimileY;
        void Delete(T_ListItem *&);
        void DeleteItem(T_ListItem *&);
    public:
        T_LIST();
        void Add(T_Any_Object *);
        void Delete();
        void SetSimile(T_Simile s1,T_Simile s2){SimileX=s1;SimileY=s2;}
        void Draw(TCanvas *,float,float);
};
//---------------------------------------------------------------------------
#endif
