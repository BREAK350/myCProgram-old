//---------------------------------------------------------------------------
#ifndef T_ListH
#define T_ListH
#include "T_Any_Object.h"
//---------------------------------------------------------------------------
struct T_ListItem
{
    T_Any_Object *Object;
    T_ListItem *Next;
    T_ListItem(){Object=NULL;Next=NULL;}
    ~T_ListItem(){Object=NULL;Next=NULL;}
};
//---------------------------------------------------------------------------
class T_List
{
    protected:
        T_ListItem *First;
        void Delete(T_ListItem *&);
        void DeleteItem(T_ListItem *&);
        int N;
        T_Poligon **Picture;
    public:
        T_List();
        T_List(const T_List &);
        ~T_List();
        bool Add(T_Any_Object *);
        void Delete();
        void Draw(TCanvas *,T_Point,float,float);
        void AfterBang(T_Bang);
        bool isHere(T_Point);
        T_Any_Object* GetObject(T_Point);
        void Check();
        void NextStep();
        void SaveToFile(char *);
        void LoadFromFile(char *);
        int AddPicture(T_Poligon *,int);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
