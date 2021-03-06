#include <windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include "winuser.h"
#include "resource.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{

	static TCHAR szAppName[] = TEXT("HelloWin");
	HWND         hwnd;
	MSG          msg;
	WNDCLASS     wndclass;



	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));//使用自定义图标     //(HICON) LoadImage(NULL,TEXT("./11.ico"),IMAGE_ICON,0, 0,LR_DEFAULTCOLOR | LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);


	HBITMAP		back_groud;
	back_groud = (HBITMAP)LoadImage(hInstance, "miao.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	wndclass.hbrBackground = (HBRUSH)(CreatePatternBrush(back_groud));
	// wndclass.hbrBackground = (HBRUSH) GetStockObject (GRAY_BRUSH) ;
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;


	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("Program requires Windows NT!"),
			szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(szAppName, TEXT("一只嗷大喵"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		640, 640,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;


}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC         hdc;
	PAINTSTRUCT ps;
	RECT        rect;


	switch (message)
	{

	case WM_CREATE:
		PlaySound(TEXT("liyuchun.wav"), NULL, SND_FILENAME | SND_ASYNC);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		GetClientRect(hwnd, &rect);

		DrawText(hdc, TEXT("我差不多是一只废猫了"), -1, &rect,
			DT_TOP | DT_CENTER | DT_VCENTER);

		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);



}
