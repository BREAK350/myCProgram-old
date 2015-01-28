//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <vcl.h>
#define SIZE_DOSHKA 8
#define S(a) ((a)->Width/SIZE_DOSHKA)
#define SD SIZE_DOSHKA
#define ABS(a) ( ((a>=0))?(a):(-(a)) )
#define ZNAK(a) (((a)>0)?(1):(-1))
#define isCORRECTLY(a,b) ( ( (a)>=0 && (a)<SD && (b)>=0 && (b)<SD)?(1):(0) )
#define isCorrectly(a) isCORRECTLY((a).i,(a).j)
#define DK(a) (D[(a).i][(a).j])
#define init(a,b,c) {(a).i=(b);(a).j=(c);}

#define isBLACK(a) ( (a==BLACK_PLAYER || a==BLACK_QUEEN )?(1):(0) )
#define isWHITE(a) ( (a==WHITE_PLAYER || a==WHITE_QUEEN )?(1):(0) )
#define isQUEEN(a) ( (a==BLACK_QUEEN || a==WHITE_QUEEN)?(1):(0) )
#define WHO_PLAYER(a) ( ((a)==BLACK_PLAYER || (a)==BLACK_QUEEN )?(BLACK_PLAYER):(WHITE_PLAYER) )
#define OPPOSITE(a) ( (a==BLACK_PLAYER || a==BLACK_QUEEN )?(WHITE_PLAYER):(BLACK_PLAYER) )
#define BE_QUEEN(a) ( ((a)==BLACK_PLAYER)?(BLACK_QUEEN):(WHITE_QUEEN) )
//---------------------------------------------------------------------------
enum fishka
{
    NOTHING,
    BLACK_PLAYER,
    BLACK_QUEEN,
    WHITE_PLAYER,
    WHITE_QUEEN
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
struct kory
{
    int i,j;
};
//---------------------------------------------------------------------------
class doshka
{
    private:
        int D[SIZE_DOSHKA][SIZE_DOSHKA];
        int BLACK,WHITE;
        int UPSTAIRS;   //UPSTAIRS = BLACK_PLAYER or WHITE_PLAYER
        int WHO_GO;     //WHO_GO  =  BLACK_PLAYER or WHITE_PLAYER
        kory ok[28];
        int CreateCanGo(kory);
        int CanGo(kory,kory);
        kory isKill(kory,kory);
    public:
        void Init(int);
        void D_Show(Graphics::TBitmap*);
        void RUN(kory*,int);
        int ReturnPlayer(kory);
        int ReturnWHO_GO();
        void ReturnD();
        void ReturnOk(kory,kory*&);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 