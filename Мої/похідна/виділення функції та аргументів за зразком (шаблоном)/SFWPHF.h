//---------------------------------------------------------------------------
#ifndef SFWPHFH
#define SFWPHFH
#include <string.h>
#include <vcl.h>
//---------------------------------------------------------------------------
#define levelUp '('
#define levelDown ')'
#define ARG '_'
#define END '\0'
//---------------------------------------------------------------------------
// A: ( or )
// D: * or /
// E: + or -
// M: D or E
// N: all
#define A16 'A'
#define ACTION16(p) ( (p)=='(' || (p)==')' || (p)==A16 )
#define A13 'D'
#define ACTION13(p) ( (p)=='*' || (p)=='/' || (p)==A13 )
#define A12 'E'
#define ACTION12(p) ( (p)=='+' || (p)=='-' || (p)==A12 )
#define A1 ','
#define ACTION1(p)  ( (p)==',' )
#define MA 'M'
#define MATH_ACTION(p) ( ACTION13(p) || ACTION12(p) || (p)==MA )
#define AA 'N'
#define ANY_ACTION(p) ( ACTION16(p) || MATH_ACTION(p) || ACTION1(p) || (p)==AA )

//---------------------------------------------------------------------------
char *SFWP(char*,char*,char*&,char**&,int&);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
