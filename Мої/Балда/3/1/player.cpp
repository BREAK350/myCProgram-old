//---------------------------------------------------------------------------
#pragma hdrstop
#include "player.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void T_Player::SearchWord_NextSymbol(T_Field &field,const char *word,const int &i,
            const int &x,const int &y,int &q)
{
    if(q==0)
    {
        if(word[i]==0)
        {
            q=1;
        }
        else
        {
            if(Stack.Search(x,y)==0)
            {
                if(word[i]==field.Search(x,y))
                {
                    Stack.Write(x,y);
                    SearchWord_NextSymbol(field,word,i+1,x+1,y  ,q);
                    SearchWord_NextSymbol(field,word,i+1,x  ,y+1,q);
                    SearchWord_NextSymbol(field,word,i+1,x-1,y  ,q);
                    SearchWord_NextSymbol(field,word,i+1,x  ,y-1,q);
                    if(q==0)
                    {
                        Stack.Read(TPoint(0,0));
                    }
                }
            }
        }
    }
}
//---------------------------------------------------------------------------
int T_Player::SearchWord(T_Field &field,const char *word,const int &x,const int &y)
{                          // x,y - координати на межі
    int q=0;
    SearchWord_NextSymbol(field,word,1,x+1,y,q);
    SearchWord_NextSymbol(field,word,1,x,y+1,q);
    SearchWord_NextSymbol(field,word,1,x-1,y,q);
    SearchWord_NextSymbol(field,word,1,x,y-1,q);
    if(q==0)
    {
        char *buf=strdup(word);
        DoBack(buf);
        SearchWord_NextSymbol(field,buf,1,x+1,y,q);
        SearchWord_NextSymbol(field,buf,1,x,y+1,q);
        SearchWord_NextSymbol(field,buf,1,x-1,y,q);
        SearchWord_NextSymbol(field,buf,1,x,y-1,q);
        delete[] buf;
        if(q==1)
        {
            q=-1;
        }
    }
    return q;
}
//---------------------------------------------------------------------------
void DoBack(char *w)
{
    if(w)
    {
        int i,n=strlen(w);
        char c;
        for(i=0;i<n/2;i++)
        {
            c=w[i];
            w[i]=w[n-i-1];
            w[n-i-1]=c;
        }
    }
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
