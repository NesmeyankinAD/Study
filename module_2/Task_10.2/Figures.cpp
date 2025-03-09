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

#include"FigureException.h"

using namespace figure;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	

	Figure figure;
	Figure* p_figure = &figure;
	p_figure->PrintInfo();

	try
	{
		Triangle triangle(1, 2, 3, 50, 70, 60);
		Triangle* p_triangle = &triangle;
		p_triangle->PrintInfo();

		RightAngledTriangle right_angled_triangle(1, 2, 3, 30, 60);
		Triangle* p_right_angled_triangle = &right_angled_triangle;
		p_right_angled_triangle->PrintInfo();

		IsoscelesTriangle isosceles_triangle(20, 10, 75, 30);
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

		figure::Rectangle rectangle(10, 20); //существует некая функция Rectangle - конфликт имён
		Quadrangle* p_rectangle = &rectangle;
		p_rectangle->PrintInfo();
		
		Rhomb rhomb(20, 150, 30);
		Quadrangle* p_rhomb = &rhomb;
		p_rhomb->PrintInfo();

		Square square(5);
		Quadrangle* p_square = &square;
		p_square->PrintInfo();

	}
	catch (FigureException& except)
	{
		std::cout << except.what() << std::endl;
	}			

	return EXIT_SUCCESS;
}