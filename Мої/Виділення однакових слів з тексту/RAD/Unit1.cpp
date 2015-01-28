//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma argsused
FILE *fname,*fp;
char s,w[20];
TTreeItem *tree;

int main(int argc, char* argv[])
{
    printf("input file name, that to load: ");
    gets(w);
    fp=fopen(w,"rt");
    if(fp==NULL)
    {
        printf("Error:not find file %s\n",w);
        getch();
        return 0;
    }
    tree=NULL;
    printf("input symbol ");
    scanf("%c",&s);
    printf("wait...\n");
	int n = Search();
	printf("All words %d\n",n);
    fclose(fp);
    printf("Tree is made\ninput file name that to save tree: ");
    gets(w);
    fname=fopen(w,"wt");
    if(fname==NULL)
    {
        printf("Error:not find file %s\n",w);
        getch();
        return 0;
	}
	fprintf(fname,"/*All words %d*/\n",n);
    _FPrintTree(tree);
    _DestroyTree(tree);
    fclose(fname);
    printf("end\n");
    getch();
    return 0;
}
//---------------------------------------------------------------------------
