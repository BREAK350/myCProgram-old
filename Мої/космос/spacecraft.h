//---------------------------------------------------------------------------
#ifndef spacecraftH
#define spacecraftH
#include <alloc.h>
struct TCharacteristic;
struct TLocation;
struct TSpaceCraft;
struct TFleetOne;
struct TPlanet;
struct TPlanets;
struct TMyEmpire;
//---------------------------------------------------------------------------
struct TCharacteristic {
 int type,
     life,
     attack,
     protection;
                       };
struct TLocation {
 int galaxy,
     star,
     planet,
     quadrate;
                 };
struct TSpaceCraft {
 TCharacteristic characteristic;
 int passengers;
 TFleetOne *vantazh;
 TLocation location,
           fly;
                 };
struct TFleetOne {
 TSpaceCraft *ship;
 TFleetOne *next,
           *prev;
                 };
struct TPlanet {
 char name[20];
 TLocation location;
 TFleetOne *fleet;
 int population,
     income;
               };
struct TPlanets {
 TPlanet *Planet;
 TPlanets *next,
          *prev;
                };
struct TMyEmpire {
 TPlanet *mainPlanet;
 TPlanets *colonys;
                 };
//---------------------------------------------------------------------------
#endif
