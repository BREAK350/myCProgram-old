//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
FILE *fp;
extern int ianswer;
//---------------------------------------------------------------------------
int LoadQuestion(TQ *&q)
{
 int n,i,m,j,r,p;
 char a[300];
 fp=fopen(fnN,"rt");
 if(fp==NULL)
   return -1;
 fscanf(fp,"%d",&n);
 fclose(fp);
 Form1->Label10->Caption=FloatToStr(n);
 fp=fopen(fn,"rt");
 q=(TQ*)malloc(n*sizeof(TQ));
 for(i=0;i<n;i++)
  {
    fgets(a,300,fp);
    m=0;
    j=0;
    while(a[j]!=rozd)
    {
      j++;
      m++;
    }
    q[i].question=(char*)malloc(m*sizeof(char));
    for(r=0;r<m;r++)
      q[i].question[r]=a[r];
    q[i].question[r]='\n';
    j++;
    p=j;
    m=0;
    while(a[j]!=rozd)
    {
      j++;
      m++;
    }
    q[i].answer[0]=(char*)malloc(m*sizeof(char));
    for(r=0;r<m;r++)
      q[i].answer[0][r]=a[r+p];
    //q[i].answer[0][r]='\n';
    j++;
    p=j;
    m=0;
    while(a[j]!=rozd)
    {
      j++;
      m++;
    }
    q[i].answer[1]=(char*)malloc(m*sizeof(char));
    for(r=0;r<m;r++)
      q[i].answer[1][r]=a[r+p];
    //q[i].answer[1][r]='\n';
    j++;
    p=j;
    m=0;
    while(a[j]!=rozd)
    {
      j++;
      m++;
    }
    q[i].answer[2]=(char*)malloc(m*sizeof(char));
    for(r=0;r<m;r++)
      q[i].answer[2][r]=a[r+p];
    //q[i].answer[2][r]='\n';
    j++;
    p=j;
    m=0;
    while(a[j])
    {
      j++;
      m++;
    }
    q[i].answer[3]=(char*)malloc(m*sizeof(char));
    for(r=0;r<m;r++)
      q[i].answer[3][r]=a[r+p];
    //q[i].answer[3][r]='\n';
    j++;
  }
 fclose(fp); 
 return n;
}
//---------------------------------------------------------------------------
void ShowQuestion(TQ *q,int i)
{
 int a[4];
 RandomIndex(a,4);
 Question=q[i].question;
 Answer1=q[i].answer[a[0]];
 Answer2=q[i].answer[a[1]];
 Answer3=q[i].answer[a[2]];
 Answer4=q[i].answer[a[3]];
 for(i=0;i<4;i++)
   if(a[i]==0)
     {
      ianswer=i;
      break;
     }
}
//---------------------------------------------------------------------------
void RandomIndex(int *&a,int n)
{
 int i,g,j;
 for(i=0;i<n;i++)
  {
   do
    {
     g=random(n);
     for(j=0;j<i;j++)
       if(a[j]==g)
         break;
     if(j==i)
      {
       a[i]=g;
       g=-1;
      }
    }
    while(g!=-1);
  }
}
//---------------------------------------------------------------------------
void Cl(TQ*&q,int *&a,int n)
{
 int i,j;
 for(i=0;i<n;i++)
  {                             
   free(q[i].question);
   for(j=0;j<4;j++)
     free(q[i].answer[j]);
  }
 free(q);
 q=NULL;
 free(a);
 a=NULL;
}
//---------------------------------------------------------------------------
