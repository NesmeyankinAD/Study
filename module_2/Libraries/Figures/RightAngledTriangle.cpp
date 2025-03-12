#include "RightAngledTriangle.h"


figure::RightAngledTriangle::RightAngledTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) 
{ 
	this->Name = "Прямоугольный треугольник";

	if (this->Get_C() != 90) throw FigureException(this->GetName() + " не создан. Угол С не равен 90."); 
};


void figure::RightAngledTriangle::PrintInfo()
{
	Triangle::PrintInfo();
}