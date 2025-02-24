#include "IsoscelesTriangle.h"


FIGURE::IsoscelesTriangle::IsoscelesTriangle() : Triangle(1, 0, 1, 1, 0, 1) { this->Name = "Равнобедренный треугольник"; };

FIGURE::IsoscelesTriangle::IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) { this->Name = "Равнобедренный треугольник"; };

bool FIGURE::IsoscelesTriangle::CheckFigure()
{
	if (Triangle::CheckFigure()) return true; //без иных условий, равенство a=c и A=C заложено в конструкторе

	else return false;
}

void FIGURE::IsoscelesTriangle::PrintInfo()
{
	Triangle::PrintInfo();
}