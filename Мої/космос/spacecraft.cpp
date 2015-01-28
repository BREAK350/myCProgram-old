//---------------------------------------------------------------------------

#pragma hdrstop

#include "spacecraft.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void Print()
{
 TFleetOne *one;
 TMyEmpire MyEmpire;
 MyEmpire.colonys->Planet->fleet->ship->characteristic.protection=0;
 //MyEmpire.mainPlanet->fleet->ship->load=(TFleetOne*)malloc(sizeof(TFleetOne));
}
