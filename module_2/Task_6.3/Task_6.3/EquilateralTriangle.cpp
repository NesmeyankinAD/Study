#include "EquilateralTriangle.h"


FIGURE::EquilateralTriangle::EquilateralTriangle() : IsoscelesTriangle(1, 1, 60, 60) { this->Name = "Равносторонний треугольник"; };

FIGURE::EquilateralTriangle::EquilateralTriangle(int a) : IsoscelesTriangle(a, a, 60, 60) { this->Name = "Равносторонний треугольник"; };

bool FIGURE::EquilateralTriangle::CheckFigure()
{
	if (Triangle::CheckFigure() &&
		this->Get_a() == this->Get_b() &&
		this->Get_c() == this->Get_a() &&
		this->Get_A() == 60 &&
		this->Get_B() == 60 &&
		this->Get_C() == 60) return true;

	else return false;
}

void FIGURE::EquilateralTriangle::PrintInfo()
{
	Triangle::PrintInfo();
}