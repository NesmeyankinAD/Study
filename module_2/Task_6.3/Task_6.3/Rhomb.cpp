#include "Rhomb.h"

FIGURE::Rhomb::Rhomb() : Parallelogram(1, 1, 0, 0) { this->Name = "Ромб"; };

FIGURE::Rhomb::Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B) { this->Name = "Ромб"; };

bool FIGURE::Rhomb::CheckFigure()
{
	if (Quadrangle::CheckFigure() &&
		this->Get_a() == this->Get_b() &&
		this->Get_c() == this->Get_d() &&
		this->Get_a() == this->Get_c() &&
		this->Get_A() == this->Get_C() &&
		this->Get_B() == this->Get_D()) return true;

	else return false;
}

void FIGURE::Rhomb::PrintInfo()
{
	Quadrangle::PrintInfo();
}