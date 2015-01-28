//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <string.h>
#include <stdlib.h>
//---------------------------------------------------------------------------
struct TbListItem
{
    char Symbol;
    TbListItem *Next,*Prev;
    TbListItem(const char &Symbol)
    {
        this->Symbol=Symbol;
        Next=Prev=NULL;
    }
    TbListItem(const char &Symbol,TbListItem *Next,TbListItem *Prev)
    {
        this->Symbol=Symbol;
        this->Next=Next;
        this->Prev=Prev;
    }
};
//---------------------------------------------------------------------------
char* CreateRandom(const int &MaxLength);
void ChangeSymbol(TbListItem *Item,int &Length,const int &MaxLength);
void ChangeSymbol(TbListItem *Item,int &Length,const int &MaxLength,const int &Prevk);
void ChangeSymbol(char *Expression,const char *Symbols);
bool isGood(const char *Expression);
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
 