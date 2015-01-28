//---------------------------------------------------------------------------
#ifndef playersH
#define playersH
#include <iostream.h>
#include "dictionary.h"
#include <fstream.h>
//---------------------------------------------------------------------------
struct T_Player
{
    string Name;
    int Symbols,isPeople; // 0 - computer, 1 - people
    T_Dictionary Dictionary;
    T_Player() { Symbols=0; isPeople=1; }
    T_Player(const char *name):Name(name) { Symbols=0; isPeople=1; }
    T_Player(const string name):Name(name) { Symbols=0; isPeople=1; }
    void SetName(const char *name) { Name=name; Symbols=0; }
    void SetDictionery(const char *fname) { Dictionary.LoadFromFile(fname); isPeople=0; }
};
//---------------------------------------------------------------------------
class T_Players
{
    private:
        T_Player *Player;
        int N,Curr;
    public:
        T_Players();
        T_Players(const int &n);
        ~T_Players();
        T_Player* GetCurrPlayer();
        T_Player* GetPlayer(const int &i);
        void SetN(const int &n);
        int GetN()const { return N; }
        void SaveToFile(ofstream &ofs);
        void LoadFromFile(ifstream &ifs);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 