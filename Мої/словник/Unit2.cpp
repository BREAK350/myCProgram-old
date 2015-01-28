//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
TWord CreateWord(char*a)
{
 TWord word;
 int i,i_e,i_u,i_d,j,i_left,i_right;
 word.n_e=word.n_u=0;
 word.eng=NULL;
 word.ukr=NULL;
   i_e=0;
   i_u=0;
   if(a[0]!='(')
     return word;
   i=0;
   while((a[i])&&(a[i]!='\n'))
    {
     i_d=0;
     while(a[i]!='=')
      {
       if(a[i]=='(')
         i_e++;
       if(a[i]==')')
        {
         i_d++;
         if(a[i-1]=='(')
           return word;
        }
       i++;
      }
     if(i_e!=i_d)
       return word;
     i_d=0;
     while((a[i])&&(a[i]!='\n'))
      {
       if(a[i]=='(')
         i_u++;
       if(a[i]==')')
        {
         i_d++;
         if(a[i-1]=='(')
           return word;
        }
       i++;
      }
     if((i_u!=i_d)&&(i_u>0))
       return word;
    }
   word.n_e=i_e;
   word.n_u=i_u;
   word.eng=(char**)malloc(i_e*sizeof(char*));
   word.ukr=(char**)malloc(i_u*sizeof(char*));
   i=0;
   while((a[i])&&(a[i]!='\n'))
    {
     j=0;
     while(a[i]!='=')
      {
       i_right=-1;
       while(i_right==-1)
       {
         if(a[i]=='(')
           i_left=i+1;
         if(a[i]==')')
           i_right=i;
         i++;
       }
       word.eng[j]=(char*)malloc((i_right-i_left)*sizeof(char));
       for(i_d=0;i_d<i_right-i_left;i_d++)
         word.eng[j][i_d]=a[i_d+i_left];
       word.eng[j][i_d]='\0';
       j++;
      }
     j=0;
     while((a[i])&&(a[i]!='\n'))
      {
       i_right=-1;
       while(i_right==-1)
       {
         if(a[i]=='(')
           i_left=i+1;
         if(a[i]==')')
           i_right=i;
         i++;
       }
       word.ukr[j]=(char*)malloc((i_right-i_left)*sizeof(char));
       for(i_d=0;i_d<i_right-i_left;i_d++)
         word.ukr[j][i_d]=a[i_d+i_left];
       word.ukr[j][i_d]='\0';
       j++;
      }
    }
 return word;
}
//---------------------------------------------------------------------------
void PrintWord(TWord word)
{
 int i;
 printf("England: ");
 for(i=0;i<word.n_e;i++)
   printf("(%s)",word.eng[i]);
 printf("\nUkranian: ");
 for(i=0;i<word.n_u;i++)
   printf("(%s)",word.ukr[i]);
}
//---------------------------------------------------------------------------
void push_back(TListW &list,TWord word)
{
 if(list.last)
 {
  list.last->next=(TListItem*)malloc(sizeof(TListItem));
  list.last->next->word=word;
  list.last->next->next=NULL;
  list.last->next->prev=list.last;
  list.last=list.last->next;
 }
 else
 {
  list.first=(TListItem*)malloc(sizeof(TListItem));
  list.first->next=list.first->prev=NULL;
  list.first->word=word;
  list.last=list.first;
 }
}
int CreateList(TListW &list,char *fname)
{
 int i=0;
 FILE *fp;
 char a[500];
 TWord w;
 fp=fopen(fname,"rt");
 list.last=list.first=NULL;
 if(fp)
   while(fgets(a,500,fp))
    {
     w=CreateWord(a);
     if((w.n_e>0)&&(w.n_u>0))
      {
       push_back(list,w);
       i++;
      }
    }
 return i;
}
//---------------------------------------------------------------------------
void ShowWord(TListItem *t)
{
 int i;
 for(i=0;i<MaxLines;i++)
  {
   Form1->Memo1->Lines->Strings[i]="";
   Form1->Memo2->Lines->Strings[i]="";
  }
 for(i=0;i<t->word.n_e;i++)
   Form1->Memo1->Lines->Strings[i]=t->word.eng[i];
 for(i=0;i<t->word.n_u;i++)
   Form1->Memo2->Lines->Strings[i]=t->word.ukr[i];
}
void ShowWordEng(TListItem *t)
{
 int i;
 for(i=0;i<MaxLines;i++)
   Form1->Memo1->Lines->Strings[i]="";
 for(i=0;i<t->word.n_e;i++)
   Form1->Memo1->Lines->Strings[i]=t->word.eng[i];
}
void ShowWordUkr(TListItem *t)
{
 int i;
 for(i=0;i<MaxLines;i++)
   Form1->Memo2->Lines->Strings[i]="";
 for(i=0;i<t->word.n_u;i++)
   Form1->Memo2->Lines->Strings[i]=t->word.ukr[i];
}
void ShowWordOne(TListItem *t,int m)
{
 int i;
 switch(m)
  {
   case 0:ShowWordEng(t);
          for(i=0;i<MaxLines;i++)
            Form1->Memo2->Lines->Strings[i]="";
          break;
   case 1:ShowWordUkr(t);
          for(i=0;i<MaxLines;i++)
            Form1->Memo1->Lines->Strings[i]="";
          break;
  }
}
//---------------------------------------------------------------------------
