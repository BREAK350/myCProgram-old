//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void ChangeSymbol(TbListItem *Item,int &Length,const int &MaxLength) // Item!=NULL && Prev!=NULL && Next!=NULL
{
    int k=0;
    TbListItem *p=NULL;
    if(Item->Symbol=='S')
    {
        k=random(2);
        if(Length>MaxLength)
        {
            k=1;
        }
        if(k==0)
        {
            Item->Symbol='|';
            p=new TbListItem('A',Item,Item->Prev);
            Item->Prev->Next=p;
            Item->Prev=p;
            p=new TbListItem('A',Item->Next,Item);
            Item->Next->Prev=p;
            Item->Next=p;
            ChangeSymbol(Item->Prev,Length+2,MaxLength);
            ChangeSymbol(Item->Next,Length+2,MaxLength);
        }
        else
        if(k==1)
        {
            Item->Symbol='A';
            ChangeSymbol(Item,Length,MaxLength);
        }
    }
    else
    if(Item->Symbol=='A')
    {
        k=random(3);
        if(Length>MaxLength)
        {
            k=2;
        }
        if(k==0)
        {
            Item->Symbol='S';
            p=new TbListItem('(',Item,Item->Prev);
            Item->Prev->Next=p;
            Item->Prev=p;
            p=new TbListItem(')',Item->Next,Item);
            Item->Next->Prev=p;
            Item->Next=p;
            p=new TbListItem('*',Item->Next->Next,Item->Next);
            Item->Next->Next->Prev=p;
            Item->Next->Next=p;
            ChangeSymbol(Item,Length+3,MaxLength);
        }
        else
        if(k==1)
        {
            Item->Symbol='S';
            p=new TbListItem('a',Item,Item->Prev);
            Item->Prev->Next=p;
            Item->Prev=p;
            ChangeSymbol(Item,Length+1,MaxLength);
        }
        else
        if(k==2)
        {
            Item->Symbol='a';
            delete p;
        }
    }
}
//---------------------------------------------------------------------------
void ChangeSymbol(TbListItem *Item,int &Length,const int &MaxLength,const int &Prevk) // Item!=NULL && Prev!=NULL && Next!=NULL
{
    int k=4;
    TbListItem *p=NULL;
    if(Length<=MaxLength)
    {
        do
        {
            k=random(5);
        }
        while(k==Prevk);
    }
    if(k==0)  // S->S|S
    {
        Item->Symbol='|';
        p=new TbListItem('S',Item,Item->Prev);
        Item->Prev->Next=p;
        Item->Prev=p;
        p=new TbListItem('S',Item->Next,Item);
        Item->Next->Prev=p;
        Item->Next=p;
        Length+=2;
        ChangeSymbol(Item->Prev,Length,MaxLength,-1);
        ChangeSymbol(p,Length,MaxLength,-1);
    }
    else
    if(k==1)  // S->SS
    {
        p=new TbListItem('S',Item->Next,Item);
        Item->Next->Prev=p;
        Item->Next=p;
        Length+=1;
        ChangeSymbol(Item,Length,MaxLength,-1);
        ChangeSymbol(p,Length,MaxLength,-1);
    }
    else
    if(k==2)  // S->(S)
    {
        p=new TbListItem('(',Item,Item->Prev);
        Item->Prev->Next=p;
        Item->Prev=p;
        p=new TbListItem(')',Item->Next,Item);
        Item->Next->Prev=p;
        Item->Next=p;
        Length+=2;
        ChangeSymbol(Item,Length,MaxLength,Prevk);
    }
    else
    if(k==3)  // S->S*
    {
        p=new TbListItem('*',Item->Next,Item);
        Item->Next->Prev=p;
        Item->Next=p;
        Length+=1;
        ChangeSymbol(Item,Length,MaxLength,Prevk);
    }
    else
    if(k==4)  // S->a
    {
        Item->Symbol='a';
    }
}
//---------------------------------------------------------------------------
char* CreateRandom(const int &MaxLength)
{
    int i=0,Length=1;
    char *res=NULL;
    TbListItem *First=new TbListItem('['),*p=NULL;
    First->Next=new TbListItem('S',NULL,First);
    First->Next->Next=new TbListItem(']',NULL,First->Next);

    ChangeSymbol(First->Next,Length,MaxLength);

    p=First->Next;
    while(p->Symbol!=']')
    {
        i++;
        p=p->Next;
    }
    res=new char [i+1];
    p=First->Next;
    i=0;
    while(p->Symbol!=']')
    {
        res[i]=p->Symbol;
        i++;
        delete p->Prev;
        p=p->Next;
    }
    delete p->Next;
    delete p;
    res[i]=0;
    return res;
}
//---------------------------------------------------------------------------
void ChangeSymbol(char *Expression,const char *Symbols)
{
    int i=0,n=strlen(Symbols);
    int Count=2+random(2);
    char s[3];
    s[0]=Symbols[random(n)];
    do
    {
        s[1]=Symbols[random(n)];
    }
    while(s[0]==s[1]);
    do
    {
        s[2]=Symbols[random(n)];
    }
    while(s[2]==s[1] || s[2]==s[0]);
    while(Expression[i])
    {
        if(Expression[i]=='a')
        {
            Expression[i]=s[random(Count)];
        }
        i++;
    }
}
//---------------------------------------------------------------------------
bool isGood(const char *Expression)
{
    int i=0,a=0,it=0;
    while(Expression[i] && (a==0 || it==0))
    {
        if(Expression[i]=='|')
        {
            a=1;
        }
        if(Expression[i]=='*')
        {
            it=1;
        }
        i++;
    }
    return a*it;
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 