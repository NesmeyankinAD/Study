#include <iostream>
#include <locale.h>

namespace sum
{
	int calc(int x, int y)
	{
		return x + y;
	}
}

namespace sub
{
	int calc(int x, int y)
	{
		return x - y;
	}
}

namespace divide
{
	int calc(int x, int y)
	{
		return x / y;
	}
}

namespace prod
{
	int calc(int x, int y)
	{
		return x * y;
	}
}


int main()
{
	setlocale(LC_ALL, "Rus");

	int a = 5, b = 9;

	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << "Сложение: " << sum::calc(a, b) << std::endl;

	std::cout << "Вычитание: " << sub::calc(a, b) << std::endl;

	std::cout << "Деление: " << divide::calc(a, b) << std::endl;

	std::cout << "Умножение: " << prod::calc(a, b) << std::endl;

}