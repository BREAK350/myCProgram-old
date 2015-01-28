//---------------------------------------------------------------------------
#ifndef Unit6H
#define Unit6H
#include "Unit4.h"
//---------------------------------------------------------------------------
class TbBCPlural_char:public TbCPlural_char // Bull + Cow
{
    public:
        int Bull;
    public:
        TbBCPlural_char():TbCPlural_char() { Bull=0; }
        TbBCPlural_char(const char *Item):TbCPlural_char(Item) { Bull=0; }
        TbBCPlural_char(const char *Item,const int &Found,const int &Bull)
            :TbCPlural_char(Item,Found)
        {
            this->Bull=(Bull>=0 && Bull<=Found)?(Bull):(0);
        }
        TbBCPlural_char(const int &Count):TbCPlural_char(Count) { Bull=0; }
        TbBCPlural_char(const TbCPlural_char &BCPl)
            :TbCPlural_char(BCPl)
        {
            Bull=0;
        }
        TbBCPlural_char(const TbPlural_char &BCPl)
            :TbCPlural_char(BCPl)
        {
            Bull=0;
        }
        TbBCPlural_char& operator = (const TbBCPlural_char &BCPl)
        {
            if(this!=&BCPl)
            {
                TbCPlural_char::operator = (BCPl);
                Bull=BCPl.Bull;
            }
            return *this;
        }
        int GetBull()const { return Bull; }
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 