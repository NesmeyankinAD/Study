#include "Quadrangle.h"


int FIGURE::Quadrangle::Sides::Get_a() { return this->a; }

int FIGURE::Quadrangle::Sides::Get_b() { return this->b; }

int FIGURE::Quadrangle::Sides::Get_c() { return this->c; }

int FIGURE::Quadrangle::Sides::Get_d() { return this->d; }

FIGURE::Quadrangle::Sides::Sides(int a, int b, int c, int d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
};

FIGURE::Quadrangle::Sides::Sides()
{
	this->a = 0;
	this->b = 0;
	this->c = 0;
	this->d = 0;
};


int FIGURE::Quadrangle::Angles::Get_A() { return this->A; }

int FIGURE::Quadrangle::Angles::Get_B() { return this->B; }

int FIGURE::Quadrangle::Angles::Get_C() { return this->C; }

int FIGURE::Quadrangle::Angles::Get_D() { return this->D; }

FIGURE::Quadrangle::Angles::Angles(int A, int B, int C, int D)
{
	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;
};

FIGURE::Quadrangle::Angles::Angles()
{
	this->A = 0;
	this->B = 0;
	this->C = 0;
	this->D = 0;
};

FIGURE::Quadrangle::Sides sides;
FIGURE::Quadrangle::Angles angles;


FIGURE::Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(4)
	{
		this->Name = "Четырёхугольник";

		sides = Sides(a, b, c, d);
		angles = Angles(A, B, C, D);

	};

FIGURE::Quadrangle::Quadrangle() : Figure(4)
	{
		this->Name = "Четырёхугольник";
	};

bool FIGURE::Quadrangle::CheckFigure()
{
	if (this->sides.Get_a() == 0 ||
		this->sides.Get_b() == 0 ||
		this->sides.Get_c() == 0 ||
		this->sides.Get_d() == 0 ||
		(this->angles.Get_A() + this->angles.Get_B() + this->angles.Get_C() + this->angles.Get_D() != 360))
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
	std::cout << "a = " << this->sides.Get_a() << ", ";
	std::cout << "b = " << this->sides.Get_b() << ", ";
	std::cout << "c = " << this->sides.Get_c() << ", ";
	std::cout << "d = " << this->sides.Get_d() << std::endl;

	std::cout << "Углы: ";
	std::cout << "A = " << this->angles.Get_A() << ", ";
	std::cout << "B = " << this->angles.Get_B() << ", ";
	std::cout << "C = " << this->angles.Get_C() << ", ";
	std::cout << "D = " << this->angles.Get_D() << std::endl;
}
