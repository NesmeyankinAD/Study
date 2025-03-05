#include "Rectangle.h"


figure::Rectangle::Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) 
{
	this->Name = "Прямоугольник"; 

	if (this->Get_a() != this->Get_c() || this->Get_b() != this->Get_d())
		throw FigureException(this->GetName() + " не создан. Стороны a, c и/или b, d не равны.");

	if (this->Get_A() != 90 || this->Get_B() != 90 || this->Get_C() != 90 || this->Get_D() != 90)
		throw FigureException(this->GetName() + " не создан. Углы A, C и/или B, D не равны.");
};


void figure::Rectangle::PrintInfo()
{
	Quadrangle::PrintInfo();
}