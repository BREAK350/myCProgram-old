//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void loadkom(FILE *tf,inf_kom *k,char *name)
{
 int g;
 inf_kom kl;
 tf=fopen("fkoms.txt","rt");
 if(tf!=NULL)
  do
  {
   g=fread(&kl,sizeof(inf_kom),1,tf);
  }
  while((strcmp(name,kl.name)!=0)&&(g!=0));
  if(g==1)
   *k=kl;
  else
   printf("not find!\n");
  fclose(tf);
}

void oform(inf_kom *k)
{
 int i;
 printf("Name  \"%s\"\nMoney  %d$\n",k->name,k->money);
 printf("Win %3d | Lost %3d | Draw %3d\n",k->win,k->lost,k->draw);
 printf("Players:\n");
 for(i=0;i<7;i++)
  printf(" %10s  A=%3d Z=%3d\n",k->fb[i].name,k->fb[i].A,k->fb[i].Z);
 getch();
}

void donewkom(inf_kom *k,FILE *tf)
{
 int i,is=1;
 char er[10];
 while(is==1)
 {
  clrscr();
  printf("Input name ");
  gets(k->name);
  k->win=0; k->lost=0; k->draw=0; k->money=1000;
  for(i=0;i<7;i++)
    {
     strcpy(k->fb[i].name,"no name");
     k->fb[i].A=0;
     k->fb[i].Z=0;
     k->fb[i].pos=0;
     k->fb[i].prise=0;
    }
  printf("input 1-to save or 0-not save ");
  scanf("%d",&is);
   if(is==1)
   {
    tf=fopen("fkoms.txt","at");
    fwrite(k,sizeof(inf_kom),1,tf);
    fclose(tf);
   }
  printf("input 1-to contin or 0-end ");
  scanf("%d",&is);
  gets(er);
 }
}

void loadfb(FILE *tf,inf_fb *fb,char *name)
{
 int g;
 inf_fb f;
 tf=fopen("fbs.txt","rt");
 if(tf!=NULL)
 do
 {
  g=fread(&f,sizeof(inf_fb),1,tf);
 }
 while((strcmp(name,f.name)!=0)&&(g!=0));
 if(g==1)
  *fb=f;
 fclose(tf);
}