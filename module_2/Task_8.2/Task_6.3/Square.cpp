#include "Square.h"


figure::Square::Square(int a) : Rectangle(a, a) 
{
	this->Name = "Квадрат";

	if (this->Get_a() != this->Get_b() || this->Get_c() != this->Get_d() || this->Get_a() != this->Get_c())
		throw FigureException(this->GetName() + " не создан. Стороны не равны.");

	if (this->Get_A() != 90 || this->Get_B() != 90 || this->Get_C() != 90 || this->Get_D() != 90)
		throw FigureException(this->GetName() + " не создан. Углы A, C и/или B, D не равны.");
};


void figure::Square::PrintInfo()
{
	Quadrangle::PrintInfo();
}