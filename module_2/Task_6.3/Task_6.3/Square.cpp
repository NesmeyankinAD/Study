#include "Square.h"


FIGURE::Square::Square() : Rectangle(1, 1) { this->Name = "Квадрат"; };

FIGURE::Square::Square(int a) : Rectangle(a, a) { this->Name = "Квадрат"; };

bool FIGURE::Square::CheckFigure()
{
	if (Quadrangle::CheckFigure()) return true; //равенство сторон и попарное равенство углов заложено в 
	else return false;
}

void FIGURE::Square::PrintInfo()
{
	Quadrangle::PrintInfo();
}