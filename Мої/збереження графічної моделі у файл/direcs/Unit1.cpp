#include <windows.h>
#include <tchar.h>
#include "math.h"

#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib, "d3d9.lib")
#include "d3dx9core.h"
#include "d3d9.h"
 
// ����� � ��� ������� ���������
struct Vertex
{
    D3DXVECTOR3 Pos;    // ����� �������
    DWORD Color;        // � ����
    static const DWORD FVF =
            D3DFVF_XYZ      // ������� � ��� ��� ���� ������� � ���������
        |   D3DFVF_DIFFUSE; // ������� � ��� ��� ���� ���� � ���������
};
 
int APIENTRY _tWinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPTSTR lpCmdLine, int nCmdShow)
{
    // ������ ������
    int Width = 1024, Height = 768;
    // ������ ��������� ( LandscapeSize � LandscapeSize )
    size_t LandscapeSize = 256;
 
    // ******** ������ ������������� ���� ******** //
    HWND hWnd; WNDCLASSEX wcex;
    
    wcex.cbSize = sizeof(WNDCLASSEX);   wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = DefWindowProc;    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_WAIT));
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCE(IDC_WAIT);
    wcex.lpszClassName  = "wcex";
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDC_WAIT));
    RegisterClassEx(&wcex);
    hWnd = CreateWindow(wcex.lpszClassName, lpCmdLine, WS_VISIBLE,
    CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
    // ******** ����� ������������� ���� ******** //
    ShowWindow(hWnd, nCmdShow); // ���������� ��� �������
 
    // ******** ������ ������������� DirectX ******** //
    IDirect3D9* D3D; IDirect3DDevice9* Device;
    D3D = Direct3DCreate9(D3D_SDK_VERSION);
 
    D3DPRESENT_PARAMETERS d3pp;
    memset(&d3pp, 0, sizeof d3pp);
    d3pp.Windowed = true;
    d3pp.EnableAutoDepthStencil = TRUE;
    d3pp.AutoDepthStencilFormat = D3DFMT_D24X8;
 
    D3DDISPLAYMODE d3ddm; memset(&d3ddm, 0, sizeof(d3ddm));
    D3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm);
    d3pp.SwapEffect = D3DSWAPEFFECT_DISCARD;    d3pp.BackBufferFormat = d3ddm.Format;
    d3pp.BackBufferWidth = Width;               d3pp.BackBufferHeight = Height;
 
 
    D3D->CreateDevice(  D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
                        D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3pp, &Device);
    // ******** ����� ������������� DirectX ******** //
 
 
 
    // �������� ������ ������
    IDirect3DVertexBuffer9* VBuf;
    Device->CreateVertexBuffer( 
            sizeof(Vertex) * LandscapeSize * LandscapeSize,
            0,
            Vertex::FVF,
            D3DPOOL_DEFAULT,
            &VBuf, NULL);
 
    // ���������� ������ ������
    Vertex* VData = NULL;
    VBuf->Lock(0, 0, (void**)&VData, 0);
        for (size_t i = 0; i < LandscapeSize; ++i)
            for (size_t j = 0; j < LandscapeSize; ++j)
            {
                // ������ ������� ��������������� ���������� �� ������
                // ((i - 128)^2 + (j - 128)^2)^0.5
                float dist = pow(
                                pow((i - (LandscapeSize / 2.0f)), 2.0f) + 
                                pow((j - (LandscapeSize / 2.0f)), 2.0f),
                        0.5f);
                VData->Pos.y = abs(sin( dist / 3.14f ) - log( dist * 1.0f ));
                VData->Pos.x = (float)i;
                VData->Pos.z = (float)j;
                VData->Color = D3DCOLOR_XRGB(80, 80, (DWORD)(VData->Pos.y * 40.0f));
 
                VData++;
            }
    VBuf->Unlock();
 
    // �������� ���������� ������
    IDirect3DIndexBuffer9*  IBuf;
    Device->CreateIndexBuffer( 
            sizeof(short) * 2 * ( LandscapeSize - 1 ) * ( LandscapeSize - 1 ) * 3, 
            0, 
            D3DFMT_INDEX16,
            D3DPOOL_DEFAULT,
            &IBuf,
            NULL);
 
    // ������ ��������
    unsigned short* index = NULL; size_t idx = 0;
    IBuf->Lock(0, 0, (void**)&index, 0);
        for (size_t x = 0; x < LandscapeSize - 1; x++)
            for (size_t y = 0; y < LandscapeSize - 1; y++)
            {      
                index[idx++] = y * LandscapeSize + x;
                index[idx++] = (y + 1) * LandscapeSize + x;
                index[idx++] = (y + 1) * LandscapeSize + x + 1;
                index[idx++] = y * LandscapeSize + x;
                index[idx++] = (y + 1) * LandscapeSize + x + 1;
                index[idx++] = y * LandscapeSize + x + 1;
            }
    IBuf->Unlock();
 
    // ������� � ������������� ������� ����, �������������� ���� �����
    // � ����������� ��������� � ����������� 3D ����
    D3DXMATRIX mView;
    D3DXVECTOR3 LookAt  = D3DXVECTOR3(128.0f, 20.0f, 128.0f);
    D3DXVECTOR3 Eye     = D3DXVECTOR3(-50.0f, 500.0f, -0.0f);
    D3DXVECTOR3 Up      = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
    D3DXMatrixLookAtLH(&mView,      &Eye,       &LookAt,        &Up);
    Device->SetTransform(D3DTS_VIEW, &mView);
 
    // ������� � ������������� ������� ��������
    D3DXMATRIX mProjection; 
    D3DXMatrixPerspectiveFovLH(
        &mProjection,       // ���������� �������� ������� ��������
        D3DX_PI / 4,        // ���� ������ � ����������� ��� Y � ��������
        (Width / Height),   // ����������� ������ ������
        1.0f,               // �������� ���� ��������� �����
        1000.0f             // ������ ���� ��������� �����
    );
    Device->SetTransform(D3DTS_PROJECTION, &mProjection);
 
    Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW);
    Device->SetRenderState(D3DRS_LIGHTING, FALSE);
    Device->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
    Device->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
    Device->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
 
 
    // �������� ���������� � ��� ��� ����� �������� ������� �� VBuf
    Device->SetStreamSource(0, VBuf, 0, sizeof Vertex); 
    Device->SetIndices(IBuf);       // ���������� � ��������� �������
    Device->SetFVF(Vertex::FVF);    // � ����� ��� ������ ����� ��������������
 
 
    ShowCursor(FALSE);
    DWORD Time = GetTickCount();
    float fi = 0.0f;    // ���������� ��� ��������� ������� ������
    while (! GetAsyncKeyState(VK_ESCAPE))   // ���� �� ����� Escape
    {
        fi += 0.001f * (GetTickCount() - Time); // �������� ����
        Time = GetTickCount();                  // ����� �����
        Eye.x = 100.0f * sin(fi);               // �������� ������� ������
        Eye.y = 300.0f + 300.0f * sin(fi);
        D3DXMatrixLookAtLH(&mView, &Eye, &LookAt, &Up); // ���������� ������� ���������
        Device->SetTransform(D3DTS_VIEW, &mView);       // ���������������
 
        // ������� �����
        Device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(255,255,255), 1.0f, 0);
 
        Device->BeginScene();
            Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, LandscapeSize * LandscapeSize, 0, 2 * ( LandscapeSize - 1 ) * ( LandscapeSize - 1 ));
        Device->EndScene();
 
        Device->Present(NULL, NULL, NULL, NULL);
    }
 
    // ����������� ���������� �������
    IBuf->Release();
    VBuf->Release();
    Device->Release();
    D3D->Release();
return 0;
}
