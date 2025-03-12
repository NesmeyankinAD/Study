#include "EquilateralTriangle.h"


figure::EquilateralTriangle::EquilateralTriangle(int a) : IsoscelesTriangle(a, a, 60, 60) 
{
	this->Name = "Равносторонний треугольник"; 

	if (this->Get_a() != this->Get_c() || this->Get_a() != this->Get_b())
		throw FigureException(this->GetName() + " не создан. Стороны не равны.");

	if (this->Get_A() != 60 || this->Get_B() != 60 || this->Get_C() != 60)
		throw FigureException(this->GetName() + " не создан. Углы не равны 60.");
};


void figure::EquilateralTriangle::PrintInfo()
{
	Triangle::PrintInfo();
}