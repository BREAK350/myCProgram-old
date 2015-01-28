//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <iostream.h>
#include <fstream.h>
//---------------------------------------------------------------------------
class T_List
{
    private:
        struct T_ListItem
        {
            char *Word;
            T_ListItem *Next;
            T_ListItem();
            T_ListItem(const char *w);
            ~T_ListItem();
            int operator == (const T_ListItem &li);
        } *First;
        void Delete(T_ListItem *&li);
    public:
        T_List() { First=NULL; }
        int Add(const char *w);
        void Delete() { Delete(First); }
        ~T_List() { Delete(); }
        void SaveToFile(FILE *f);
};
//---------------------------------------------------------------------------
class T_Words
{
    private:
        int MaxSize,N;
        T_List *Row;
    public:
        T_Words();
        T_Words(const int &ms);
        ~T_Words();
        int Add(const char *w);
        void LoadFromFile(const char *fname);
        void SetSize(const int &ms);
        void SaveToFile(const char *fname);
        int GetN() { return N; }
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 