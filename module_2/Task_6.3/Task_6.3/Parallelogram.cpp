#include "Parallelogram.h"


FIGURE::Parallelogram::Parallelogram() : Quadrangle(1, 0, 1, 0, 1, 0, 1, 0) { this->Name = "Параллелограмм"; };

FIGURE::Parallelogram::Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) { this->Name = "Параллелограмм"; };

bool FIGURE::Parallelogram::CheckFigure()
{
	if (Quadrangle::CheckFigure()) return true; //попарное равенство сторон и углов заложено в конструкторе

	else return false;
}

void FIGURE::Parallelogram::PrintInfo()
{
	Quadrangle::PrintInfo();
}