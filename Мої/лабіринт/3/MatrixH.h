//---------------------------------------------------------------------------
#ifndef MatrixHH
#define MatrixHH
#include <alloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <vcl.h>
#define WALL     0
#define ROAD     1
#define BEGIN    2
#define END      3
#define PLAYER   4
#define HALFWALL 5
#define GOUP     6
#define GODOWN   7
typedef int(Func)(int,int);
//---------------------------------------------------------------------------
class TMatrix
{
	protected:
		int mP,mN,mM;
		char ***L;
		int License;
	public:
		TMatrix();
		TMatrix(const TMatrix &);
		~TMatrix();
		TMatrix& operator = (const TMatrix &);
		void SaveToFile(char *);
		bool LoadFromFile(char *);
		void SaveToFileLicense(char *);
		int LoadFromFileLicense(char *);
		void RandomMatrix(int);
		void Delete();
		void Create(int,int);
		void Create(int,int,int);
		void Create(int,int,int,int);
		void Insert(int,int,int,const TMatrix &);
		TMatrix CreateCopy();
		int FuncLicense(int b,int c){return b*c;}
		int FuncUser(int b,int c){return b+c;}
};
//---------------------------------------------------------------------------
class AbstractElement
{
	public:
		virtual bool isAllowed() { return true; }
		virtual void onEntered() {}
		virtual void onExit() {}
};
//---------------------------------------------------------------------------
class AbstractDrawElement: public AbstractElement
{
	public:
		void onPaint(TCanvas *canvas,const TRect &rect);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 