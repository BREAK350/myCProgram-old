//---------------------------------------------------------------------------
#ifndef Unit3H
#define Unit3H
#include <string.h>
//---------------------------------------------------------------------------
class TbPlural_char
{
    private:
        char *Item;
        int Count;
    private:
        void Init(const char *Item); // Item!=NULL
        void Nullify();
        void Delete();
        void New(const int &Count); // Count>0
    protected:
        int GetItemPos(const char &Item)const;
        bool SearchItem(const char &Item)const;
        //int GetCommonItem
    public:
        TbPlural_char() { Nullify(); }
        TbPlural_char(const char *Item); // в Item знаходяться різні елементи
        TbPlural_char(const char &Count);
        TbPlural_char(const TbPlural_char &Pl);
        ~TbPlural_char();
    public:
        TbPlural_char& operator = (const TbPlural_char &Pl);
        TbPlural_char Union(const TbPlural_char &Pl)const;
        TbPlural_char Cross(const TbPlural_char &Pl)const;
        TbPlural_char Sub(const TbPlural_char &Pl)const;
        TbPlural_char operator + (const TbPlural_char &Pl)const { return Union(Pl); };
        TbPlural_char operator - (const TbPlural_char &Pl)const { return Sub(Pl); }
        TbPlural_char operator * (const TbPlural_char &Pl)const { return Cross(Pl); }
        TbPlural_char GetFirst(const int &Count)const;
        char& operator [] (const int &i)const { return Item[i]; }
        bool operator == (const TbPlural_char &Pl)const;
        bool operator != (const TbPlural_char &Pl)const;
        int GetCount()const { return Count; }
        char* GetStr()const;
        int GetCommonItem(const TbPlural_char &Pl)const;
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
 