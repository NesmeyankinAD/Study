#include<iostream>
#include<locale.h>

int** create_two_dim_array(int rows, int column)
{
	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[column];
	}

	return arr;
}

void fill_two_dim_array(int** arr, int rows, int column)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < column; j++)
		{
			arr[i][j] = (i + 1) * (j + 1);
		}
	}
}

void print_two_dim_array(int** arr, int rows, int column)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < column; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void delete_two_dim_array(int** arr, int rows, int column)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int ROWS{0}, COL{0};

	std::cout << "¬ведите количество строчек таблицы умножени€: ";
	std::cin >> ROWS;

	std::cout << "¬ведите количество столбцов таблицы умножени€: ";
	std::cin >> COL;

	int** ARR = create_two_dim_array(ROWS, COL);

	fill_two_dim_array(ARR, ROWS, COL);

	print_two_dim_array(ARR, ROWS, COL);

	delete_two_dim_array(ARR, ROWS, COL);

}