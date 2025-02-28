#include "Triangle.h"


int FIGURE::Triangle::Get_a() { return this->a; }

int FIGURE::Triangle::Get_b() { return this->b; }

int FIGURE::Triangle::Get_c() { return this->c; }


int FIGURE::Triangle::Get_A() { return this->A; }

int FIGURE::Triangle::Get_B() { return this->B; }

int FIGURE::Triangle::Get_C() { return this->C; }


FIGURE::Triangle::Triangle(int a, int b, int c, int A, int B, int C) : Figure(3)
{
	this->Name = "Треугольник";

	this->a = a;
	this->b = b;
	this->c = c;

	this->A = A;
	this->B = B;
	this->C = C;
};

FIGURE::Triangle::Triangle() : Figure(3)
{
	this->Name = "Треугольник";

	this->a = 0;
	this->b = 0;
	this->c = 0;

	this->A = 0;
	this->B = 0;
	this->C = 0;
};

bool FIGURE::Triangle::CheckFigure()
{
	if (this->Get_a() == 0 ||
		this->Get_b() == 0 ||
		this->Get_c() == 0 ||
		(this->Get_A() + this->Get_B() + this->Get_C() != 180))
	{
		return false;
	}
	else
	{
		return true;
	}
}

void FIGURE::Triangle::PrintInfo()
{
	Figure::PrintInfo();

	std::cout << "Стороны: ";
	std::cout << "a = " << this->Get_a() << ", ";
	std::cout << "b = " << this->Get_b() << ", ";
	std::cout << "c = " << this->Get_c() << std::endl;

	std::cout << "Углы: ";
	std::cout << "A = " << this->Get_A() << ", ";
	std::cout << "B = " << this->Get_B() << ", ";
	std::cout << "C = " << this->Get_C() << std::endl;
}
