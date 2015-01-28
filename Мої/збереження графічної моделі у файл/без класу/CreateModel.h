//---------------------------------------------------------------------------
#ifndef CreateModelH
#define CreateModelH
#include "TModel.h"
//---------------------------------------------------------------------------
void          CreateGraf(TModel&);
void          CreateLine(TModel,int,int);
void          DeleteLine(TModel,int,int);
int           isLine(TModel,int,int);
int           _is_Line(graf*,int,int);
int           _CreateLine(graf*&,int,int);
int           _DeleteLine(graf*&,int,int);
void          CreateCHP(TModel&);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
