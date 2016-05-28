#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <string.h>
#include <iostream>
#define ESC 27 //для выхода по кнопке esc

int Paint(HDC &hdc)
{
	int x, y, rс, gс, bс;
	bool stop = false;
	int n = 0;
	while (stop == false) {
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			stop = true;
		}
		x = rand() % 800;
		y = rand() % 500;
		rс = 1 + rand() % 256;
		gс = 1 + rand() % 256;
		bс = 1 + rand() % 256;
		if (GetPixel(hdc, x, y) == RGB(0, 0, 0)) 
		{
			SetPixel(hdc, x, y, RGB(rс, gс, bс));
			n++;
		}
		else
		{
			SetPixel(hdc, x, y, RGB(0, 0, 0));
			n--;
		}
	}
	return n;
};

double Rate(int n){

	long int all = 800 * 500;
	double k =n * 200 / (double)all;
	return k;
};

int main()
{  
	
	//hwnd - дескриптор окна, в котором будем рисовать
	HWND hwnd = GetConsoleWindow();//получение консольного окна
								   //hdc - дескриптор контекста устройства
	HDC hdc = GetDC(hwnd); //получаем дискриптор,свзянный с окном, в котором будем рисовать
	srand(time(NULL)); //ГСЧ
	if (hdc) {
		int n = Paint(hdc);//вызываем функцию рисования звезд
		double count = Rate(n);// количество звезд
		HFONT hfont, myfont;//шрифт
		myfont = CreateFont(38, 0, 0, 0, 700, 0, 0, 0, 0, OUT_DEFAULT_PRECIS, 0, DRAFT_QUALITY, FIXED_PITCH | FF_ROMAN, "Algerian");//создаем шрифт
		hfont = (HFONT)SelectObject(hdc, myfont);
		SetTextColor(hdc, RGB(0, 0xff, 0));//задаем цвет текста
		SetBkMode(hdc, 0);//фон закрашивается текущим цветом фона	
		char t2[30] = "";
		_gcvt(count,2, t2);//конвертируем количество процентов в строку 
		char t1[] = "The rate of star's fill is ";
		char t3[] = "%";
		char str[60] = "";
		strcat(str, t1);
		strcat(str, t2);
		strcat(str, t3);
		TextOut(hdc, 200, 120, str, ARRAYSIZE(str));//
		//освобождаем контекст
		ReleaseDC;
	}
	char c=_getch();
	_getch();
	
	return 0;
}









