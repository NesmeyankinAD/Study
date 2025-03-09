#include "Parallelogram.h"


figure::Parallelogram::Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) 
{
	this->Name = "Параллелограмм"; 

	if(this->Get_a() != this->Get_c() || this->Get_b() != this->Get_d())
		throw FigureException(this->GetName() + " не создан. Стороны a, c и/или b, d не равны.");

	if (this->Get_A() != this->Get_C() || this->Get_B() != this->Get_D())
		throw FigureException(this->GetName() + " не создан. Углы A, C и/или B, D не равны.");

};


void figure::Parallelogram::PrintInfo()
{
	Quadrangle::PrintInfo();
}