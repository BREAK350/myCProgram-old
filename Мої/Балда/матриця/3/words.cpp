//---------------------------------------------------------------------------
#pragma hdrstop
#include "words.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void T_Words::Delete(T_Item *&item)
{
    if(item)
    {
        Delete(item->Next);
        delete item;
        item=NULL;
    }
}
//---------------------------------------------------------------------------
int T_Words::GetCurrWord(string &word)
{
    int q=0;
    if(Curr)
    {
        word=Curr->Word;
        Curr=Curr->Next;
        q=1;
    }
    return q;
}
//---------------------------------------------------------------------------
int T_Words::Write(const char *w)
{
    int q=0;
    if(First)
    {
        if(Search(w)==0)
        {
            Last->Next=new T_Item(w);
            Last=Last->Next;
        }
    }
    else
    {
        First=new T_Item(w);
        Last=First;
        q=1;
    }
    return q;
}
//---------------------------------------------------------------------------
int T_Words::Search(const char *w)
{
    int q=0;
    T_Item *t=First;
    while(t && t->Word!=w)
    {
        t=t->Next;
    }
    if(t)
    {
        q=1;
    }
    return q;
}
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
 