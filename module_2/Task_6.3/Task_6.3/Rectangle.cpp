#include "Rectangle.h"

FIGURE::Rectangle::Rectangle() : Parallelogram(1, 0, 90, 90) { this->Name = "Прямоугольник"; };

FIGURE::Rectangle::Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) { this->Name = "Прямоугольник"; };

bool FIGURE::Rectangle::CheckFigure()
{
	if (Quadrangle::CheckFigure()) return true;

	else return false;
}

void FIGURE::Rectangle::PrintInfo()
{
	Quadrangle::PrintInfo();
}