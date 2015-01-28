//---------------------------------------------------------------------------
#ifndef Unit3H
#define Unit3H
#include <iostream.h>
#include <fstream.h>
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
class T_Dictionary
{
    private:
        int N;
        char **W;
    protected:
        int SearchPathWord(const int &row,const char *pw)const;
    public:
        T_Used Used;
    public:
        T_Dictionary();
        T_Dictionary(const T_Dictionary &d);
        ~T_Dictionary();
        T_Dictionary(const char *fname);
        int SearchPathWord(const char *pw)const;
        char* operator [] (const int &n);
        int GetN()const { return N; }
        int LoadFromFile(const char *fname);
        void Delete();
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
