//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
extern FILE *fname,*fp;
extern char s;
extern TTreeItem *tree;
char w[20];
int d,n=0,g;
//---------------------------------------------------------------------------
void _DestroyTree(TTreeItem*&t)
{
    if(t)
    {
        _DestroyTree(t->left);
        _DestroyTree(t->right);
        free(t->word);
        t->word=NULL;
        free(t);
        t=NULL;
    }
}
//---------------------------------------------------------------------------
void _FPrintTree(TTreeItem*tree)
{
    if(tree)
    {
        _FPrintTree(tree->left);
         fprintf(fname,"%s\n",tree->word);
        _FPrintTree(tree->right);
    }
}
//---------------------------------------------------------------------------
int Rozd(char a)
{
    if((a==' ')||(a==',')||(a=='.')||(a=='!')||(a=='?')||(a=='\t')||(a=='\''))
    {
        return 1;
    }
    if((a==';')||(a==':')||(a=='\n')||(a=='(')||(a==')')||(a=='"')||(a=='_'))
    {
        return 1;
    }
    return 0;
}
//---------------------------------------------------------------------------
void Search()
{
    while(fscanf(fp,"%s",w)==1)
    {
        d=strlen(w);
        TrueWord();
        strlwr(w);
        if(d>0)
        _InsertItemWithoutRepetitions(tree);
    }
    printf("All words %d\n",n);
}
//---------------------------------------------------------------------------
void _InsertItemWithoutRepetitions(TTreeItem*&t)
{
    if(t)
    {
        g=strcmp(t->word,w);
        if(g>0)
        {
            _InsertItemWithoutRepetitions(t->left);
        }
        else
        {
            if(g<0)
            {
                _InsertItemWithoutRepetitions(t->right);
            }
        }
    }
    else
    {
        t=(TTreeItem*)malloc(sizeof(TTreeItem));
        t->right=NULL;
        t->left=NULL;
        t->word=strdup(w);
        n++;
    }
}
//---------------------------------------------------------------------------
void TrueWord()
{
    int i;
    i=0;
    while((w[i])&&(Rozd(w[i])==1))
    {
        i++;
    }
    strcpy(w,&w[i]);
    while((w[i])&&(Rozd(w[i])==0))
    {
        i++;
    }
    w[i]='\0';
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
