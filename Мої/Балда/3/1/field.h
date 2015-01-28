//---------------------------------------------------------------------------
#ifndef fieldH
#define fieldH
#include <stdio.h>
#include <vcl.h>
//---------------------------------------------------------------------------
class T_Field
{
    protected:
        struct T_Field_Item
        {
            char Symbol;
            TPoint Location;
            T_Field_Item *Quarter[4];
            T_Field_Item(const char &s,const TPoint &l);
        } *Root;
        void Delete(T_Field_Item *&fi);
        void Draw(T_Field_Item *fi,TCanvas *Canvas,const TPoint &c,const int &s)const;
    public:
        T_Field();
        T_Field(const char *word);
        ~T_Field() { Delete(Root); Root=NULL; }
        int Add(const char &s,const TPoint &l);
        int Add(const char &s,const int &x,const int &y) { return Add(s,TPoint(x,y)); }
        char Search(const TPoint &l)const;
        char Search(const int &x,const int &y)const { return Search(TPoint(x,y)); }
        void Draw(TCanvas *Canvas,const TPoint &c,const int &s)const;
};
//---------------------------------------------------------------------------
int GetIndexQuarter(const TPoint &first,const TPoint &second); // first відносно second
int operator == (const TPoint &a,const TPoint &b);
int operator !=(const TPoint &a,const TPoint &b);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 