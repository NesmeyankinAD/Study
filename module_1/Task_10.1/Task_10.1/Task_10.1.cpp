#include<iostream>
#include<locale.h>


int main()
{
	setlocale(LC_ALL, "Rus");

	int size = 0;

	std::cout << "������� ������ �������: ";
	std::cin >> size;
	
	int* arr = new int[size];

	std::cout << "������� �������� �������:" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << "arr[" << i << "]= ";
		std::cin >> arr[i];
	}

	std::cout << "������� ������: ";

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	delete[] arr;
}