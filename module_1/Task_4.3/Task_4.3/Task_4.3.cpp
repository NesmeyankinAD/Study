#include <iostream>
#include <locale.h>

int main() 
{
	setlocale(LC_ALL, "Rus");

	int a;

	std::cout << "¬ведите число: ";
	std::cin >> a;

	for (int i=1; i<=10; i++)
	{
		std::cout << a << "*" << i << "=" << (a * i) << std::endl;
	}
}