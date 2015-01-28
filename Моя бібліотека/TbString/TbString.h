//---------------------------------------------------------------------------
#ifndef TbStringH
#define TbStringH
#include <iostream.h>
#include <fstream.h>
//---------------------------------------------------------------------------
class TbBaseString
{
    private:
        int length;
        char *row;
    protected:
        char* SearchPlace(const char *row)const;
    public:
        TbBaseString() { length=0; row=NULL; }
        TbBaseString(const char *row);
        TbBaseString(const TbBaseString &BaseString);
        ~TbBaseString();

        TbBaseString& operator = (const TbBaseString &BaseString);
        bool operator == (const TbBaseString &BaseString)const;
        bool operator < (const TbBaseString &BaseString)const;
        bool operator > (const TbBaseString &BaseString)const;
        bool Search(const TbBaseString &BaseString)const;
        bool Search(const char *row)const;
        const char* ToChar()const { return row; } 
        int Length()const { return length; }
        int SizeByte()const { return length*sizeof(char)+sizeof(int); }
        void LoadFromFile(FILE *File);
        void SaveToFile(FILE *File)const;
        void Union(const TbBaseString &BaseString);
        void Union(const char *row);
        TbBaseString SeparateBegin(const TbBaseString &Separator); //відокремити з початку
};
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
//---------------------------------------------------------------------------
#endif
