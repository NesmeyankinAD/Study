#include <iostream>
#include <locale.h>

//сумма цифр введённого числа

int main()
{
	setlocale(LC_ALL, "rus");

	int a, sum{ 0 };

	std::cout << "Введите целое число: ";
	std::cin >> a;

	while (a != 0)
	{
		sum += (a%10);

		a = (a - (a % 10)) / 10;
			
	}

	std::cout << "Сумма цифр введённого числа: " << sum << std::endl;

	return 0;
}