#include <iostream>
#include <locale.h>

int main() 
{
	setlocale(LC_ALL, "Rus");

	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i];
		
		if (i == 9) break;

		std::cout << ", ";
	}
}