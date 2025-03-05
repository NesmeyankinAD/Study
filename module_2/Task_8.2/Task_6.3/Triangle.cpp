#include "Triangle.h"


int figure::Triangle::Get_a() { return this->a; }

int figure::Triangle::Get_b() { return this->b; }

int figure::Triangle::Get_c() { return this->c; }


int figure::Triangle::Get_A() { return this->A; }

int figure::Triangle::Get_B() { return this->B; }

int figure::Triangle::Get_C() { return this->C; }


figure::Triangle::Triangle(int a, int b, int c, int A, int B, int C) : Figure(3)
{
	this->Name = "Треугольник";

	this->a = a;
	this->b = b;
	this->c = c;

	this->A = A;
	this->B = B;
	this->C = C;

	if (this->Get_a() == 0 || this->Get_b() == 0 || this->Get_c() == 0)
		throw FigureException(this->GetName() + " не создан. Количество сторон не равно трём.");

	if (this->Get_A() + this->Get_B() + this->Get_C() != 180)
		throw FigureException(this->GetName() + " не создан. Сумма углов не равна 180.");
};


void figure::Triangle::PrintInfo()
{
	std::cout << this->GetName() << " создан. ";

	std::cout << "Стороны: ";
	std::cout << "a = " << this->Get_a() << ", ";
	std::cout << "b = " << this->Get_b() << ", ";
	std::cout << "c = " << this->Get_c() << ". ";

	std::cout << "Углы: ";
	std::cout << "A = " << this->Get_A() << ", ";
	std::cout << "B = " << this->Get_B() << ", ";
	std::cout << "C = " << this->Get_C() << ". " << std::endl;
	std::cout << std::endl;
}
