#include<iostream>
#include<fstream>
#include<string>

int** create_array(int rows, int column)
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


	std::ifstream file("C:\\Users\\mrsas\\Desktop\\Cpp_Folder\\Game_Live\\Read_array\\array.txt");
	std::string s;
	
	if (file.is_open())
	{
		file >> s;
		int rows = std::stoi(s); std::cout << "Строчек массива: " << rows << " " << std::endl;
		
		file >> s;
		int column = std::stoi(s); std::cout << "Столбцов массива: " << column << " " << std::endl;
		
		int** ARR = create_array(rows, column);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < column; j++)
			{
				file >> s;
				ARR[i][j] = std::stoi(s);
			}
		}

		file.close();
		
		print_two_dim_array(ARR, rows, column);
		delete_two_dim_array(ARR, rows, column);
	}
	else {std::cout << "Не удалось открыть файл.";}
		
	return EXIT_SUCCESS;
}