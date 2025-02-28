#include "Rectangle.h"

FIGURE::Rectangle::Rectangle() : Parallelogram(1, 0, 90, 90) { this->Name = "Прямоугольник"; };

FIGURE::Rectangle::Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) { this->Name = "Прямоугольник"; };

bool FIGURE::Rectangle::CheckFigure()
{
	if (Quadrangle::CheckFigure() &&
		this->Get_a() == this->Get_c() &&
		this->Get_b() == this->Get_d() &&
		this->Get_A() == 90 &&
		this->Get_B() == 90 &&
		this->Get_C() == 90 &&
		this->Get_D() == 90) return true;

	else return false;
}


void FIGURE::Rectangle::PrintInfo()
{
	Quadrangle::PrintInfo();
}