#include "Triangle.h"


int FIGURE::Triangle::Sides::Get_a() { return this->a; }

int FIGURE::Triangle::Sides::Get_b() { return this->b; }

int FIGURE::Triangle::Sides::Get_c() { return this->c; }

FIGURE::Triangle::Sides::Sides(int a, int b, int c)
{
	this->a = a;
	this->b = b;
	this->c = c;
};

FIGURE::Triangle::Sides::Sides()
{
	this->a = 0;
	this->b = 0;
	this->c = 0;
};


int FIGURE::Triangle::Angles::Get_A() { return this->A; }

int FIGURE::Triangle::Angles::Get_B() { return this->B; }

int FIGURE::Triangle::Angles::Get_C() { return this->C; }

FIGURE::Triangle::Angles::Angles(int A, int B, int C)
{
	this->A = A;
	this->B = B;
	this->C = C;
};

FIGURE::Triangle::Angles::Angles()
{
	this->A = 0;
	this->B = 0;
	this->C = 0;
};

FIGURE::Triangle::Sides sides;
FIGURE::Triangle::Angles angles;

FIGURE::Triangle::Triangle(int a, int b, int c, int A, int B, int C) : Figure(3)
{
	this->Name = "Треугольник";

	sides = Sides(a, b, c);
	angles = Angles(A, B, C);

};

FIGURE::Triangle::Triangle() : Figure(3)
{
	this->Name = "Треугольник";
};

bool FIGURE::Triangle::CheckFigure()
{
	if (this->sides.Get_a() == 0 ||
		this->sides.Get_b() == 0 ||
		this->sides.Get_c() == 0 ||
		(this->angles.Get_A() + this->angles.Get_B() + this->angles.Get_C() != 180))
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
	std::cout << "a = " << this->sides.Get_a() << ", ";
	std::cout << "b = " << this->sides.Get_b() << ", ";
	std::cout << "c = " << this->sides.Get_c() << std::endl;

	std::cout << "Углы: ";
	std::cout << "A = " << this->angles.Get_A() << ", ";
	std::cout << "B = " << this->angles.Get_B() << ", ";
	std::cout << "C = " << this->angles.Get_C() << std::endl;
}