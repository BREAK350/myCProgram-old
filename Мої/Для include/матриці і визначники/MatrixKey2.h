//---------------------------------------------------------------------------

#ifndef MatrixKey2H
#define MatrixKey2H
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------
struct TKey {
    float **e;
    int n;
            };
struct TMatrix {
    float **e;
    int n;
    int m;
               };
//---------------------------------------------------------------------------
float KeyRez(TKey);
void ScanKey(TKey&);
void MemoryAllocation(TKey&);
void PrintKey(TKey);
void DiagonalKey(TKey&);
void KeyToKey(TKey,TKey&);
//---------------------------------------------------------------------------
void ScanMatrix(TMatrix&);
void PrintMatrix(TMatrix);
void MemoryAllocation(TMatrix&);
void MemoryAllocation(TMatrix&,int,int);
void ScanMatrix(TMatrix&);
TMatrix SummaMatrix(TMatrix,TMatrix);
TMatrix DobytokMatrix(TMatrix,TMatrix);
TMatrix Transpon(TMatrix);
void DiagonalMatrix(TMatrix&);
TMatrix NumberToMatrix(float,TMatrix);
//---------------------------------------------------------------------------
TKey MatrixToKey(TMatrix);
TKey MinorMatrix(TMatrix,int,int);

