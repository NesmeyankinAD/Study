#include <iostream>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");

	int max{ -INT_MAX }, min{ INT_MAX };
	int i_max, i_min, j_max, j_min;

	const int columns = 6;
	const int rows = 3;

	int arr[rows][columns] ={	{1, 6, 18, 20, 56, 506}, 
								{5, 2, 3, 4, 610, 7 },
								{84, -10, 14, 21, 6, 88 } 
							};

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << arr[i][j] << "\t";

			if (arr[i][j] > max) { max = arr[i][j]; i_max = i; j_max = j; }
			if (arr[i][j] < min) { min = arr[i][j]; i_min = i; j_min = j; }

		}

		std::cout << "\n";
	}

	std::cout << "Индексы максимального элемента: [" << i_max << "][" << j_max << "]" << std::endl;
	std::cout << "Индексы минимального элемента: [" << i_min << "][" << j_min << "]" << std::endl;
}