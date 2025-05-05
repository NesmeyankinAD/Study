#include<iostream>
#include<Windows.h>


int Search(int arr[], int arr_size, int search_point) 
{
	int left = 0;
	int right = arr_size - 1;

	while (left < right) 
	{
		int mid = left + (right - left) / 2;

		if (arr[mid] > search_point) 	right = mid;
		else							left = mid + 1;
	}

	return arr_size - left;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	const int arr_size = 9;
	int ref{ 0 };

	int arr[arr_size] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };

	std::cout << "Введите точку отсчёта: ";
	std::cin >> ref;

	std::cout << "Количество элементов больших, чем " << ref << ": ";
	std::cout << Search(arr, arr_size, ref) << std::endl;
}