#include "Square.h"


FIGURE::Square::Square() : Rectangle(1, 1) { this->Name = " вадрат"; };

FIGURE::Square::Square(int a) : Rectangle(a, a) { this->Name = " вадрат"; };

bool FIGURE::Square::CheckFigure()
{
	if (Quadrangle::CheckFigure() &&
		this->Get_a() == this->Get_b() &&
		this->Get_c() == this->Get_d() &&
		this->Get_a() == this->Get_c() &&
		this->Get_A() == this->Get_C() &&
		this->Get_A() == 90 &&
		this->Get_B() == 90 &&
		this->Get_C() == 90 &&
		this->Get_D() == 90) return true;

	else return false;
}

void FIGURE::Square::PrintInfo()
{
	Quadrangle::PrintInfo();
}