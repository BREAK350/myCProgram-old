/*
    Connect dsound.lib
*/
//---------------------------------------------------------------------------
#ifndef wavsoundH
#define wavsoundH
#include <dsound.h>
#include <mmsystem.h>
#include <stdio.h>
//---------------------------------------------------------------------------
struct sWaveHeader
{
    char  RiffSig[4];        // 'RIFF'
    long  WaveformChunkSize; // 8
    char  WaveSig[4];        // 'WAVE'
    char  FormatSig[4];      // 'fmt ' (�������� ��������
                             //     �� ����������� ������)
    long  FormatChunkSize;   // 16
    short FormatTag;         // WAVE_FORMAT_PCM
    short Channels;          // ���������� �������
    long  SampleRate;        // ������� �������
    long  BytesPerSec;       // ���� �� �������
    short BlockAlign;        // ������������ ����� �������
    short BitsPerSample;     // ��� � �������
    char  DataSig[4];        // 'data'
    long  DataSize;          // ������ �������� ������
};
struct WAVHEADER
{
// WAV-������ ���������� � RIFF-���������:
 
// �������� ������� "RIFF" � ASCII ���������
// (0x52494646 � big-endian �������������)
char chunkId[4];
 
// 36 + subchunk2Size, ��� ����� �����:
// 4 + (8 + subchunk1Size) + (8 + subchunk2Size)
// ��� ���������� ������ �������, ������� � ���� �������.
// ����� ������, ��� ������ ����� - 8, �� ����,
// ��������� ���� chunkId � chunkSize.
unsigned int chunkSize;
 
// �������� ������� "WAVE"
// (0x57415645 � big-endian �������������)
char format[4];
 
// ������ "WAVE" ������� �� ���� ����������: "fmt " � "data":
// ���������� "fmt " ��������� ������ �������� ������:
// �������� ������� "fmt "
// (0x666d7420 � big-endian �������������)
char subchunk1Id[4];
 
// 16 ��� ������� PCM.
// ��� ���������� ������ ����������, ������� � ���� �������.
unsigned int subchunk1Size;
 
// ����� ������, ������ ������ ����� �������� ����� [url]http://audiocoding.ru/wav_formats.txt[/url]
// ��� PCM = 1 (�� ����, �������� �����������).
// ��������, ������������ �� 1, ���������� ��������� ������ ������.
unsigned short int audioFormat;
 
// ���������� �������. ���� = 1, ������ = 2 � �.�.
unsigned short int numChannels;
 
// ������� �������������. 8000 ��, 44100 �� � �.�.
unsigned int sampleRate;

// sampleRate * numChannels * bitsPerSample/8
unsigned int byteRate;
 
// numChannels * bitsPerSample/8
// ���������� ���� ��� ������ ������, ������� ��� ������.
unsigned short int blockAlign;

// ��� ���������� "��������" ��� �������� ��������. 8 ���, 16 ��� � �.�.
unsigned short int bitsPerSample;
 
// ���������� "data" �������� �����-������ � �� ������.
 
// �������� ������� "data"
// (0x64617461 � big-endian �������������)
char s[2];
char subchunk2Id[4];
 
// numSamples * numChannels * bitsPerSample/8
// ���������� ���� � ������� ������.
unsigned int subchunk2Size;
 
// ����� ������� ��������������� Wav ������.
};
//---------------------------------------------------------------------------
bool bDirectSoundCreate8(IDirectSound *&g_pDS);
IDirectSoundBuffer* CreateBufferFromWAV(FILE *fp,WAVHEADER *Hdr,
                                        IDirectSound *g_pDS);
BOOL LoadSoundData(IDirectSoundBuffer *pDSBuffer,
                   long LockPos, FILE *fp, long Size);
IDirectSoundBuffer *LoadWAV(char *Filename,IDirectSound *g_pDS);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
