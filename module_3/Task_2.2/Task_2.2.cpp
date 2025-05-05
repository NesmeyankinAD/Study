#include<iostream>
#include<Windows.h>

unsigned long long NumberFibonacciFast(unsigned long long* arr, int n)
{

	arr[0] = 0;
	arr[1] = 1;

	static int nums = 2;


	if (n <= 1)
	{
		return n;
	}
	else
	{

		if ((arr[n] == 0) && (n >= 1))
		{
			for (int i = nums; i <= n; i++)
			{
				arr[n] = arr[n - 1] + arr[n - 2];
				nums++;
			}
		}

		return arr[n];
	}
}




int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int n{0};

	std::cout << "Введите количество чисел Фибоначчи n (нумерация с 1 до 93): ";
	std::cin >> n;

	unsigned long long arr[93]{};

	std::cout << "n чисел Фибоначчи:" << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::cout << NumberFibonacciFast(arr, i) << std::endl;
	}

	return 0;
}