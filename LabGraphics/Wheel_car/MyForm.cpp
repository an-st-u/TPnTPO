#include "MyForm.h"
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include "figure.h"
#include "point.h"
#include "line.h"
#include "circle.h"
#include "Rectgle.h"
#include "Wheel.h"

using namespace SECOND_WinForms;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);

	return 0;
}


void MyForm::OnPaint(PaintEventArgs^ e) { DoPaint(e); }
void MyForm::DoPaint(PaintEventArgs^ e){
	Graphics ^ g = e->Graphics;
	g->Clear(Color::White);
	Figure fig;

	fig.add(new Rectgle(g, 10, 10, 190, 140));  // кузов
	fig.add(new Line(g, 200, 50, 200, 150));      // задняя стенка кабины
	fig.add(new Line(g, 200, 50, 250, 50));      // крыша кабины
	fig.add(new Line(g, 250, 50, 270, 100));      // стойка крыши
	fig.add(new Line(g, 270, 100, 310, 110));      // капот
	fig.add(new Line(g, 310, 110, 310, 150));      // решетка радиатора
	fig.add(new Line(g, 200, 150, 310, 150));      // пол кабины
	fig.add(new Line(g, 210, 60, 245, 60));      // окно - верх
	fig.add(new Line(g, 210, 60, 210, 100));      // окно - задняя часть
	fig.add(new Line(g, 245, 60, 260, 100));      // окно - передняя часть
	fig.add(new Line(g, 260, 100, 210, 100));      // окно - нижняя часть
	fig.add(new Rectgle(g, 310, 140, 10, 10)); // бампер
	fig.add(new Line(g, 290, 115, 300, 115));      // воздухозаборник 1
	fig.add(new Line(g, 290, 120, 300, 120));      // воздухозаборник 2
	fig.add(new Line(g, 290, 125, 300, 125));      // воздухозаборник 3

	fig.add(new Wheel(g, 62, 142, 35));          // Заднее колесо
	fig.add(new Wheel(g, 242, 142, 35));          // Переднее колесо

	fig.show();

	for (int i = 0; i < 400; i++) {
		fig.move(1, 0);
	}
	
	
}



