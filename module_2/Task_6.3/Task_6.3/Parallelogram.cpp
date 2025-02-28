#include "Parallelogram.h"


FIGURE::Parallelogram::Parallelogram() : Quadrangle(1, 0, 1, 0, 1, 0, 1, 0) { this->Name = "ֿאנאככוכמדנאלל"; };

FIGURE::Parallelogram::Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) { this->Name = "ֿאנאככוכמדנאלל"; };

bool FIGURE::Parallelogram::CheckFigure()
{
	if (Quadrangle::CheckFigure() &&
		this->Get_a() == this->Get_c() &&
		this->Get_b() == this->Get_d() &&
		this->Get_A() == this->Get_C() &&
		this->Get_B() == this->Get_D()) return true;

	else return false;
}

void FIGURE::Parallelogram::PrintInfo()
{
	Quadrangle::PrintInfo();
}