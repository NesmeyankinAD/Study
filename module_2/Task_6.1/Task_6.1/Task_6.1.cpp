#include<iostream>
#include<Windows.h>
#include"MathFunctions.h"


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	bool work{0};
	float num1{0}, num2{0};

	while (!work)
	{
		std::cout << "Введите первое число: ";
		std::cin >> num1;

		std::cout << "Введите второе число: ";
		std::cin >> num2;

		int choise{ 0 };

		std::cout << "Выберите операцию: 1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень: ";
		std::cin >> choise;

		switch (choise)
		{
		case 1: std::cout << num1 << " + " << num2 << " = " << Sum(num1, num2) << std::endl; break;
		case 2: std::cout << num1 << " - " << num2 << " = " << Sub(num1, num2) << std::endl; break;
		case 3: std::cout << num1 << " * " << num2 << " = " << Mult(num1, num2) << std::endl; break;
		case 4:
		{
			if (num2 == 0) { std::cout << "Деление на ноль невозможно!" << std::endl; }

			else std::cout << num1 << " / " << num2 << " = " << Div(num1, num2) << std::endl; break;
		}

		case 5: std::cout << num1 << " ^ " << num2 << " = " << Power(num1, num2) << std::endl; break;

		default: std::cout << "Неверно выбрана операция!" << std::endl;
		}

		std::cout << "Хотите выйти? (1 - да, 0 - нет): ";
		std::cin >> work;
	}
}