#include <iostream>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "rus");
	
	const int size = 10;

	int arr[size] = { 5, 1, 3, -5, -9, 2, -2, 8, 15, 10 };
	
	bool swapped = false;

	std::cout << "Массив до сортировки: ";

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;

	do
	{
		swapped = false;
		for (int i = size-1; i >= 0; i--)
		{
			if (arr[i - 1] > arr[i])
			{
				int temp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = temp;
				swapped = true;
			}
		}
	} while (swapped);

	std::cout << "Массив после сортировки: ";

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}