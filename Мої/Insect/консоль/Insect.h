//---------------------------------------------------------------------------
#ifndef InsectH
#define InsectH
//---------------------------------------------------------------------------
struct TCharacteristicInsect {
 int med,
     E,
     life,
     gn,
     sl,
     vl,
     mz,
     re,
     shv;
                       };
struct TPlace {
 char type,
      name[10];
 TPlace *runTo[6];
              };
struct TWorld {
              };
struct TInsect {

               };
//---------------------------------------------------------------------------
#endif
