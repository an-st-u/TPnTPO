#define BN 2000
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <string.h>
#include <iostream>

double Rate(int n, int width, int height) {
	int all = width * height;
	double k = n * 100 / (double)all;
	return round(k * 100)/100;
};

int randColor() {
	return 1 + rand() % 255;
}

void PText(HDC &hdc, double count) {

	static char str[40];
	SetTextColor(hdc, RGB(0, 0, 0));
	TextOut(hdc, 70, 510, str, ARRAYSIZE(str));
	HFONT hfont, myfont;//шрифт
	myfont = CreateFont(38, 0, 0, 0, 700, 0, 0, 0, 0, OUT_DEFAULT_PRECIS, 0, DRAFT_QUALITY, FIXED_PITCH | FF_ROMAN, "Algerian");//создаем шрифт
	hfont = (HFONT)SelectObject(hdc, myfont);
	SetTextColor(hdc, RGB(255, 0, 0));//задаем цвет текста
	SetBkMode(hdc, 0);//фон закрашивается текущим цветом фона	
	sprintf_s(str,"The rate of star's fill is %.2f %%", count);
	HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBlackBrush);
	Rectangle(hdc, 70, 510, 800, 550);
	TextOut(hdc, 70, 510, str, ARRAYSIZE(str));
	DeleteObject(hfont);
	DeleteObject(myfont);
	DeleteObject(hBlackBrush);

}

int Paint(HDC &hdc, int width, int height) {

	int x[BN], y[BN];
	bool stop = false;
	int n = 0;
	while (stop == false) {

		if (GetAsyncKeyState(VK_ESCAPE)) {
			_getch();
			stop = true;
		}

		// Cоздаем контекст
		HDC hmemDC = CreateCompatibleDC(hdc);
		// Cоздаем битмап
		HBITMAP hbmpTarget = CreateCompatibleBitmap(hdc, width, height);
		// Выбираем битмап в контекст
		::SelectObject(hmemDC, hbmpTarget);
		//Записывает наш bmb в память
		BitBlt(hmemDC, 0, 0, width, height, hdc, 0, 0, SRCCOPY);

		for (int i = 0; i<BN; i++) {
			x[i] = rand() % width;
			y[i] = rand() % height;

			if (GetPixel(hmemDC, x[i], y[i]) == RGB(0, 0, 0)) {
				SetPixel(hdc, x[i], y[i], RGB(randColor(), randColor(), randColor()));
				n++;
			}
			else {
				SetPixel(hdc, x[i], y[i], RGB(0, 0, 0));
				n--;
			}
		}

		PText(hdc, Rate(n, width, height));
		DeleteDC(hmemDC); // контекст отжирает уйму ресурсов, поэтому не забудем его грохнуть
		DeleteObject(hbmpTarget);
		hmemDC = NULL;
		Sleep(12);
	}
	return n;
};


int main()
{

	//hwnd - дескриптор окна, в котором будем рисовать
	HWND hwnd = GetConsoleWindow();//получение консольного окна
								   //hdc - дескриптор контекста устройства
	HDC hdc = GetDC(hwnd); //получаем дискриптор,свзянный с окном, в котором будем рисовать

	if (hdc) {
		int width = 800, height = 500;
		int n = Paint(hdc, width, height);//вызываем функцию рисования звезд
		double count = Rate(n, width, height);// количество звезд
		PText(hdc, count);
		ReleaseDC(hwnd, hdc); //освобождаем контекст
	}

	_getch();
	return 0;
}
