//---------------------------------------------------------------------------
#ifndef footlH
#define footlH
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAXF 7
#define TL "TeamList"
#define MAXK 5
#define MAXO 6
#define Match(team1,team2) _Match(team1,team2,MAXK)
typedef char tchar[10];
//---------------------------------------------------------------------------
struct TFootballer {
 tchar name;
 char type;
 int A,Z;
 char rest;
 int goal;
             };
struct TTeam {
 tchar name;
 int money;
 int win,draw,loss;
 TFootballer footballer[MAXF];
             };
struct TTreeItem {
 TTeam team;
 TTreeItem *right,*left;
                 };
struct TTeamCham {
 int o;
 TTeam team;
                 };
struct TGroup {
 TTeamCham teams[4];
             };
struct TChampionship {

                     };
//---------------------------------------------------------------------------
void        RandomName(tchar&);
void        CreateNewFootballer(TFootballer&);
void        CreateNewFootballer(TFootballer&,char);
void        PrintFootballer(TFootballer);
void        CreateNewTeam(TTeam&);
void        CreateNewTeam(TTeam&,char*);
void        PrintTeamFB(TTeam);
void        PrintTeam(TTeam);
void        SaveTeam(TTeam);
TTeam       LoadTeam(char*);
void        PrintListTeam();
int         _Match(TTeam&,TTeam&,int);
void        PrintTeamData(TTeam);
void        Championship();
TTeam       GroupFight(TGroup);
//---------------------------------------------------------------------------
#endif
