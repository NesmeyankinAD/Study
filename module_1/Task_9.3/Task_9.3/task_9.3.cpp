#include<iostream>
#include<locale.h>

void my_swap(int* x, int* y)
{
	//std::cout << "x = " << *x << ", y = " << *y << std::endl;

	*x = *x ^ *y;	//x xor y = Z
	*y = *x ^ *y;	//Z xor y = x
	*x = *x ^ *y;	//Z xor x = y

	//std::cout << "x = " << *x << ", y = " << *y << std::endl;
}

void print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void reverse(int* arr, int size)
{
	std::cout << "Исходный массив: "; print(arr, size);

	if (size % 2 == 0)
	{
		for (int i = 0; i < size/2; i++)
		{
			my_swap(&arr[i], &arr[size - i - 1]);
		}
	}
	else
	{
		for (int i = 0; i < (size-1)/2; i++)
		{
			my_swap(&arr[i], &arr[size - i - 1]);
		}
	}

	std::cout << "Развёрнутый массив: "; print(arr, size);
	}

int main()
{
	setlocale(LC_ALL, "Rus");

	int b[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int c[] = { 1, 2, 3, 4, 5};
	
	int size_b = sizeof(b) / sizeof(b[0]);
	int size_c = sizeof(c) / sizeof(c[0]);
	
	reverse(b, size_b);
	reverse(c, size_c);

}