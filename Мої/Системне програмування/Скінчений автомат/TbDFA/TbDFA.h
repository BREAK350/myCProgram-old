//---------------------------------------------------------------------------
#ifndef TbDFAH
#define TbDFAH
#include "TbUFA.h"
#include <stack.h>
#include <fstream.h>
//---------------------------------------------------------------------------
class TbDFA // deterministic finite automaton
{
    private:
        struct TbListItem
        {
            TbSeti Set;
            int Q;
            TbListItem *Prev,*Next;
            TbListItem(const TbSeti &Set) { this->Set=Set; Prev=Next=NULL; }
        };
        TbListItem* SearchItem(TbListItem *Item,const TbSeti &Set)const;
        TbListItem* SearchItem(TbListItem *Item,const int &Q)const;
        struct TbG
        {
            int Group;
            int Symbol;
            TbG() { Group=Symbol=0; }
            TbG(const int &Group,const int &Symbol)
            {
                this->Group=Group;
                this->Symbol=Symbol;
            }
            bool operator == (const TbG &G)const
            {
                return Group==G.Group && Symbol==G.Symbol;
            }
            bool operator != (const TbG &G)const
            {
                return Group!=G.Group || Symbol!=G.Symbol;
            }
            bool operator > (const TbG &G)const
            {
                return (Group>G.Group)?(true):((Group==G.Group)?(Symbol>G.Symbol):(false));
            }
            bool operator < (const TbG &G)const
            {
                return (Group<G.Group)?(true):((Group==G.Group)?(Symbol<G.Symbol):(false));
            }
        };
    private:
        int CountQ, // кількість станів + рядок алфавіту, тобто всього станів CountQ-1
            CountS; // кількість символів алфавіту + стовбець ознака заключності стану(1 -заключний)
        int **Table; // останній рядок матриці визначає символи алфавіту
        int GetNextState(const int &StartQ,const int &CountS,const int *SymbolsIndex)const;
        void MinimizeBase();
    public:
        TbDFA();
        ~TbDFA();
        TbDFA(const TbDFA &DFA);
        TbDFA& operator = (const TbDFA &DFA);
        int GetCountQ()const { return CountQ-1; }
        int GetCountS()const { return CountS-1; }
        int GetCountFinaleState()const;
        int GetSymbolIndex(const int &Symbol)const;
        void CreateNew(const int &CountQ,const int &CountS);
        void Clear();
        void CreateFull(const TbUFA &UFA);
        void CreateFrom(const TbUFA &UFA);
        void Print()const;
        bool isEmpty()const;
        void RemoveUnreachableStates();
        bool isOwn(const char *Expression)const;
        bool isOwnStepByStep(const char *Expression,const int &Action,
            int &currQ,int &currS)const;
        bool isEndQ(const int &iQ)const;
        void DoFullyDefined();
        void DoNotFullyDefined();
        void LoadFromFile(const char *fName);
        void Minimize();
        int GetSymbol(const int &Index)const;
        int GetElement(const int &iQ,const int &iS)const;
        int DistinguishStates(const int &q1,const int &q2,int *Symbols);
            //розрізнити стани, повертає довжину ланцюжка, який розпізнав, або -1
};
//---------------------------------------------------------------------------
TbSeti* CreateQSet(const int &CountQ);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif

