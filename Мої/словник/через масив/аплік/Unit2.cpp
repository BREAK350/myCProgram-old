//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit3.h"
#include "Unit2.h"
#include "Unit1.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
extern  int     n;
extern  TWord   *w,add;
extern  int     typeshow1;
extern  int     typeshow2;
extern  int     index;
extern  int     oneword;
extern  char    search[500];
extern  data    dat;
extern  int     change;
extern  int     pfn;
//---------------------------------------------------------------------------
int LoadWords()
{
 int i,j,r;
 FILE *f;
 char s[1000];
 index=0;
 switch(pfn)
  {
   case 1:n=NumberLine(dat.fwtxt);break;
   case 2:n=NumberLine(dat.fstxt);break;
  }
 if(n<=0)
   return 0;
 switch(pfn)
  {
   case 1:f=fopen(dat.fwtxt,"rt");break;
   case 2:f=fopen(dat.fstxt,"rt");break;
  }
 w=(TWord*)malloc(n*sizeof(TWord));
 for(i=0;i<n;i++)
   {
    fgets(s,1000,f);
    j=0;
    while((s[j])&&(s[j]!='='))
      j++;
    s[j]='\0';
    w[i].eng=strdup(s);
    j++;
    r=j;
    while((s[r])&&(s[r]!='\n'))
      r++;
    s[r]='\0';
    w[i].ukr=strdup(&s[j]);
   }
 fclose(f);
 return 1; 
}
//---------------------------------------------------------------------------
void ShowRandomWord()
{
 int i;
 i=random(n);
 Form1->eng->Lines->Strings[0]=w[i].eng;
 Form1->ukr->Lines->Strings[0]=w[i].ukr;
}
//---------------------------------------------------------------------------
void ShowWord1()
{
 switch(typeshow1)
  {
   case 1:ShowWord2();break;
   case 2:index=random(n);
          ShowWord2();break;
  }
}
//---------------------------------------------------------------------------
void ShowWord2()
{
 if((w[index].eng)&&(w[index].ukr))
   switch(typeshow2)
    {
     case 1:Form1->eng->Clear();
            Form1->ukr->Clear();
            Form1->eng->Lines->Strings[0]=w[index].eng;
            Form1->ukr->Lines->Strings[0]=w[index].ukr;
            break;
     case 2:Form1->eng->Lines->Strings[0]=w[index].eng;
            Form1->ukr->Clear();
            oneword=0;
            break;
     case 3:Form1->ukr->Lines->Strings[0]=w[index].ukr;
            Form1->eng->Clear();
            oneword=1;
            break;
     case 4:oneword=random(2);;
            switch(oneword)
             {
              case 0:Form1->eng->Lines->Strings[0]=w[index].eng;
                     Form1->ukr->Clear();
                     break;
              case 1:Form1->ukr->Lines->Strings[0]=w[index].ukr;
                     Form1->eng->Clear();
                     break;
             }
    }
 else
 {
  Form1->eng->Clear();
  Form1->ukr->Clear();
  Form1->ukr->Lines->Strings[0]="Дане слово було видалене";
 }
}
//---------------------------------------------------------------------------
void SortWordEng()
{
 int i,j;
 TWord p;
 for(i=0;i<n-1;i++)
   for(j=n-1;j>i;j--)
     if((w[i].eng)&&(w[j].eng)&&(strcmp(w[i].eng,w[j].eng)>0))
       {
        p=w[i];
        w[i]=w[j];
        w[j]=p;
       }
}
//---------------------------------------------------------------------------
void SortWordUkr()
{
 int i,j;
 TWord p;
 for(i=0;i<n-1;i++)
   for(j=n-1;j>i;j--)
     if((w[i].ukr)&&(w[j].ukr)&&(strcmp(w[i].ukr,w[j].ukr)>0))
       {
        p=w[i];
        w[i]=w[j];
        w[j]=p;
       }
}
//---------------------------------------------------------------------------
void SearchNextWord()
{
 Form1->eng->Clear();
 Form1->ukr->Clear();
 while(index<n)
    {
      if(strstr(w[index].eng,search))
        {
         Form1->ukr->Lines->Strings[0]=w[index].ukr;
         Form1->eng->Lines->Strings[0]=w[index].eng;
         break;
        }
      if(strstr(w[index].ukr,search))
        {
         Form1->eng->Lines->Strings[0]=w[index].eng;
         Form1->ukr->Lines->Strings[0]=w[index].ukr;
         break;
        }
      index++;
    }
}
//---------------------------------------------------------------------------
void SearchEngWord()
{
 index=0;
 while(index<n)
  {
   if(strstr(w[index].eng,search))
    {
     Form1->ukr->Lines->Strings[0]=w[index].ukr;
     Form1->eng->Lines->Strings[0]=w[index].eng;
     break;
    }
   index++;
  }
}
//---------------------------------------------------------------------------
void SearchUkrWord()
{
 index=0;
 while(index<n)
  {
   if(strstr(w[index].ukr,search))
    {
     Form1->ukr->Lines->Strings[0]=w[index].ukr;
     Form1->eng->Lines->Strings[0]=w[index].eng;
     break;
    }
   index++;
  }
}
//---------------------------------------------------------------------------
void CreateStandartWords()
{
 FILE *f;
 n=10;
 switch(pfn)
  {
   case 1:f=fopen(dat.fwtxt,"at");break;
   case 2:f=fopen(dat.fstxt,"at");break;
  }
 w=(TWord*)malloc(n*sizeof(TWord));
 w[0].eng=strdup("english");
 w[0].ukr=strdup("англійська");
 w[1].eng=strdup("ukrainian");
 w[1].ukr=strdup("українська");
 w[2].eng=strdup("do");
 w[2].ukr=strdup("робити");
 w[3].eng=strdup("yellow");
 w[3].ukr=strdup("жовтий");
 w[4].eng=strdup("programming");
 w[4].ukr=strdup("програмування");
 w[5].eng=strdup("The United Kingdom of Great Britain and Northern Ireland is situated on the British Isles.");
 w[5].ukr=strdup("З’єднане Королівство Великобританії і Північної Ірландії розташоване на Британських островах.");
 w[6].eng=strdup("Great Britain is a beautiful country with old traditions and good people.");
 w[6].ukr=strdup("Великобританія — прекрасна країна з давніми традиціями і гарними людьми.");
 w[7].eng=strdup("to consist of");
 w[7].ukr=strdup("складатися");
 w[8].eng=strdup("translator");
 w[8].ukr=strdup("перекладач");
 w[9].eng=strdup("word");
 w[9].ukr=strdup("слово");
}
//---------------------------------------------------------------------------
void StandartData()
{
 dat.fwtxt="Words.txt";
 dat.fwbak="Words.bak";
 dat.fstxt="Sentences.txt";
 dat.fsbak="Sentences.bak";
}
//---------------------------------------------------------------------------
void SaveAll()
{
 FILE *f;
 switch(pfn)
  {
   case 1:remove(dat.fwbak);
          rename(dat.fwtxt,dat.fwbak);
          f=fopen(dat.fwtxt,"wt");break;
   case 2:remove(dat.fsbak);
          rename(dat.fstxt,dat.fsbak);
          f=fopen(dat.fstxt,"wt");break;
  }
 for(index=0;index<n;index++)
   if((w[index].eng)&&(w[index].ukr))
     fprintf(f,"%s=%s\n",w[index].eng,w[index].ukr);
 fclose(f);
}
//---------------------------------------------------------------------------
void SaveOne()
{
 FILE *f;
 switch(pfn)
  {
   case 1:f=fopen(dat.fwtxt,"at");break;
   case 2:f=fopen(dat.fstxt,"at");break;
  }
 fprintf(f,"%s=%s\n",add.eng,add.ukr);
 fclose(f);
}
//---------------------------------------------------------------------------
void reLoad()
{
 int i;
 if(change==0)
   {
    for(i=0;i<n;i++)
     {
      free(w[i].eng);
      free(w[i].ukr);
     }
    free(w);
    if(LoadWords()==0)
      CreateStandartWords();
    ShowWord1();
    Form1->Label5->Caption=FloatToStr(n);
   }
 else
  {
   Form1->msg->Visible=true;
   Form1->Memo1->Text="Увага! Були проведені деякі зміни в словах. Без збереження ці зміни не збережуться!";
   change=0;
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

