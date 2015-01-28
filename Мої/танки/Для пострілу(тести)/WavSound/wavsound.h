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
    char  FormatSig[4];      // 'fmt ' (обратите внимание
                             //     на завершающий пробел)
    long  FormatChunkSize;   // 16
    short FormatTag;         // WAVE_FORMAT_PCM
    short Channels;          // количество каналов
    long  SampleRate;        // частота выборки
    long  BytesPerSec;       // байт на секунду
    short BlockAlign;        // выравнивание блока выборки
    short BitsPerSample;     // бит в выборке
    char  DataSig[4];        // 'data'
    long  DataSize;          // размер волновых данных
};
struct WAVHEADER
{
// WAV-формат начинается с RIFF-заголовка:
 
// Содержит символы "RIFF" в ASCII кодировке
// (0x52494646 в big-endian представлении)
char chunkId[4];
 
// 36 + subchunk2Size, или более точно:
// 4 + (8 + subchunk1Size) + (8 + subchunk2Size)
// Это оставшийся размер цепочки, начиная с этой позиции.
// Иначе говоря, это размер файла - 8, то есть,
// исключены поля chunkId и chunkSize.
unsigned int chunkSize;
 
// Содержит символы "WAVE"
// (0x57415645 в big-endian представлении)
char format[4];
 
// Формат "WAVE" состоит из двух подцепочек: "fmt " и "data":
// Подцепочка "fmt " описывает формат звуковых данных:
// Содержит символы "fmt "
// (0x666d7420 в big-endian представлении)
char subchunk1Id[4];
 
// 16 для формата PCM.
// Это оставшийся размер подцепочки, начиная с этой позиции.
unsigned int subchunk1Size;
 
// Аудио формат, полный список можно получить здесь [url]http://audiocoding.ru/wav_formats.txt[/url]
// Для PCM = 1 (то есть, Линейное квантование).
// Значения, отличающиеся от 1, обозначают некоторый формат сжатия.
unsigned short int audioFormat;
 
// Количество каналов. Моно = 1, Стерео = 2 и т.д.
unsigned short int numChannels;
 
// Частота дискретизации. 8000 Гц, 44100 Гц и т.д.
unsigned int sampleRate;

// sampleRate * numChannels * bitsPerSample/8
unsigned int byteRate;
 
// numChannels * bitsPerSample/8
// Количество байт для одного сэмпла, включая все каналы.
unsigned short int blockAlign;

// Так называемая "глубиная" или точность звучания. 8 бит, 16 бит и т.д.
unsigned short int bitsPerSample;
 
// Подцепочка "data" содержит аудио-данные и их размер.
 
// Содержит символы "data"
// (0x64617461 в big-endian представлении)
char s[2];
char subchunk2Id[4];
 
// numSamples * numChannels * bitsPerSample/8
// Количество байт в области данных.
unsigned int subchunk2Size;
 
// Далее следуют непосредственно Wav данные.
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
