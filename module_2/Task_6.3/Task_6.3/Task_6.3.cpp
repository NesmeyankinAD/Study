#include<iostream>
#include<Windows.h>
#include<string>

#include"Figure.h"
#include"Triangle.h"
#include"Quadrangle.h"
#include"EquilateralTriangle.h"
#include"IsoscelesTriangle.h"
#include"RightAngledTriangle.h"
#include"Parallelogram.h"
#include"Rectangle.h"
#include"Rhomb.h"
#include"Square.h"

using namespace FIGURE;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Figure figure;

	Figure* p_figure = &figure;

	p_figure->PrintInfo();


	Triangle triangle(1, 2, 3, 50, 70, 60);		//создаЄм экземпл€р

	Triangle* p_triangle = &triangle;			//создаЄм указатель на базовый класс = ссылка на экземпл€р

	p_triangle->PrintInfo();					//по указателю на базовый класс вызываем переопределЄнные методы экземпл€ров


	RightAngledTriangle right_angled_triangle(1, 2, 3, 30, 60);

	Triangle* p_right_angled_triangle = &right_angled_triangle;

	p_right_angled_triangle->PrintInfo();


	IsoscelesTriangle isosceles_triangle(20, 10, 75, 20);

	Triangle* p_isosceles_triangle = &isosceles_triangle;

	p_isosceles_triangle->PrintInfo();


	EquilateralTriangle equilateral_triangle(10);

	Triangle* p_equilateral_triangle = &equilateral_triangle;

	p_equilateral_triangle->PrintInfo();


	Quadrangle quadrangle(1, 2, 3, 4, 90, 70, 110, 90);

	Quadrangle* p_quadrangle = &quadrangle;

	p_quadrangle->PrintInfo();


	Parallelogram parallelogram(10, 30, 120, 60);

	Quadrangle* p_parallelogram = &parallelogram;

	p_parallelogram->PrintInfo();


	Rhomb rhomb(20, 150, 20);

	Quadrangle* p_rhomb = &rhomb;

	p_rhomb->PrintInfo();


	FIGURE::Rectangle rectangle(10, 20); //существует нека€ функци€ Rectangle - конфликт имЄн
	
	Quadrangle* p_rectangle = &rectangle;
	
	p_rectangle->PrintInfo();


	Square square(5);

	Quadrangle* p_square = &square;

	p_square->PrintInfo();

	return EXIT_SUCCESS;
}