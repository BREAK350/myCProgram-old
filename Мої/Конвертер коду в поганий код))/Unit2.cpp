//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include <fstream.h>
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool isSpace(const char &s)
{
	return s==' ' || s=='\t' || s=='\n' || s=='\r';
}
//---------------------------------------------------------------------------
void Convert(const char *finname,const char *foutname)
{
	FILE *fin=fopen(finname,"rt");
	FILE *fout=fopen(foutname,"wt");
	char s;
	bool space=false;
	while(fscanf(fin,"%c",&s)==1)
	{
		if(isSpace(s))
		{
			if(space==false)
			{
				space=true;
				fprintf(fout,"%c",' ');
			}
		}
		else
		{
			space=false;
			fprintf(fout,"%c",s);
		}
	}
	fclose(fin);
	fclose(fout);
}
//---------------------------------------------------------------------------
void Convert(ifstream &ifs,ofstream &ofs)
{
	bool space=false;
	char s;
	do
	{
		ifs>>s;
		if(s==' ')
		{
			if(space==false)
			{
				space=true;
				ofs<<s;
			}
		}
		else
		{
			space=false;
			ofs<<s;
		}
	}
	while(s!=EOF);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	if(od->Execute())
	{
		String fname=od->FileName;
		String fnew=fname+"~";
		//ifstream ifs(fname.t_str());
		//ofstream ofs(fnew.t_str());
		//Convert(ifs,ofs);
		Convert(fname.t_str(),fnew.t_str());
		//ifs.close();
		//ofs.close();
	}
}
//---------------------------------------------------------------------------
