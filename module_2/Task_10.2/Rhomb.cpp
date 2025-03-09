#include "Rhomb.h"


figure::Rhomb::Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B) 
{
	this->Name = "Ромб"; 

	if (this->Get_a() != this->Get_b() || this->Get_c() != this->Get_d() || this->Get_a() != this->Get_c())
		throw FigureException(this->GetName() + " не создан. Стороны не равны.");

	if (this->Get_A() != this->Get_C() || this->Get_B() != this->Get_D())
		throw FigureException(this->GetName() + " не создан. Углы A, C и/или B, D не равны.");
};


void figure::Rhomb::PrintInfo()
{
	Quadrangle::PrintInfo();
}