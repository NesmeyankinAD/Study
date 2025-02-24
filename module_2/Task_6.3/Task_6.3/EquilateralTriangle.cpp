#include "EquilateralTriangle.h"


FIGURE::EquilateralTriangle::EquilateralTriangle() : IsoscelesTriangle(1, 1, 60, 60) { this->Name = "Равносторонний треугольник"; };

FIGURE::EquilateralTriangle::EquilateralTriangle(int a) : IsoscelesTriangle(a, a, 60, 60) { this->Name = "Равносторонний треугольник"; };

bool FIGURE::EquilateralTriangle::CheckFigure()
{
	if (Triangle::CheckFigure()) return true; //без иных условий, равенство сторон и углы по 60 заложены в конструкторе

	else return false;
}

void FIGURE::EquilateralTriangle::PrintInfo()
{
	Triangle::PrintInfo();
}