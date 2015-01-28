//---------------------------------------------------------------------------
#ifndef SpaceStructureH
#define SpaceStructureH
#include "T_Vector2d.h"
#include "TbList2.h"
//---------------------------------------------------------------------------
class TbStrategyObject
{
	protected:
		TbVector2d Location;
	public:
		TbStrategyObject();
		TbStrategyObject(const TbVector2d &Location);
		TbStrategyObject(const double &X,const double &Y);


};
//---------------------------------------------------------------------------
class TbStrategyDroid;
//---------------------------------------------------------------------------
class TbStrategyPlanet:public TbStrategyObject
{
	protected:
		TbStrategyPlanet **NearestPlanets;
		int CountNearestPlanet;
		TbList2 <TbStrategyDroid*> Droids;
};
//---------------------------------------------------------------------------
class TbStrategyDroid:public TbStrategyObject
{
	protected:
		TbStrategyPlanet *NearestPlanet;
		TbList2 <TbStrategyDroid*> Droids;
};
//---------------------------------------------------------------------------
class TbStrategyPlayer
{
	protected:
		TbList2 <TbStrategyDroid> Droids;
		TbList2 <TbStrategyPlanet*> VisitedPlanet;
};
//---------------------------------------------------------------------------
class TbStrategyGame
{
	protected:
		TbStrategyPlanet *Planets;
		int CountPlanet;
		TbStrategyPlayer *Players;
		int CountPlayer;
		int CurrPlayer;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
