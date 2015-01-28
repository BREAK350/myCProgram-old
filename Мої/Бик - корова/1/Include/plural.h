//---------------------------------------------------------------------------
#ifndef pluralH
#define pluralH
#include <iostream.h>
#include "TbList2.h"
//---------------------------------------------------------------------------
struct TbResult
{
    int Cow,Bull;
    TbResult() { Cow=Bull=0; }
    operator int () { return Cow+Bull; }
    void Print()const { cout<<"Cow="<<Cow<<" Bull="<<Bull; }
    void Println()const { Print(); cout<<endl; }
};
//---------------------------------------------------------------------------
class TbPlural10
{
    private:
        char Element[10];
        int Count;
    protected:
        bool Search(const char &el)const;
    public:
        TbPlural10();
        TbPlural10(const char *Element);

        TbResult Equal(const TbPlural10 &Pl)const;
        int GetCount()const { return Count; }

        TbPlural10 operator + (const TbPlural10 &Pl)const;
        TbPlural10 operator - (const TbPlural10 &Pl)const;
        TbPlural10 operator * (const TbPlural10 &Pl)const;
        TbPlural10 Take_4();
};
//---------------------------------------------------------------------------
struct TbPluralResult
{
    TbPlural10 Plural;
    TbResult Result; 
};
//---------------------------------------------------------------------------
struct TbNumber
{
    int Digit[4];
};
//---------------------------------------------------------------------------
struct TbProgress
{
    TbNumber Number;
    int Cow,Bull;
    TbProgress();
    int SearchNumber(const int &num)const;
    void Init(const int &num0,const int &num1,const int &num2,const int &num3);
    int CommonNumbers(const TbProgress &Prog)const;
    void Check(const TbNumber &num);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
