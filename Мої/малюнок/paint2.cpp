//---------------------------------------------------------------------------
#pragma hdrstop
#include "paint2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
int PaintPicture(TForm *Form1,char *fname,int x,int y)
{
 FILE *fp;
 if((fp=fopen(fname,"rb"))==NULL)
  return 0;
 Form1->Canvas->Pixels[100][100]=clRed;
}
//---------------------------------------------------------------------------
