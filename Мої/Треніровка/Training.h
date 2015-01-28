//---------------------------------------------------------------------------
#ifndef TrainingH
#define TrainingH
#include <iostream.h>
//---------------------------------------------------------------------------
class T_Training;
//---------------------------------------------------------------------------
class T_TrainingElement
{
    protected:
        int SizeName;
        char *Name;
        int AllAmount,
            MaxAmount,
            AmountDay;
        void SaveToFile(FILE *);
        void LoadFromFile(FILE *);
    public:
        T_TrainingElement();
        T_TrainingElement(const T_TrainingElement &);
        ~T_TrainingElement();
        T_TrainingElement& operator = (const T_TrainingElement &);
        void GiveName(char *name){Name=strdup(name);}
        friend ostream& operator << (ostream &,T_TrainingElement &);
        friend T_Training;
};
//---------------------------------------------------------------------------
class T_Training
{
    protected:
        int Amount;
        T_TrainingElement *Element;
        void SaveToFile(FILE *);
        void LoadFromFile(FILE *);
        int SearchNumber(char *);
    public:
        T_Training();
        T_Training(const T_Training &);
        ~T_Training();
        void AddElement(char *);
        void DeleteElement(int);
        void DeleteElement(char *);
        void DoTraining(int,int);
        T_TrainingElement operator [] (int);
        int GetAmount(){return Amount;}
        void SaveToFile(char *);
        bool LoadFromFile(char *);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
