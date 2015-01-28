//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <alloc.h>
#include <stdio.h>
#include <stdlib.h>
#define fn "Question.txt"
#define fnN "QuestionK.txt"
#define rozd '.'
#define Question Form1->Panel4->Caption
#define Answer1 Form1->Button6->Caption
#define Answer2 Form1->Button7->Caption
#define Answer3 Form1->Button8->Caption
#define Answer4 Form1->Button9->Caption
//---------------------------------------------------------------------------
struct TQ {
 char *question,
      *answer[4];
          };
//---------------------------------------------------------------------------
int LoadQuestion(TQ*&);
void ShowQuestion(TQ*,int);
void RandomIndex(int*&,int);
void Cl(TQ*&,int*&,int);
//---------------------------------------------------------------------------
#endif
 