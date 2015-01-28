//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
extern FILE *fname;
extern char s;
//---------------------------------------------------------------------------
void _InsertItem(TTreeItem*&tree,TTreeItem*t)
{
 if(tree)
  {
   if(strcmp(tree->word,t->word)>0)
     _InsertItem(tree->left,t);
   else
     _InsertItem(tree->right,t);
  }
 else
   tree=t;
}
//---------------------------------------------------------------------------
void _InsertItem(TTreeItem*&tree,char*&a)
{
 if(!a)
   return;
 if(tree)
  {
   if(strcmp(tree->word,a)>0)
     _InsertItem(tree->left,a);
   else
     _InsertItem(tree->right,a);
  }
 else
  {
   tree=(TTreeItem*)malloc(sizeof(TTreeItem));
   tree->right=tree->left=NULL;
   tree->word=(char*)malloc(strlen(a)*sizeof(char));
   strcpy(tree->word,a);
   free(a);
   a=NULL;
  }
}
//---------------------------------------------------------------------------
void _InsertItemWithoutRepetitions(TTreeItem*&tree,char*&a)
{
 if(!a)
   return;
 if(tree)
  {
   if(strcmp(tree->word,a)>0)
     _InsertItemWithoutRepetitions(tree->left,a);
   else
     if(strcmp(tree->word,a)<0)
       _InsertItemWithoutRepetitions(tree->right,a);
  }
 else
  {
   tree=(TTreeItem*)malloc(sizeof(TTreeItem));
   tree->right=tree->left=NULL;
   tree->word=(char*)malloc(strlen(a)*sizeof(char));
   strcpy(tree->word,a);
   free(a);
   a=NULL;
  }
}
//---------------------------------------------------------------------------
TTreeItem* _CreateNewItem()
{
 TTreeItem *t;
 t=(TTreeItem*)malloc(sizeof(TTreeItem));
 t->word=NULL;
 t->right=NULL;
 t->left=NULL;
 return t;
}
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
void _AwardingItem(TTreeItem*&t,char*a,int l,int r)
{
 int i;
 if(l>=r)
   return;
 t->word=(char*)malloc((r-l)*sizeof(char));
 for(i=l;i<r;i++)
   t->word[i-l]=a[i];
 t->word[i-l]='\0';
}
//---------------------------------------------------------------------------
char* _SeparateWord(char*a,int l,int r)
{
 int i;
 char*b;
 b=NULL;
 if(l>=r)
   return NULL;
 b=(char*)malloc((r-l)*sizeof(char));
 for(i=l;i<r;i++)
   b[i-l]=a[i];
 b[i-l]='\0';
 return b;
}
//---------------------------------------------------------------------------
void _PrintItem(TTreeItem*t)
{
 printf("%s\n",t->word);
}
//---------------------------------------------------------------------------
void _FPrintItem(TTreeItem*t)
{
 fprintf(fname,"%s\n",t->word);
}
//---------------------------------------------------------------------------
void _PrintTree(TTreeItem*tree)
{
 if(tree)
  {
   _PrintTree(tree->left);
   PrintItem(tree);
   _PrintTree(tree->right);
  }
}
void _FPrintTree(TTreeItem*tree)
{
 if(tree)
  {
   _FPrintTree(tree->left);
   _FPrintItem(tree);
   _FPrintTree(tree->right);
  }
}
//---------------------------------------------------------------------------
CTreeItem::CTreeItem()
{
 word=NULL;
 right=left=NULL;
}
//---------------------------------------------------------------------------
CTreeItem::~CTreeItem()
{
 free(word);
 right=left=NULL;
}
//---------------------------------------------------------------------------
void _CreateTree(TTreeItem*&tree,char*a)
{
 int i,l;
 i=0;
 while(a[i])
  {
   while((a[i])&&(Rozd(a[i])==1))
     i++;
   l=i;
   while((a[i])&&(Rozd(a[i])==0))
     i++;
   if((a[l]==s)||(s==' '))
     _InsertItemWithoutRepetitions(tree,_SeparateWord(a,l,i));
  }
}
//---------------------------------------------------------------------------
int Rozd(char a)
{
 if((a==' ')||(a==',')||(a=='.')||(a=='!')||(a=='?')||(a=='\t'))
   return 1;
 if((a==';')||(a==':')||(a=='\n'))
   return 1;
 return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
