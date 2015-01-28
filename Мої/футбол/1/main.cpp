//---------------------------------------------------------------------------
#include <stdio.h>
#include <conio.h>
#pragma hdrstop
#include "footl.h"
//---------------------------------------------------------------------------
#pragma argsused
FILE *list;

int main(int argc, char* argv[])
{
 int i;
 tchar n,g;
 TFootballer footballer;
 TTeam team1,team2;
 randomize();
 CreateNewTeam(team1,"abcd");
 CreateNewTeam(team2);
 i=Match(team1,team2);
 PrintTeamData(team1);
 PrintTeamData(team2);
 getch();
 return 0;
}
//---------------------------------------------------------------------------
