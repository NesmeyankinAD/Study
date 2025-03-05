#include "Quadrangle.h"


int figure::Quadrangle::Get_a() { return this->a; }
	
int figure::Quadrangle::Get_b() { return this->b; }
	
int figure::Quadrangle::Get_c() { return this->c; }
	
int figure::Quadrangle::Get_d() { return this->d; }
	
	
int figure::Quadrangle::Get_A() { return this->A; }
	
int figure::Quadrangle::Get_B() { return this->B; }
	
int figure::Quadrangle::Get_C() { return this->C; }
	
int figure::Quadrangle::Get_D() { return this->D; }


figure::Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(4)
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

		if (this->Get_a() == 0 || this->Get_b() == 0 || this->Get_c() == 0 || this->Get_d() == 0)
			throw FigureException(this->GetName() + " не создан. Количество сторон не равно четырём.");

		if (this->Get_A() + this->Get_B() + this->Get_C() + this->Get_D() != 360)
			throw FigureException(this->GetName() + " не создан. Сумма углов не равна 180.");
	};


void figure::Quadrangle::PrintInfo()
{
	std::cout << this->GetName() << " создан. ";

	std::cout << "Стороны: ";
	std::cout << "a = " << this->Get_a() << ", ";
	std::cout << "b = " << this->Get_b() << ", ";
	std::cout << "c = " << this->Get_c() << ", ";
	std::cout << "d = " << this->Get_d() << ". ";

	std::cout << "Углы: ";
	std::cout << "A = " << this->Get_A() << ", ";
	std::cout << "B = " << this->Get_B() << ", ";
	std::cout << "C = " << this->Get_C() << ", ";
	std::cout << "D = " << this->Get_D() << std::endl;
	std::cout << std::endl;
}
