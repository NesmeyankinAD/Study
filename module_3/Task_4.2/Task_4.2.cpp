#include<iostream>
#include<Windows.h>


void print_dynamic_array(int* arr, int actual_size, int fact_size)
{
	for (int i = 0; i < fact_size; i++)
	{
		if (i < actual_size) std::cout << arr[i];
		else std::cout << "_";

		std::cout << " ";
	}
}


int* append_to_dynamic_array(int* arr, int& actual_size, int& fact_size, int &add_num)
{
	if (actual_size < fact_size)
	{
		arr[actual_size] = add_num;

		actual_size++;

		return arr;
	}
	else
	{
		int* new_arr = new int[fact_size * 2] {};
		
		for (int i = 0; i < actual_size; i++)
		{
			new_arr[i] = arr[i];
		}

		new_arr[actual_size] = add_num;

		actual_size++;
		fact_size = fact_size * 2;

		delete [] arr;

		return new_arr;
	}
}


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int fact_size{ 0 }, actual_size{ 0 };

	bool flag_1{ false };

	while (!flag_1)
	{
		std::cout << "Введите фактический размер массива: ";
		std::cin >> fact_size;

		std::cout << "Введите логический размер массива: ";
		std::cin >> actual_size;

		if (actual_size > fact_size) std::cout << "\nОшибка! Логический размер массива не может превышать фактический!\n\n";
		else flag_1 = true;
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
	std::cout << std::endl;

	bool flag_2{ true };
	int choise{ 0 };

	do
	{
		std::cout << "Хотите добавить элемент в массив? \n1 - Да, 0 - Выход. \n";
		std::cin >> choise;

		if (choise == 1)
		{
			int add_num{0};

			std::cout << "Введите число, которое хотите добавить: ";
			std::cin >> add_num;

			arr = append_to_dynamic_array(arr, actual_size, fact_size, add_num);
		}
		else { std::cout << "Неверная команда!" << std::endl; continue; }

		std::cout << "Динамический массив: "; print_dynamic_array(arr, actual_size, fact_size);
		std::cout << std::endl;
	} while (flag_2);

	delete[] arr;

	return EXIT_SUCCESS;
}