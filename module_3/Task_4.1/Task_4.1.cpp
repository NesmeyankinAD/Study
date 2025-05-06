#include<iostream>
#include<Windows.h>


void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
	for (int i = 0; i < actual_size; i++)
	{
		if (i < logical_size) std::cout << arr[i];
		else std::cout << "_";

		std::cout << " ";
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int fact_size{ 0 }, actual_size{ 0 };

	bool flag{ false };

	while (!flag)
	{
		std::cout << "Введите фактический размер массива: ";
		std::cin >> fact_size;

		std::cout << "Введите логический размер массива: ";
		std::cin >> actual_size;

		if (actual_size > fact_size) std::cout << "\nОшибка! Логический размер массива не может превышать фактический!\n\n";
		else flag = true;
	}

	int* arr = new int[fact_size] {};

	std::cout << "Заполните массив." << std::endl;

	for (int i = 0; i < actual_size; i++)
	{
		std::cout << "arr[" << i << "] = ";
		std::cin >> arr[i];
		std::cout << std::endl;
	}

	std::cout << "Динамический массив: "; print_dynamic_array(arr, actual_size, fact_size);
}