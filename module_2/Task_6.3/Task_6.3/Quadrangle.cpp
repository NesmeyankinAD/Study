#include "Quadrangle.h"


int FIGURE::Quadrangle::Get_a() { return this->a; }

int FIGURE::Quadrangle::Get_b() { return this->b; }

int FIGURE::Quadrangle::Get_c() { return this->c; }

int FIGURE::Quadrangle::Get_d() { return this->d; }


int FIGURE::Quadrangle::Get_A() { return this->A; }

int FIGURE::Quadrangle::Get_B() { return this->B; }

int FIGURE::Quadrangle::Get_C() { return this->C; }

int FIGURE::Quadrangle::Get_D() { return this->D; }


FIGURE::Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(4)
	{
		this->Name = "Четырёхугольник";

		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;

		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	};

FIGURE::Quadrangle::Quadrangle() : Figure(4)
	{
		this->Name = "Четырёхугольник";

		this->a = 0;
		this->b = 0;
		this->c = 0;
		this->d = 0;

		this->A = 0;
		this->B = 0;
		this->C = 0;
		this->D = 0;
	};

bool FIGURE::Quadrangle::CheckFigure()
{
	if (this->Get_a() == 0 ||
		this->Get_b() == 0 ||
		this->Get_c() == 0 ||
		this->Get_d() == 0 ||
		(this->Get_A() + this->Get_B() + this->Get_C() + this->Get_D() != 360))
	{
		return false;
	}
	else
	{
		return true;
	}
}

void FIGURE::Quadrangle::PrintInfo()
{
	Figure::PrintInfo();

	std::cout << "Стороны: ";
	std::cout << "a = " << this->Get_a() << ", ";
	std::cout << "b = " << this->Get_b() << ", ";
	std::cout << "c = " << this->Get_c() << ", ";
	std::cout << "d = " << this->Get_d() << std::endl;

	std::cout << "Углы: ";
	std::cout << "A = " << this->Get_A() << ", ";
	std::cout << "B = " << this->Get_B() << ", ";
	std::cout << "C = " << this->Get_C() << ", ";
	std::cout << "D = " << this->Get_D() << std::endl;
}
