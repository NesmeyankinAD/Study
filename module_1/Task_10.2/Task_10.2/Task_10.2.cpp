#include<iostream>
#include<locale.h>


double* create_array(int size)
{
	double* arr = new double[size]();
	
	return arr;
}


int main()
{
	setlocale(LC_ALL, "Rus");

	int size = 0;

	std::cout << "¬ведите размер массива: ";
	std::cin >> size;

	double* array = create_array(size);


	std::cout << "¬ведЄный массив: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	delete[] array;
}