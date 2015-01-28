//---------------------------------------------------------------------------
#pragma hdrstop
#include "wavsound.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
bool bDirectSoundCreate8(IDirectSound *g_pDS)
{
    return FAILED(DirectSoundCreate(NULL, &g_pDS, NULL));
}
//---------------------------------------------------------------------------
IDirectSoundBuffer* CreateBufferFromWAV(FILE *fp,WAVHEADER *Hdr,IDirectSound *g_pDS)
{
    IDirectSoundBuffer  *pDSB;
    IDirectSoundBuffer *pDSBuffer;
    DSBUFFERDESC        dsbd;
    WAVEFORMATEX        wfex;

    // ������ ��������� � ������ �����
    fseek(fp, 0, SEEK_SET);
    fread(Hdr, 1, sizeof(WAVHEADER), fp);

    // ��������� ���� ��������,
    // ������������ � ������ ������
    if(memcmp(Hdr->chunkId, "RIFF", 4) ||
       memcmp(Hdr->format, "WAVE", 4) ||
       memcmp(Hdr->subchunk1Id, "fmt ", 4) ||
       memcmp(Hdr->subchunk2Id, "data", 4))
        return NULL;

    // ������������� ������ ���������������
    ZeroMemory(&wfex, sizeof(WAVEFORMATEX));
    wfex.wFormatTag      = WAVE_FORMAT_PCM;
    wfex.nChannels       = Hdr->numChannels;
    wfex.nSamplesPerSec  = Hdr->sampleRate;
    wfex.wBitsPerSample  = Hdr->bitsPerSample;
    wfex.nBlockAlign     = wfex.wBitsPerSample / 8 * wfex.nChannels;
    wfex.nAvgBytesPerSec = wfex.nSamplesPerSec * wfex.nBlockAlign;

    // ������� �������� �����, ��������� ������ ���������
    ZeroMemory(&dsbd, sizeof(DSBUFFERDESC));
    dsbd.dwSize = sizeof(DSBUFFERDESC);
    dsbd.dwFlags = DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLPAN |
                 DSBCAPS_CTRLFREQUENCY;
    dsbd.dwBufferBytes = Hdr->subchunk2Size;
    dsbd.lpwfxFormat = &wfex;
    if(FAILED(g_pDS->CreateSoundBuffer(&dsbd, &pDSB, NULL)))
        return NULL;

    // �������� ����� ������ ����������
    if(FAILED(pDSB->QueryInterface(IID_IDirectSoundBuffer,(void**)&pDSBuffer)))
    {
        pDSB->Release();
        return NULL;
    }

    // ���������� ���������
    return pDSBuffer;
}
//---------------------------------------------------------------------------
BOOL LoadSoundData(IDirectSoundBuffer *pDSBuffer,
                   long LockPos, FILE *fp, long Size)
{
    BYTE  *Ptr1, *Ptr2;
    DWORD Size1, Size2;

    if(!Size)
        return FALSE;

    // ��������� �������� ����� � �������� �������
    if(FAILED(pDSBuffer->Lock(LockPos, Size,
                             (void**)&Ptr1, &Size1,
                             (void**)&Ptr2, &Size2, 0)))
        return FALSE;

    // ������ ������
    fread(Ptr1, 1, Size1, fp);
    if(Ptr2 != NULL)
        fread(Ptr2, 1, Size2, fp);

    // ������������ �����
    pDSBuffer->Unlock(Ptr1, Size1, Ptr2, Size2);
    // ���������� ���� ������
    return TRUE;
}
//---------------------------------------------------------------------------
IDirectSoundBuffer* LoadWAV(char *Filename,IDirectSound *g_pDS)
{
    IDirectSoundBuffer *pDSBuffer;
    WAVHEADER Hdr;
    FILE *fp;

    // ��������� �������� ����
    if((fp=fopen(Filename, "rb"))==NULL)
        return NULL;

    // ������� �������� �����
    if((pDSBuffer = CreateBufferFromWAV(fp, &Hdr, g_pDS)) == NULL)
    {
        fclose(fp);
        return NULL;
    }

    // ������ ������
    fseek(fp, sizeof(WAVHEADER), SEEK_SET);
    LoadSoundData(pDSBuffer, 0, fp, Hdr.subchunk2Size);

    // ��������� �������� ����
    fclose(fp);
    // ���������� ����� �������� ����� �
    // ���������� � ���� ������
    return pDSBuffer;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
