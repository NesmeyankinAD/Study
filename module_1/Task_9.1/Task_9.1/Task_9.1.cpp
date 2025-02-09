#include<iostream>

void print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}


int main()
{

	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = { 8, -1, 6, 12, 2, 36, 10, -5 };
	int c[] = { 100, 1, -6, -9, -6, -5, 80, 56, 20, 36, -90, 3};

	int size_a = sizeof(a) / sizeof(a[0]);
	int size_b = sizeof(b) / sizeof(b[0]);
	int size_c = sizeof(c) / sizeof(c[0]);

	print(a, size_a);
	print(b, size_b);
	print(c, size_c);

	
}