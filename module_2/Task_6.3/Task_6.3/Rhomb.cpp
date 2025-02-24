#include "Rhomb.h"

FIGURE::Rhomb::Rhomb() : Parallelogram(1, 1, 0, 0) { this->Name = "Ромб"; };

FIGURE::Rhomb::Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B) { this->Name = "Ромб"; };

bool FIGURE::Rhomb::CheckFigure()
{
	if (Quadrangle::CheckFigure()) return true; //равенство сторон и попарное равенство углов заложено в конструкторе

	else return false;
}

void FIGURE::Rhomb::PrintInfo()
{
	Quadrangle::PrintInfo();
}