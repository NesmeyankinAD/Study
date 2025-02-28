#include "IsoscelesTriangle.h"


FIGURE::IsoscelesTriangle::IsoscelesTriangle() : Triangle(1, 0, 1, 1, 0, 1) { this->Name = "Равнобедренный треугольник"; };

FIGURE::IsoscelesTriangle::IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) { this->Name = "Равнобедренный треугольник"; };

bool FIGURE::IsoscelesTriangle::CheckFigure()
{
	if (Triangle::CheckFigure() &&
		this->Get_a() == this->Get_c() &&
		this->Get_A() == this->Get_C())		return true;

	else return false;
}

void FIGURE::IsoscelesTriangle::PrintInfo()
{
	Triangle::PrintInfo();
}