#include "RightAngledTriangle.h"

FIGURE::RightAngledTriangle::RightAngledTriangle() : Triangle(0, 0, 0, 0, 0, 90) { this->Name = "Прямоугольный треугольник"; };

FIGURE::RightAngledTriangle::RightAngledTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) { this->Name = "Прямоугольный треугольник"; };

bool FIGURE::RightAngledTriangle::CheckFigure()
{
	if (Triangle::CheckFigure() && this->angles.Get_C() == 90) return true;

	else return false;
}

void FIGURE::RightAngledTriangle::PrintInfo()
{
	Triangle::PrintInfo();
}