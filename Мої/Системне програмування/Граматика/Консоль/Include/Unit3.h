//---------------------------------------------------------------------------
#ifndef Unit3H
#define Unit3H
#include <stdlib.h>
#include <string.h>
//---------------------------------------------------------------------------
typedef char* (*TbOperand)(const int &Length,const int &Count_N);
const char STRUCT_N = 'A';
const char STRUCT_T = 'a';
//---------------------------------------------------------------------------
char* CreateStructRG(const int &Length); // Right Gram
char* CreateStructLG(const int &Length); // Left Gram
char* CreateStructKVG(const int &Length); // Kontekstno-vilna
//---------------------------------------------------------------------------
char* CreateStructOperand(const int &Length,const int &Count_N);
char* CreateStructOperandLeft(const int &Length,const int &Count_N);
char* CreateStructOperandRight(const int &Length,const int &Count_N);
char* CreateRule(TbOperand Left,TbOperand Right);
char* CreateRule(const char *Left,const char *Right);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 