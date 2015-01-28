//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "wavsound.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Test *t;
//---------------------------------------------------------------------------
HRESULT OnBufferLost(LPDIRECTSOUNDBUFFER lpDSBuffer, float flFreq )
{
    HRESULT hRes;
    PUCHAR pLockBuf;
    DWORD dwBufSize;
    WAVEFORMATEX waveFmt;
    do
        hRes = lpDSBuffer->Restore();
    while (hRes == DSERR_BUFFERLOST);
    if ( FAILED( hRes ) )
        return hRes;
    if ( FAILED( hRes =lpDSBuffer->Lock(0, 0, (LPVOID*)&pLockBuf, &dwBufSize, NULL, 0,
        DSBLOCK_ENTIREBUFFER ) ))
        return hRes;
    if ( FAILED( hRes =
        lpDSBuffer->GetFormat(&waveFmt, sizeof(waveFmt), NULL )) )
        return hRes;
    for (int i = 0; i < dwBufSize; ++i)
    {
        pLockBuf[i] = (UCHAR)
            (64.0 * (1.0 + cos(2.0*3.1416*i*flFreq/waveFmt.nSamplesPerSec) ) );
    }
    return lpDSBuffer->Unlock( (LPVOID)pLockBuf, dwBufSize, NULL, 0);
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    hRes=DirectSoundCreate(NULL, &pDSound, NULL);
    hRes=pDSound->SetCooperativeLevel(this->Handle,DSSCL_NORMAL);

    WAVEFORMATEX waveFmt;
    waveFmt.wFormatTag = WAVE_FORMAT_PCM;
    waveFmt.nChannels = 1;
    waveFmt.nSamplesPerSec = 8000;
    waveFmt.wBitsPerSample = 8;
    waveFmt.nBlockAlign = (WORD)(waveFmt.wBitsPerSample * waveFmt.nChannels / 8);
    waveFmt.nAvgBytesPerSec = waveFmt.nSamplesPerSec * waveFmt.nBlockAlign;
    waveFmt.cbSize = 0;

    DSBUFFERDESC dsBufDesc;
    ZeroMemory(&dsBufDesc, sizeof(dsBufDesc) );
    dsBufDesc.dwSize = sizeof(dsBufDesc);
    dsBufDesc.dwFlags = DSBCAPS_CTRLPOSITIONNOTIFY;
    dsBufDesc.dwBufferBytes = waveFmt.nAvgBytesPerSec * 4;
    dsBufDesc.dwReserved = 0;
    dsBufDesc.lpwfxFormat = &waveFmt;

    /*pDSound->CreateSoundBuffer(&dsBufDesc, &pDsBuffer, NULL);

    hRes=OnBufferLost(pDsBuffer, 440.0);

    LPDIRECTSOUNDNOTIFY lpDsNotify;
    DSBPOSITIONNOTIFY PositionNotify;

    //Требуем нужный нам интерфейс IDirectSoundNotify
    hRes = pDsBuffer->QueryInterface(IID_IDirectSoundNotify,
        (LPVOID*)&lpDsNotify);

    PositionNotify.dwOffset = DSBPN_OFFSETSTOP;
    PositionNotify.hEventNotify = CreateEvent(NULL, FALSE, FALSE, NULL);
    hRes = lpDsNotify->SetNotificationPositions(1, &PositionNotify);
    lpDsNotify->Release();
    */
    //while (pDsBuffer->Play(0, 0, 0 ) == DSERR_BUFFERLOST)
    //    OnBufferLost(pDsBuffer, 440.0);
    pDsBuffer=LoadWAV("awp1.wav",pDSound);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    /*while (pDsBuffer->Play(0, 0, 0 ) == DSERR_BUFFERLOST)
    {
        OnBufferLost(pDsBuffer, 440.0);
    }*/
    pDsBuffer->Play(0, 0, 0 );
}
//---------------------------------------------------------------------------

