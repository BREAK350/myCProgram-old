//---------------------------------------------------------------------------
#ifndef LanguagesH
#define LanguagesH
#include <vcl.h>
//---------------------------------------------------------------------------
const char EnglishSymbol[2][33] = {
    {
        'q','w','e','r','t','y','u','i','o','p','[',']',
        'a','s','d','f','g','h','j','k','l',';','\'',
        'z','x','c','v','b','n','m',',','.','/'
    },
    {
        'Q','W','E','R','T','Y','U','I','O','P','{','}',
        'A','S','D','F','G','H','J','K','L',':','"',
        'Z','X','C','V','B','N','M','<','>','?'
    }
};
//---------------------------------------------------------------------------
const char UkrainianSymbol[2][33] = {
    {
        '�','�','�','�','�','�','�','�','�','�','�','�',
        '�','�','�','�','�','�','�','�','�','�','�',
        '�','�','�','�','�','�','�','�','�','.',
    },
    {
        '�','�','�','�','�','�','�','�','�','�','�','�',
        '�','�','�','�','�','�','�','�','�','�','�',
        '�','�','�','�','�','�','�','�','�',','
    }
};
//---------------------------------------------------------------------------
const TPoint KeyCoordinate[33] = {
    TPoint( 77, 52),TPoint(128, 52),TPoint(179, 52),
    TPoint(230, 52),TPoint(281, 52),TPoint(332, 52),
    TPoint(383, 52),TPoint(434, 52),TPoint(485, 52),
    TPoint(536, 52),TPoint(587, 52),TPoint(638, 52),
    TPoint( 89,103),TPoint(140,103),TPoint(191,103),
    TPoint(242,103),TPoint(293,103),TPoint(344,103),
    TPoint(395,103),TPoint(446,103),TPoint(497,103),
    TPoint(548,103),TPoint(599,103),TPoint(102,154),
    TPoint(153,154),TPoint(204,154),TPoint(255,154),
    TPoint(306,154),TPoint(357,154),TPoint(408,154),
    TPoint(459,154),TPoint(510,154),TPoint(561,154)
};
//---------------------------------------------------------------------------
/*
    ������� ��� ���������� ����, �� ���������� ��� ��������� �������.
    ������ ������� �����  - ������� �����, ��� - ������� � ��������� �����
    �������. ����� 5 ����� ���������� ��� ����, 5 ��������� - �����.
    ��� ����� ���� - ��� ���������� �� ������ �� �������� ������, ���,
    ���������, ������� �� ����� 0, � �������  - 4.
*/
const int Finger[10][8] = {
    {2,0,12},                // ��� ����   �������
    {3,1,13,23},             // ��� ����   ���������
    {3,2,14,24},             // ��� ����   ��������
    {7,3,4,15,16,25,26,27},  // ��� ����   ��������
    {0},                     // ��� ����   �������
    {6,9,10,11,21,22,32},    // ����� ����  �������
    {3,8,20,31},             // ����� ����  ���������
    {3,7,19,30},             // ����� ����  ��������
    {6,5,6,17,18,28,29},     // ����� ����  ��������
    {0}                      // ����� ����  �������
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
