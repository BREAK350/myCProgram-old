/*

	d3dx9tex.h - Header file for the Direct3D9 Utility API

	Written by Filip Navara <xnavara@volny.cz>

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

*/

#ifndef _D3DX9TEX_H
#define _D3DX9TEX_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#define D3DX_FILTER_NONE	1
#define D3DX_FILTER_POINT	2
#define D3DX_FILTER_LINEAR	3
#define D3DX_FILTER_TRIANGLE	4
#define D3DX_FILTER_BOX	5
#define D3DX_FILTER_MIRROR_U	0x10000
#define D3DX_FILTER_MIRROR_V	0x20000
#define D3DX_FILTER_MIRROR	0x30000
#define D3DX_FILTER_DITHER	0x80000

typedef enum _D3DXIMAGE_FILEFORMAT
{
	D3DXIFF_BMP = 0,
	D3DXIFF_JPG = 1,
	D3DXIFF_TGA = 2,
	D3DXIFF_PNG = 3,
	D3DXIFF_DDS = 4,
	D3DXIFF_PPM = 5,
	D3DXIFF_DIB = 6,
	D3DXIFF_FORCE_DWORD = 0x7fffffff
} D3DXIMAGE_FILEFORMAT;

typedef struct _D3DXIMAGE_INFO {
	UINT Width;
	UINT Height;
	UINT Depth;
	UINT MipLevels;
	D3DFORMAT Format;
	D3DRESOURCETYPE ResourceType;
	D3DXIMAGE_FILEFORMAT ImageFileFormat;
} D3DXIMAGE_INFO;

#ifdef __cplusplus
extern "C"
{
#endif

HRESULT WINAPI D3DXCreateTextureFromFileExA(LPDIRECT3DDEVICE9,LPCSTR,UINT,UINT,UINT,DWORD,D3DFORMAT,D3DPOOL,DWORD,DWORD,D3DCOLOR,D3DXIMAGE_INFO*,PALETTEENTRY*,LPDIRECT3DTEXTURE9*);
HRESULT WINAPI D3DXCreateTextureFromFileExW(LPDIRECT3DDEVICE9,LPCWSTR,UINT,UINT,UINT,DWORD,D3DFORMAT,D3DPOOL,DWORD,DWORD,D3DCOLOR,D3DXIMAGE_INFO*,PALETTEENTRY*,LPDIRECT3DTEXTURE9*);

#ifdef __cplusplus
};
#endif

#ifdef UNICODE
#define D3DXCreateTextureFromFileEx D3DXCreateTextureFromFileExW
#else
#define D3DXCreateTextureFromFileEx D3DXCreateTextureFromFileExA
#endif

#endif
