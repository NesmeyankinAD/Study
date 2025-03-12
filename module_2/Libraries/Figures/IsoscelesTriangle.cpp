#include "IsoscelesTriangle.h"


figure::IsoscelesTriangle::IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) 
{ 
	this->Name = "Равнобедренный треугольник"; 

	if (this->Get_a() != this->Get_c())
		throw FigureException(this->GetName() + " не создан. Стороны а и с не равны.");

	if (this->Get_A() != this->Get_C())
		throw FigureException(this->GetName() + " не создан. Углы А и С не равны.");
};


void figure::IsoscelesTriangle::PrintInfo()
{
	Triangle::PrintInfo();
}