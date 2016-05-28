#include "windows.h"
#include "conio.h"
#include <iostream>
#include <fstream>


struct snowflake {
	int x;
	int y;
	COLORREF rgb;
};

void drawSnowflake(snowflake& snow) {

}



void MyPoint(HDC &hdc, HWND &hwnd, int density) {

	int width = 800, height = 500;
	//MoveWindow(hwnd, width / 2, 100, width, height, TRUE);


	HBRUSH hBlueBrush, hBlackBrush;
	hBlueBrush = CreateSolidBrush(RGB(68, 147, 235));
	hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBlueBrush);
	Ellipse(hdc, 400, 10, 500, 110);
	SelectObject(hdc, hBlackBrush);
	Ellipse(hdc, 370, 20, 470, 120);

	HFONT hfont, hNewf1;
	hNewf1 = CreateFont(38, 0, 0, 0, 400, 0, 0, 0, 0, 0, 0, 2, 1 | FF_ROMAN, "Segoe Print");
	hfont = (HFONT)SelectObject(hdc, hNewf1);
	SetBkMode(hdc, 0);
	SetTextColor(hdc, RGB(68, 147, 235));
	TCHAR n[50] = TEXT("Hello, world!!");
	TextOut(hdc, 550, 40, n, ARRAYSIZE(n));

	snowflake *snow = new  snowflake[density];
	for (int i = 1; i < density; i++) {
		snow[i].x = rand() % width + 5;
		snow[i].y = rand() % height + 5;
		snow[i].rgb = GetPixel(hdc, snow[i].x, snow[i].y);
	}

	bool exit = false;
	int k = 0;
	while (exit == false) {

		// Cоздаем контекст
		HDC hmemDC = CreateCompatibleDC(hdc);
		// Cоздаем битмап
		HBITMAP hbmpTarget = CreateCompatibleBitmap(hdc,width, height);
		// Выбираем битмап в контекст
		SelectObject(hmemDC, hbmpTarget);
		BitBlt(hmemDC, 0, 0, width, height, hdc, 0, 0, SRCCOPY);

		for (int i = 0; i < density; i++) {
			if (snow[i].y > height) {
				SetPixel(hmemDC, snow[i].x, snow[i].y, snow[i].rgb);
				snow[i].y -= height;
			}
			else {
				SetPixel(hmemDC, snow[i].x, snow[i].y, snow[i].rgb);
				snow[i].y++;
				if (snow[i].x % 2 == 0) {
					snow[i].x -= rand() % 4 + 1;
					if (snow[i].x < 0) {
						snow[i].x += width;
					}
				}
				else {
					snow[i].x += rand() % 2 + 1;
					if (snow[i].x > width) {
						snow[i].x -= width;
					}
				}
			}
		}

		if (GetAsyncKeyState(VK_ESCAPE)) {
			exit = true;
		}
		else if (GetAsyncKeyState(VK_RIGHT)) {
			for (int i = 0; i < density; i++) {
				snow[i].x+=3;
				if (snow[i].x > width) {
					snow[i].x -= width;
				}
			}
		}
		else if (GetAsyncKeyState(VK_LEFT)) {
			for (int i = 0; i < density; i++) {
				snow[i].x-=3;
				if (snow[i].x < 0) {
					snow[i].x += width;
				}
			}
		}


		for (int i = 0; i < density; i++) {
				snow[i].rgb = GetPixel(hmemDC, snow[i].x, snow[i].y);
		}
		
		
		for (int i = 0; i < density; i++) {
			if (snow[i].y > height) {
				SetPixel(hmemDC, snow[i].x, snow[i].y, RGB(255, 255, 255));		
			} else {
				SetPixel(hmemDC, snow[i].x, snow[i].y, RGB(255, 255, 255));
			}
		}

				
		BitBlt(hdc, 0, 0, width, height, hmemDC, 0, 0, SRCCOPY);
		// свобождаем контекст
		DeleteDC(hmemDC); // контекст отжирает уйму ресурсов, поэтому не забудем его грохнуть
		hmemDC = NULL;
		Sleep(33);
	}
}



int main()

{

	std::ifstream in;
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	int density = 1000;
	in.open("C:\\1\\1.txt");
	in >> density;
	MyPoint(hdc, hwnd, density);
	_getch();
	return 0;

}

