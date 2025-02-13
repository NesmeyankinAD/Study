#include <iostream>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");

	int max{ 0 }, min{INT_MAX};
	const int size = 10;

	int arr[size] = { 5, 6, 18, 20, 56, 5006, 1, 2, 3, 4 };

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";

		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];

	}

	std::cout << "\n" << "Максимум массива: " << max << std::endl;
	std::cout << "Минимум массива: " << min << std::endl;
}