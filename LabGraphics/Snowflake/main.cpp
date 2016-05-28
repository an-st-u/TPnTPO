#include "windows.h"
#include "conio.h"
#include <iostream>
#include <fstream>


struct snowflake {
	int x;
	int y;
	COLORREF rgb;
};

void drawBackground(HDC &hdc) {

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
	DeleteObject(hBlueBrush);
	DeleteObject(hBlackBrush);
	DeleteObject(hfont);
	DeleteObject(hNewf1);
}

bool snowMove(snowflake snow[], int height, int width, int density) {

	//Генерируем движение 
	for (int i = 0; i < density; i++) {
		//Сверху вниз
		if (snow[i].y > height) {
			snow[i].y -= height;
		} else {
			snow[i].y++;
		}

		//Слева направо (ветер)
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

	//Снимаем клавиши
	if (GetAsyncKeyState(VK_ESCAPE)) {
		return true;
	}
	else if (GetAsyncKeyState(VK_RIGHT)) {
		for (int i = 0; i < density; i++) {
			snow[i].x += 3;
			if (snow[i].x > width) {
				snow[i].x -= width;
			}
		}
	}
	else if (GetAsyncKeyState(VK_LEFT)) {
		for (int i = 0; i < density; i++) {
			snow[i].x -= 3;
			if (snow[i].x < 0) {
				snow[i].x += width;
			}
		}
	}
	return false;
}


void MyPoint(HDC &hdc, HWND &hwnd, int density) {

	int width = 800, height = 500;
	drawBackground(hdc);

	//Генериреум массив снежинок
	snowflake *snow = new  snowflake[density];
	for (int i = 1; i < density; i++) {
		snow[i].x = rand() % width + 5;
		snow[i].y = rand() % height + 5;
		snow[i].rgb = GetPixel(hdc, snow[i].x, snow[i].y);
	}

	bool exit = false;

	while (exit == false) {

		// Cоздаем контекст
		HDC hmemDC = CreateCompatibleDC(hdc);
		// Cоздаем битмап
		HBITMAP hbmpTarget = CreateCompatibleBitmap(hdc,width, height);
		// Выбираем битмап в контекст
		SelectObject(hmemDC, hbmpTarget);
		//Записывает наш bmb в память
		BitBlt(hmemDC, 0, 0, width, height, hdc, 0, 0, SRCCOPY);

		//Очистить экран
		for (int i = 0; i < density; i++) {
				SetPixel(hmemDC, snow[i].x, snow[i].y, snow[i].rgb);
		}

		//Выполнить перемещения
		exit = snowMove(snow, height, width, density);

		//Сфотографировать фон
		for (int i = 0; i < density; i++) {
				snow[i].rgb = GetPixel(hmemDC, snow[i].x, snow[i].y);
		}
		
		//Нарисовать пиксели
		for (int i = 0; i < density; i++) {
				SetPixel(hmemDC, snow[i].x, snow[i].y, RGB(255, 255, 255));		
		}
		
		//Выводим наш bmb на экран
		BitBlt(hdc, 0, 0, width, height, hmemDC, 0, 0, SRCCOPY);
		// освобождаем контекст
		DeleteDC(hmemDC); // контекст отжирает уйму ресурсов, поэтому не забудем его грохнуть
		hmemDC = NULL;
		Sleep(33);
	}
}

int main() {

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

