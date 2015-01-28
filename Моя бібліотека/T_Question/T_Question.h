//---------------------------------------------------------------------------
#ifndef T_QuestionH
#define T_QuestionH
#include <vcl.h>
#include <iostream.h>
#include <fstream.h>
//---------------------------------------------------------------------------
class T_Question
{
    private:
        char *Question,
             **Variant,
             *CorrectAnswers;
    public:
        T_Question();
        T_Question(const T_Question &Q);
        ~T_Question();
        T_Question(const char *Q,char **V,const char *CA);
        int GetN()const { return (CorrectAnswers)?(strlen(CorrectAnswers)):(0); }
        int GetNCorrectAnswers()const;
        void Delete();
        void Create(const char *Q,char **V,const char *CA);
        float CheckAnswer(const char *CA);
        void SaveToFile(FILE *f);
        void LoadFromFile(FILE *f);
        void SaveToFile(ofstream &ofs);
        void LoadFromFile(ifstream &ifs);
};
//---------------------------------------------------------------------------
void DoCorect(char *s);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 