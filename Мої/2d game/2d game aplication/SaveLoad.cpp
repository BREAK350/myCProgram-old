//---------------------------------------------------------------------------


#pragma hdrstop
#include "main.h"
#include "DrawFunction.h"
#include "SaveLoad.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------
void SavePicture(TPicture2d Picture,FILE *f,char *name)
{
 //------
 int i,j;
 Picture.width=256;
 Picture.height=256;
 Picture.points=(TColorObjChar**)malloc(Picture.width*sizeof(TColorObjChar*));
 for(i=0;i<Picture.width;i++)
  Picture.points[i]=(TColorObjChar*)malloc(Picture.height*sizeof(TColorObjChar));
 for(i=0;i<Picture.width;i++)
  for(j=0;j<Picture.height;j++)
   {
    Picture.points[i][j].k1=i;
    Picture.points[i][j].k2=j;
    Picture.points[i][j].k3=1;
    if(Picture.points[i][j].k1==EOF)
     Picture.points[i][j].k1++;
    if(Picture.points[i][j].k2==EOF)
     Picture.points[i][j].k2++;
   }
 //------
 Draw2DPicture(100,100,Picture);
 f=fopen(name,"wb");
 fwrite(&Picture.width,sizeof(int),1,f);
 fwrite(&Picture.height,sizeof(int),1,f);
 //fwrite(Picture.points,sizeof(TColorObjChar),Picture.width*Picture.height,f);
 for(i=0;i<Picture.width;i++)
  for(j=0;j<Picture.height;j++)
   fwrite(&Picture.points[i][j],sizeof(TColorObjChar),1,f);
 fclose(f);
}

void LoadPicture(TPicture2d &Picture,FILE *f,char *name)
{
 int i,j;
 f=fopen(name,"rb");
 fread(&Picture.width,sizeof(int),1,f);
 fread(&Picture.height,sizeof(int),1,f);
 Picture.points=(TColorObjChar**)malloc(Picture.width*sizeof(TColorObjChar*));
 for(i=0;i<Picture.width;i++)
  Picture.points[i]=(TColorObjChar*)malloc(Picture.height*sizeof(TColorObjChar));
 for(i=0;i<Picture.width;i++)
  for(j=0;j<Picture.height;j++)
   fread(&Picture.points[i][j],sizeof(TColorObjChar),1,f);
 fclose(f);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
