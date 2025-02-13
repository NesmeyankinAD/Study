#include<iostream>
#include<locale.h>

unsigned long long NumberFibonacci(int n)
{
	if (n <= 1) return n;				// для первых двух чисел	
	
	unsigned long long c_1 = 0, c_2 = 1;// первые два числа
	unsigned long long c;				// искомое число
	
	for (int i = 2; i <= n; i++) 
	{
		c = c_1 + c_2;
		c_1 = c_2;						// сдвиг чисел
		c_2 = c;
	}
	return c;
}
	
int main()
{
	setlocale(LC_ALL, "Rus");

	int n;

	std::cout << "Введите количество чисел Фибоначчи n (нумерация с 1 до 93): ";
	std::cin >> n;

	std::cout << "n чисел Фибоначчи:" << std::endl;

	for (int i = 1; i <= n; i++)
	{
		std::cout << NumberFibonacci(i) << std::endl;
	}

	return 0;
}