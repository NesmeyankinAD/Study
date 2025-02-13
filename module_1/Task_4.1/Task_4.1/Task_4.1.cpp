#include <iostream>
#include <locale.h>

//сумма введЄных чисел
int main()
{
	setlocale(LC_ALL, "rus");

	int a, sum{0};

	do
	{
		std::cout << "¬ведите целое число (0 дл€ выхода): ";
		std::cin >> a;
		sum += a;

		if (a == 0) break;

	} while (1);

	std::cout << "—умма введЄных чисел: " << sum << std::endl;

	return 0;
}