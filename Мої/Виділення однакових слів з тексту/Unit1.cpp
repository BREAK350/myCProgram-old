//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma argsused
FILE *fname;       
char s;

int main(int argc, char* argv[])
{
 FILE *fp;
 fp=fopen("1.txt","rt");
 TTreeItem *tree;
 char a[10000];
 tree=NULL;
 printf("input symbol ");
 scanf("%c",&s);
 while(fgets(a,10000,fp)!=NULL)
  {
   _CreateTree(tree,a);
  }
 fname=fopen("word.txt","wt");
 _FPrintTree(tree);
 _DestroyTree(tree);
 fclose(fname);
 printf("end\n");
 getch();
 return 0;
}
//---------------------------------------------------------------------------
