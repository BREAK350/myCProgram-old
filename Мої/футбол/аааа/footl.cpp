//---------------------------------------------------------------------------
#pragma hdrstop
#include "footl.h"
#pragma package(smart_init)
extern FILE *list;
//---------------------------------------------------------------------------
void RandomName(tchar &name)
{
 int i,n;
 n=random(7)+3;
 for(i=0;i<n;i++)
   name[i]=random(26)+97;
 name[i]='\0';
 name[0]=name[0]-'a'+'A';
}
//---------------------------------------------------------------------------
void CreateNewFootballer(TFootballer &footballer)
{
 int p;
 RandomName(footballer.name);
 p=random(3);
 switch(p)
 {
   case 0:footballer.type='V';break;
   case 1:footballer.type='A';break;
   case 2:footballer.type='Z';break;
 }
 footballer.A=footballer.Z=footballer.goal=0;
 footballer.rest=0;
}
//---------------------------------------------------------------------------
void CreateNewFootballer(TFootballer &footballer,char type)
//type={A,Z,V}
{
 RandomName(footballer.name);
 footballer.type=type;
 footballer.A=footballer.Z=footballer.goal=0;
 footballer.rest=0;
}
//---------------------------------------------------------------------------
void PrintFootballer(TFootballer footballer)
{
 printf("Footballer\n-name  %s\n-type  %c\n",footballer.name,footballer.type);
 printf("-A=%d\n-Z=%d\n-rest=%d\n-goals=%d\n",footballer.A,footballer.Z,footballer.rest,footballer.goal);
}
//---------------------------------------------------------------------------
void CreateNewTeam(TTeam &team)
{
 int i;
 RandomName(team.name);
 team.money=1000;
 team.win=team.draw=team.loss=0;
 CreateNewFootballer(team.footballer[0],'V');
 for(i=1;i<MAXF/2+1;i++)
   CreateNewFootballer(team.footballer[i],'A');
 for(;i<MAXF;i++)
   CreateNewFootballer(team.footballer[i],'Z');
}
//---------------------------------------------------------------------------
void CreateNewTeam(TTeam &team,char*name)
{
 int i;
 strcpy(team.name,name);
 team.money=1000;
 team.win=team.draw=team.loss=0;
 CreateNewFootballer(team.footballer[0],'V');
 for(i=1;i<MAXF/2+1;i++)
   CreateNewFootballer(team.footballer[i],'A');
 for(;i<MAXF;i++)
   CreateNewFootballer(team.footballer[i],'Z');
}
//---------------------------------------------------------------------------
void PrintTeamFB(TTeam team)
{
 int i;
 PrintTeamData(team);
 printf("Footbollers:\n");
 for(i=0;i<MAXF;i++)
   PrintFootballer(team.footballer[i]);
}
//---------------------------------------------------------------------------
void PrintTeam(TTeam team)
{
 int i;
 PrintTeamData(team);
 printf("Footbollers:\n");
 for(i=0;i<MAXF;i++)
   printf("%10s(%c)\n",team.footballer[i].name,team.footballer[i].type);
}
//---------------------------------------------------------------------------
void PrintTeamData(TTeam team)
{
 printf("Team\n-name  %s\n-money=   %d\n-win=     %d\n-draw=    %d\n-loss=    %d\n",team.name,team.money,team.win,team.draw,team.loss);
}
//---------------------------------------------------------------------------
void SaveTeam(TTeam team)
{
 FILE *f;
 f=fopen(team.name,"wt");
 fwrite(&team,sizeof(TTeam),1,f);
 fclose(f);
 list=fopen(TL,"a");
 fprintf(list,"%s\n",team.name,list);
 fclose(list);
}
//---------------------------------------------------------------------------
void LoadTeam()
{
 FILE *team;
 char name[10];
 printf("Input name team  ");
 gets(name);
 if((team=fopen(name,"r"))==NULL)
   printf("not found team\n");
}
//---------------------------------------------------------------------------
TTeam LoadTeam(char*name)
{
   FILE   *fteam;
   TTeam  team;
 team.win=-1;
 if((fteam=fopen(name,"r"))==NULL)
  {
   printf("Not found team\n");
   return team;
  }
 fread(&team,sizeof(TTeam),1,fteam);
 fclose(fteam);
 return team;
}
//---------------------------------------------------------------------------
void PrintListTeam()
{
 int i;
 char name[10];
 list=fopen(TL,"r");
 i=1;
 while(fgets(name,10,list))
 {
  printf("%2d)%s",i,name);
  i++;
 }
 fclose(list);
}
//---------------------------------------------------------------------------
int _Match(TTeam &team1,TTeam &team2,int maxk)
{
 int i=0,goal1=0,goal2=0;
 int nA,nZ,A,Z;
 randomize();
 for(i=0;i<maxk;i++)
  { //------------------------------------------
    nA=random(3)+1;
    A=random(MAXO)+1+team1.footballer[nA].A/100;
    nZ=random(3)+4;
    Z=random(MAXO)+1+team2.footballer[nZ].Z/100;
    if(A>Z)
    {
      team1.footballer[nA].A++;
      A=random(MAXO)+1+team1.footballer[nA].A/100;
      Z=random(MAXO)+1+team2.footballer[0].Z/100;
      if(A>Z)
      {
        team1.footballer[nA].A++;
        goal1++;
        team1.footballer[nA].goal++;
      }
      else
      {
        team2.footballer[0].Z++;
      }
    }
    else
    {
      team2.footballer[nZ].Z++;
    }
  //------------------------------------------
    nA=random(3)+1;
    A=random(MAXO)+1+team2.footballer[nA].A/100;
    nZ=random(3)+4;
    Z=random(MAXO)+1+team1.footballer[nZ].Z/100;
    if(A>Z)
    {
      team2.footballer[nA].A++;
      A=random(MAXO)+1+team2.footballer[nA].A/100;
      Z=random(MAXO)+1+team1.footballer[0].Z/100;
      if(A>Z)
      {
        team2.footballer[nA].A++;
        goal2++;
        team2.footballer[nA].goal++;
      }
      else
      {
        team1.footballer[0].Z++;
      }
    }
    else
    {
      team1.footballer[nZ].Z++;
    }
  }
 if(goal1>goal2)
 {
   team1.win++;
   team2.loss++;
   return 1;
 }
 if(goal1<goal2)
 {
   team1.loss++;
   team2.win++;
   return 2;
 }
 team1.draw++;
 team2.draw++;
 return 0;
}
//---------------------------------------------------------------------------
void Championship()
{

}
//---------------------------------------------------------------------------
TTeam GroupFight(TGroup group)
{
  int i,j,maxo=0;
  TTeamCham t;
  for(i=0;i<4;i++)
    group.teams[i].o=0;
  i=Match(group.teams[0].team,group.teams[1].team);
  switch(i)
  {
    case 0:group.teams[0].o+=1;
           group.teams[1].o+=1;break;
    case 1:group.teams[0].o+=2;break;
    case 2:group.teams[1].o+=2;break;
  }
  i=Match(group.teams[2].team,group.teams[3].team);
  switch(i)
  {
    case 0:group.teams[2].o+=1;
           group.teams[3].o+=1;break;
    case 1:group.teams[2].o+=2;break;
    case 2:group.teams[3].o+=2;break;
  }
  i=Match(group.teams[0].team,group.teams[2].team);
  switch(i)
  {
    case 0:group.teams[0].o+=1;
           group.teams[2].o+=1;break;
    case 1:group.teams[0].o+=2;break;
    case 2:group.teams[2].o+=2;break;
  }
  i=Match(group.teams[1].team,group.teams[3].team);
  switch(i)
  {
    case 0:group.teams[1].o+=1;
           group.teams[3].o+=1;break;
    case 1:group.teams[1].o+=2;break;
    case 2:group.teams[3].o+=2;break;
  }
  i=Match(group.teams[0].team,group.teams[3].team);
  switch(i)
  {
    case 0:group.teams[0].o+=1;
           group.teams[3].o+=1;break;
    case 1:group.teams[0].o+=2;break;
    case 2:group.teams[3].o+=2;break;
  }
  i=Match(group.teams[1].team,group.teams[2].team);
  switch(i)
  {
    case 0:group.teams[1].o+=1;
           group.teams[2].o+=1;break;
    case 1:group.teams[1].o+=2;break;
    case 2:group.teams[2].o+=2;break;
  }
 for(i=0;i<3;i++)
   for(j=3;j>i;j--)
     if(group.teams[i].o<group.teams[j].o)
      {
        t=group.teams[i];
        group.teams[i]=group.teams[j];
        group.teams[j]=t;
      }
 if(group.teams[0].o!=group.teams[1].o)
   return group.teams[0].team;
 if(group.teams[1].o!=group.teams[2].o)
 {
   i=Match(group.teams[0].team,group.teams[1].team);
   if(i==1)
     return group.teams[0].team;
   if(i==2)
     return group.teams[1].team;
 }
 return group.teams[0].team;
}
//---------------------------------------------------------------------------
